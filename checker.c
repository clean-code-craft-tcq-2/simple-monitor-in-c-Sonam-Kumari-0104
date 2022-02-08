#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "checker.h"

void printAlertMsg(char msg[]){
  printf("%s out of range!\n", msg);
}

int BMSValuesoutOfRangeCheck(float input, float minThreshold, float maxThreshold) {
  if(input < minThreshold || input > maxThreshold){
    return 0;
  }
  return 1;
}

int temperature_check(float temperature) {
  int tempRangeStatus = BMSValuesoutOfRangeCheck(temperature, TEMP_MINTHRESHOLD, TEMP_MAXTHRESHOLD);
  if(!tempRangeStatus) {
    printAlertMsg("Temperature");
  }
  return tempRangeStatus;
}

int SOC_check(float soc) {
  int socRangeStatus = BMSValuesoutOfRangeCheck(soc, SOC_MINTHRESHOLD, SOC_MAXTHRESHOLD);
  if(!socRangeStatus) {
    printAlertMsg("State of Charge");
  }
  return socRangeStatus;
}

int chargeRate_check(float chargeRate) {
  int chargeRateRangeStatus = BMSValuesoutOfRangeCheck(chargeRate, CHARGERATE_MINTHRESHOLD, CHARGERATE_MAXTHRESHOLD);
  if(!chargeRateRangeStatus) {
    printAlertMsg("Charge Rate");
  }
  return chargeRateRangeStatus;
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  int ret_value = 1;
  ret_value = temperature_check(temperature)&&SOC_check(soc)&&chargeRate_check(chargeRate);
  return ret_value;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(40, 85, 0));
  assert(!batteryIsOk(40, 60, 0.9));
  assert(!temperature_check(-5));
  assert(temperature_check(40));
  assert(!temperature_check(60));
  assert(SOC_check(50));
  assert(!SOC_check(90.8));
  assert(!chargeRate_check(-2));
  assert(chargeRate_check(0.6));
  assert(!chargeRate_check(1));
}
