#pragma once
#include <vector>
#include "Particle.hpp"

class AppVar
/** Variáveis "globais" de App */
{
    public:
        // Frames por segundo da janela SDL.
        int fps;
        
        // Ticks atuais do SDL.
        int ticks;

        // Delta desejado.
        double dDT;

        // Delta do loop.
        int dT;

        // Delta real.
        double rDT;

        // Largura da janela SDL.
        int width;

        // Altura da janela SDL.
        int height;

        // Quantidade de vértices para se desenhar as partículas.
        int particleVertexQuantity;

        // Part�culas.
    public:
        // Partículas.
        std::vector<Particle> vectorParticle;

        // Construtor vazio.
        AppVar();

        /**
         * Construtor. Inicializa um objeto AppVar responsável 
         * por armazenar variáveis "globais" de App.
         *
         * \param fps Frames por segundo da janela SDL
         * \param width Largura da janela SDL
         * \param heigth Altura da janela SDL
         * \param vectorParticle Lista de partículas
         */
        AppVar(int fps, int width, int heigth, int particleVertexQuantity, std::vector<Particle> vectorParticle);
};