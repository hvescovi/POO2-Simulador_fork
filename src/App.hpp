#pragma once
#include <SDL.h>
#include "AppVar.hpp"
#include "Particle.hpp"
#include <string>

class App
{
    private:
        // Objeto que armazena vari�veis "globais" de App, como FPS,
        // dimens�es da tela e lista de part�culas.
        AppVar global;

        // Aplica��o em execu��o.
        bool running;

        // Janela SDL.
        SDL_Window* window;

        // Renderizador SDL.
        SDL_Renderer* renderer;

    public:
        // Construtor vazio.
        App();

        /**
         * Inicializa o SDL, vari�veis de App e loop do simulador.
         *
         * \return 0 ao t�rmino da execu��o.
         */
        int Execute();

        /**
         * Inicia funcionalidades do SDL e propriedades de App.
         * Se ocorrer algum erro ao iniciar objetos, este � tratado
         * e o programa para de executar com c�dido de sa�da 1.
         * 
         * \return void
         */
        void OnInit();

        /**
         * � executado antes do loop principal da aplica��o.
         * 
         * \return void
         */
        void OnBeforeLoop();

        /**
         * Trata eventos do SDL.
         * 
         * \param event
         * \return void
         */
        void OnEvent(SDL_Event event);

        /**
         * Executa um la�o que percorre cada part�cula.
         * 
         * \return void
         */
        void OnLoopThroughParticles();

        /**
         * Atualiza a posi��o das part�culas baseando-se em suas
         * velocidades e no tempo entre frames.
         * 
         * \param particle Part�cula
         */
        void OnParticleMove(Particle& particle);

        /**
         * Verifica colis�o entre duas part�culas e, caso haja,
         * calcula as velocidades p�s-colis�o.
         * 
         * \param particle1 Part�cula 1
         * \param particle2 Part�cula 2
         * \return void
         */
        void OnParticleCollision(Particle& particle1, Particle& particle2);

        /**
         * Verifica colis�o entre part�cula e borda e, caso
         * haja, inverte componentes do vetor de velocidade.
         * 
         * \param particle Part�cula
         * \return void
         */
        void OnParticleBorderCollision(Particle& particle);

        /**
         * Limpa a janela SDL.
         * 
         * \return void
         */
        void OnRenderClear();

        /**
         * Atualiza a janela SDL com o renderizador.
         * 
         * \return void
         */
        void OnRenderPresent();

        /**
         * Renderiza uma part�cula.
         * 
         * \param particle
         * \return void
         */
        void OnRenderParticle(Particle particle);

        /**
         * OnTimeDelay mant�m o contador de FPS perto do desejado, uniformizando
         * o comportamento do simulador e economizando recursos.
         * 
         * \return void
         */
        void OnTimeDelay();

        /**
         * Limpa objetos da mem�ria e finaliza o SDL.
         * 
         * \return void
         */
        void OnCleanup();

        std::vector<Particle> LoadFromArchive(std::string filename);
};