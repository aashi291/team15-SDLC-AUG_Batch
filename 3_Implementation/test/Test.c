#include <unity.h>
#include <unity_internals.h>
#include "header.h"
#define PROJECT_NAME "TradingStrategy"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}
void testSma(void);
void testBollingerBands(void);
void testMFI(void);
//array to test sma and crossover functions
float *close;
//array to test sma and crossover functions
const char *filePath = "LTTS.csv";
int main(){
    //array to test sma and crossover functions
    const char *filePath = "LTTS.csv";
    FILE *file = fopen(filePath,"r");
    close = readColumn(file,7);
    UNITY_BEGIN();
    RUN_TEST(testSma);
    RUN_TEST(testBollingerBands);
    RUN_TEST(testMFI);
    return UNITY_END();
}

void testSma(void)
{
    TEST_ASSERT_EQUAL_FLOAT(2848.829,sma(12,10,close));
    TEST_ASSERT_FLOAT_WITHIN(5.000,2844.38,sma(12,10,close));
}
void testBollingerBands(void)
{
    TEST_ASSERT_EQUAL_FLOAT(1774.471,upperBand(2,20,361,close));
    TEST_ASSERT_EQUAL_FLOAT(1469.00298,lowerBand(2,20,361,close));
    TEST_ASSERT_FLOAT_WITHIN(2.000,1774.471,upperBand(2,20,361,close));
    TEST_ASSERT_FLOAT_WITHIN(2.000,1469.00298,lowerBand(2,20,361,close));
    TEST_ASSERT_EQUAL(-3,upperBand(2,20,365,close));
    TEST_ASSERT_EQUAL(1,lowerBand(2,20,365,close));
    TEST_ASSERT_EQUAL(-1,movingMiddleBand(20,365,close));
    TEST_ASSERT_EQUAL(-1,stdDev(20,365,close));
}

void testMFI(void)
{
    TEST_ASSERT_EQUAL(78, mfiCalculator(3.586692897));
    TEST_ASSERT_EQUAL(78, mfiCalculator(3.639461998));
    TEST_ASSERT_EQUAL(64, mfiCalculator(1.797571971));
    TEST_ASSERT_EQUAL(10, mfiCalculator(0.114763051));
    TEST_ASSERT_EQUAL(86, mfiCalculator(6.174203173));
    TEST_ASSERT_EQUAL(15, mfiCalculator(0.180448517));
}
