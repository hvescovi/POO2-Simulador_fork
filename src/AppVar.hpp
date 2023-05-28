#pragma once
#include <vector>
#include "Body.hpp"
#include "SimulationTime.hpp"
#include "RectBody.hpp"
#include "CircumBody.hpp"
using namespace std;

class AppVar
{
    public:
        // Largura da janela SDL.
        int width;

        // Altura da janela SDL.
        int height;

        // Quantidade de vértices para se desenhar as circunferências.
        int circumVertexQuantity;

        // Objeto para manusear o tempo
        SimulationTime ST;

        // Corpos
        vector<RectBody>   rectBodies;
        vector<CircumBody> circumBodies;

        // Construtor vazio.
        AppVar();

        /**
         * Construtor. Inicializa um objeto AppVar responsável 
         * por armazenar variáveis "globais" de App.
         *
         * \param fps Frames por segundo da janela SDL
         * \param width Largura da janela SDL
         * \param heigth Altura da janela SDL
         * \param rectBodies Lista de corpos retangulares
         * \param circumBodies Lista de corpos circulares
         */
        AppVar(int fps, int width, int heigth, int circumVertexQuantity, vector<RectBody> rectBodies, vector<CircumBody> circumBodies);
};