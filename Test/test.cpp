#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
using namespace std;

#include "Member.h"

Member dani, efi, finch;

TEST_CASE("testing Member") {
    dani.follow(efi);
    dani.follow(finch);
    CHECK(dani.numFollowing() == 2);
    dani.unfollowAll();
    CHECK(dani.numFollowing() == 0);
    efi.follow(efi);
    CHECK(efi.numFollowing() == 0);
}