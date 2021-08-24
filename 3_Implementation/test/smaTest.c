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
float *close;
int main(){

    //array to test sma and crossover functions
    const char *filePath = "LTTS.csv";
    FILE *file = fopen(filePath,"r");
    close = readColumn(file,7);
    UNITY_BEGIN();

    RUN_TEST(testSma);

    return UNITY_END();
}

void testSma(void)
{
    TEST_ASSERT_EQUAL_FLOAT(2848.829,sma(12,10,close));
}
