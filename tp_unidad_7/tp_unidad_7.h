#ifndef tp_unidad_7_h
#define tp_unidad_7_h

#include "StudentList.h"

void showOptions(std::ostream& stream)
{
    stream << "\t(1) Enter Student" << std::endl;
    stream << "\t(2) Search Student" << std::endl;
    stream << "\t(3) Remove Student" << std::endl;
    stream << "\t(4) Show Student List " << std::endl;
    stream << "\t(0) E X I T" << std::endl;
}
int menu(std::istream& input)
{
    int option = 0;
    showOptions(std::cout);
    std::cout << "Enter a option: ";
    input >> option;
    return option;
}
void functionality(StudentList& stList)
{
    int option;
    int iden1 = 0;
    int iden2 = 0;
    do
    {
        option = menu(std::cin);
        switch (option)
        {
        case 1:
            stList.enterStudent();
            break;
        case 2:
            
            std::cout << "Enter the ID of the student: ";
            std::cin >> iden1;
            stList.searchStudent(iden1);
            std::cin.ignore();
            break;
        case 3:
            
            std::cout << "Enter the ID of the student: ";
            std::cin >> iden2;
            stList.removeStudent(iden2);
            std::cin.ignore();
            break;
        case 4:
            stList.showList();
            break;
        default:
            std::cerr << "Invalid option, try again..." << std::endl;
            break;
        }
    } while (option != 0);
    stList.saveList("Alumnos.txt");
}
#endif // !1
