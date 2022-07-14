//---------------------------------------------------------------
#ifndef PROGRAM_HPP
#define PROGRAM_HPP
//---------------------------------------------------------------
#include "./zoo.hpp"
//---------------------------------------------------------------
void ( Zoo::*arrFuncOfZoo[4])() =
{
  &Zoo::showList, 
  &Zoo::showListSleeping,
  &Zoo::showListEating,
  &Zoo::showListMother
};
void (Zoo::*SelectMammals[3]) () = 
{
  &Zoo::enterWhales, 
  &Zoo::enterSeaLions, 
  &Zoo::enterBats
};
void (Zoo::*SelectOviparous[3]) () = 
{
  &Zoo::enterGoose, 
  &Zoo::enterCrocodile, 
  &Zoo::enterPelican
};
void showMenu()
{
  std::cout << "------------------------------------" << std::endl
            << "\t(1) Enter Mamal"                    << std::endl
            << "\t(2) Enter Oviparous "               << std::endl
            << "\t(3) Show List"                      << std::endl
            << "\t(4) Show List ->Sleep()"            << std::endl
            << "\t(5) Show List ->Eat()"              << std::endl
            << "\t(6) Show list ->Nurse or Lay Eggs"  << std::endl
            << "\t(0) Exit "                          << std::endl
            << "------------------------------------" << std::endl;
}
int selectAnimal()
{
  int animal;
  std::cin >> animal;
  return animal;
}
void showMenuMammals()
{
  std::cout << "(1)Enter Whales"   << std::endl
            << "(2)Enter SeaLions" << std::endl
            << "(3)Enter Bats"     << std::endl;
}
void showMenuOviparous()
{
  std::cout << "(1)Enter Goose"     << std::endl
            << "(2)Enter Crocodile" << std::endl
            << "(3)Enter Pelican"   << std::endl;
}
//---------------------------------------------------------------
#endif // PROGRAM_HPP
//---------------------------------------------------------------