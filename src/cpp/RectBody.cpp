#include "../hpp/RectBody.hpp"

RectBody::RectBody():
    Body(),
    height{ 0.0 },
    width{ 0.0 },
    terminator{ false }
{}

RectBody::RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double width, double height):
    Body(initialPosition, initalVelocity, initialAcceleration, height * width),
    width{ width },
    height{ height },
    terminator{ false }
{}

RectBody::RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double width, double height, bool terminator):
    Body(initialPosition, initalVelocity, initialAcceleration, height * width),
    width{ width },
    height{ height },
    terminator{ terminator }
{}