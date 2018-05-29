lab4: main.o PrecondViolatedExcep.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o -o lab4

main.o: Stack.cpp Stack.h Queue.cpp Queue.h PrecondViolatedExcep.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp

clean:
	rm *.o lab4
	clean done
