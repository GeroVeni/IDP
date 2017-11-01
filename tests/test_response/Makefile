#Automatically generated file
test_response.arm: test_response.o core.o utility.o
	arm-linux-gnueabi-g++ -L/usr/arm-unknown-linux-gnueabi/lib -o test_response.arm  test_response.o core.o utility.o -lrobot

 test_response.o: test_response.cc ../../topkek/utility.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c test_response.cc
 core.o: ../../topkek/core.cc ../../topkek/core.h ../../topkek/utility.h ../../topkek/values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c ../../topkek/core.cc
 utility.o: ../../topkek/utility.cc ../../topkek/utility.h ../../topkek/values.h
	arm-linux-gnueabi-g++ -ansi -Wall -g -I/usr/arm-unknown-linux-gnueabi/include -I/export/teach/1BRobot -c ../../topkek/utility.cc
