#include "Shape.hpp"
#include <SDL.h>
#include "Vect.hpp"

class Rectangle : public Shape
{
    public:
        double width;
        double height;

        Rectangle(double width, double height);

        void Display(SDL_Renderer* renderer, Vect& drawPosition);
};