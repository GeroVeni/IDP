# IDP

Robot program repository

Robot name: ERROR

Description: Best robot ev3r

## How to compile new test programs

* If you want to compile a TEST program to run from the workstation:
1. Open a terminal
2. cd (to the location of your test file; usually cd ~/Desktop/IDP/tests/NAME\_OF\_TEST\_FILE) <b>OR</b> Open folder then right click and select "open terminal"
3. rm \*.o
4. makemake -f MakeDesk NAME\_OF\_TEST\_FILE.cc ../../topkek/core.cc ../../topkek/utility.cc ../../topkek/values.cc
5. make -f MakeDesk
6. To run the program use: ./NAME\_OF\_TEST\_FILE (without .cc at the end)

* If you want to compile a TEST program to run from the microprocessor:
1. Steps 1 - 3 as above
4. makemake --arm NAME\_OF\_TEST\_FILE.cc ../../topkek/core.cc ../../topkek/utility.cc ../../topkek/values.cc
5. make
6. To run the program first transfer it to robot: scp NAME\_OF\_TEST\_FILE.arm team@wlan-robot16.private:NAME\_OF\_TEST\_FILE.arm
7. Login to robot: slogin team@wlan-robot16.private
8. ./NAME\_OF\_TEST\_FILE.arm

