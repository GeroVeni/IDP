# Automatically generated Makefile for arm
test_line_track.arm :  utility.arm.o test_line_track.arm.o core.arm.o
	 arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o test_line_track.arm  utility.arm.o  test_line_track.arm.o  core.arm.o  -lrobot

utility.arm.o: utility.cc utility.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c utility.cc -o utility.arm.o
test_line_track.arm.o: test_line_track.cc core.h utility.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c test_line_track.cc -o test_line_track.arm.o
core.arm.o: core.cc core.h utility.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c core.cc -o core.arm.o
