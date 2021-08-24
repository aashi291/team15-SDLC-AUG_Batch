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
void testmacd(void);
void testWilliamR(void);
//array to test sma and crossover functions
float *close;
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
    RUN_TEST(testmacd);
    RUN_TEST(testWilliamR);
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

void testmacd(void)
{
    TEST_ASSERT_FLOAT_WITHIN(4.000,70.93,macd(12,26,10,close));
}
void testWilliamR(void)
{
    float close1[100] = {2917.55,2954.00,2963.70,2921.75,2893.50,2899.90,2877.20,2892.60,2903.10,2892.75,2885.45,2927.05,2854.65,2825.20,2824.25,2806.55,2794.60,2808.20,2844.55,2859.45,2863.25,2873.80,2810.00,2738.60,2784.30,2776.95,2720.90,2701.65,2668.60,2687.00,2710.85,2705.25,2725.45,2704.15,2616.90,2588.10,2624.25,2610.80,2638.25,2640.40,2566.65,2539.55,2538.50,2530.45,2505.85,2521.40,2549.15,2567.85,2,575.50,2,797.40};
    float high1[100] = {3,005.00,2986.85,2987.00,2935.25,2962.65,2932.00,2926.70,2924.00,2942.00,2923.05,2950.00,2978.00,2930.90,2855.00,2842.00,2817.15,2874.00,2855.55,2899.80,2882.00,2910.00,2885.00,2850.00,2838.00,2825.00,2805.00,2779.50,2709.75,2704.15,2730.90,2743.65,2747.90,2751.95,2715.00,2631.00,2648.00,2654.65,2664.00,2669.70,2650.95,2579.95,2583.00,2599.00,2585.00,2533.00,2575.00,2592.00,2620.00,2690.00,2820.00};
    float low1 [100]={2,909.00,2927.05,2909.45,2850.00,2881.15,2879.45,2868.60,2867.50,2886.00,2860.35,2875.55,2865.10,2825.95,2820.00,2815.00,2720.00,2734.15,2753.85,2835.00,2843.20,2806.00,2806.90,2742.60,2715.00,2758.00,2730.00,2688.00,2667.00,2649.35,2676.00,2696.40,2694.00,2678.45,2610.65,2592.50,2585.00,2610.25,2599.20,2630.95,2560.00,2517.25,2531.55,2528.00,2476.05,2492.10,2510.30,2485.00,2560.00,2557.80,2640.00};
    //TEST_ASSERT_FLOAT_WITHIN((-20,20),findWillR(50, 14,50,10, close1,high1 , low1));
    TEST_ASSERT_FLOAT_WITHIN(6000,6000,findDMA(20, 10 , close1,50));
}
