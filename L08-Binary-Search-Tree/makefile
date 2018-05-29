lab8: main.o BinarySearchTree.o BinaryNode.o Pokemon.o NotFoundException.o
	g++ -g main.o BinarySearchTree.o BinaryNode.o Pokemon.o NotFoundException.o -o lab8

main.o: BinarySearchTree.h BinaryNode.h NotFoundException.h Pokemon.h main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BinarySearchTree.o: BinarySearchTree.h BinaryNode.h BinarySearchTree.cpp
	g++ -std=c++11 -g -Wall -c BinarySearchTree.cpp

BinaryNode.o: BinaryNode.h Pokemon.h NotFoundException.h BinaryNode.cpp
	g++ -std=c++11 -g -Wall -c BinaryNode.cpp

Pokemon.o: Pokemon.h Pokemon.cpp
	g++ -std=c++11 -g -Wall -c Pokemon.cpp

NotFoundException.o: NotFoundException.h NotFoundException.cpp
	g++ -std=c++11 -g -Wall -c NotFoundException.cpp

Clean:
	rm *.o lab8
