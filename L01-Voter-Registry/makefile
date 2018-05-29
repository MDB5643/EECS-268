lab1: main.o Executive.o VoterRegistration.o
	g++ -g main.o Executive.o VoterRegistration.o -o lab1

main.o: Executive.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h VoterRegistration.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

VoterRegistration.o: VoterRegistration.h VoterRegistration.cpp
	g++ -std=c++11 -g -Wall -c VoterRegistration.cpp

Clean:
	rm *.o lab1
