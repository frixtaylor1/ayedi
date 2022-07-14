#ifndef CAR_HPP
#define CAR_HPP
#include "Vehicle.hpp"

class Car : public Vehicle
{
private:
    int motor;
public:
    Car();
    Car(std::string colour, std::string brand, int motor);
    virtual ~Car();
    void setMotor(int motor);
    int getMotor();
    void start();
    void stop();
    void refuel();
    void getInfo();

};

#endif // CAR_HPP
