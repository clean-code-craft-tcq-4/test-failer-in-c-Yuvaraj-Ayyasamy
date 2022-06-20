#include <stdio.h>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int majorIndex, minorIndex;
    for(majorIndex = 1; majorIndex < 6; majorIndex++) {
        for(minorIndex = 0; minorIndex < 5; minorIndex++) {
            printf("%d | %s | %s\n", (majorIndex-1) * 5 + minorIndex, majorColor[majorIndex-1], minorColor[minorIndex]);
        }
    }
    return majorIndex * minorIndex;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
