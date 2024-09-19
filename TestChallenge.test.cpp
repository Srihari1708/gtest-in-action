#include <gtest/gtest.h>
#include "Testchallenge.h"
#include <gmock/gmock.h>

using testing::FloatEq;
using testing::Return;

// Stub implementation
class NetworkAlerterStub : public INetworkAlerter {
public:
    int alert(float celsius) override {
        return 500; // Simulate a fixed unsuccessful response
    }
};

// Mock implementation
class NetworkAlerterMock : public INetworkAlerter {
public:
    MOCK_METHOD(int, alert, (float celsius), (override));
};

TEST(NetworkAlerterTestSuite, StateBasedTest) {
    NetworkAlerterStub stub;
    int failureCount = alertInCelciusFacade(400, &stub);
    ASSERT_EQ(failureCount, 1); // Expect a failure since the stub always returns 500
}

TEST(NetworkAlerterTestSuite, InteractionTest) {
    NetworkAlerterMock mock;

    // Simulate a failure by returning 500
    EXPECT_CALL(mock, alert(FloatEq(204.444f)))
        .WillOnce(Return(500)); // Returning 500 for failure

    int failureCount = alertInCelciusFacade(400, &mock);
    ASSERT_EQ(failureCount, 1); // Expect 1 failure since the alert returns 500
}
