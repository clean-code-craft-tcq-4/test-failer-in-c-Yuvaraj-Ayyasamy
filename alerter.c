#include "alerter.h"

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius <= THRESHOLD_CELCIUS_VALUE) {
        return 200;
    } else {
        return 500;
    }
}

float farenheitToCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}

void alertInCelcius(float farenheit) {
    float celcius = farenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
    else {
        alertFailureCount = 0;
    }
}
int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);
    alertInCelcius(392.0);
    assert(alertFailureCount == 0);
    alertInCelcius(303.6);
    assert(alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
