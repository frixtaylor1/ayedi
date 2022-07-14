#ifndef Student_h
#define Student_h

#include <iostream>

using std::string;

const int CAPACITY = 100;

typedef struct
{
    string name;
    string surname;
    string major;
    int    numberClass;
    int    id;
} Student;

typedef Student Students[CAPACITY];

bool operator<(Student leftHand, Student rightHand);
/*
bool operator>(Student leftHand, Student rightHand);
*/

#endif