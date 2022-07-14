#ifndef StudentList_h
#define StudentList_h

#include "Student.h"
#include "fileHandler.h"

#include <iomanip>

struct StudentList
{
    void   showList();
    void   saveList(string path);
    void   enterStudent();
    void   searchStudent(int iden);
    void   removeStudent(int iden);
    string getName(int idx);
    string getSurname(int idx);
    string getMajor(int idx);
    int    getID(int idx);
    void   setName(string Name, int idx);
    void   setSurname(string Surname, int idx);
    void   setMajor(string Major, int idx);
    void   setID(int iden, int idx);
    void   getDataFile(ifstream& file);
    
  
private:
    void   sortStudentList();
    int    counter;
    Students students;
};
#endif // !1