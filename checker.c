#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "checker.h"

int temperature_check(float temperature) {
  if(temperature < TEMP_MINTHRESHOLD || temperature > TEMP_MAXTHRESHOLD) {
    printAlertMsg("Temperature");
    return 0;
  }
  return 1;
}

int SOC_check(float soc) {
  if(soc < SOC_MINTHRESHOLD || soc > SOC_MAXTHRESHOLD) {
    printAlertMsg("State of Charge");
    return 0;
  }
  return 1;
}

int chargeRate_check(float chargeRate) {
  if(chargeRate > CHARGERATE_MAXTHRESHOLD) {
    printAlertMsg("Charge Rate");
    return 0;
  }
  return 1;
}

void printAlertMsg(char msg[]){
  printf("%s out of range!\n", msg);
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
}
