#Automatically generated file
test_line_track: test_line_track.o utility.o core.o
	g++ -L/export/teach/1BRobot -o test_line_track  test_line_track.o utility.o core.o -lrobot

 test_line_track.o: test_line_track.cc ../../topkek/core.h ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c test_line_track.cc
 utility.o: ../../topkek/utility.cc ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/utility.cc
 core.o: ../../topkek/core.cc ../../topkek/core.h ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/core.cc
