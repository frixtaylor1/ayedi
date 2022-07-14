#include "Vehicle.hpp"

Vehicle::Vehicle()
{
    colour = "";
    brand = "";
}
Vehicle::Vehicle(std::string colour, std::string brand)
{
    this->colour = colour;
    this->brand = brand;
}
Vehicle::Vehicle(const Vehicle& vehicle)
{
    colour = vehicle.colour;
    brand = vehicle.brand;
}
Vehicle::~Vehicle()
{
}
void Vehicle::setColour(std::string colour)
{
    this->colour = colour;
}
void Vehicle::setBrand(std::string brand)
{
    this->brand = brand;
}
std::string Vehicle::getBrand()
{
    return brand;
}
std::string Vehicle::getColour()
{
    return colour;
}
std::istream& operator>>(std::istream& in, Vehicle& vehi)
{
    std::string brand{""}, colour{""};
    int cc{0};
    in >> colour >> brand >> cc;
    vehi.setColour(colour); vehi.setBrand(brand);
    return in;
}
