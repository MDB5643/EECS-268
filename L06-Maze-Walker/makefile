lab6: main.o MazeWalker.o MazeReader.o MazeCreationException.o
	g++ -g main.o MazeWalker.o MazeReader.o MazeCreationException.o -o lab6

main.o: MazeReader.h MazeWalker.h MazeCreationException.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

MazeWalker.o: MazeWalker.h MazeReader.h MazeWalker.cpp
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

MazeReader.o: MazeReader.h MazeCreationException.h MazeReader.cpp
	g++ -std=c++11 -g -Wall -c MazeReader.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -Wall -c MazeCreationException.cpp

Clean:
	rm *.o lab6
