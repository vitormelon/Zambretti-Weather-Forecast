
#include "ZambrettiForecaster.h"

ZambrettiForecaster::ZambrettiForecaster(float deltaPressureToChangeTrend) {
  _deltaPressureToChangeTrend = deltaPressureToChangeTrend;
}
// ZambrettiForecaster::~ZambrettiForecaster(){}

int ZambrettiForecaster::forecast(unsigned int pressure, ZambrettiForecaster::TREND pressureTrend) {
  int result = 0;

  switch(pressureTrend)
  {
    case FALLING:   // pressure falling
      result = 127 - (0.12 * pressure);
      break;
    case STEADY:   // pressure steady
      result = 144 - (0.13 * pressure);
      break;
    case RIZING:   // pressure rising
      result = 185 - (0.16 * pressure) ;
      break;
  }

  result = constrain(result, 1, 32);
  return result;
}

ZambrettiForecaster::TREND ZambrettiForecaster::getPressureTrendBy(float deltaPressurePerHour) {
    if(isRising(deltaPressurePerHour)) {
        return RIZING;
    }
    if(isFalling(deltaPressurePerHour)) {
        return FALLING;
    }
    return STEADY;
}

bool ZambrettiForecaster::isRising(float deltaPressure) {
    return deltaPressure > DELTA_PRESSURE_TO_CHANGE_TREND;
}

bool ZambrettiForecaster::isFalling(float deltaPressure) {
    return deltaPressure < -DELTA_PRESSURE_TO_CHANGE_TREND;
}

int ZambrettiForecaster::constrain(int value, int max, int min) {
  if(value > max) return max;
  if(value < min) return min;
  return value;
}