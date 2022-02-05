#include <stdio.h>
#include <assert.h>
#include "checker.h"

void temperature_check(float temperature) {
  if(temperature < TEMP_MINTHRESHOLD || temperature > TEMP_MAXTHRESHOLD) {
    printAlertMsg("Temperature");
  }
}

void SOC_check(float soc) {
  if(soc < SOC_MINTHRESHOLD || soc > SOC_MAXTHRESHOLD) {
    printAlertMsg("State of Charge");
  }
}

void chargeRate_check(float chargeRate) {
  if(chargeRate > CHARGERATE_MAXTHRESHOLD) {
    printAlertMsg("Charge Rate");
  }
}

void printAlertMsg(string msg){
  printf("%s out of range!\n", msg);
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
  temperature_check(temperature);
  SOC_check(soc);
  chargeRate_check(chargeRate);
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
