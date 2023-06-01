#include "../hpp/App.hpp"
#include <iostream>
#include "../hpp/Mechanics.hpp"
#include "../hpp/Exhibition.hpp"

void App::OnBeforeLoop()
{
    global.ST.ticks = SDL_GetTicks();
    OnRenderClear();
    OnLoopThroughBodies();
    OnRenderPresent();
    global.ST.Delay();
    SDL_Delay((Uint32)1000);
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
    global = AppVar(60, 800, 600, 24, RBVExample1(800, 600), CBVExample1());

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
    int circumSize = global.circumBodies.size();
    int rectSize   = global.rectBodies.size();
    bool drawRects = true;
    while (i < circumSize)
    {
        Mechanics::CircumMove(global.circumBodies[i], global.ST.rDT);
        Mechanics::CircumAccelerate(global.circumBodies[i], global.ST.rDT);

        Exhibition::DisplayCircumBody(renderer, global.circumBodies[i], global.circumVertexQuantity, i);

        Exhibition::DisplayVector(
            renderer, 
            global.circumBodies[i].position, 
            global.circumBodies[i].position + global.circumBodies[i].velocity
        );

        j = 0;
        while (j < circumSize)
        {
            // Não se pode verificar colisão de um círculo com ele mesmo
            if (i == j)
            {
                j += 1;
                continue;
            }

            Mechanics::CircumCollision(global.circumBodies[i], global.circumBodies[j]);

            j += 1;
        }

        j = 0;
        while (j < rectSize)
        {
            Mechanics::CircumRectCollision(global.circumBodies[i], global.rectBodies[j]);

            if (drawRects)
                Exhibition::DisplayRectBody(renderer, global.rectBodies[j]);

            j += 1;
        }

        Mechanics::AttractToTerminator(global.circumBodies[i], global.rectBodies, 5);

        drawRects = false;

        i += 1;
    }

    // Outro laço para remover do vetor de corpos circulares
    // aqueles que estão terminados
    i = 0;
    while (i < circumSize)
    {
        if (global.circumBodies[i].terminated)
            global.circumBodies.erase(global.circumBodies.begin() + i);

        i += 1;
    }
}

std::vector<CircumBody> App::CBVExample1()
{
    vector<CircumBody> v;

    // v.push_back(CircumBody(Vect(140, 240), Vect(20, 20), Vect(0, 10), 30));

    int i = 1;
    int j = 1;
    while (i <= 13)
    {
        j = 1;
        while (j <= 7)
        {
            v.push_back(CircumBody(Vect(50 + (i * 50), 20 + (j * 70)), Vect(i * 2, 0), Vect(0, 0), 10 + i + j));
            j += 1;
        }
        i += 1;
    }

    return v;
}

std::vector<RectBody> App::RBVExample1(int width, int height)
{
    vector<RectBody> v;

    // Bordas
    v.push_back(RectBody(Vect(0, 0),           Vect(0, 0), Vect(0, 0), width, 10 ));
    v.push_back(RectBody(Vect(0, height - 10), Vect(0, 0), Vect(0, 0), width, 10 ));
    v.push_back(RectBody(Vect(0, 0),           Vect(0, 0), Vect(0, 0), 10, height));
    v.push_back(RectBody(Vect(width - 10, 0),  Vect(0, 0), Vect(0, 0), 10, height));

    // Teste
    v.push_back(RectBody(Vect(150, 250), Vect(0, 0), Vect(0, 0), 200, 100));
    v.push_back(RectBody(Vect(30, 400),  Vect(0, 0), Vect(0, 0), 100, 20 ));
    v.push_back(RectBody(Vect(400, 120), Vect(0, 0), Vect(0, 0), 20,  350));
    v.push_back(RectBody(Vect(700, 10),  Vect(0, 0), Vect(0, 0), 15,  420, true));

    return v;
}