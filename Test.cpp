#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * 1 _===_
 * 2  ___ \n ....
 * 3   _  \n /_\\
 * 4  ___ \n (_*_)
 * HNLRXYTB
 **/

string nospaces(string input) {
	input.erase(remove(input.begin(),input.end(),' '),input.end());
  input.erase(remove(input.begin(),input.end(),'\t'),input.end());
  input.erase(remove(input.begin(),input.end(),'\r'),input.end());
  input.erase(remove(input.begin(),input.end(),'\n'),input.end());
	return input;
}

  TEST_CASE("good snowman code"){
    CHECK(nospaces(snowman(11111111))==nospaces("\n _===_\n (.,.)\n<( : )>\n ( : )\n"));
    CHECK(nospaces(snowman(22412131))==nospaces("\n  ___ \n  ....\n\\(-..)\n (> <)>\n ( : )\n"));
    CHECK(nospaces(snowman(12411223))==nospaces("\n _===_\n\\(-..)\n (\" \")>\n (___)\n"));
    CHECK(nospaces(snowman(32334144))==nospaces("\n   _  \n  /_\\ \n (o.o)\n (   )>\n (   )\n"));
    CHECK(nospaces(snowman(12341234))==nospaces("\n _===_\n (O.o)/\n<(> <)\n (   )"));
    CHECK(nospaces(snowman(43214321))==nospaces("\n  ___ \n (_*_)\n (o_.)\n (] [)\\ \n ( : )\n"));
    CHECK(nospaces(snowman(43432112))==nospaces("\n  ___ \n (_*_)\n\\(-_O)\n ( : )>\n (\" \")\n"));
    CHECK(nospaces(snowman(12334212))==nospaces("\n _===_\n (O.O)/\n ( : )\n ( : )\n"));
    CHECK(nospaces(snowman(4232212))==nospaces("\n _===_\n (o O)\n\\( : )/\n ( : )\n"));
    CHECK(nospaces(snowman(12411222))==nospaces("\n _===_\n\\(-..)\n (\" \")>\n ( : )\n"));
}
TEST_CASE("Bad snowman code"){
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(1234432));
    CHECK_THROWS(snowman(11245213));
    CHECK_THROWS(snowman(111322122));
    CHECK_THROWS(snowman(432113));
    CHECK_THROWS(snowman(232));
    CHECK_THROWS(snowman(12342215));
    CHECK_THROWS(snowman(552212341));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(2231563));
    CHECK_THROWS(snowman(23213));

}


