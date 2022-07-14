#include <iostream>
#include <string>
#include <string.h>

using std::string;
using std::cout;

const int maxRows = 10;
const int maxColu = 10;

void totalCharsPerWord(string frase)
{
	int whiteSpace = 0, tempChars = 1, totalAmountOfChars = 0;
	for (int i = 0; i < frase.length(); i++)
	{
		if (frase[i] == ' ' || frase[i + 1] == '\0')
		{
			whiteSpace++;
			if (frase[i + 1] == '\0') whiteSpace--;
			totalAmountOfChars = tempChars - whiteSpace;
			tempChars = 0;
			whiteSpace = 0;
			cout << totalAmountOfChars << " ";
		}
		tempChars++;
	}
}
void showMatrix(char A[maxRows][maxColu], string frase)
{
	for (int i = 0; i < maxRows; i++)
	{
		for (int j = 0; j < maxColu; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << std::endl;
	}
	totalCharsPerWord(frase);
}

int main()
{
	char A[maxRows][maxColu];

	string frase = "";

	getline(std::cin, frase);

	memset(A, ' ', sizeof A);

	int iPos = 0,
		temp = 0,
		charCounter = 0;

	for (int i = 0; i < frase.length(); i++)
	{
		iPos++;
		if (frase[i] == ' ')
		{
			temp++;
			iPos = 0;
		}
		A[iPos][temp] = frase[i];		
		
	}

	showMatrix(A, frase);

	std::cin.ignore();

	return 0;
}