#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
    cout << "Test Function " << dana.memberId << endl;
	dana.follow(avi);
	cout << " line 14" << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1 
	cout << " line 15 " << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0 
	cout << " line 16" << "  " << Member::count() << endl; // 4
}

int main() {
	cout << avi.numFollowers() <<" line 20" << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() <<" line 22" << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " line 23" << " " << beni.numFollowing() << endl; // 1 0 
	cout << "line 25 " << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " line 29 " <<" " << avi.numFollowing() << endl; // 0 1 
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " line 31  " <<" " << avi.numFollowing() << endl; // 0 0 
	cout << endl;

	cout << chana.numFollowers() << " line 34" << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " line 36 " <<" " <<  chana.numFollowing() << endl; // 0 0 -----------------EROR 0 1
	cout << avi.numFollowers() << " line 37 " << " " <<  avi.numFollowing() << endl; // 0 0 -----------------------Eror 1 0
	cout << "line 38 " << Member::count() << endl; // 3 
}