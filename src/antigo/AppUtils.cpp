#include "AppUtils.hpp"
#include <cmath>

#define PI 3.1415926535897932384626433832795
#define PI_DIV_180 0.01745329251994329576923690768489
#define PI_MINUS_PI_DIV_6 2.6179938779914943653855361527329
#define PI_PLUS_PI_DIV_6 3.6651914291880921115397506138261


// void AppUtils::s_DrawVect(SDL_Renderer* renderer, Vect initialPos, Vect finalPos)
// {
//     Vect mainSegment = Vect(initialPos, finalPos);

//     double arrowMod = mainSegment.Module() * 0.2;

//     Vect LArrowSegment = Vect(arrowMod, 0.0);
//     Vect RArrowSegment = Vect(arrowMod, 0.0);

//     double mainSegmentArg = mainSegment.Argument();

//     LArrowSegment.IncArgument(mainSegmentArg + PI_MINUS_PI_DIV_6);
//     RArrowSegment.IncArgument(mainSegmentArg + PI_PLUS_PI_DIV_6);

//     // Renderiza segmento esquerdo da flecha do vetor
//     SDL_RenderDrawLine(
//         renderer,
//         (int)finalPos.x,
//         (int)finalPos.y,
//         (int)finalPos.x + (int)std::round(LArrowSegment.x), 
//         (int)finalPos.y + (int)std::round(LArrowSegment.y)
//     );

//     // Renderiza segmento direito da flecha do vetor
//     SDL_RenderDrawLine(
//         renderer,
//         (int)finalPos.x,
//         (int)finalPos.y,
//         (int)finalPos.x + (int)std::round(RArrowSegment.x),
//         (int)finalPos.y + (int)std::round(RArrowSegment.y)
//     );

//     // Renderiza segmento principal do vetor
//     SDL_RenderDrawLine(
//         renderer, 
//         (int)initialPos.x, 
//         (int)initialPos.y,
//         (int)finalPos.x,
//         (int)finalPos.y
//     );
// }

// void AppUtils::s_DrawParticle(SDL_Renderer* renderer, Particle particle, int vertexQuantity)
// {
//     double incRad = (360.0 / vertexQuantity) * PI_DIV_180;

//     Vect vAux1 = Vect(particle.radius, 0.0);
//     Vect vAux2 = Vect(particle.radius, 0.0);
//     vAux2.IncArgument(incRad);

//     double cPosX = particle.position.x;
//     double cPosY = particle.position.y;

//     int i = 0;
//     while (i < vertexQuantity)
//     {
//         SDL_RenderDrawLine(
//             renderer, 
//             (int)(cPosX + vAux1.x),
//             (int)(cPosY + vAux1.y),
//             (int)(cPosX + vAux2.x),
//             (int)(cPosY + vAux2.y)
//         );

//         vAux1.IncArgument(incRad);
//         vAux2.IncArgument(incRad);

//         i += 1;
//     }
// }

// double AppUtils::s_DistanceBetweenParticles(Particle particle1, Particle particle2)
// {
//     return Vect(particle1.position, particle2.position).Module();
// }