#include "StringCalculator.h"
#include <gtest/gtesh.h>

TEST(StringCalculatorTestSuite,Add_emptyInputString_ZeroIsExpected){
  //Arrange
  string input = "";
  int expectedValue=0;
  //Act
  int actualValue=Add(input);
  //Assert
  ASSERT_EQ(actualValue,expectedValue);
}
