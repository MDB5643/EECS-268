lab3: main.o MathTools.o NegativeDiscriminant.o CannotDetermineRoomDimensions.o NoIntersection.o Executive.o
	g++ -std=c++11 -g -Wall MathTools.o NegativeDiscriminant.o CannotDetermineRoomDimensions.o NoIntersection.o Executive.o main.o -o lab3

main.o: main.cpp MathTools.h NegativeDiscriminant.h CannotDetermineRoomDimensions.h NoIntersection.h Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

MathTools.o: MathTools.h NegativeDiscriminant.h CannotDetermineRoomDimensions.h NoIntersection.h MathTools.cpp
	g++ -std=c++11 -g -Wall -c MathTools.cpp

NegativeDiscriminant.o: NegativeDiscriminant.h NegativeDiscriminant.cpp
	g++ -std=c++11 -g -Wall -c NegativeDiscriminant.cpp

CannotDetermineRoomDimensions.o: CannotDetermineRoomDimensions.h CannotDetermineRoomDimensions.cpp
	g++ -std=c++11 -g -Wall -c CannotDetermineRoomDimensions.cpp

NoIntersection.o: NoIntersection.h NoIntersection.cpp
	g++ -std=c++11 -g -Wall -c NoIntersection.cpp

Executive.o: Executive.h MathTools.h NegativeDiscriminant.h NoIntersection.h CannotDetermineRoomDimensions.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

clean:
	rm *.o lab3
