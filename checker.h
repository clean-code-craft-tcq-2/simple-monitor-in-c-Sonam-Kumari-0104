/* Local macros */
#define TEMP_MINTHRESHOLD 0
#define TEMP_MAXTHRESHOLD 45
#define SOC_MINTHRESHOLD 20
#define SOC_MAXTHRESHOLD 80
#define CHARGERATE_MINTHRESHOLD 0.0
#define CHARGERATE_MAXTHRESHOLD 0.8

/*function Prototypes*/
int BMSValuesoutOfRangeCheck(float input, float minThreshold, float maxThreshold);
int temperature_check(float temperature);
int SOC_check(float soc);
int chargeRate_check(float chargeRate);
int batteryIsOk(float temperature, float soc, float chargeRate) ;
