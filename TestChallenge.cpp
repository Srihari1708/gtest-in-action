#include <stdio.h>
#include <assert.h>
#include<Testchallenge.h>
 
int alertFailureCount = 0;

int getfailurecount(){
 return alertFailureCount;
}
int networkAlerter(float celcius) {
   //Communicate with Network, Require Internet Connectivity and credentials
  //If Communication is successfull , returns 200 otherwise 500
    return 500;
}
 
void alertInCelcius(float farenheit, *networkAlerterPtr) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerterPtr->alert(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}

int alertInCelsiusFacade(float farenheit *networkAlerterPtr){
alertInCelsius(farenheit);
 return getfailurecount();
}

 
