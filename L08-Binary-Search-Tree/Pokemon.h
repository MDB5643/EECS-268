/*
/ @author: Matt Bailey
/	@project: Binary Search Tree Lab
/	@file: Pokemon.h
/	@since: 11-12-2016
*/

#ifndef _POKEMON_H
#define _POKEMON_H

#include <string>

using namespace std;

class Pokemon
{
private:
	string englishName;
	int index;
	string japaneseName;

public:
	Pokemon();
	Pokemon(string englishName, int index, string japaneseName);
	~Pokemon();
	string getEnglishName();
	string getJapaneseName();
	int getIndex();



	friend bool operator< (const Pokemon &p1, const Pokemon &p2);
	friend bool operator< (const Pokemon &p1, const string &s2);
	friend bool operator== (const Pokemon &p1, const string &s2);
	friend ostream& operator<< (ostream &os, const Pokemon &p);

};




#endif
