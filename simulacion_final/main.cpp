#include <iostream>
#include "RepairShop.hpp"
#include "Car.hpp"


int main(int argc, char **argv)
{
    RepairShop* repairShop = new RepairShop();
    
    Vehicle* car = new Car("sad", "asd", 2323);
    repairShop->enterVehicle(car);
    
    Vehicle* vehi();

    
    repairShop->repairVehicle();
    
    delete car;
    delete repairShop;
    
    std::cin.get();
    std::cin.ignore();
    return 0;
}
