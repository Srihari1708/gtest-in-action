#include <stdio.h>
#include <assert.h>
#include "Testchallenge.h"

int alertFailureCount = 0;

int getFailureCount() {
    return alertFailureCount;
}

void alertInCelcius(float farenheit, INetworkAlerter* networkAlerterPtr) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerterPtr->alert(celcius);

    // Modify this condition based on expected usage.
    // Assuming the alert should return 200 for success, and anything else is a failure.
    if (returnCode != 200) {
        alertFailureCount += 1;
    }
}

int alertInCelciusFacade(float farenheit, INetworkAlerter* networkAlerterPtr) {
    alertInCelcius(farenheit, networkAlerterPtr);
    return getFailureCount();
}
