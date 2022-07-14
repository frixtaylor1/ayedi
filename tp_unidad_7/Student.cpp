#include "Student.h"

bool operator<(Student leftHand, Student rightHand)
{
	return leftHand.id < rightHand.id;
}
/*
bool operator>(Student leftHand, Student rightHand)
{
	return leftHand.id > rightHand.id;
}
*/