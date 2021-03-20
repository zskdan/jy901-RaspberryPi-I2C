/*######################################################################
#                        JY901 I2C header by cold                      #
######################################################################*/
#ifndef _JY901_H_
#define _JY901_H_
#endif

#define default_addr 0x50

//Following numbers are error code for the initilization of jy901.
#define INTERFACE_ERR 0x01 //i2c initialization error
#define DEVICE_ERR 0x02  //error on device address set or device connection
#define INIT_SUCCESS 0x03 //initilization successful

#define g 9.80665//local gravitational acceleration


/* #####################################################################
 * NOTICE: JY901 sensors have a configuration register on 0x02 that can 
 * configure the output data of the sensor, and this device control word
 *  is set to 0x07df to make the sensor work in most conditions. To
 *  change that, use jy901_config(). You can refer to the following 
 * graph & JY901 datasheet to findout what device control word you need.
 * 
 * data_type	void		gps_accuracy	quaternion	gps_velocity		
 * state	0		1		1		1					
 * data_type	gps_position	pressure/height	interface_state	magenetic_data
 * state	1		0		1		1	
 * data_type	attitude	Omega		acceleration	time
 * state	1		1		1		1
 * 
 * NOTE: Although there is no I2C register address for GPS accuracy and
 * satelites number mentioned as they are in serial communication 
 * protocal on the datasheet, I have found 0x55, 0x56,0x57 and 0x58 are 
 * all accessable after configure the sensor properly.These register 
 * function are showed below:
 *
 * 	register			function			
 * 	0x55				number of satelites
 * 	0x56				positioning accuracy
 * 	0x57				vertical accuracy
 * 	0x58				horizontal accuracy
 * #####################################################################*/
 #define default_control_word 0x07df


 typedef struct {
	 int roll;
	 int pitch;
	 int yaw;
 }raw_angle;
 
 typedef struct {
	 int ax;
	 int ay;
	 int az;
 }raw_accel;
 
 typedef struct {
	 float roll;
	 float pitch;
	 float yaw;
 }angle;
 
 typedef struct {
	 float ax;
	 float ay;
	 float az;
 }accel;
 
 typedef struct {
	int longti[2];
	int lati[2];
	int gpsYaw;
	int gpsv[2];
	int accur;
	int sat_num;
}raw_gps;

typedef struct {
	float longti;
	float lati;
	float gpsYaw;
	float gpsv;
	float accur;
	int sat_num;
}gps; 

typedef struct {
	int wx;
	int wy;
	int wz;
}raw_omega;

typedef struct {
	float wx;
	float wy;
	float wz;
}omega;
