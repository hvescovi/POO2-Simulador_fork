#include "Circumference.hpp"

#define PI_DIV_180 0.01745329251994329576923690768489

Circumference::Circumference(double radius):
    radius{radius}
{}

void Circumference::Display(SDL_Renderer* renderer, Vect& drawPosition, int vertexQuantity)
{
    double incRad = (360.0 / vertexQuantity) * PI_DIV_180;

    Vect vAux1 = Vect(radius, 0.0);
    Vect vAux2 = Vect(radius, 0.0);
    vAux2.IncArgument(incRad);

    double cPosX = drawPosition.x;
    double cPosY = drawPosition.y;

    int i = 0;
    while (i < vertexQuantity)
    {
        SDL_RenderDrawLine(
            renderer, 
            cPosX + vAux1.x,
            cPosY + vAux1.y,
            cPosX + vAux2.x,
            cPosY + vAux2.y
        );

        vAux1.IncArgument(incRad);
        vAux2.IncArgument(incRad);

        i += 1;
    }
}