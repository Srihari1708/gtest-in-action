#include "StringCalculator.h"
#include <gtest/gtest.h>

class stringCalculatorFixture:public testing :: Test{
protected:
  string input;
int actualValue;
int expectedValue;
};

TEST_F(stringCalculatorFixture, Add_emptyInputString_ZeroIsExpected){
input = "";
expectedValue = 0;
actualValue = Add(input);
ASSERT_EQ(actualValue, expectedValue);
}
  

TEST(StringCalculatorTestSuite,Add_emptyInputString_ZeroIsExpected){
  //Arrange
  string input = "";
  int expectedValue=0;
  //Act
  int actualValue=Add(input);
  //Assert
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite,Add_whenSinglenumberispassed_ZeroIsExpected){
  //Arrange
  string input = "0";
  int expectedValue = 0;
  //Act
  int actualValue=Add(input);
  //Assert
  ASSERT_EQ(actualValue,expectedValue);
  
}

TEST(StringCalculatorTestSuite, Add_when_passed_two_comma_delimited_numbers)
{
  //Arrange
  string input = "1,2";
  int expectedValue = 3;

  //Act
  int actualValue = Add(input);

  //Assert
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_passed_multiple_comma_delimited_numbers)
{
  //Arrange
  string input = "7,8,9";
  int expectedValue = 24;

  //Act
  int actualValue = Add(input);

  //Assert
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_delimited_with_newline_and_comma)
{
  string input = "1\n2,3,4";
  int expectedValue = 10;

  int actualValue = Add(input);

  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_passed_a_delimiter)
{
  string input = "//\n,1,2,3//\n4";
  int expectedValue = 10;

  int actualValue = Add(input);

  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_passed_negative_numbers)
{
  string input = "1,2,-4,-5";
  int expectedValue = 0;
 ASSERT_THROW(Add(input),invalid_argument);
}

TEST(StringCalculatorTestSuite, when_passed_numbers_over_1000)
{
  string input = "1,1,2,10002,1000,1";
  int expectedValue = 1005;

  int actualValue = Add(input);

  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_passed_multicharacter_delimiter)
{
  string input = "//[***]\n8***2***3";
  int expectedValue = 13;

  int actualValue = Add(input);

  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_passed_multiple_delimiters)
{
  string input = "//[*][%]\n4*2%3";
  int expectedValue = 9;

  int actualValue = Add(input);

  ASSERT_EQ(actualValue,expectedValue);
}

TEST(StringCalculatorTestSuite, when_passed_multiple_multicharacter_delimiters)
{
  string input = "//[**][%^]\n4**1%^9";
  int expectedValue = 14;

  int actualValue = Add(input);

  ASSERT_EQ(actualValue,expectedValue);
}

