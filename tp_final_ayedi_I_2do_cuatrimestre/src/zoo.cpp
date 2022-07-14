//---------------------------------------------------------------
#include "../headers/zoo.hpp"
//---------------------------------------------------------------
Zoo::Zoo() : counter{0} {}
Zoo::~Zoo() 
{
  for(int i = 0; i < counter; i++)
  {
    delete animal[i];
  }
}
//---------------------------------------------------------------
// Methods of the struct...
//---------------------------------------------------------------
void Zoo::showList()
{
  
  for(int i = 0; i < counter; i++)
  {
    std::cout << *animal[i];
  }
}
void Zoo::showListEating()
{
  for(int i = 0; i < counter; i++)
  {
    animal[i]->eat();
    std::cout << *animal[i];
  }
}
void Zoo::showListSleeping()
{
  for(int i = 0; i < counter; i++)
  {
    animal[i]->sleep();
    std::cout << *animal[i];
  }
}
void Zoo::showListMother()
{
  for(int i = 0; i < counter; i++)
  {
    animal[i]->mater();
    std::cout << *animal[i];
  }
}
void Zoo::enterAnimal(Animal& animas)
{
  std::cin >> animas;
  animal[counter] = &animas;
  counter++;
}
void Zoo::enterSeaLions()
{
  SeaLion* seaLion = new SeaLion;
  enterAnimal(*seaLion);
}
void Zoo::enterWhales()
{ 
  Whale* whale = new Whale;
  enterAnimal(*whale);
}
void Zoo::enterBats()
{
  Bat* bat = new Bat;
  enterAnimal(*bat);
}
void Zoo::enterGoose()
{
  Goose* goose = new Goose;
  enterAnimal(*goose);
}
void Zoo::enterPelican()
{
  Pelican* pelican = new Pelican;
  enterAnimal(*pelican);
}
void Zoo::enterCrocodile()
{
  Crocodile* croco = new Crocodile;
  enterAnimal(*croco);
}
//---------------------------------------------------------------