#pragma once
#include <SDL.h>
#include "Vect.hpp"
#include "RectBody.hpp"
#include "CircumBody.hpp"

class Exhibition
{
    public:
        static void DisplayVector(SDL_Renderer* renderer, Vect initialPos, Vect finalPos);
        static void DisplayRectBody(SDL_Renderer* renderer, RectBody& rect);
        static void DisplayCircumBody(SDL_Renderer* renderer, CircumBody& circum, int circumVertexQuantity, int index);
};