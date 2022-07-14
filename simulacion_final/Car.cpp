#include "Car.hpp"

Car::Car()
{
    motor = 0;
}
Car::Car(std::string colour, std::string brand, int motor) : Vehicle(colour, brand)
{
    this->motor = motor;
}
Car::~Car()
{
}
int Car::getMotor()
{
    return motor;
}
void Car::setMotor(int motor)
{
    this->motor = motor;
}
void Car::start()
{
    std::cout << "...STARTED... " << std::endl;
    getInfo();
}
void Car::refuel()
{
    std::cout << "...REFUEL..." << std::endl;
}
void Car::stop()
{
    std::cout << "...STOPED..." << std::endl;
}
void Car::getInfo()
{
    std::cout << "brand: " << getBrand() << std::endl;
    std::cout << "colour: " << getColour() << std::endl;
    std::cout << "cc: " << getMotor() << std::endl;
}