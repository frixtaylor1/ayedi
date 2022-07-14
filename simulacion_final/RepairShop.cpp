#include "RepairShop.hpp"

RepairShop::RepairShop()
{
    nbVehicle = 0;
}
RepairShop::~RepairShop()
{
}
void RepairShop::enterVehicle(Vehicle* vehi)
{
    vehicles[nbVehicle] = vehi;
    nbVehicle++;
}
void RepairShop::repairVehicle()
{
    for(int i = 0; i < nbVehicle; i++)
    {
        vehicles[i]->refuel();
        vehicles[i]->start();
    }
}
