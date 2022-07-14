/* 
	3.mplementa un programa que permita realizar operaciones sobre matrices de NxN. El programa 
	debe permitir al usuario la selección de alguna de las siguientes operaciones: 
	a) Sumar 2 matrices.
	b) Restar 2 matrices.
	c) Multiplicar 2 matrices.
	d) Trasponer una matriz.
	e) Mostrar una matriz señalando cuáles son los puntos de silla (los puntos de silla de una matriz 
	son aquellos elementos de la misma que cumplen ser el mínimo de su fila y el máximo de su 
	columna).
	Habrá también dos subprogramas para leer del teclado o mostrar en la pantalla una matriz.
*/

#include <iostream>
#include <string.h>

const int rows 	  	 = 3;
const int columns 	 = 3;
const int maxElement = 3;
void puntoSilla(int matrix[rows][columns], int maxFiles[maxElement], int minColumns[maxElement])
{
	int tempi = 0, tempj = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] < maxFiles[i]) 
			{
				maxFiles[i] = matrix[i][j];
			}
			if (matrix[i][j] > minColumns[j])
			{
				minColumns[j] = matrix[i][j];
			}
		
			if (maxFiles[i] == minColumns[j])
			{
				tempi = i;
				tempj = j;
			}
		}
	}
	std::cout << "El punto de siila es: " << tempi << ", " << tempj << std::endl;
}


int main()
{
	int A[rows][columns] = {
		{2,2,2},
		{2,2,2},
		{2,2,2}
	};
	int B[rows][columns] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int C[rows][columns];
	memset(C, 0, sizeof C);

	std::cout << "Matriz A: " << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << "[" << A[i][j] << "]";
		}
		std::cout << std::endl;
	}

	std::cout << "Matriz B: " << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << "[" << B[i][j] << "]";
		}
		std::cout << std::endl;
	}

	std::cout << "Resultado de la suma de la matriz A + B: " << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
			std::cout << "[" << C[i][j] << "]";
		}
		std::cout << std::endl;
	}

	std::cout << "Resultado de la resta de A - B: " << std::endl;
	memset(C, 0, sizeof C);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			C[i][j] = A[i][j] - B[i][j];
			std::cout << "[" << C[i][j] << "]";
		}
		std::cout << std::endl;
	}
	
	std::cout << "Resultado de la multiplicacion de A * B: " << std::endl;
	memset(C, 0, sizeof C);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			C[i][j] = A[i][j] * B[i][j];
			std::cout << "[" << C[i][j] << "]";
		}
		std::cout << std::endl;
	}

	int maxFiles[maxElement];
	int minColumns[maxElement];

	memset(maxFiles, 0, sizeof maxFiles);
	memset(minColumns, 0, sizeof minColumns);

	puntoSilla(C, maxFiles, minColumns);


	return 0;
}