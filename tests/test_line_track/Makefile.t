#Automatically generated file
test_line_track: test_line_track.o ../../topkek/core.o ../../topkek/utility.o
	g++ -L/export/teach/1BRobot -o test_line_track  test_line_track.o ../../topkek/core.o ../../topkek/utility.o -lrobot

test_line_track.o: test_line_track.cc ../../topkek/core.h ../../topkek/utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c test_line_track.cc
../../topkek/core.o: ../../topkek/core.cc core.h utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/core.cc
../../topkek/utility.o: ../../topkek/utility.cc utility.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c ../../topkek/utility.cc
