/*
/ @author: Matt Bailey
/	@project: Binary Search Tree Lab
/	@file: main.cpp
/	@since: 11-12-2016
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "BinaryNode.h"
#include "BinarySearchTree.h"
#include "Pokemon.h"
#include <cctype>

using namespace std;

int main(int argc, char* argv[])
{
	//BST declaration

	BinarySearchTree<Pokemon, string> bst;
	//reads in from pokemon.csv and adds them to the BST
	std::string inputfile;
	std::cout << "What is the name of the file you would like me to read in?" << endl;
	cin >> inputfile;
	std::ifstream inp(inputfile);
	string line = "";
	while (getline(inp, line))
	{
		//cout << line << endl;
		istringstream iss(line);
		char delim = ',';

		string name;
		string index;
		string jname;
		getline(iss, name, delim);
		getline(iss, index, delim);
		getline(iss, jname, delim);

		Pokemon *nextPokemon = new Pokemon(name, stoi(index), jname);
		bst.add(*nextPokemon);

		//Pokemon nextPokemon(Pokemon(name, stoi(index), jname));
		//bst.add(nextPokemon);
	}

	//intial stability checks
	cout << "---Testing contains for a real pokemon---" << endl;
	if (bst.contains("Jigglypuff"))
		cout << "Jigglypuff is a pokemon" << endl;

	cout << "---Testing contains for a fake pokemon---" << endl;
	if (!bst.contains("Saggypants"))
		cout << "Saggypants is not a pokemon" << endl;


	cout << "---Retrieving Jigglypuff---" << endl;
	Pokemon searched = bst.getEntry("Jigglypuff");

	cout << "---Testing << overload---" << endl;
	cout << searched.getEnglishName() << " " << searched.getIndex() << " " << searched.getJapaneseName() << endl;

	//first copy
	BinarySearchTree<Pokemon, string> bstCopy;
	bstCopy.addAllFrom(bst);

	BinarySearchTree<Pokemon, string> bstCopy1;

	string input = "";
	int num = -1;

	//User interface
	while (input != "quit" && num != 0)
	{
		cout << "=============================================================== \n";
		cout << "============= WELCOME TO THE POKEDEX TRANSLATOR =============== \n";
		cout << "=============================================================== \n";
		cout << "I have loaded values from 'pokemon.csv' to my memory." << endl;
		cout << "What would you like for me to do, trainer?" << endl;
		cout << "1. Search Pokemon" << endl;
		cout << "2. Create/Edit/List Copy" << endl;
		cout << "3. List All" << endl;
		// cout << "4. List Copy" << endl;
		cout << "4. Save" << endl;
		cout << "5. Test mode" << endl;
		cout << "0. Quit" << endl;
		cin >> num;


		//Search function
		if (num == 1)
		{
			cout << "Type a pokemon's english name and I'll try to find it" << endl;
			cin >> input;
			input[0] = toupper(input[0]);
			try
			{
				searched = bst.getEntry(input);
				//		if (searched != nullptr)
				cout << searched << endl;
			}
			catch (const NotFoundException &e)
			{
				cout << "Couldn't find it" << endl;
			}
		}

		//Copier and copy editor submenu
		else if (num == 2)
		{
			cout << "1. Insert to copied list" << endl;
			cout << "2. Remove from copied list" << endl;
			cout << "3. Display all pokemon from copied list" << endl;
			cout << "4. Create NEW copy" << endl;
			cin >> num;
			//Insert to copy function
			if (num == 1)
			{
				cout << "Please type the pokemon english name, pokedex number, and japanese name" << endl;
				string eng;
				cin >> eng;
				string poke;
				cin >> poke;
				string japanese;
				cin >> japanese;
				Pokemon *nextPokemon = new Pokemon(eng, stoi(poke), japanese);
				bstCopy.add(*nextPokemon);
			}
			//delete from copy function
			else if (num == 2)
			{
				cout << "Please type the pokemon english name and I'll try to delete it" << endl;
				string eng;
				cin >> eng;
				bstCopy.deleteAndReorder(eng);
			}
			//Print copy function
			else if (num == 3)
			{
				cout << "Printing all the copied pokemon!" << endl;
				bstCopy.inorderTraverseLazy();
			}
			//New copy function
			else if (num == 4)
			{
				bstCopy.addAllFrom(bst);
			}

		}
		//Print BST function
		else if (num == 3)
		{
			cout << "Printing all the pokemon!" << endl;
			bst.inorderTraverseLazy();
		}
		// else if (num == 4)
		// {
		// 	cout << "Printing all the copied pokemon!" << endl;
		// 	bstCopy.inorderTraverseLazy();
		// }

		//Save to file function
		else if (num == 4)
		{
			cout << "Which tree do you want to save?" << endl;
			cout << "1. Original List" << endl;
			cout << "2. Copy List" << endl;
			int whichList;
			cin >> whichList;
			cout << "Which method?" << endl;
			cout << "1. Preorder" << endl;
			cout << "2. Inorder" << endl;
			cout << "3. Postorder" << endl;
			int method;
			cin >> method;
			cout << "What file name?" << endl;
			string filename;
			cin >> filename;
			ofstream *outfile = new ofstream(filename);

			if (whichList == 1)
			{
				bst.writeToFile(outfile, method);
			}
			else if (whichList == 2)
			{
				bstCopy.writeToFile(outfile, method);
			}
			outfile->close();
		}

		//Testing functions
		else if (num == 5)
		{
			int testchoice;
			cout << "1. Run TestAdds" << endl;
			cout << "2. Run TestRemoves" << endl;
			cout << "3. Run TestWriteToFile" << endl;
			cin >> testchoice;

			if (testchoice == 1)
			{
				bst.testAdds(bst);
				cout << "Printing all the pokemon!" << endl;
				bst.inorderTraverseLazy();
			}

			if (testchoice == 2)
			{
				bst.testRemoves(bst);
				cout << "Printing all the pokemon!" << endl;
				bst.inorderTraverseLazy();
			}

			if (testchoice == 3)
			{
				bst.testWriteToFile(bst);
			}


		}

//		else
//			cout << "NOT FOUND" << endl;
	}
	//Example declaration of a BST
	//BinarySearchTree<Pokemon , std::string> bst;
	//Example adding
	//Pokemon p("Bulbasaur", 1, "Bulbasaur");
	//bst.add(p);
	cout << "===============================================================" << endl;
	cout << "Thank you for using the pokedex!" << endl;

	return 0;
}
