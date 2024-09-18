#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <tuple>

class StringCalculatorTestFixture : public ::testing::Test {
protected:
    string input;
    int expectedValue;
    int actualValue;
};

class StringCalculatorParameterFixture : public StringCalculatorTestFixture,
                                        public testing::WithParamInterface<tuple<string, int>> {
protected:
    void SetUp() override {
        // Set up parameters for the test based on the current test case
        input = std::get<0>(GetParam());
        expectedValue = std::get<1>(GetParam());
    }
};

// Parameter Values for testing
INSTANTIATE_TEST_SUITE_P(ValidStringCalculatorInputs, StringCalculatorParameterFixture,testing::Values(
                             make_tuple("", 0),
                             make_tuple("1", 1),
                             make_tuple("1,2", 3),
                             make_tuple("1,1000", 1001)
                         ));

TEST_P(StringCalculatorParameterFixture, ParameterizedTest) {
    actualValue = Add(input);
    ASSERT_EQ(actualValue, expectedValue);
}
