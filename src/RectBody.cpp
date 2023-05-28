#include "RectBody.hpp"

RectBody::RectBody():
    Body(),
    height{ 0.0 },
    width{ 0.0 }
{}

RectBody::RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double height, double width):
    Body(initialPosition, initalVelocity, initialAcceleration, height * width),
    height{ height },
    width{ width }
{}