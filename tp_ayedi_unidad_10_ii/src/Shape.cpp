#include "../include/Shape.hpp"

void Shape::move()
{
    std::cout << "Moving Shape" << std::endl;
}
void Shape::turn()
{
    std::cout << "Turning Shape" << std::endl;
}
void Circle::draw()
{
    std::cout << "Drawing Circle!" << std::endl;
}
void Circle::erase()
{
    std::cout << "Erasing Circle!" << std::endl;
}
void Rectangle::draw()
{
    std::cout << "Drawing Rectangle!" << std::endl;
}
void Rectangle::erase()
{
    std::cout << "Erasing Rectangle!" << std::endl;
}
void Triangle::draw()
{
    std::cout << "Drawing Triangle!" << std::endl;
}
void Triangle::erase()
{
    std::cout << "Erasing Triangle!" << std::endl;
}