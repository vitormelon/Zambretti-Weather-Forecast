
#include "ZambrettiForecaster.h"
#include <string>

ZambrettiForecaster::ZambrettiForecaster(float deltaPressureToChangeTrend) {
  _deltaPressureToChangeTrend = deltaPressureToChangeTrend;
}
// ZambrettiForecaster::~ZambrettiForecaster(){}

string ZambrettiForecaster::getForecastText(int zambrettiNumber) {
  switch(zambrettiNumber)   
    {
    case 1:
        return "Settled Fine";
    case 2:
        return "Fine Weather";
    case 3:
        return "Fine. Becoming less settled";
    case 4:
        return "Mostly fine. Showers developing later";
    case 5:
        return "Showers. Becoming more unsettled";
    case 6:
        return "Unsettled, Rain later";
    case 7:
        return "Rain at times, worse later";
    case 8:
        return "Rain at times, becoming very unsettled";
    case 9:
        return "Very Unsettled, Rain";
    case 10:
        return "Settled Fine";
    case 11:
        return "Fine Weather";
    case 12:
        return "Fine, Possibly showers";
    case 13:
        return "Fairly Fine , Showers likely";
    case 14:
        return "Showery Bright Intervals";
    case 15:
        return "Changeable some rain";
    case 16:
        return "Unsettled, rain at times";
    case 17:
        return "Rain at Frequent Intervals";
    case 18:
        return "Very Unsettled, Rain";
    case 19:
        return "Stormy, much rain";
    case 20:
        return "Settled Fine";
    case 21:
        return "Fine Weather";
    case 22:
        return "Becoming Fine";
    case 23:
        return "Fairly Fine, Improving";
    case 24:
        return "Fairly Fine, Possibly showers, early";
    case 25:
        return "Showery Early, Improving";
    case 26:
        return "Changeable Mendin";
    case 27:
        return "Rather Unsettled Clearing Later";
    case 28:
        return "Unsettled, Probably Improving";
    case 29:
        return "Unsettled, short fine Interval";
    case 30:
        return "Very Unsettled, Finer at times";
    case 31:
        return "Stormy, possibly improving";
    case 32:
        return "Stormy, much rain";
    default:
        return "Unknow";
    }
}

int ZambrettiForecaster::forecast(float pressure, ZambrettiForecaster::TREND pressureTrend) {
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

int ZambrettiForecaster::constrain(int value, int min, int max) {
  if(value > max) return max;
  if(value < min) return min;
  return value;
}