#include <unity.h>
#include <unity_internals.h>
#include "header.h"

#define PROJECT_NAME "TradingStrategy"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void testSma(void);

//array to test sma and crossover functions
float arrayTata[] = {379,316,346,344,344,339,341,342,339,334,335,337,334,337,345,349,352,355,350,344,343,352,345,334,325,323,318,318,318,
    318,315,315,311,313,307,314,332,321,312,326,315,314,302,301,291,289,293,293,301,305,301,295,294,294,298,301,310,303,302,286,318,313,307,
    307,305,307,301,297,296,285,294,307,303,308,307,305,319,318,317,321,315,321,325,339,348,345,328,322,333,321,324,304,311,323,330,329,333,
    325,325,328,325,335,315,326,331,322,279,262,266,267,279,289,290,274,258,245,260,245,242,237,220,198,196,195,193,191,186,183,184,183,186,
    175,169,164,164,180,181,182,178,177,178,177,182,181,183,184,184,183,179,180,173,171,172,170,169,167,173,158,148,146,151,150,146,141,139,
    137,135,134,132,132,131,134,135,133,137,133,130,129,128,127,126,130,134,135,138,140,141,144,133,133,133,131,132,127,122,131,133,137,147,
    147,151,148,148,144,143,140,142,149,147,151,150,143,143,142,144,137,127,121,120,121,125,125,123,124,131,125,122,123,119,116,115,111,113,
    104,103,105,106,101,103,106,105,108,105,106,102,103,105,108,107,106,105,109,109,103,101,100,98,99,101,103,104,104,102,102,96,95,94,100,
    105,106,111,111,115,110,98,98,96,89,87,87,84,83,82,84,83,81,80,84,83,87,86,86,81,82,83,80,83,93,78,76,75,74,75,75,74,80,76,74,72,74,74,
    67,67,65,67,71,68,70,70,70,68,66,77,72,75,77,82,89,88,98,105,114,125,126,130,125,128,145,144,149,150,158,158,161,169,169,169,170,169,168,
    173,178,183,165,163,165,176,186,188,176,182,186,188,185,191,195,197,197,200,195,196,196,192,182,184,185,191,193,184};
float *arrayTataCls = (float*)arrayTata;

int main(){
    UNITY_BEGIN();

    RUN_TEST(testSma);

    return UNITY_END();
}

void testSma(void)
{
    TEST_ASSERT_EQUAL_FLOAT(312.4286,sma(14,31,arrayTataCls));
    TEST_ASSERT_EQUAL_FLOAT(154.3333,sma(6,156,arrayTataCls));
    TEST_ASSERT_EQUAL_FLOAT(-1,sma(28,370,arrayTataCls));
}