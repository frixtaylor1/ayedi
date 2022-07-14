#include "MotorBike.hpp"

MotorBike::MotorBike()
{
    cc = 0;
}
MotorBike::MotorBike(std::string colour, std::string brand, int cc) : Vehicle(colour, brand)
{
    this-> cc = cc;
}
MotorBike::~MotorBike()
{
}
void MotorBike::setCc(int cc)
{
    this->cc = cc;
}
int MotorBike::getCc()
{
    return cc;
}
void MotorBike::start()
{
    std::cout << "...STARTED... " << std::endl;
    getInfo();
    
}
void MotorBike::stop()
{
    std::cout << "...STOPED..." << std::endl;
    getInfo();
}
void MotorBike::refuel()
{
    std::cout << "...REFUEL..." << std::endl;
    getInfo();
}
void MotorBike::getInfo()
{
    std::cout << "brand: " << getBrand() << std::endl;
    std::cout << "colour: " << getColour() << std::endl;
    std::cout << "cc: " << getCc() << std::endl;
}



