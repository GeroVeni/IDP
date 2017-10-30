#Automatically generated file
color_calibration.arm: color_calibration.o core.o utility.o
	arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o color_calibration.arm  color_calibration.o core.o utility.o -lrobot

 color_calibration.o: color_calibration.cc ../../topkek/values.h ../../topkek/utility.h ../../topkek/core.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c color_calibration.cc
 core.o: ../../topkek/core.cc ../../topkek/core.h ../../topkek/utility.h ../../topkek/values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c ../../topkek/core.cc
 utility.o: ../../topkek/utility.cc ../../topkek/utility.h ../../topkek/values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c ../../topkek/utility.cc
