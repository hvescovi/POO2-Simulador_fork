#include "App.hpp"
#include "AppUtils.hpp"
#include <iostream>
#include "Mechanics.hpp"
#include "Exhibition.hpp"

void App::OnBeforeLoop()
{
    global.ST.ticks = SDL_GetTicks();
    OnRenderClear();
    OnLoopThroughBodies();
    OnRenderPresent();
    global.ST.Delay();
    SDL_Delay((Uint32)2000);
}

void App::OnCleanup() 
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::OnEvent(SDL_Event event) 
{
    // Tipo de evento
    switch (event.type) 
    {
        // Tecla pressionada
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) 
            {
                // Escape (Esc)
                case SDLK_ESCAPE:
                    running = false;
                    break;

                default: break;
            }
            break;

        case SDL_QUIT:
            running = false;
            break;

        default: break;
    }
}

void App::OnInit()
{
    global = AppVar(60, 800, 600, 24, Body::createVectorBody());

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        std::cout << "SDL não pôde ser inicializado. " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow(
        "Simulador",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        global.width,
        global.height,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) 
    {
        std::cout << "A janela SDL está com valor nulo. " << SDL_GetError() << std::endl;
        exit(1);
    }

    if (renderer == NULL)
    {
        std::cout << "O renderizador SDL está com valor nulo. " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void App::OnRenderClear()
{
    // Seta a cor atual para preto e o alfa para o máximo
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    // Preenche a tela com a cor atual
    SDL_RenderClear(renderer);
}

void App::OnRenderPresent()
{
    //Atualiza a janela com o renderizador
    SDL_RenderPresent(renderer);
}

void App::OnLoopThroughBodies()
{
    int i = 0;
    int j = 0;
    int size = (int)global.bodies.size();
    while (i < size)
    {
        Mechanics::Move(global.bodies[i], global.ST.rDT);
        // OnParticleBorderCollision(global.bodies[i]);

        j = 0;
        while (j < size)
        {
            // Não se pode verificar colisão de um círculo com ele mesmo
            if (i == j)
            {
                j += 1;
                continue;
            }

            // OnParticleCollision(global.bodies[i], global.bodies[j]);

            j += 1;
        }

        // OnRenderParticle(global.bodies[i]);

        i += 1;
    }
}