###############################################################
# Program:
#     Carrier Automation System
# Author:
#     Cube
# Summary:
#     Make the jumps easy and let the program do it while you sleep.
#     With things like tritium refuel and optimal jump timings, you
#	  can now grind less and actually get sleep or work not game.
###############################################################

LFLAGS = -lXtst -lX11 -lxdo -ljsoncpp
LIBS = /home/brandon/Documents/cpp-projects/carrierJump/lib/efsw/lib/libefsw-debug.so

###############################################################
# Build the main program
###############################################################
CarrierAutomationSystem.L: CarrierAutomationSystem.o readInstructions.o keyboard.o systemList.o inputInstructions.o updateListener.o jsonParse.o
	g++ CarrierAutomationSystem.o readInstructions.o keyboard.o systemList.o inputInstructions.o updateListener.o jsonParse.o $(LFLAGS) -o CarrierAutomationSystem.l $(LIBS)
	tar -j -cf CarrierAutomationSystem.tar makefile *.h *.cpp *.csv
	make clean

###############################################################
# Individual files
###############################################################
systemList.o: systemList.cpp systemList.h readInstructions.h
	g++ -c systemList.cpp

inputInstructions.o: inputInstructions.cpp inputInstructions.h readInstructions.h keyboard.h
	g++ -c inputInstructions.cpp

readInstructions.o: readInstructions.cpp readInstructions.h
	g++ -c readInstructions.cpp

keyboard.o: keyboard.cpp keyboard.h
	g++ -c keyboard.cpp

jsonParse.o: jsonParse.cpp jsonParse.h
	g++ -c jsonParse.cpp

updateListener.o: updateListener.cpp updateListener.h
	g++ -c updateListener.cpp

CarrierAutomationSystem.o: CarrierAutomationSystem.cpp systemList.h inputInstructions.h
	g++ -c CarrierAutomationSystem.cpp

###############################################################
# General rules
###############################################################
clean:
	rm *.o
