# jy901-RaspberryPi-I2C
A C++ library for raspberry pi to access WIT-motion's MEMS-IMU sensor JY901(S). It enables you to access attitude, angular velocity, acceleration rate and GPS data( longtitude & latitude, position accuracy, numbers of satellites. Most of these datas are accurate ,but the attitude angles may not fit the definition, if you want to make it fit the definition, you can calculate yourslef.
Use wiringPi's I2C library: http://wiringpi.com/ .
GPS functions require the GPS to be connected to PIN D1, refer to the module's datasheet for further imformation.
This program was tested on Raspberry Pi zero, on which its all functions work properly. In thoery, it will work on all Raspberry Pi, but further tests are still needed to make sure its stablity.
Due to the lack of experience on programming & github, my project may not fit some standard, I'm sorry about the incovenience brought by it.
Looking forward to any feedback.
中文说明：
这是一个用于树莓派的维特智能JY901（S）微机电惯性传感器I2C接口的C++库。它能让你通过I2C访问姿态角、角速度、加速度和GPS信息（包括经纬度、定位精度信息、卫星数量）。大多数数据都是准确的，但姿态角是传感器的原始数据，不符合姿态角的定义，如果需要让它们符合定义，需要自行计算。
本项目使用了wiringPi的I2C库：http://wiringpi.com/ 。
使用GPS相关数据需要将GPS的TX引脚连接至模块的D1引脚，并将GPS模块的串口波特率设置为9600bps。若需要更多信息，请参阅模块的数据表。
本项目在树莓派zero上通过了测试，其全部功能均可用。理论上在其余树莓派上也能正常使用这一项目，但若要确保其稳定性仍需要进一步测试。
由于本人C++编程经验与GitHub使用经验并不丰富，所以可能很多地方格式并不标准，还请各位谅解。
期待各位的反馈。
