#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <vector>

class TestDataPair{
public:
    string input;
    int expectedValue;
    TestDataPair(string _input, int _expectedValue) : input{_input}, expectedValue{_expectedValue}{
    }
};

TEST(StringCalculatorTestSuite, data_driven_test){
  vector<TestDataPair> datalist;
  class TestDataPair{
public:
    string input;
    int expectedValue;
    TestDataPair(string _input, int _expectedValue) : input{_input}, expectedValue{_expectedValue}{
    }
};

TEST(StringCalculatorTestSuite, data_driven_test){
  vector<TestDataPair> datalist;
  TestDataPair pair_one{"", 0};
  TestDataPair pair_two{"1,2,3",6};
  TestDataPair pair_three{"1", 1};
  TestDataPair pair_four{"1,1000", 1001};

  dataList.pushback(pair_one);
  dataList.pushback(pair_two);
  dataList.pushback(pair_three);
  dataList.pushback(pair_four);

  for(TestDataPair dataPair : dataList){
    int actualValue = Add(dataPair.input);
    ASSERT_EQ(actualValue, datapair.expectedValue);
  }
  
  
} pair_one{"", 0};
  TestPair pair_two{"1,2,3",6};
  TestPair pair_three{"1", 1};
  TestPair pair_four{"1,1000", 1001};

  dataList.pushback(pair_one);
  dataList.pushback(pair_two);
  dataList.pushback(pair_three);
  dataList.pushback(pair_four);

  for(TestDataPair dataPair : dataList){
    int actualValue = Add(dataPair.input);
    ASSERT_EQ(actualValue, datapair.expectedValue);
  }
  
  
}

