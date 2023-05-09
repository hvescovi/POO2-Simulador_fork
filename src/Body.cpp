#include "Body.hpp"
#include <vector>

Body::Body() :
    position{ Vect(0, 0) },
    velocity{ Vect(0, 0) },
    area{ 0.0 },
    mass{ area }
{}

Body::Body(Vect initialPosition, Vect initalVelocity, double area):
    position{ initialPosition },
    velocity{ initalVelocity },
    area{ area },
    mass{ area } // Considera-se a massa igual � �rea
{}

Vect Body::pos() const { return position; }

Vect Body::vel() const { return velocity; }

double Body::a() const { return area; }

double Body::m() const { return mass; }