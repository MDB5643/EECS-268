/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: main.cpp
/ @since: 9-17-2016
*/

#include "LinkedList.h"
#include "MedicalExecutive.h"

using namespace std;

int main(int argc, char* argv[])
{

MedicalExecutive medExec("input.txt");
medExec.run();
return 0;

}
