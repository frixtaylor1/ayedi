#ifndef MOTORBIKE_HPP
#define MOTORBIKE_HPP
#include "Vehicle.hpp"
#include <iostream>

class MotorBike : public Vehicle
{
private:
    int cc;
    void getInfo();
public:
    MotorBike();
    MotorBike(std::string colour, std::string brand, int cc);
    ~MotorBike();
    void setCc(int cc);
    int getCc();
    void start();
    void stop();
    void refuel();
};

#endif // MOTORBIKE_HPP
