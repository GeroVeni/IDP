#Automatically generated file
kek: core.o failsafe.o kek.o utility.o values.o
	g++ -L/export/teach/1BRobot -o kek  core.o failsafe.o kek.o utility.o values.o -lrobot

 core.o: core.cc core.h utility.h values.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c core.cc
 failsafe.o: failsafe.cc failsafe.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c failsafe.cc
 kek.o: kek.cc utility.h values.h core.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c kek.cc
 utility.o: utility.cc utility.h values.h
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c utility.cc
 values.o: values.cc
	g++ -ansi -Wall -g -I/export/teach/1BRobot -c values.cc
