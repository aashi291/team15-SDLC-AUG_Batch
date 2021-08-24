#include <unity.h>
#include <unity_internals.h>
#include "header.h"
#include "WillR.h"

#define PROJECT_NAME "TradingStrategy"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void testSma(void);
void testBollingerBands(void);
void testWilliamR(void);

//array to test sma and crossover functions
float *close,*low,*high;
//array to test sma and crossover functions
 char *filePath = "LTTS.csv";
int length;
int main(){

    //array to test sma and crossover functions
    length = findLength(filePath);
    //const char *filePath = "LTTS.csv";
    FILE *file = fopen(filePath,"r");
    float *coloumn2 = readColumn(file,3);
       high = malloc(length*sizeof(float));
        memcpy(high,coloumn2,length*sizeof(float));

        
        float *coloumn3 = readColumn(file,4);
        low = malloc(length*sizeof(float));
        memcpy(low,coloumn3,length*sizeof(float));
    close = readColumn(file,7);
    UNITY_BEGIN();

    RUN_TEST(testSma);
    RUN_TEST(testBollingerBands);
    RUN_TEST(testWilliamR);

    return UNITY_END();
}

void testSma(void)
{
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

void testWilliamR(void)
{
        //TEST_ASSERT_EQUAL(0,WilliamR(filePath));
        int length = findLength(filePath);
        TEST_ASSERT_FLOAT_WITHIN(-20.00,20.00,findWillR(100,14,length,10,close , high,low));
        TEST_ASSERT_FLOAT_WITHIN(1000.0,3000,findDMA(100,10,close,length));
}

void testFindLength(void)
{
    TEST_ASSERT_TRUE(findLength(filePath)) ;
}