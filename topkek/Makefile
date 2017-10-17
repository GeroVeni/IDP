# Automatically generated Makefile
kek :  utility.o kek.o core.o
	 g++ -L/export/teach/1BRobot -o kek  utility.o  kek.o  core.o  -lrobot

utility.o: utility.cpp utility.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c utility.cpp
kek.o: kek.cpp utility.h core.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c kek.cpp
core.o: core.cpp core.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c core.cpp
