#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height):
    width{width},
    height{height}
{}

void Rectangle::Display(SDL_Renderer* renderer, Vect& drawPosition)
{
    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x,
            drawPosition.y,
            drawPosition.x + width,
            drawPosition.y
        );

    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x,
            drawPosition.y,
            drawPosition.x,
            drawPosition.y + height
        );

    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x + width,
            drawPosition.y,
            drawPosition.x + width,
            drawPosition.y + height
        );

    SDL_RenderDrawLine(
            renderer, 
            drawPosition.x,
            drawPosition.y + height,
            drawPosition.x + width,
            drawPosition.y + height
        );
}