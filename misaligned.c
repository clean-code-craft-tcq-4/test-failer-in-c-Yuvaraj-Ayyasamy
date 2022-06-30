#include <stdio.h>
#include <assert.h>
#include <string.h>

#define COLORMANUAL_TEXTSIZE 20*25
char colorMap[COLORMANUAL_TEXTSIZE];
char referenceColorMap[COLORMANUAL_TEXTSIZE];
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

int printColorMap() 
{
    int majorIndex, minorIndex, pairNumber = 0, pairLength = 0;
    for(majorIndex = 0; majorIndex < numberOfMajorColors; majorIndex++) {
        for(minorIndex = 0; minorIndex < numberOfMinorColors; minorIndex++) {
            pairLength = sprintf(&colorMap[pairNumber], "%d\t|%s\t|%s\n", (majorIndex * numberOfMajorColors + minorIndex)+1, majorColor[majorIndex], minorColor[minorIndex]);
            pairNumber += pairLength;
        }
    }
    printf("%s", colorMap);
    return majorIndex * minorIndex;
}
void colorCodeReferenceManual()
{
    int majorIndex, minorIndex, pairNumber = 0, pairLength = 0;
    for(majorIndex = 0; majorIndex < numberOfMajorColors; majorIndex++) {
        for(minorIndex = 1; minorIndex <= numberOfMinorColors; minorIndex++) {
            pairLength = sprintf(&referenceColorMap[pairNumber], "%d\t|%s\t|%s\n", majorIndex * numberOfMajorColors + minorIndex, majorColor[majorIndex], minorColor[minorIndex-1]);
            pairNumber += pairLength;
        }
    }
}
void testManualAlignment()
{
    int result;
    colorCodeReferenceManual();
    result = strcmp(&referenceColorMap[0], &colorMap[0]);
    assert( result == 0);     
}
int main() 
{
    int result = printColorMap();
    assert(result == 25);
    testManualAlignment();
    printf("All is well (maybe!)\n");
    return 0;
}
