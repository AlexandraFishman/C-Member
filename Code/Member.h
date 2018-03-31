
#include <iostream>
using namespace std;
// #include<list>
#include <vector>
#include <algorithm>

class Member{
    static int counter;
    public:
        vector <Member> followers; //This member's followers
        vector <Member> following; //Who this member is following
         int memberId;
         static int count()
         {
             return counter;
         }

Member()
{
     counter++;
     memberId = counter;
}

~Member()
{
    followers.clear();
    following.clear();
    cout << "destructor " << endl;
    // counter--;
}

bool WhoIsThis(Member &who){
 return (this->memberId == who.memberId);
}

bool exists(Member &who, vector <Member> flo){
    vector <Member> :: iterator it;

  for (it = flo.begin(); it != flo.end(); it++) {
     if(it->WhoIsThis(who))
            return true;
  }
  return false;
}

 void follow(Member &who)
{
    if(!exists(*this, who.followers))
    { 
        // cout << "We add avi to benis followers" << endl;
        who.followers.push_back(*this);
    }
    if(!exists(who, this->following))
    {
        // cout << "We add beni to avis following" << endl;
        this->following.push_back(who);
    }
}
 void unfollow( Member &who)
{
    for (unsigned i=0; i<who.followers.size(); i++)
    {
        if(who.followers.at(i).WhoIsThis(*this))
            who.followers.erase(who.followers.begin()+ i);
    }

   for (unsigned i=0; i< this->following.size(); i++)
    {
        if(this->following.at(i).WhoIsThis(who))
            this->following.erase(this->following.begin()+ i);
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