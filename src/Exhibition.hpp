#include <SDL.h>
#include "Vect.hpp"
#include "RectBody.hpp"
#include "CircumBody.hpp"

class Exhibition
{
    public:
        static void DisplayVector    (SDL_Renderer* renderer, Vect&       initialPos, Vect& finalPos);
        static void DisplayRectBody  (SDL_Renderer* renderer, RectBody&   rect,       Vect& drawPosition);
        static void DisplayCircumBody(SDL_Renderer* renderer, CircumBody& circum,     Vect& drawPosition, int circumVertexQuantity);
};