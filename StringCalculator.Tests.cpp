#include "StringCalculator.h"
#include <gtest/gtest.h>

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

