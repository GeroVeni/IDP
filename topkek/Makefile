#Automatically generated file
kek.arm: core.o failsafe.o kek.o utility.o values.o
	arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o kek.arm  core.o failsafe.o kek.o utility.o values.o -lrobot

 core.o: core.cc core.h utility.h values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c core.cc
 failsafe.o: failsafe.cc failsafe.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c failsafe.cc
 kek.o: kek.cc utility.h values.h core.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c kek.cc
 utility.o: utility.cc utility.h values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c utility.cc
 values.o: values.cc
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c values.cc
