#include "../hpp/Body.hpp"
#include <vector>

Body::Body() :
    position{ Vect(0, 0) },
    velocity{ Vect(0, 0) },
    acceleration{ Vect(0, 0) },
    area{ 0.0 },
    mass{ area }
{}

Body::Body(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double area):
    position{ initialPosition },
    velocity{ initalVelocity },
    acceleration{ initialAcceleration },
    area{ area },
    mass{ area } // Considera-se a massa igual à área
{}

// std::vector<Body> Body::createVectorBody()
// {
//     std::vector<Body> vC;

//     vC.push_back(Body(Vect(100, 100), Vect(100, 100), Vect(0, 0), 30));

//     int i = 1;
//     int j = 1;
//     while (i <= 10)
//     {
//         j = 1;
//         while (j <= 8)
//         {
//             vC.push_back(
//                 Body(
//                     Vect(70 * i, 100 + 50 * j),
//                     Vect(0, 0),
//                     Vect(0, 0),
//                     12
//                 )
//             );

//             j += 1;
//         }

//         i += 1;
//     }

//     return vC;
// }