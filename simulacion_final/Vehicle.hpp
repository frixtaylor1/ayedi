#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>

class Vehicle
{
private:
    std::string colour;
    std::string brand;
public:
    Vehicle();
    Vehicle(std::string colour, std::string brand);
    Vehicle(const Vehicle& vehicle);
    virtual ~Vehicle();
    void setColour(std::string colour);
    void setBrand(std::string brand);
    std::string getColour();
    std::string getBrand();
    // Virtual Methods of the class...
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void refuel() = 0;
    // Redefined operators...
    
    friend std::istream& operator>>(std::istream& in, Vehicle& vehi);
};

#endif // VEHICLE_HPP
