#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>

class Shape
{
    private:
    public:
        void turn();
        void move();
        virtual void draw() = 0;
        virtual void erase() = 0;
};
class Circle : public Shape
{
    private:
    public:
        void draw();
        void erase();
};
class Rectangle : public Shape
{
    private:
    public:
        void draw();
        void erase();
};
class Triangle : public Shape
{
    private:
    public:
        void draw();
        void erase();
};
#endif // SHAPE_HPP