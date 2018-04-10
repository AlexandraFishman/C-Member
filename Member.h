
#include <iostream>
using namespace std;
// #include<list>
#include <vector>
#include <algorithm>

class Member{
    static int counter;
    protected: static int nextID;
    public:
        vector <Member *> followers; //This member's followers
        vector <Member *> following; //Who this member is following
        int memberId;
         static int count()
         {
             return counter;
         }
//Constructor
Member()
{
     counter++;
     memberId = ++nextID;
}
//Destructor
~Member()
{
    unfollowAll();
    followers.clear();
    following.clear();
    counter--;
}
//Checks if a member is in a list (follower/following)
bool exists(Member &who, vector <Member *> flo){
  for (unsigned i=0; i<flo.size(); i++)
  {
     if(flo.at(i)->memberId == who.memberId)
            return true;
  }
  return false;
}
//Add a member to the following vector and the followers of the other member
void follow(Member &who)
{
    if(this->memberId!=who.memberId){//checks if its the same Member
        if(!exists(*this, who.followers))
        { 
            who.followers.push_back(this);//(this->memberId);
        }
        if(!exists(who, this->following))
        {
            this->following.push_back(&who);//who.memberId);
        }
    }
}

//Unfollow a specific member
 void unfollow( Member &who)
{
    for (unsigned i=0; i<who.followers.size(); i++)
    {
        if(who.followers.at(i)->memberId == this->memberId)
            who.followers.erase(who.followers.begin()+ i);
    }

   for (unsigned i=0; i< this->following.size(); i++)
    {
        if(this->following.at(i)->memberId == who.memberId)
            this->following.erase(this->following.begin()+ i);
    }
   
}
//Unfollow every Member
void unfollowAll()
{
  for (unsigned i=0; i< this->followers.size(); i++)
  {
     this->followers.at(i)->unfollow(*this);
  }

  for (unsigned i=0; i< this->following.size(); i++)
  {
      this->unfollow(*this->following.at(i));
  }

}
//Returns the number of followers this Member has
 int numFollowers()
{
    return this->followers.size();
}
//Returns the number of people the Memeber is following
 int numFollowing()
{
    return this->following.size();
}
};

int Member::counter=0;
int Member::nextID=0;