#pragma once
#include <vector>
#include "Body.hpp"
#include "SimulationTime.hpp"

class AppVar
{
    public:
        // Largura da janela SDL.
        int width;

        // Altura da janela SDL.
        int height;

        // Quantidade de vértices para se desenhar as partículas.
        int particleVertexQuantity;

        // Objeto para manusear o tempo
        SimulationTime ST;

        // Corpos
        std::vector<Body> bodies;

        // Construtor vazio.
        AppVar();

        /**
         * Construtor. Inicializa um objeto AppVar responsável 
         * por armazenar variáveis "globais" de App.
         *
         * \param fps Frames por segundo da janela SDL
         * \param width Largura da janela SDL
         * \param heigth Altura da janela SDL
         * \param bodies Lista de corpos
         */
        AppVar(int fps, int width, int heigth, int particleVertexQuantity, std::vector<Body> bodies);
};