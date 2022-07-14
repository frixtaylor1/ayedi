//---------------------------------------------------------------
#include "../headers/oviparous.hpp"
//---------------------------------------------------------------
// Constructor of Crocodile class...
Crocodile::Crocodile()
  : eating(false), sleeping(false), layingEggs(false) {}
//---------------------------------------------------------------
std::string Crocodile::getType()
{
  return "crocodile";
}
std::string Crocodile::eat()
{
  eating = true;
  sleeping = false;
  layingEggs = false;
  return "eating row meat";
}
void Crocodile::sleep()
{
  eating = false;
  sleeping = true;
  layingEggs = false;
}
std::string Crocodile::layEggs()
{
  eating = false;
  sleeping = false;
  layingEggs = true; 
  return "Lay eggs";
}
std::string Crocodile::mater()
{
  return layEggs();
}
bool Crocodile::getEatingStatus()
{
  return eating;
}
bool Crocodile::getSleepingStatus()
{
  return sleeping;
}
bool Crocodile::getMotherStatus()
{
  return layingEggs;
}
//---------------------------------------------------------------
// Constructor of Goose class...
Goose::Goose()
  : eating(false), sleeping(false), layingEggs(false) {}
//---------------------------------------------------------------
std::string Goose::getType()
{
  return "goose";
}
std::string Goose::eat()
{
  eating = true;
  sleeping = false;
  layingEggs = false;
  return "eating grass";
}
void Goose::sleep()
{
  eating = false;
  sleeping = true;
  layingEggs = false;
}
std::string  Goose::layEggs()
{
  eating = false;
  sleeping = false;
  layingEggs = true; 
  return "Lay eggs";
}
std::string Goose::mater()
{
  return layEggs();
}
bool Goose::getEatingStatus()
{
  return eating;
}
bool Goose::getSleepingStatus()
{
  return sleeping;
}
bool Goose::getMotherStatus()
{
  return layingEggs;
}
//---------------------------------------------------------------
// Constructor of Pelican class...
Pelican::Pelican()
  : eating(false), sleeping(false), layingEggs(false) {}
//---------------------------------------------------------------
std::string Pelican::getType()
{
  return "Pelican";
}
std::string Pelican::eat()
{
  eating = true;
  sleeping = false;
  layingEggs = false;
  return "eating fish";
}
void Pelican::sleep()
{
  eating = false;
  sleeping = true;
  layingEggs = false;
}
std::string  Pelican::layEggs()
{
  eating = false;
  sleeping = false;
  layingEggs = true; 
  return "Lay eggs";
}
std::string Pelican::mater()
{
  return layEggs();
}
bool Pelican::getEatingStatus()
{
  return eating;
}
bool Pelican::getSleepingStatus()
{
  return sleeping;
}
bool Pelican::getMotherStatus()
{
  return layingEggs;
}
//---------------------------------------------------------------
