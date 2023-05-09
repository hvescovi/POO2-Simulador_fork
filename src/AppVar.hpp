#pragma once
#include <vector>
#include "Particle.hpp"

class AppVar
/** Variáveis "globais" de App */
{
    private:
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

        int get_fps();

        int get_ticks();
        void set_ticks(int ticks);

        double get_dDT();

        int get_dT();
        void set_dT(int dT);

        double get_rDT();
        void set_rDT(double rDT);

        int get_width();
        int get_heigth();
        int get_halfWidth();
        int get_halfHeigth();

        int get_particleVertexQuantity();
};

