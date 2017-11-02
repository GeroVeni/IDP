# Automatically generated Makefile for arm
kek.arm :  values.arm.o utility.arm.o kek.arm.o failsafe.arm.o core.arm.o
	 arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o kek.arm  values.arm.o  utility.arm.o  kek.arm.o  failsafe.arm.o  core.arm.o  -lrobot

values.arm.o: values.cc
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c values.cc -o values.arm.o
utility.arm.o: utility.cc utility.h values.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c utility.cc -o utility.arm.o
kek.arm.o: kek.cc utility.h values.h core.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c kek.cc -o kek.arm.o
failsafe.arm.o: failsafe.cc failsafe.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c failsafe.cc -o failsafe.arm.o
core.arm.o: core.cc core.h utility.h values.h
	 arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c core.cc -o core.arm.o
