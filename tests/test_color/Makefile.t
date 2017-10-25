#Automatically generated file
test_color: test_color.o core.o utility.o values.o
	g++ -L/export/teach/1BRobot -o test_color  test_color.o core.o utility.o values.o -lrobot

 test_color.o: test_color.cc ../../topkek/values.h ../../topkek/utility.h ../../topkek/core.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c test_color.cc
 core.o: ../../topkek/core.cc ../../topkek/core.h ../../topkek/utility.h ../../topkek/values.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/core.cc
 utility.o: ../../topkek/utility.cc ../../topkek/utility.h ../../topkek/values.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/utility.cc
 values.o: ../../topkek/values.cc
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/values.cc
