#include "../hpp/RectBody.hpp"

RectBody::RectBody():
    Body(),
    height{ 0.0 },
    width{ 0.0 }
{}

RectBody::RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double width, double height):
    Body(initialPosition, initalVelocity, initialAcceleration, height * width),
    width{ width },
    height{ height }
{}