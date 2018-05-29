lab2: main.o City.o MedicalExecutive.o
	g++ -std=c++11 -g -Wall main.o MedicalExecutive.o City.o -o lab2

main.o: main.cpp MedicalExecutive.h City.h Node.h Node.hpp LinkedList.h LinkedList.hpp
	g++ -std=c++11 -g -Wall -c main.cpp

City.o: City.h City.cpp
	g++ -std=c++11 -g -Wall -c City.cpp

MedicalExecutive.o: MedicalExecutive.h MedicalExecutive.cpp
		g++ -std=c++11 -g -Wall -c MedicalExecutive.cpp

clean:
	rm *.o lab2
