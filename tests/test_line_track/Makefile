# Automatically generated Makefile for arm
test_line_track.arm :  utility.arm.o test_line_track.arm.o core.arm.o
	 arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o test_line_track.arm  utility.arm.o  test_line_track.arm.o  core.arm.o  -lrobot

utility.arm.o: ../../topkek/utility.cc ../../topkek/utility.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c utility.cc -o utility.arm.o
test_line_track.arm.o: test_line_track.cc ../../topkek/core.h ../../topkek/utility.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c test_line_track.cc -o test_line_track.arm.o
core.arm.o: ../../topkek/core.cc ../../topkek/core.h ../../topkek/utility.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c core.cc -o core.arm.o

