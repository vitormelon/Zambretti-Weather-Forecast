// #ifdef UNIT_TEST

#include <unity.h>
#include <string>
#include <iostream>
#include "ZambrettiForecaster.h"

void testGivenRizingDeltaPressureWhenProcessedTrendShouldReturnRizing() {
    ZambrettiForecaster zambrettiForecaster;

    TEST_ASSERT_EQUAL(ZambrettiForecaster::RIZING, zambrettiForecaster.getPressureTrendBy(1000.1));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::RIZING, zambrettiForecaster.getPressureTrendBy(2));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::RIZING, zambrettiForecaster.getPressureTrendBy(0.54));
}

void testGivenSteadyDeltaPressureWhenProcessedTrendShouldReturnSteady() {
    ZambrettiForecaster zambrettiForecaster;

    TEST_ASSERT_EQUAL(ZambrettiForecaster::STEADY, zambrettiForecaster.getPressureTrendBy(0.53));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::STEADY, zambrettiForecaster.getPressureTrendBy(0.123));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::STEADY, zambrettiForecaster.getPressureTrendBy(0));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::STEADY, zambrettiForecaster.getPressureTrendBy(-0));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::STEADY, zambrettiForecaster.getPressureTrendBy(-0.123));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::STEADY, zambrettiForecaster.getPressureTrendBy(-0.53));
}

void testGivenFallingDeltaPressureWhenProcessedTrendShouldReturnFalling() {
    ZambrettiForecaster zambrettiForecaster;

    TEST_ASSERT_EQUAL(ZambrettiForecaster::FALLING, zambrettiForecaster.getPressureTrendBy(-0.54));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::FALLING, zambrettiForecaster.getPressureTrendBy(-2));
    TEST_ASSERT_EQUAL(ZambrettiForecaster::FALLING, zambrettiForecaster.getPressureTrendBy(-1000.123));
}

void testGivenDiferentPressureTrendsWhenForecastProcessedThenShouldReturDifferentResults() {
    ZambrettiForecaster ZambrettiForecaster;

    TEST_ASSERT_EQUAL(5, ZambrettiForecaster.forecast(1009.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(12, ZambrettiForecaster.forecast(1009.00, ZambrettiForecaster::STEADY));
    TEST_ASSERT_EQUAL(23, ZambrettiForecaster.forecast(1009.00, ZambrettiForecaster::RIZING));
}

void testGivenExtremePressuresWhenForecastProcessedThenShouldReturTheExtremeValue() {
    ZambrettiForecaster ZambrettiForecaster;

    TEST_ASSERT_EQUAL(32, ZambrettiForecaster.forecast(9.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(1, ZambrettiForecaster.forecast(10009.00, ZambrettiForecaster::RIZING));
}

void testGivenDiferentPressuresWhenKeepingTheTrendThenShouldReturDifferentResults() {
    ZambrettiForecaster ZambrettiForecaster;

    TEST_ASSERT_EQUAL(9, ZambrettiForecaster.forecast(980.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(8, ZambrettiForecaster.forecast(990.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(7, ZambrettiForecaster.forecast(1000.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(6, ZambrettiForecaster.forecast(1005.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(5, ZambrettiForecaster.forecast(1010.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(4, ZambrettiForecaster.forecast(1020.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(3, ZambrettiForecaster.forecast(1030.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(2, ZambrettiForecaster.forecast(1040.00, ZambrettiForecaster::FALLING));
    TEST_ASSERT_EQUAL(1, ZambrettiForecaster.forecast(1050.00, ZambrettiForecaster::FALLING));
    
}

//TODO: Just made it work, now i need to give a better name and test all the cases
void testForecastText() {
    ZambrettiForecaster ZambrettiForecaster;
    TEST_ASSERT_EQUAL_STRING("Settled Fine", ZambrettiForecaster.getForecastText(1).c_str());
}



int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testGivenRizingDeltaPressureWhenProcessedTrendShouldReturnRizing);
    RUN_TEST(testGivenSteadyDeltaPressureWhenProcessedTrendShouldReturnSteady);
    RUN_TEST(testGivenFallingDeltaPressureWhenProcessedTrendShouldReturnFalling);
    RUN_TEST(testGivenDiferentPressureTrendsWhenForecastProcessedThenShouldReturDifferentResults);
    RUN_TEST(testGivenExtremePressuresWhenForecastProcessedThenShouldReturTheExtremeValue);
    RUN_TEST(testGivenDiferentPressuresWhenKeepingTheTrendThenShouldReturDifferentResults);
    RUN_TEST(testMelon);
    UNITY_END();
}

// #endif

