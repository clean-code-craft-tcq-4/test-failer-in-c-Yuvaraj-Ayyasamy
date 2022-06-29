#include "alerter.h"

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius <= THRESHOLD_CELCIUS_VALUE) {
        return OK;
    } else {
        return NOTOK;
    }
}

float farenheitToCelcius(float farenheit) {
    return ((farenheit - 32) * 5 / 9);
}

void alertInCelcius(float farenheit) {
    // float celcius = farenheitToCelcius(farenheit);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != OK) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}
int main() {
    alertInCelcius(farenheitToCelcius(400.5));
    assert(alertFailureCount == 1);
    alertInCelcius(farenheitToCelcius(392.0));
    assert(alertFailureCount == 1);
    alertInCelcius(farenheitToCelcius(303.6));
    assert(alertFailureCount == 1);
    alertInCelcius(farenheitToCelcius(410.5));
    assert(alertFailureCount == 2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
