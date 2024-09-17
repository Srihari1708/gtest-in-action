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
  
  if(string input = "0")
  {
  int expectedValue = 0;
  }

  if(string input = "1")
  {
    int expectedValue = "1";
  }
  
  //Act
  int actualvalue=Add(input);
  //Assert
  ASSERT_EQ(actualValue,expectedValue);
  
}

TEST(StringCalculatorTestSuite, Add_when

