#pragma once
#include "Body.hpp"
#include "Vect.hpp"
#include <vector>

class Particle : public Body
/** Classe que representa uma part�cula circular. */
{
    private:
        // Raio da part�cula (a part�cula � circular)
        double radius;

    public:
        // Construtor padr�o.
        Particle();

        /**
         * Construtor. Inicializa uma part�cula.
         * 
         * \param initialPosition Vetor de posi��o inicial
         * \param initalVelocity Vetor de velocidade inicial
         * \param radius Raio
         */
        Particle(Vect initialPosition, Vect initalVelocity, double radius);

        double get_rad();

        static std::vector<Particle> createVectorParticle1();
        static std::vector<Particle> createVectorParticle2();
        static std::vector<Particle> createVectorParticle3();
        static std::vector<Particle> createVectorParticle4();
};