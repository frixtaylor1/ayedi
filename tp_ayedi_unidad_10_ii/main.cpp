#include <iostream>
#include "./unit.hpp"

void Program();

int main()
{
    Program();

    return 0;
}

void Program()
{
    collectionOfShapes* collection = new collectionOfShapes();
    int operationSelected = 0;
    while(true)
    {
        showMenu();
        operationSelected = selectingOperation(std::cin);
        operationSelected = operationSelected - 1;
        if(operationSelected == -1) break;
        (collection->*optionsOfShapes[operationSelected])();
    }
    delete collection;
}