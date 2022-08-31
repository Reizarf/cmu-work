#include <regex>
#include <string>
#include <gtest/gtest.h>
using namespace std;

//goal - match c++ decimal base10 integer strings


// Digit = r(0|..|9)
// positiveDigit = r(1|..|9)
// Decimal == r(0|(positiveDigit((|')Digit)*))

bool isDecimal(const std::string &candidate) {
    regex matcher("(-?(0|([1-9]((|')[0-9])*))|\\((0|([1-9]('?[0-9])*))\\))");
    return regex_match(candidate,matcher);
}

//homework (what he's looking for) lookup BNF notation
bool isDouble(const std::string &candidate){

    return true;
}

bool isIdentifier(const std::string &candidate){

    return true;
}

test(regEx,Double){
    
}//
test(regEx,Identifier){

}

test(regEx, deimalInteger){
    ASSERT_TRUE(IsDecimal("0"));
    ASSERT_TRUE(IsDecimal("1"));
    ASSERT_TRUE(IsDecimal("1'2"));
    ASSERT_TRUE(IsDecimal("1'2'3"));
    ASSERT_TRUE(IsDecimal("1'000'000"));
   
    ASSERT_FALSE(IsDecimal("00"));
    ASSERT_FALSE(IsDecimal("0001"));
    ASSERT_FALSE(IsDecimal("001''000''0"));
    ASSERT_FALSE(IsDecimal("a20"));
    ASSERT_FALSE(IsDecimal("20a.00"));
}