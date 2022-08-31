#include <regex>
#include <string>
#include <assert.h>
using namespace std;
string var = "1";
bool isInteger(const std::string &candidate)
{
    regex matcher("(-?(0|([1-9]((|')[0-9])*))|\\((0|([1-9]('?[0-9])*))\\))");
    return regex_match(candidate,matcher);
}

void TEST()
{
    assert(isInteger("0") == true);
    
}

std::regex int_regex("[0-9]+"); // '+' - quantifier '1 or more' items from range [0-9] 

regex_match(int_regex,var);
regex_mat


TEST(RegEx,DecimalInteger) 
{
   ASSERT_TRUE(IsDecimal("0"));
   ASSERT_TRUE(IsDecimal("1"));
   //ASSERT_TRUE(IsDecimal("1'2'3"));
   //ASSERT_TRUE(IsDecimal("1'000'000"));

   ASSERT_TRUE(IsDecimal("-0"));
   ASSERT_TRUE(IsDecimal("-1"));
   ASSERT_TRUE(IsDecimal("-1'2'3"));
   ASSERT_TRUE(IsDecimal("-1'000'000"));

   ASSERT_FALSE(IsDecimal("-"));
   ASSERT_FALSE(IsDecimal("00"));
   ASSERT_FALSE(IsDecimal("00"));
   ASSERT_FALSE(IsDecimal("0001"));
   ASSERT_FALSE(IsDecimal("1''000''000"));
   ASSERT_FALSE(IsDecimal(".20"));
   ASSERT_FALSE(IsDecimal("20."));
}