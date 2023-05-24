#include "Body.hpp"

class Mechanics
{
    static void Move(Body& body, double rDT);
    static void Accelerate(Body& body);
    static void MustCollide(Body& body1, Body& body2);
    static void DoCollide(Body& body1, Body& body2);
};