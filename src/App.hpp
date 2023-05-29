#pragma once
#include <SDL.h>
#include "AppVar.hpp"
#include <string>

class App
{
    public:
        // Objeto que armazena variáveis "globais" de App, como FPS,
        // dimensões da tela e lista de partículas.
        AppVar global;

        // Aplicação em execução.
        bool running;

        // Janela SDL.
        SDL_Window* window;

        // Renderizador SDL.
        SDL_Renderer* renderer;

        // Construtor vazio.
        App();

        /**
         * Inicia a simulação.
         *
         * \return 0 ao término da execução
         */
        int Execute();

        /** 
         * Inicia funcionalidades do SDL e propriedades de App.
         * Se ocorrer algum erro ao iniciar objetos, este é tratado
         * e o programa para de executar com códido de saída 1.
         */
        void OnInit();

        /**
         * É executado antes do loop principal da aplicação.
         */
        void OnBeforeLoop();

        /**
         * Trata eventos do SDL.
         * 
         * \param event
         */
        void OnEvent(SDL_Event event);

        /**
         * Executa um loop que percorre cada corpo.
         */
        void OnLoopThroughBodies();

        /**
         * Limpa a janela SDL.
         */
        void OnRenderClear();

        /**
         * Atualiza a janela SDL com o renderizador.
         */
        void OnRenderPresent();

        /**
         * Limpa objetos da memória e finaliza o SDL.
         */
        void OnCleanup();

        std::vector<CircumBody> CBVExample1();
        std::vector<RectBody> RBVExample1(int width, int height);
};