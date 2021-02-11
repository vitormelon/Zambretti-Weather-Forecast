// #ifdef UNIT_TEST

#include <unity.h>
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

int main( int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(testGivenRizingDeltaPressureWhenProcessedTrendShouldReturnRizing);
    RUN_TEST(testGivenSteadyDeltaPressureWhenProcessedTrendShouldReturnSteady);
    RUN_TEST(testGivenFallingDeltaPressureWhenProcessedTrendShouldReturnFalling);
    UNITY_END();
}

// #endif

