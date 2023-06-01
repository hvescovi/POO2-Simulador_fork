#include "../hpp/Exhibition.hpp"

#define PI 3.1415926535897932384626433832795
#define PI_DIV_180 0.01745329251994329576923690768489
#define PI_MINUS_PI_DIV_6 2.6179938779914943653855361527329
#define PI_PLUS_PI_DIV_6 3.6651914291880921115397506138261

void Exhibition::DisplayVector(SDL_Renderer* renderer, Vect initialPos, Vect finalPos)
{
    SDL_SetRenderDrawColor(renderer, 255, 20, 147, SDL_ALPHA_OPAQUE);

    Vect mainSegment = Vect(initialPos, finalPos);

    double arrowMod = mainSegment.Module() * 0.15;

    Vect LArrowSegment = Vect(arrowMod, 0.0);
    Vect RArrowSegment = Vect(arrowMod, 0.0);

    double mainSegmentArg = mainSegment.Argument();

    LArrowSegment.IncArgument(mainSegmentArg + PI_MINUS_PI_DIV_6);
    RArrowSegment.IncArgument(mainSegmentArg + PI_PLUS_PI_DIV_6);

    // Renderiza segmento esquerdo da flecha do vetor
    SDL_RenderDrawLine(
        renderer,
        finalPos.x,
        finalPos.y,
        finalPos.x + /*(int)std::round(*/LArrowSegment.x, 
        finalPos.y + /*(int)std::round(*/LArrowSegment.y
    );

    // Renderiza segmento direito da flecha do vetor
    SDL_RenderDrawLine(
        renderer,
        finalPos.x,
        finalPos.y,
        finalPos.x + /*(int)std::round(*/RArrowSegment.x,
        finalPos.y + /*(int)std::round(*/RArrowSegment.y
    );

    // Renderiza segmento principal do vetor
    SDL_RenderDrawLine(
        renderer, 
        initialPos.x, 
        initialPos.y,
        finalPos.x,
        finalPos.y
    );
}

void Exhibition::DisplayRectBody(SDL_Renderer* renderer, RectBody& rect)
{
    if (rect.terminator)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    else
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    SDL_RenderDrawLine(
        renderer, 
        rect.position.x,
        rect.position.y,
        rect.position.x + rect.width,
        rect.position.y
    );

    SDL_RenderDrawLine(
        renderer, 
        rect.position.x,
        rect.position.y,
        rect.position.x,
        rect.position.y + rect.height
    );

    SDL_RenderDrawLine(
        renderer, 
        rect.position.x + rect.width,
        rect.position.y,
        rect.position.x + rect.width,
        rect.position.y + rect.height
    );

    SDL_RenderDrawLine(
        renderer, 
        rect.position.x,
        rect.position.y + rect.height,
        rect.position.x + rect.width,
        rect.position.y + rect.height
    );
}

void Exhibition::DisplayCircumBody(SDL_Renderer* renderer, CircumBody& circum, int circumVertexQuantity, int index)
{
    SDL_SetRenderDrawColor(renderer, ((5 * index) > 255) ? 255 : 5 * index, 255, 0, SDL_ALPHA_OPAQUE);

    double incRad = (360.0 / circumVertexQuantity) * PI_DIV_180;

    Vect vAux1 = Vect(circum.radius, 0.0);
    Vect vAux2 = Vect(circum.radius, 0.0);
    vAux2.IncArgument(incRad);

    double cPosX = circum.position.x;
    double cPosY = circum.position.y;

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