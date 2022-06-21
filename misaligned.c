#include <stdio.h>
#include <assert.h>

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct {
    int pairNumber;
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

const int MAX_COLORPAIR_COUNT = 25;
ColorPair colorReferenceManual[MAX_COLORPAIR_COUNT];

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
const int MAX_COLORPAIR_NAME_CHARS = 16;

int prepareColorReferenceManual() {
    int majorIndex, minorIndex, colorPairIndex;
    for(majorIndex = 1, colorPairIndex = 0; majorIndex <= numberOfMajorColors; majorIndex++) {
        for(minorIndex = 1; minorIndex <= numberOfMinorColors; minorIndex++) {
            colorReferenceManual[colorPairIndex].pairNumber = colorPairIndex + 1;
            colorReferenceManual[colorPairIndex].majorColor = (enum MajorColor)(majorIndex);
            colorReferenceManual[colorPairIndex].minorColor = (enum MinorColor)(minorIndex);
            colorPairIndex++;
        }
    }
    return majorIndex * minorIndex;
}

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        MajorColorNames[colorPair->majorColor],
        MinorColorNames[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    pairNumber--;
    colorPair.pairNumber = colorReferenceManual[pairNumber].pairNumber;
    colorPair.majorColor = colorReferenceManual[pairNumber].majorColor;
    colorPair.minorColor = colorReferenceManual[pairNumber].minorColor;
    return colorPair;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
}

int printColorMap() {
    int majorIndex, minorIndex;
    for(majorIndex = 0; majorIndex < numberOfMajorColors; majorIndex++) {
        for(minorIndex = 0; minorIndex < numberOfMinorColors; minorIndex++) {
            printf("%d | %s | %s\n", majorIndex * numberOfMajorColors + minorIndex, MajorColorNames[majorIndex], MinorColorNames[minorIndex]);
        }
    }
    return majorIndex * minorIndex;
}

void testNumberToPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    ColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    colorPair.pairNumber = GetPairNumberFromColor(&colorPair);
    printf("Got pair number %d\n", colorPair.pairNumber);
    assert(colorPair.pairNumber == expectedPairNumber);
}

void testMinorColorCode(ColorPair* const colorPair)
{
  ColorPair testColorCodeData;
    
  if((colorPair->pairNumber > 0) && (colorPair->pairNumber <= MAX_COLORPAIR_COUNT))
  {
     testColorCodeData = GetColorFromPairNumber(colorPair->pairNumber);
    
     assert(testColorCodeData.minorColor == colorPair->minorColor); 
  }
  else if(colorPair->pairNumber == 0)
  {
      assert(colorPair->pairNumber == 1);
  }
}

void testMajorColorCode(ColorPair* const colorPair)
{
  ColorPair testColorCodeData;
    
  if((colorPair->pairNumber > 0) && (colorPair->pairNumber <= MAX_COLORPAIR_COUNT))
  {
     testColorCodeData = GetColorFromPairNumber(colorPair->pairNumber);
    
     assert(testColorCodeData.minorColor == colorPair->minorColor); 
  }
  else if(colorPair->pairNumber == 0)
  {
      assert(colorPair->pairNumber == 1);
  }
}

int main() {
    int colorPairCount, result;
    colorPairCount = prepareColorReferenceManual();
    testNumberToPair(5, WHITE, SLATE);
    testPairToNumber(BLACK, ORANGE, 12);
    result = printColorMap();
    assert(result == colorPairCount);
    testMajorColorCode(&colorReferenceManual[0]);
    testMinorColorCode(&colorReferenceManual[25]);
    printf("All is well (maybe!)\n");
    return 0;
}
