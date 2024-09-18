#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <tuple>
#include <sstream>
#include <iostream>

class StringCalculatorTestFixture : public ::testing::Test {
protected:
    std::string input;
    int expectedValue;
    std::string actualOutput; // Changed from int to string to capture output
};

class StringCalculatorParameterFixture : public StringCalculatorTestFixture,
                                        public testing::WithParamInterface<std::tuple<std::string, int>> {
protected:
    void SetUp() override {
        // Set up parameters for the test based on the current test case
        input = std::get<0>(GetParam());
        expectedValue = std::get<1>(GetParam());
    }

    // Use a method to capture the output
    void CaptureOutput() {
        std::ostringstream buf; // Create a string stream
        std::streambuf *oldCoutBuf = std::cout.rdbuf(buf.rdbuf()); // Redirect cout to the string stream
        Add(input); // Call the Add function (which prints to cout)
        std::cout.rdbuf(oldCoutBuf); // Restore cout
        actualOutput = buf.str(); // Get the captured output
    }
};

// Parameter Values for testing
INSTANTIATE_TEST_SUITE_P(ValidStringCalculatorInputs, StringCalculatorParameterFixture, testing::Values(
                             //std::make_tuple("", 0),
                             std::make_tuple("1", 1),
                             std::make_tuple("1,2", 3),
                             std::make_tuple("1,1000", 1001)
                         ));

TEST_P(StringCalculatorParameterFixture, ParameterizedTest) {
    CaptureOutput(); // Capture the output from Add function

    // Now we need to check if the actualOutput matches the expected format
    // Example format: "The sum is: x", where x is expectedValue
    std::string expectedOutput = std::to_string(expectedValue);
    ASSERT_EQ(actualOutput, expectedOutput);
}
