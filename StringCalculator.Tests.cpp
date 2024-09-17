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

