#include <gtest/gtest.h>
#include "Testchallenge.h"
#include <gmock/gmock.h>
using testing::FloatEq; //matcher used to match the argumernts
using testing::Return; 
//Stub - Fake Dependency
class NetworkAlerterStub:public INetworkAlerter{
public:
      int  alert(float celcius) override{
          return 500;
      }
};
//Mock implementation
class NetworkAlerterMock:public INetworkAlerter{
public:
            MOCK_METHOD(int,alert,(float celcius));

};
TEST(NetworkAlerterTestSuite,StateBasedTest){
  NetworkAlerterStub stub;
    int failureCount=  alertInCelciusFacade(400,&stub);
    ASSERT_EQ(failureCount,1);
}

TEST(NetworkAlerterTestSuite,InteractionTest){
    NetworkAlerterMock mock;
      //Expected Value
     EXPECT_CALL(mock,alert(FloatEq(204.44))).Times(1).WillOnce(Return(500));
    int failureCount =  alertInCelciusFacade(400,&mock);
    ASSERT_EQ(failureCount,1);
      
}


