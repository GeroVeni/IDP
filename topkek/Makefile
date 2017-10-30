#Automatically generated file
kek.arm: kek.o core.o utility.o values.o failsafe.o
	arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o kek.arm  kek.o core.o utility.o values.o failsafe.o -lrobot

 kek.o: kek.cc utility.h values.h core.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c kek.cc
 core.o: core.cc core.h utility.h values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c core.cc
 utility.o: utility.cc utility.h values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c utility.cc
 values.o: values.cc
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c values.cc
 failsafe.o: failsafe.cc failsafe.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c failsafe.cc
