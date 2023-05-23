#pragma once
#include "Vect.hpp"

class Body
{
    public:
        // Vetor de posição
        Vect position;

        // Vetor de velocidade
        Vect velocity;

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
        Body(Vect initialPosition, Vect initalVelocity, double area);
};