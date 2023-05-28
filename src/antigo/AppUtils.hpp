#pragma once
#include <SDL.h>
#include "Vect.hpp"
#include "Particle.hpp"

class AppUtils
{
    public:
        /**
         * Método estático. Desenha um vetor.
         * 
         * \param renderer Renderizador SDL
         * \param initialPos Posição inicial do vetor
         * \param finalPos Posição final do vetor
         */
        static void s_DrawVect(SDL_Renderer* renderer, Vect initialPos, Vect finalPos);

        /**
         * Método estático. Desenha uma partícula.
         * 
         * \param renderer Renderizador SDL
         * \param particle Partícula
         * \param vertexQuantity Quantidade de vértices da partícula
         */
        static void s_DrawParticle(SDL_Renderer* renderer, Particle particle, int vertexQuantity);

        /**
         * Método estático. Calcula a distância entre duas partículas.
         * 
         * \param particle1 Partícula 1
         * \param particle2 Partícula 2
         * \return A distância entre as partículas
         */
        static double s_DistanceBetweenParticles(Particle particle1, Particle particle2);
};