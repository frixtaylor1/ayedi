// tp_unidad_7.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "tp_unidad_7.h"

void program();

int main()
{
    program();

    return EXIT_SUCCESS;
}
void program()
{
    StudentList lStudents;
    ifstream file = readFile("Alumnos.txt");
    lStudents.getDataFile(file);
    closeFile(file);

    functionality(lStudents);
}
