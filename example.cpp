#include"JY901.h"
#include"JY901.cpp"
#include<stdio.h>
#include<wiringPi.h>
#include <unistd.h>

int main(void)
{
    int fd;

    jy901_set_addr( 0x50 );
    unsigned char jinit = jy901_init(&fd);

    if ( INIT_SUCCESS == jinit ) {
	angle attitude;
	accel acceleration;
	omega w;
	jy901_cali();
	for(;;) {
	    jy901_getAngle( &attitude );
	    jy901_getAccel( &acceleration );
	    jy901_getOmega( &w );
	    printf("attitude:%f,%f,%f\n"
		"acceleration:%f,%f,%f\n"
		"omega:%f,%f,%f\n\n",
		attitude.roll, attitude.pitch, attitude.yaw,
		acceleration. ax,acceleration.ay, acceleration.az,
		w.wx, w.wy, w.wz);
	}
    } else {
	printf("Initialization failed, err=%#x\n", jinit );
    }
}
