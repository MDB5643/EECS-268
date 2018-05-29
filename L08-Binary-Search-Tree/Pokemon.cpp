/*
/ @author: Matt Bailey
/	@project: Binary Search Tree Lab
/	@file: Pokemon.cpp
/	@since: 11-12-2016
*/

#ifndef _POKEMON_CPP
#define _POKEMON_CPP


#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon()
{
	this->englishName = "Unknown";
	this->japaneseName = "Wakarimasen";
	this->index = -1;
}

Pokemon::Pokemon(string englishName, int index, string japaneseName)
{
	this->englishName = englishName;
	this->japaneseName = japaneseName;
	this->index = index;
}


Pokemon::~Pokemon()
{

}


string Pokemon::getEnglishName()
{
	return englishName;
}

string Pokemon::getJapaneseName()
{
	return japaneseName;
}

int Pokemon::getIndex()
{
	return index;
}

bool operator<(const Pokemon &p1, const Pokemon &p2)
{
	return(p1.englishName < p2.englishName);
}

bool operator<(const Pokemon &p1, const string &s2)
{
	return(p1.englishName < s2);
}

bool operator==(const Pokemon &p1, const string &s2)
{
	return(p1.englishName == s2);
}

ostream& operator<< (ostream &os, const Pokemon &p)
{
	os << p.englishName;
	os << " #" << p.index << " Japanese name: " << p.japaneseName;
	return os;
}

#endif
