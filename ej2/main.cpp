/*
	2. Escribe un programa que lea del teclado una frase y a continuación visualice las palabras de la 
	frase en columna, seguida cada una del número de letras que la componen.
*/

#include <iostream>
using namespace std;
int main()
{

	string frase;
	int counterchar  = 1;
	cout << "Escriba una frase: ";

	getline(cin, frase);

	for (int i = 0; i < frase.length(); i++)
	{
		cout << frase[i] << endl;

		if (frase[i] == ' ' || frase[i+1] == '\0')
		{
			cout << "total characters: " << counterchar << endl;
			cout << endl;
			counterchar --;
			counterchar = 0;
		}
		counterchar++;
	}

	return 0;
}