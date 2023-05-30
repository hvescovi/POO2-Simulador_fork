#include "../hpp/CircumBody.hpp"

#define PI 3.1415926535897932384626433832795

CircumBody::CircumBody():
    Body(),
    radius{ 0.0 }
{}

CircumBody::CircumBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double radius):
    Body(initialPosition, initalVelocity, initialAcceleration, radius * 2 * PI),
    radius{ radius }
{}