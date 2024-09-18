#include <Testchallenge.h>
#include <gtest/gtest.h>


//stub - Fake dependency
class NetworkAlerterStub:public INetworkAlerter{
public:
    int alert(float celcius) override{
        return 500;
    }
};
TEST(NetworkAlerterTestSuite,StateBasedTest){
  NetworkAlerterStub stub;
  int failurecount = int alertInCelsiusFacade(400,&stub);  
  ASSERT_EQ(failurecount,1);
}
