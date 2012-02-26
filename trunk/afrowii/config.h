/*******************************/
/*******************************/
/****CONFIGURABLE PARAMETERS****/
/*******************************/

#ifndef BRUSHED
/* Set the minimum throttle command sent to the ESC (Electronic Speed Controller)
   This is the minimum value that allow motors to run at a idle speed  */
//#define MINTHROTTLE 1300 // for Turnigy Plush ESCs 10A
//#define MINTHROTTLE 1120 // for Super Simple ESCs 10A
//#define MINTHROTTLE 1220
#define MINTHROTTLE 1120
/* this is the value for the ESCs when they are not armed
   in some cases, this value must be lowered down to 900 for some specific ESCs */
#define MINCOMMAND 1000
/* this is the maximum value for the ESCs at full power
   this value can be increased up to 2000 */
#define MAXTHROTTLE 2000
// #define DIGITAL_SERVO      // If high-speed (200hz) refresh is needed on tail servo or for camera stabilization, define this. otherwise 50hz is used.

#else
/* Set the minimum throttle command sent to the ESC (Electronic Speed Controller)
   This is the minimum value that allow motors to run at a idle speed  */
//#define MINTHROTTLE 1300 // for Turnigy Plush ESCs 10A
//#define MINTHROTTLE 1120 // for Super Simple ESCs 10A
//#define MINTHROTTLE 1220
#define MINTHROTTLE 100
/* this is the value for the ESCs when they are not armed
   in some cases, this value must be lowered down to 900 for some specific ESCs */
#define MINCOMMAND 0
/* this is the maximum value for the ESCs at full power
   this value can be increased up to 2000 */
#define MAXTHROTTLE 2000
// #define DIGITAL_SERVO      // If high-speed (200hz) refresh is needed on tail servo or for camera stabilization, define this. otherwise 50hz is used.
#endif

#define YAW_DIRECTION 1		// if you want to reverse the yaw correction direction
//#define YAW_DIRECTION -1

//#define I2C_SPEED 100000L	//100kHz normal mode, this value must be used for a genuine WMP
#define I2C_SPEED 400000L   //400kHz fast mode, it works only with some WMP clones

//****** advanced users settings   *************

/* This option should be uncommented if ACC Z is accurate enough when motors are running*/
#define TRUSTED_ACCZ

/* This option is here if you want to use the old level code from the verison 1.7
   It's just to have some feedback. This will be removed in the future */
// #define STAB_OLD_17

/* GPS
   only available on MEGA boards (this might be possible on 328 based boards in the future)
   if enabled, define here the Arduino Serial port number and the UART speed
   note: only the RX PIN is used, the GPS is not configured by multiwii
   the GPS must be configured to output NMEA sentences (which is generally the default conf for most GPS devices)
*/
//#define GPS
//#define GPS_SERIAL Serial3 // should be Serial2 for flyduino v2
//#define GPS_BAUD   4800
//#define GPS_BAUD   9600

/* Pseudo-derivative conrtroller for level mode (experimental)
   Additional information: http://wbb.multiwii.com/viewtopic.php?f=8&t=503 */
//#define LEVEL_PDF

/* introduce a deadband around the stick center
   Must be greater than zero, comment if you dont want a deadband on roll, pitch and yaw */
//#define DEADBAND 6

/* Failsave settings - added by MIS
   Failsafe check pulse on THROTTLE channel. If the pulse is OFF (on only THROTTLE or on all channels) the failsafe procedure is initiated.
   After FAILSAVE_DELAY time of pulse absence, the level mode is on (if ACC or nunchuk is avaliable), PITCH, ROLL and YAW is centered
   and THROTTLE is set to FAILSAVE_THR0TTLE value. You must set this value to descending about 1m/s or so for best results. 
   This value is depended from your configuration, AUW and some other params. 
   Next, afrer FAILSAVE_OFF_DELAY the copter is disarmed, and motors is stopped.
   If RC pulse coming back before reached FAILSAVE_OFF_DELAY time, after the small quard time the RC control is returned to normal.
   If you use serial sum PPM, the sum converter must completly turn off the PPM SUM pusles for this FailSafe functionality.*/
#define FAILSAFE		// Alex: comment this line if you want to deactivate the failsafe function
#define FAILSAVE_DELAY     10	// Guard time for failsafe activation after signal lost. 1 step = 0.1sec - 1sec in example
#define FAILSAVE_OFF_DELAY 200	// Time for Landing before motors stop in 0.1sec. 1 step = 0.1sec - 20sec in example
#define FAILSAVE_THR0TTLE  (MINTHROTTLE + 200)	// Throttle level used for landing - may be relative to MINTHROTTLE - as in this case

/* EXPERIMENTAL !!
  contribution from Luis Correia
  see http://www.multiwii.com/forum/viewtopic.php?f=18&t=828
  It uses a Bluetooth Serial module as the input for controlling the device via an Android application
  As with the SPEKTRUM option, is not possible to use the configuration tool on a mini or promini. */
//#define BTSERIAL

/* The following lines apply only for a pitch/roll tilt stabilization system
   On promini board, it is not compatible with config with 6 motors or more
   Uncomment the first line to activate it 
   These constants are also used in MULTITYPE_GIMBAL, in this case no #define is needed */
// #define SERVO_TILT
#define TILT_PITCH_MIN    1020	//servo travel min, don't set it below 1020
#define TILT_PITCH_MAX    2000	//servo travel max, max value=2000
#define TILT_PITCH_MIDDLE 1500	//servo neutral value
#define TILT_ROLL_MIN     1020
#define TILT_ROLL_MAX     2000
#define TILT_ROLL_MIDDLE  1500

/* if you use a specific sensor board:
   please submit any correction to this list.
     Note from Alex: I only own some boards
                     for other boards, I'm not sure, the info was gathered via rc forums, be cautious */
//#define FFIMUv1         // first 9DOF+baro board from Jussi, with HMC5843                   <- confirmed by Alex
//#define FFIMUv2         // second version of 9DOF+baro board from Jussi, with HMC5883       <- confirmed by Alex
//#define FREEIMUv1       // v0.1 & v0.2 & v0.3 version of 9DOF board from Fabio
//#define FREEIMUv03      // FreeIMU v0.3 and v0.3.1
//#define FREEIMUv035     // FreeIMU v0.3.5 no baro
//#define FREEIMUv035_MS  // FreeIMU v0.3.5_MS                                                <- confirmed by Alex
//#define FREEIMUv035_BMP // FreeIMU v0.3.5_MS
//#define PIPO            // 9DOF board from erazz
//#define QUADRINO        // full FC board 9DOF+baro board from witespy                       <- confirmed by Alex
//#define ALLINONE        // full FC board or standalone 9DOF+baro board from CSG_EU
//#define AEROQUADSHIELDv2
//#define ATAVRSBIN1      // Atmel 9DOF (Contribution by EOSBandi). The board requires 3.3V power.
//#define SIRIUS          // Sirius Navigator IMU                                             <- confirmed by Alex


//if you use independent sensors
//leave it commented it you already checked a specific board above
/* I2C gyroscope */
//#define ITG3200
//#define L3G4200D

/* I2C accelerometer */
//#define ADXL345
//#define BMA020
//#define BMA180
//#define NUNCHACK  // if you want to use the nunckuk as a standalone I2C ACC without WMP
//#define LIS3LV02
//#define LSM303DLx_ACC

/* I2C barometer */
//#define BMP085
//#define MS561101BA

/* I2C magnetometer */
//#define HMC5843
//#define HMC5883
//#define AK8975

/* ADC accelerometer */// for 5DOF from sparkfun, uses analog PIN A1/A2/A3
//#define ADCACC

/* ITG3200 & ITG3205 Low pass filter setting. In case you cannot eliminate all vibrations to the Gyro, you can try
   to decrease the LPF frequency, only one step per try. As soon as twitching gone, stick with that setting.
   It will not help on feedback wobbles, so change only when copter is randomly twiching and all dampening and
   balancing options ran out. Uncomment only one option!
   IMPORTANT! Change low pass filter setting changes PID behaviour, so retune your PID's after changing LPF.*/
//#define ITG3200_LPF_256HZ     // This is the default setting, no need to uncomment, just for reference
//#define ITG3200_LPF_188HZ
//#define ITG3200_LPF_98HZ
//#define ITG3200_LPF_42HZ
//#define ITG3200_LPF_20HZ
//#define ITG3200_LPF_10HZ      // Use this only in extreme cases, rather change motors and/or props

/* The following lines apply only for specific receiver with only one PPM sum signal, on digital PIN 2
   IF YOUR RECEIVER IS NOT CONCERNED, DON'T UNCOMMENT ANYTHING. Note this is mandatory for a Y6 setup on a promini
   Select the right line depending on your radio brand. Feel free to modify the order in your PPM order is different */
//#define SERIAL_SUM_PPM         PITCH,YAW,THROTTLE,ROLL,AUX1,AUX2,CAMPITCH,CAMROLL //For Graupner/Spektrum
#define SERIAL_SUM_PPM         ROLL,PITCH,THROTTLE,YAW,AUX1,AUX2,CAMPITCH,CAMROLL //For Robe/Hitec/Futaba
//#define SERIAL_SUM_PPM         PITCH,ROLL,THROTTLE,YAW,AUX1,AUX2,CAMPITCH,CAMROLL //For some Hitec/Sanwa/Others

/* The following lines apply only for Spektrum Satellite Receiver on MEGA boards only *///not yet implemented
//#define SPEKTRUM

/* for V BAT monitoring
   after the resistor divisor we should get [0V;5V]->[0;1023] on analog V_BATPIN
   with R1=33k and R2=51k
   vbat = [0;1023]*16/VBATSCALE */
#define VBAT			// comment this line to suppress the vbat code
#define VBATSCALE     91	// change this value if readed Battery voltage is different than real voltage
#define VBATLEVEL1_3S 107	// 10,7V
#define VBATLEVEL2_3S 103	// 10,3V
#define VBATLEVEL3_3S 99	// 9.9V
#define NO_VBAT       16	// Avoid beeping without any battery

/* This is the speed of the serial interface. 115200 kbit/s is the best option for a USB connection.*/
#define SERIAL_COM_SPEED 115200

/* motors will not spin when the throttle command is in low position
   this is an alternative method to stop immediately the motors */
//#define MOTOR_STOP

/* some radios have not a neutral point centered on 1500. can be changed here */
#define MIDRC 1500

/* experimental
   camera trigger function : activated via Rc Options in the GUI, servo output=A2 on promini */
//#define CAMTRIG
#define CAM_SERVO_HIGH 2000	// the position of HIGH state servo
#define CAM_SERVO_LOW 1020	// the position of LOW state servo
#define CAM_TIME_HIGH 1000	// the duration of HIGH state servo expressed in ms
#define CAM_TIME_LOW 1000	// the duration of LOW state servo expressed in ms

/* you can change the tricopter servo travel here */
#define TRI_YAW_CONSTRAINT_MIN 1020
#define TRI_YAW_CONSTRAINT_MAX 2000
#define TRI_YAW_MIDDLE 1500

/* Flying Wing: you can change change servo orientation and servo min/max values here */
/* valid for all flight modes, even passThrough mode */
/* need to setup servo directions here; no need to swap servos amongst channels at rx */ 
#define PITCH_DIRECTION_L 1 // left servo - pitch orientation
#define PITCH_DIRECTION_R -1  // right servo - pitch orientation (opposite sign to PITCH_DIRECTION_L, if servos are mounted in mirrored orientation)
#define ROLL_DIRECTION_L 1 // left servo - roll orientation
#define ROLL_DIRECTION_R 1  // right servo - roll orientation  (same sign as ROLL_DIRECTION_L, if servos are mounted in mirrored orientation)
#define WING_LEFT_MID  1500 // left servo center pos. - use this for trim
#define WING_RIGHT_MID 1500 // right servo center pos. - use this for trim
#define WING_LEFT_MIN  1020 // limit servo travel range must be inside [1020;2000]
#define WING_LEFT_MAX  2000 // limit servo travel range must be inside [1020;2000]
#define WING_RIGHT_MIN 1020 // limit servo travel range must be inside [1020;2000]
#define WING_RIGHT_MAX 2000 // limit servo travel range must be inside [1020;2000]

/* enable monitoring of the power consumption from battery (think of mAh) */
/* allows to set alarm value in GUI or via LCD */
/* Two options: */
/* 1 - soft: - (good results +-5% for plush and mystery ESCs @ 2S and 3S, not good with SuperSimple ESC */
/*      00. relies on your combo of battery type (Voltage, cpacity), ESC, ESC settings, motors, props and multiwii cycle time */
/*      01. set POWERMETER soft. Uses PLEVELSCALE = 50, PLEVELDIV = PLEVELDIVSOFT = 10000 */
/*      0. output is a value that linearily scales to power (mAh) */
/*      1. get voltage reading right first */
/*      2. start with freshly charged battery */
/*      3. go fly your typical flight (routine and duration) */
/*      4. at end connect to GUI or LCD and read the power value; write it down (example 4711)*/
/*      5. charge battery, write down amount of energy needed (example 722 mAh) */
/*      6. compute alarm value for desired power threshold (example 750 mAh : alarm = 4711 / 722 * 750) */
/*      7. set alarm value in GUI or LCD */
/*      8. enjoy your new battery alarm - possibly repeat steps 2 .. 7 */
/*      9. if you want the numbers to represent your mAh value, you must change PLEVELDIV */
/* 2 - hard: - (uses hardware sensor, after configuration gives reasonable results */
/*      00. uses analog pin 2 to read voltage output from sensor. */
/*      01. set POWERMETER hard. Uses PLEVELSCALE = 50 */
/*      02. install low path filter for 25 Hz to sensor input */
/*      1. compute PLEVELDIV for your sensor (see below for insturctions) */
/*      2. set PLEVELDIVSOFT to 10000 ( to use LOG_VALUES for individual motor comparison) */
/*      3. attach, set PSENSORNULL and  PINT2mA */
/*      4. configure, compile, upload, set alarm value in GUI or LCD */
/*      3. enjoy true readings of mAh consumed */
/* set POWERMETER to "soft" (1) or "hard" (2) depending on sensor you want to utilize */
//#define POWERMETER 1
//#define POWERMETER 2
/* the sum of all powermeters ranges from [0:60000 e4] theoretically. */
/* the alarm level from eeprom is out of [0:255], so we multipy alarm level with PLEVELSCALE and with 1e4 before comparing */
/* PLEVELSCALE is the step size you can use to set alarm */
#define PLEVELSCALE 50		// if you change this value for other granularity, you must search for comments in code to change accordingly
/* larger PLEVELDIV will get you smaller value for power (mAh equivalent) */
#define PLEVELDIV 10000		// default for soft - if you lower PLEVELDIV, beware of overrun in uint32 pMeter
#define PLEVELDIVSOFT PLEVELDIV	// for soft always equal to PLEVELDIV; for hard set to 10000
//#define PLEVELDIV 1361L // to convert the sum into mAh divide by this value
/* amploc 25A sensor has 37mV/A */
/* arduino analog resolution is 4.9mV per unit; units from [0..1023] */
/* sampling rate 20ms, approx 19977 micro seconds */
/* PLEVELDIV = 37 / 4.9  * 10e6 / 19977  * 3600 / 1000  = 1361L */
/* set to analogRead() value for zero current */
#define PSENSORNULL 510		// for I=0A my sensor gives 1/2 Vss; that is approx 2.49Volt
#define PINT2mA 13		// for telemtry display: one integer step on arduino analog translates to mA (example 4.9 / 37 * 100

/* to log values like max loop time and others to come */
/* logging values are visible via LCD config */
//#define LOG_VALUES

//****** end of advanced users settings *************

//if you want to change to orientation of individual sensor
//#define ACC_ORIENTATION(X, Y, Z)  {accADC[ROLL]  =  Y; accADC[PITCH]  = -X; accADC[YAW]  = Z;}
//#define GYRO_ORIENTATION(X, Y, Z) {gyroADC[ROLL] = -Y; gyroADC[PITCH] =  X; gyroADC[YAW] = Z;}
//#define MAG_ORIENTATION(X, Y, Z)  {magADC[ROLL]  = X; magADC[PITCH]  = Y; magADC[YAW]  = Z;}

/**************************************/
/****END OF CONFIGURABLE PARAMETERS****/
/**************************************/