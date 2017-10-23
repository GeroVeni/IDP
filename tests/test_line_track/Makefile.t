#Automatically generated file
test_line_track: test_line_track.o
	g++ -L/export/teach/1BRobot -o test_line_track  test_line_track.o -lrobot

test_line_track.o: test_line_track.cc ../../topkek/core.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c test_line_track.cc
