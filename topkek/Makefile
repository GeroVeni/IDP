# Automatically generated Makefile
kek :  utility.o kek.o failsafe.o core.o
	 g++ -L/export/teach/1BRobot -o kek  utility.o  kek.o  failsafe.o  core.o  -lrobot

utility.o: utility.cc utility.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c utility.cc
kek.o: kek.cc utility.h values.h core.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c kek.cc
failsafe.o: failsafe.cc failsafe.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c failsafe.cc
core.o: core.cc core.h utility.h
	 g++ -ansi -Wall -g -I/export/teach/1BRobot -c core.cc
