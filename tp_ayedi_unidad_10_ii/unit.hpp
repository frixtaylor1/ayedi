#ifndef UNIT_HPP
#define UNIT_HPP
#include "./include/Shape.hpp"

class collectionOfShapes
{
    public:
        collectionOfShapes();
        void enterTriangle();
        void enterCircle();
        void enterRectangle();
        void showListDraw();
        void showListErase();
        void showListMove();
        void showListTurn();
    private:
        void showList(Shape* shape[]);
        void enterShape(Shape* shape);
        enum{ capacity = 5 };
        Shape* shapes[capacity];
        int nbShapes;
};
collectionOfShapes::collectionOfShapes() : nbShapes(0) {}
void collectionOfShapes::enterTriangle() 
{
    Triangle* triangle = new Triangle();
    enterShape(triangle);
}
void collectionOfShapes::enterCircle() 
{
    Circle* circle = new Circle();
    enterShape(circle);
}
void collectionOfShapes::enterRectangle() 
{
    Rectangle* rectangle = new Rectangle();
    enterShape(rectangle);
}
void collectionOfShapes::showListDraw() 
{
    for (int i = 0; i < nbShapes; i++)
    {
        shapes[i]->draw();
    }
}
void collectionOfShapes::showListErase() 
{
    for (int i = 0; i < nbShapes; i++)
    {
        shapes[i]->erase();
    }
}
void collectionOfShapes::showListMove() 
{
    for (int i = 0; i < nbShapes; i++)
    {
        shapes[i]->move();
    }
}
void collectionOfShapes::showListTurn() 
{
    for (int i = 0; i < nbShapes; i++)
    {
        shapes[i]->turn();
    }
}
void collectionOfShapes::enterShape(Shape* shape) 
{
    shapes[nbShapes] = shape;
    nbShapes++;    
}
void showMenu()
{
    std::cout << "(1)Enter Circle"    << std::endl;
    std::cout << "(2)Enter Rectangle" << std::endl;
    std::cout << "(3)Enter Triangle"  << std::endl;
    std::cout << "(4)Show List Draw"  << std::endl;
    std::cout << "(5)Show List Erase" << std::endl;
    std::cout << "(6)Show List Move"  << std::endl;
    std::cout << "(7)Show List Turn"  << std::endl;
    std::cout << "(0)EXIT EXIT EXIT"  << std::endl;
}
int selectingOperation(std::istream& in)
{
    int option = 0;
    in >> option;
    return option;
}
void (collectionOfShapes::*optionsOfShapes[8])() =
{
    &collectionOfShapes::enterCircle,
    &collectionOfShapes::enterRectangle,
    &collectionOfShapes::enterTriangle,
    &collectionOfShapes::showListDraw,
    &collectionOfShapes::showListErase,
    &collectionOfShapes::showListMove,
    &collectionOfShapes::showListTurn
};
#endif // UNIT_HPP