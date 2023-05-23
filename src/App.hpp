#pragma once
#include <SDL.h>
#include "AppVar.hpp"
#include "Particle.hpp"
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
         * Executa um loop que percorre cada partícula.
         */
        void OnLoopThroughParticles();

        /**
         * Atualiza a posição das partículas baseando-se em suas
         * velocidades e no tempo entre frames.
         * 
         * \param particle Partícula
         */
        void OnParticleMove(Particle& particle);

        /**
         * Verifica colisão entre duas partículas e, caso haja,
         * calcula as velocidades pós-colisão.
         * 
         * \param particle1 Partícula 1
         * \param particle2 Partícula 2
         */
        void OnParticleCollision(Particle& particle1, Particle& particle2);

        /**
         * Verifica colisão entre partícula e borda e, caso
         * haja, inverte componentes do vetor de velocidade.
         * 
         * \param particle Partícula
         */
        void OnParticleBorderCollision(Particle& particle);

        /**
         * Limpa a janela SDL.
         */
        void OnRenderClear();

        /**
         * Atualiza a janela SDL com o renderizador.
         */
        void OnRenderPresent();

        /**
         * Renderiza uma partícula.
         * 
         * \param particle
         */
        void OnRenderParticle(Particle particle);

        /**
         * OnTimeDelay mantém o contador de FPS perto do desejado, uniformizando
         * o comportamento do simulador e economizando recursos.
         */
        void OnTimeDelay();

        /**
         * Limpa objetos da memória e finaliza o SDL.
         */
        void OnCleanup();

        std::vector<Particle> LoadFromArchive(std::string filename);
};