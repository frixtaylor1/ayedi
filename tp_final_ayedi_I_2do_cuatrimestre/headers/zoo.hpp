//---------------------------------------------------------------
#ifndef ZOO_HPP
#define ZOO_HPP
//---------------------------------------------------------------
#include "./mammal.hpp"
#include "./oviparous.hpp"
//---------------------------------------------------------------
class Zoo
{
  public:
    Zoo();
    ~Zoo();
    void enterAnimal(Animal& animas);
    void enterSeaLions();
    void enterWhales();
    void enterBats();
    void enterCrocodile();
    void enterGoose();
    void enterPelican();
    void showList();
    void showListEating();
    void showListSleeping();
    void showListMother();
  private:
    enum{capacity = 100}; //static const size_t capacity = 100;
    Animal*    animal[capacity];
    int        counter;
};
//---------------------------------------------------------------
#endif // ZOO_HPP
//---------------------------------------------------------------