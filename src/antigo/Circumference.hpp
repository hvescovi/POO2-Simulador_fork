#include "Shape.hpp"
#include <SDL.h>
#include "Vect.hpp"

class Circumference : public Shape
{
    public:
        double radius;

        Circumference(double radius);

        void Display(SDL_Renderer* renderer, Vect& drawPosition, int vertexQuantity);
};