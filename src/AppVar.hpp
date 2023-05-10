#pragma once
#include <vector>
#include "Particle.hpp"

class AppVar
/** Vari�veis "globais" de App */
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

        // Quantidade de v�rtices para se desenhar as part�culas.
        int particleVertexQuantity;

        // Part�culas.
        std::vector<Particle> vectorParticle;

        // Construtor vazio.
        AppVar();

        /**
         * Construtor. Inicializa um objeto AppVar respons�vel 
         * por armazenar vari�veis "globais" de App.
         *
         * \param fps Frames por segundo da janela SDL
         * \param width Largura da janela SDL
         * \param heigth Altura da janela SDL
         * \param vectorParticle Lista de part�culas
         */
        AppVar(int fps, int width, int heigth, int particleVertexQuantity, std::vector<Particle> vectorParticle);
};