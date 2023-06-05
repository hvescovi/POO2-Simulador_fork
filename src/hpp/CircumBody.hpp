#pragma once
#include "Body.hpp"
#include "Vect.hpp"

class CircumBody : public Body
{
    public:
        double radius;

        double maxVel;

        bool terminated;

        // Construtor padrão.
        CircumBody();

        CircumBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double radius, double maxVel);
};