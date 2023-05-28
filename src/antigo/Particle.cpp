#include "Particle.hpp"
#include <cmath>
#include <vector>
#define PI 3.1415926535897932384626433832795

Particle::Particle():
    radius{ 0.0 }
{}

Particle::Particle(Vect initialPosition, Vect initalVelocity, double radius):
    Body(initialPosition, initalVelocity, PI * pow(radius, 2.0)),
    radius{ radius }
{}

std::vector<Particle> Particle::createVectorParticle1()
{
    std::vector<Particle> vC;

    int i = 1;
    while (i <= 5)
    {
        Vect v1 = Vect(60 * sin(i), 5 * (double)i);
        Vect v2 = Vect(100 * (double)i, 100);

        Particle c = Particle(v2, v1, 5 * (double)i);
        vC.push_back(c);

        i += 1;
    }

    i = 1;
    while (i <= 5)
    {
        Vect v1 = Vect(60 * sin(i), sin(i));
        Vect v2 = Vect(100 * (double)i, 300);

        Particle c = Particle(v2, v1, 8 * (double)i);
        vC.push_back(c);

        i += 1;
    }

    return vC;
}

std::vector<Particle> Particle::createVectorParticle2()
{
    std::vector<Particle> vC;

    Vect pos1 = Vect(100, 200);
    Vect vel1 = Vect(30, 0);
    Vect pos2 = Vect(400, 200);
    Vect vel2 = Vect(70, 0);

    Particle c1 = Particle(pos1, vel1, 40);
    Particle c2 = Particle(pos2, vel2, 15);
    vC.push_back(c1);
    vC.push_back(c2);

    return vC;
}

std::vector<Particle> Particle::createVectorParticle3()
{
    std::vector<Particle> vC;

    vC.push_back(Particle(Vect(100, 100), Vect(100, 100), 30));

    int i = 1;
    int j = 1;
    while (i <= 10)
    {
        j = 1;
        while (j <= 8)
        {
            vC.push_back(
                Particle(
                    Vect(70 * i, 100 + 50 * j),
                    Vect(0, 0),
                    12
                )
            );

            j += 1;
        }

        i += 1;
    }

    return vC;
}

std::vector<Particle> Particle::createVectorParticle4()
{
    std::vector<Particle> vC;

    Vect pos1 = Vect(400, 200);
    Vect vel1 = Vect(-20, 0);
    Vect pos2 = Vect(500, 200);
    Vect vel2 = Vect(-80, 0);

    Particle c1 = Particle(pos1, vel1, 15);
    Particle c2 = Particle(pos2, vel2, 15);
    vC.push_back(c1);
    vC.push_back(c2);

    return vC;
}