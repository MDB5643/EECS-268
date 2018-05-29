lab9: Main.o
	g++ -g Main.o -o lab9

Main.o: Executive.h EmptyHeap.h EmptyPriorityQueue.h Heap.h PriorityQueue.h Patient.h Main.cpp
	g++ -std=c++11 -g -Wall -c Main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Heap.o: Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Heap.cpp

Patient.o: Patient.h Patient.cpp
	g++ -std=c++11 -g -Wall -c Patient.cpp

PriorityQueue.o: PriorityQueue.h PriorityQueue.cpp
	g++ -std=c++11 -g -Wall -c PriorityQueue.cpp

Clean:
	rm *.o lab9
