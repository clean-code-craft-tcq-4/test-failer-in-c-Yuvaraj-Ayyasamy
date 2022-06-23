#include <stdio.h>
#include <assert.h>

#define THRESHOLD_CELCIUS_VALUE 200

int alertFailureCount = 0;

int networkAlertStub(float celcius);
void alertInCelcius(float farenheit);
