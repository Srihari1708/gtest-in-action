#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <vector>

class TestDataPair{
public:
    string input;
    int expectedValue;
    TestDataPair(string _input,int _expectedValue) : input{_input}, expectedValue{_expectedValue}{
      }
};




TEST(StringCalculatorDataDrivenTestSuite,DataDrivenTestCase){
  vector<TestDataPair> dataList;
  TestDataPair pair_one { "",0};
  TestDataPair pair_two { "0",0};
  TestDataPair pair_three { "1",1};
  TestDataPair pair_four { "1,2",3};
  TestDataPair pair_five { "1,2,3",6};

  dataList.push_back(pair_one);
  dataList.push_back(pair_two);
  dataList.push_back(pair_three);
  dataList.push_back(pair_four);
  dataList.push_back(pair_five);
  
  //Iterate using a range-based for-loop
    for (TestDataPair dataPair : dataList) {
        int actualValue=Add(dataPair.input);
        ASSERT_EQ(actualValue,dataPair.expectedValue);
    }

}



class StringCalculatorTestFixture : public ::testing::Test {
protected:
    struct TestDataPair {
        std::string input;
        int expectedValue;

        TestDataPair(std::string _input, int _expectedValue)
            : input{_input}, expectedValue{_expectedValue} {}
    };

    std::vector<TestDataPair> dataList;

    void SetUp() override {
        // Initialize the test data
        dataList.push_back(TestDataPair("", 0));
        dataList.push_back(TestDataPair("0", 0));
        dataList.push_back(TestDataPair("1", 1));
        dataList.push_back(TestDataPair("1,2", 3));
        dataList.push_back(TestDataPair("1,2,3", 6));
    }
};

TEST_F(StringCalculatorTestFixture, DataDrivenTestCase) {
    // Iterate using a range-based for-loop
    for (const TestDataPair& dataPair : dataList) {
        int actualValue = Add(dataPair.input);
        ASSERT_EQ(actualValue, dataPair.expectedValue);
    }
}
