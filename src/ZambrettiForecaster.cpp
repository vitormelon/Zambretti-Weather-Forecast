
#include "ZambrettiForecaster.h";

int ZambrettiForecaster::forecast(unsigned int pressure, int pressureTrend)
{

  //  fall    Z = 130-10P/81
  //  steady  Z = 147-50P/376
  //  rise    Z = 179-20P/129

  int result = 0;

  switch (pressureTrend)
  {
  case 0: // pressure falling
    result = 130 - 10 * pressure / 81;
    break;
  case 1: // pressure steady
    result = 147 - 50 * pressure / 376;
    break;
  case 2: // pressure rising
    result = 179 - 20 * pressure / 129;
    break;
  }

  result = constrain(result, 1, 32);
  return result;
}

int ZambrettiForecaster::constrain(int value, int max, int min) {
  if(value > max) return max;
  if(value < min) return min;
  return value;
}