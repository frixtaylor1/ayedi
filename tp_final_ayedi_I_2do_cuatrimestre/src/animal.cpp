//----------------------------------------------------------------------
#include "../headers/animal.hpp"
//----------------------------------------------------------------------
Animal::~Animal() {}
//----------------------------------------------------------------------
std::string Animal::getName()
{
    return name;
}
int Animal::getCode()
{
    return code;
}
void Animal::assign(std::string nam, int cod)
{
    name = nam;
    code = cod;
}
void eat() {}
void sleep() {}
std::string mater() { return ""; }
//----------------------------------------------------------------------
std::ostream& operator<<(std::ostream& stream, Animal& anima)
{ 
  stream << "--------------------------------"  << std::endl
         << "name:...\t   " << anima.getName()    << std::endl
         << "code:...\t   " << anima.getCode()    << std::endl
         << "type:...\t   " << anima.getType()    << std::endl;
  if(anima.getSleepingStatus())
    stream << "status:.\t sleeping." << std::endl;
  if(anima.getEatingStatus())
    stream << "status:.\t " << anima.eat() << std::endl;
  if(anima.getMotherStatus())
    stream << "mother status: " << anima.mater() << std::endl;
  return stream;
}
void showSomeInstructions()
{
  std::cout << "Enter name and code. e.g: 'name' 'code' " << std::endl;
}
std::istream& operator>>(std::istream& in, Animal& anima)
{
  std::string name{""}; int code{0};
  showSomeInstructions();
  in >> name >> code;
  anima.assign(name, code);
  return in;
}
//----------------------------------------------------------------------
