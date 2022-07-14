#include "StudentList.h"
#include <algorithm>
#include <string.h>

void StudentList::sortStudentList()
{
    std::sort(students, students + counter + 1);
}
void StudentList::enterStudent()
{
    if (counter < CAPACITY)
    {
        string name = "", surname = "", major = "";
        int id = 0;

        std::cout << "Enter a name: ";
        std::cin >> name;
        std::cout << "Enter a surname: ";
        std::cin >> surname;
        std::cout << "Enter a major: ";
        std::cin >> major;
        std::cout << "Enter a id (numbers only +4 numbers): ";
        std::cin >> id;

        setName(name, counter);
        setSurname(surname, counter);
        setMajor(major, counter);
        setID(id, counter);
        counter++;
    }
    else {
        std::cout << "Exceeded Max Capacity!" << std::endl;
    }
 }
void StudentList::saveList(string path)
{
    sortStudentList();
    ofstream file = writeFile(path);
    int i = 0;
    while (i != counter)
    {
        file << getName(i)    << " "
             << getSurname(i) << " "
             << getMajor(i)   << " "
             << getID(i)      << std::endl;
        i++;
    }
    file.close();
}
void StudentList::showList()
{
    std::cout << "\n**********************************************************************************" << std::endl;
    std::cout << std::setw(16) << "NAME";
    std::cout << std::setw(16) << "SURNAME";
    std::cout << std::setw(16) << "MAJOR";
    std::cout << std::setw(16) << "ID";
    
    for (int i = 0; i < counter; i++)
    {
        std::cout << "\n----------------------------------------------------------------------------------" << std::endl;
        std::cout << std::setw(16) << getName(i);
        std::cout << std::setw(16) << getSurname(i);
        std::cout << std::setw(16) << getMajor(i);
        std::cout << std::setw(16) << getID(i);
        std::cout << "\n----------------------------------------------------------------------------------" << std::endl;
    }
    std::cout << "\n**********************************************************************************" << std::endl;
}
void StudentList::searchStudent(int iden)
{
    sortStudentList();
    for (int i = 0; i < counter; i++)
    {
        if (iden == students[i].id)
        {
            std::cout << "\n------------------------------\n";
            std::cout << "\tname: " << getName(i);
            std::cout << "\n------------------------------\n";
        }
    }
    showList();
    
    return;
}
void StudentList::removeStudent(int iden)
{
    for (int i = iden; i < counter; i++)
    {
        if (iden == students[i].id)
        {
            students[i] = students[i + 1];
        }
    }
    counter--;
}
void StudentList::setName(string Name, int idx)
{
    students[idx].name = Name;
}
void StudentList::setSurname(string Surname, int idx)
{
    students[idx].surname = Surname;
}
void StudentList::setMajor(string Major, int idx)
{
    students[idx].major = Major;
}
void StudentList::setID(int iden, int idx)
{
    students[idx].id = iden;
}
string StudentList::getName(int idx)
{
    return students[idx].name;
}
string StudentList::getSurname(int idx)
{
    return students[idx].surname;
}
string StudentList::getMajor(int idx)
{
    return students[idx].major;
}
int StudentList::getID(int idx)
{
    return students[idx].id;
}
void StudentList::getDataFile(ifstream& file)
{
    string name    = "";
    string surname = "";
    string major   = "";
    int id    = 0;
    counter = 0;

    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> name
                >> surname
                >> major
                >> id;
            setName(name, counter);
            setSurname(surname, counter);
            setMajor(major, counter);
            setID(id, counter);
            counter++;
        }
        counter--;
    }
    closeFile(file);
}