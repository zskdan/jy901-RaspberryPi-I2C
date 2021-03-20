#include"JY901.h"
#include"JY901.cpp"
#include<stdio.h>
#include<wiringPi.h>


int main(void) {
	jy901_set_addr( 0x50 );
	printf("\ninit:%#x\n",jy901_init( &fd ));
	printf("\ncali:%d\n",jy901_cali());
	if ( INIT_SUCCESS == jy901_init() ) {
		angle attitude;
		accel acceleration;
		gps gpsd;
		omega w;
		jy901_cali();
		for(;;)
		{
			jy901_getAngle( &attitude );
			jy901_getAccel( &acceleration );
			jy901_getGPS( &gpsd );
			jy901_getOmega( &w );
			printf("attitude:%4f,%4f,%4f\nacceleration:%4f,%4f,%4f\ngps:%8f,%8f,%2f,%2f,%d\nomega:%4f,%4f,%4f\n\n",attitude.roll,attitude.pitch,attitude.yaw,acceleration.ax,acceleration.ay,acceleration.az,gpsd.longti,gpsd.lati,gpsd.gpsYaw,gpsd.accur,gpsd.sat_num,w.wx,w.wy,w.wz);
		}
	}
	else	printf("Initialization failed, err=%#x\n", jy901_init() );

}
