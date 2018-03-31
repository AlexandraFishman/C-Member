
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

Member()
{
     counter++;
     memberId = ++nextID;
}

~Member()
{
    unfollowAll();
    followers.clear();
    following.clear();
    counter--;
}

bool exists(Member &who, vector <Member *> flo){
  for (unsigned i=0; i<flo.size(); i++)
  {
     if(flo.at(i)->memberId == who.memberId)
            return true;
  }
  return false;
}

 void follow(Member &who)
{
    if(!exists(*this, who.followers))
    { 
        who.followers.push_back(this);//(this->memberId);
    }
    if(!exists(who, this->following))
    {
        this->following.push_back(&who);//who.memberId);
    }
}
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

 int numFollowers()
{
    return this->followers.size();
}

 int numFollowing()
{
    return this->following.size();
}
};

int Member::counter=0;
int Member::nextID=0;