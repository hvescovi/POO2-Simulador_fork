#pragma once
#include "Vect.hpp"
#include <vector>

class Body
{
    public:
        // Vetor de posição
        Vect position;

        // Vetor de velocidade
        Vect velocity;

        // Vetor de aceleração
        Vect acceleration;

        // Área
        double area;

        // Massa
        double mass;

        //double density;

        // Construtor padrão.
        Body();

        /**
         * Construtor. Inicializa uma partícula.
         *
         * \param initialPosition Vetor de posição inicial
         * \param initalVelocity Vetor de velocidade inicial
         * \param area Área
         */
        Body(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double area);

        // static std::vector<Body> createVectorBody();
};