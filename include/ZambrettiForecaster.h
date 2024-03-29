/*
  TODO:
    - Create method documentations
*/
#include <string>
using namespace std;

class ZambrettiForecaster
{
public:
  #define DELTA_PRESSURE_TO_CHANGE_TREND (0.53F)
  enum TREND : int { FALLING, STEADY, RIZING };

  ZambrettiForecaster(float deltaPressureToChangeTrend = DELTA_PRESSURE_TO_CHANGE_TREND);
  int forecast(float pressure, ZambrettiForecaster::TREND pressureTrend);
  ZambrettiForecaster::TREND getPressureTrendBy(float deltaPressure);
  string getForecastText(int zambrettiNumber);
  

private:
  float _deltaPressureToChangeTrend;

  int constrain(int value, int max, int min);
  bool isRising(float deltaPressure);
  bool isFalling(float deltaPressure);
};

