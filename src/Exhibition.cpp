#include "Exhibition.hpp"

#define PI_DIV_180 0.01745329251994329576923690768489

void Exhibition::DisplayRectBody  (SDL_Renderer* renderer, RectBody& rect,     Vect& drawPosition)
{
    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x,
            drawPosition.y,
            drawPosition.x + rect.width,
            drawPosition.y
        );

    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x,
            drawPosition.y,
            drawPosition.x,
            drawPosition.y + rect.height
        );

    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x + rect.width,
            drawPosition.y,
            drawPosition.x + rect.width,
            drawPosition.y + rect.height
        );

    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x,
            drawPosition.y + rect.height,
            drawPosition.x + rect.width,
            drawPosition.y + rect.height
        );
}

void Exhibition::DisplayCircumBody(SDL_Renderer* renderer, CircumBody& circum, Vect& drawPosition, int circumVertexQuantity)
{
    double incRad = (360.0 / circumVertexQuantity) * PI_DIV_180;

    Vect vAux1 = Vect(circum.radius, 0.0);
    Vect vAux2 = Vect(circum.radius, 0.0);
    vAux2.IncArgument(incRad);

    double cPosX = drawPosition.x;
    double cPosY = drawPosition.y;

    int i = 0;
    while (i < circumVertexQuantity)
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