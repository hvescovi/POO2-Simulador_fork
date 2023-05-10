#pragma once
#include "Vect.hpp"
class Body
{
    public:
        // Vetor de posi��o
        Vect position;

        // Vetor de velocidade
        Vect velocity;

        //Vect acceleration;

        // �rea
        double area;

        // Massa
        double mass;

        //double density;

        // Construtor padr�o.
        Body();

        /**
         * Construtor. Inicializa uma part�cula.
         *
         * \param initialPosition Vetor de posi��o inicial
         * \param initalVelocity Vetor de velocidade inicial
         * \param area �rea
         */
        Body(Vect initialPosition, Vect initalVelocity, double area);
};