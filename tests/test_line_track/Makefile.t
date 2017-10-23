#Automatically generated file
test_line_track: test_line_track.o ../../topkek/utility.o ../../topkek/core.o
	g++ -L/export/teach/1BRobot -o test_line_track  test_line_track.o ../../topkek/utility.o ../../topkek/core.o -lrobot

test_line_track.o: test_line_track.cc ../../topkek/core.h ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c test_line_track.cc
../../topkek/utility.o: ../../topkek/utility.cc ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/utility.cc
../../topkek/core.o: ../../topkek/core.cc ../../topkek/core.h ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/core.cc
