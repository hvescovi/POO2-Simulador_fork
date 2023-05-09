#pragma once
#include "Body.hpp"
#include "Vect.hpp"
#include <vector>

class Particle : public Body
/** Classe que representa uma partícula circular. */
{
    public:
        // Raio da partícula (a partícula é circular)
        double radius;

    public:
        // Construtor padrão.
        Particle();

        /**
         * Construtor. Inicializa uma partícula.
         * 
         * \param initialPosition Vetor de posição inicial
         * \param initalVelocity Vetor de velocidade inicial
         * \param radius Raio
         */
        Particle(Vect initialPosition, Vect initalVelocity, double radius);

        double rad();

        static std::vector<Particle> createVectorParticle1();
        static std::vector<Particle> createVectorParticle2();
        static std::vector<Particle> createVectorParticle3();
        static std::vector<Particle> createVectorParticle4();
};