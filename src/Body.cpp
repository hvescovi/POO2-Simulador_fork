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

Vect Body::get_pos() { return position; }
void Body::set_pos(Vect pos) { position = pos; }

Vect Body::get_vel() { return velocity; }
void Body::set_vel(Vect newVel) { velocity = newVel; }

double Body::get_area() { return area; }
double Body::get_mass() { return mass; }