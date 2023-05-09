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

        Vect pos() const;
        Vect vel() const;
        double a() const;
        double m() const;
};