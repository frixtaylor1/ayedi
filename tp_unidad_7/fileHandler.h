#ifndef fileHandler_h
#define fileHandler_h

#include <iostream>
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::string;

void readFileStatus(ifstream& file, string error);

ifstream readFile(string path);

void writeFileStatus(ofstream& file, string error);

ofstream writeFile(string path);

void closeFile(ifstream& file);

#endif	