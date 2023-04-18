#pragma once
#include <SDL.h>
#include "Vect.hpp"
#include "Particle.hpp"

class AppUtils
{
    public:
        /**
         * Est�tico. Desenha um vetor.
         * 
         * \param renderer Renderizador SDL
         * \param initialPos Posi��o inicial do vetor
         * \param finalPos Posi��o final do vetor
         * \return void
         */
        static void s_DrawVect(SDL_Renderer* renderer, Vect initialPos, Vect finalPos);

        /**
         * Est�tico. Desenha uma part�cula.
         * 
         * \param renderer Renderizador SDL
         * \param particle Part�cula
         * \param vertexQuantity Quantidade de v�rtices da part�cula
         * \return void
         */
        static void s_DrawParticle(SDL_Renderer* renderer, Particle particle, int vertexQuantity);

        /**
         * Calcula a dist�ncia entre duas part�culas.
         * 
         * \param particle1 Part�cula 1
         * \param particle2 Part�cula 2
         * \return double Dist�ncia entre as part�culas
         */
        static double s_DistanceBetweenParticles(Particle particle1, Particle particle2);
};