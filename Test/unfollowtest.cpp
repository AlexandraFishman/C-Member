#include <iostream>
using namespace std;

#include "Member.h"

Member inni,minni,miney,moe;

void test(){
    Member joe;
    cout << Member::count() << endl;
}

int main(){
    inni.follow(minni);
    inni.follow(miney);
    inni.follow(miney);
    inni.follow(moe);
    cout<< inni.numFollowing()<< endl;//should be 4
    inni.unfollowAll();
    cout << inni.numFollowing()<< endl;//should be 0
    test();
    cout << Member::count() << endl;
}