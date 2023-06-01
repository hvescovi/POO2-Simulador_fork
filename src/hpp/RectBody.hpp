#pragma once
#include "Body.hpp"
#include "Vect.hpp"

class RectBody : public Body
{
    public:
        double height;

        double width;

        bool terminator;

        // Construtor padrão.
        RectBody();

        RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double width, double height);

        RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double width, double height, bool terminator);
};