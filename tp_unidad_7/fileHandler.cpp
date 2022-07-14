#include "fileHandler.h"

void readFileStatus(ifstream& file, string error)
{
	bool condition = (!(file.is_open()) || !(file.good()));
	if (condition)
	{
		std::cerr << error << std::endl;
		exit(EXIT_FAILURE);
	}
}
ifstream readFile(string path)
{
	ifstream file;
	file.open(path);
	readFileStatus(file, "Error, Opening File!");
	return file;
}
void closeFile(ifstream& file)
{
	if (file.is_open()) file.close();
}
void writeFileStatus(ofstream& file, string error)
{
	bool condition = (!(file.is_open()) || !(file.good()));
	if (condition)
	{
		std::cerr << error << std::endl;
		exit(EXIT_FAILURE);
	}
}
ofstream writeFile(string path)
{
	ofstream file(path);
	writeFileStatus(file, "Error, Opening File Writer!!");
	return file;
}