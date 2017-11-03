#Automatically generated file
test_sensors.arm: test_sensors.o utility.o
	arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o test_sensors.arm  test_sensors.o utility.o -lrobot

 test_sensors.o: test_sensors.cc ../../topkek/utility.h ../../topkek/values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c test_sensors.cc
 utility.o: ../../topkek/utility.cc ../../topkek/utility.h ../../topkek/values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c ../../topkek/utility.cc
