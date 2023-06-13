#include "../hpp/App.hpp"
#include <iostream>
#include "../hpp/Mechanics.hpp"
#include "../hpp/Exhibition.hpp"
#include "../hpp/Persistence.hpp"

void App::OnBeforeSimulation()
{
    if (!Persistence::LoadSimulation(global))
        runningProgram = false;

    global.rectBodies = RectBodyVector();
    global.terminatedCircumQty = 0;
    global.circumQty = global.circumBodies.size();
    runningSimulation = true;

    int ticks = SDL_GetTicks();
    global.ST.ticks = ticks;
    global.ticksBeforeSimulation = ticks;

    OnRenderClear();
    OnLoopThroughBodies();
    OnRenderPresent();

    global.ST.Delay();
    SDL_Delay((Uint32)1000);
}

void App::OnAfterSimulation()
{
    if (!Persistence::SaveResults(global))
        runningProgram = false;
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
                    runningSimulation = false;
                    runningProgram    = false;
                    break;

                default: break;
            }
            break;

        case SDL_QUIT:
            runningSimulation = false;
            runningProgram    = false;
            break;

        default: break;
    }
}

void App::OnInit()
{
    global = AppVar(
        60, 
        1280, 
        720, 
        30000, 
        24, 
        RectBodyVector(), 
        CBVExample2()
    );

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
    int circumSize = global.circumBodies.size();

    if (circumSize == 0)
    {
        runningSimulation = false;
        return;
    }

    int i = 0;
    int j = 0;
    int rectSize   = global.rectBodies.size();
    bool drawRects = true;
    while (i < circumSize)
    {
        Mechanics::CircumMove(global.circumBodies[i], global.ST.rDT);
        Mechanics::CircumAccelerate(global.circumBodies[i], global.ST.rDT);

        Exhibition::DisplayCircumBody(renderer, global.circumBodies[i], global.circumVertexQuantity, i);

        // Exhibition::DisplayVector(
        //     renderer, 
        //     global.circumBodies[i].position, 
        //     global.circumBodies[i].position + global.circumBodies[i].velocity
        // );

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

        Mechanics::AttractToTerminator(global.circumBodies[i], global.rectBodies, 30);

        drawRects = false;

        i += 1;
    }

    // Outro laço para remover do vetor de corpos circulares
    // aqueles que estão terminados
    i = 0;
    while (i < circumSize)
    {
        if (global.circumBodies[i].terminated)
        {
            global.circumBodies.erase(global.circumBodies.begin() + i);
            global.terminatedCircumQty += 1;
        }

        i += 1;
    }
}

std::vector<CircumBody> App::CBVExample1()
{
    vector<CircumBody> v;

    // v.push_back(CircumBody(Vect(140, 240), Vect(20, 20), Vect(0, 10), 30));

    int i = 1;
    int j = 1;
    while (i <= 22)
    {
        j = 1;
        while (j <= 17 )
        {
            v.push_back(CircumBody(Vect(50 + (i * 30), 20 + (j * 30)), Vect(i * 2, 0), Vect(0, 0), 5 + j / 3, 30));
            j += 1;
        }
        i += 1;
    }

    return v;
}

std::vector<CircumBody> App::CBVExample2()
{
    vector<CircumBody> v;

    v.push_back(CircumBody(Vect(100, 300), Vect(0, -60), Vect(0, 0), 100, 3000));

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
    v.push_back(RectBody(Vect(30,  400), Vect(0, 0), Vect(0, 0), 100, 20 ));
    v.push_back(RectBody(Vect(400, 120), Vect(0, 0), Vect(0, 0), 20,  350));
    v.push_back(RectBody(Vect(10,  200), Vect(0, 0), Vect(0, 0), 20,  200, true));
    // v.push_back(RectBody(Vect(770, 200), Vect(0, 0), Vect(0, 0), 20,  200, true));

    return v;
}

std::vector<RectBody> App::RectBodyVector()
{
    vector<RectBody> v;

    int w = global.width;
    int h = global.height;

    // Bordas
    v.push_back(RectBody(Vect(0,            0), Vect(0, 0), Vect(0, 0), w/2-100, 30)); // Acima Esq.
    v.push_back(RectBody(Vect(w/2+100,      0), Vect(0, 0), Vect(0, 0), w/2-100, 30)); // Acima Dir.

    v.push_back(RectBody(Vect(0,         h-30), Vect(0, 0), Vect(0, 0), w/3-100, 30)); // Abaixo Esq.
    v.push_back(RectBody(Vect(w/3+100,   h-30), Vect(0, 0), Vect(0, 0), w/3-200, 30)); // Abaixo Meio
    v.push_back(RectBody(Vect(2*w/3+100, h-30), Vect(0, 0), Vect(0, 0), w/3-100, 30)); // Abaixo Dir.

    v.push_back(RectBody(Vect(0,            0), Vect(0, 0), Vect(0, 0), 30,  h/2-50)); // Lateral Esq. Acima
    v.push_back(RectBody(Vect(0,       h/2+50), Vect(0, 0), Vect(0, 0), 30,  h     )); // Lateral Esq. Abaixo

    v.push_back(RectBody(Vect(w-30,         0), Vect(0, 0), Vect(0, 0), 30,  h/2-50)); // Lateral Dir. Acima
    v.push_back(RectBody(Vect(w-30,    h/2+50), Vect(0, 0), Vect(0, 0), 30,  h     )); // Lateral Dir. Abaixo

    switch(global.simulationRectTemplate)
    {
        case 1:
            v.push_back(RectBody(Vect(w/2-100, 0), Vect(0, 0), Vect(0, 0), 50, 30));
            v.push_back(RectBody(Vect(w/2+50, 0), Vect(0, 0), Vect(0, 0), 50, 30));

            v.push_back(RectBody(Vect(w/3-100, h-30), Vect(0, 0), Vect(0, 0), 200, 30));
            v.push_back(RectBody(Vect(2*w/3-100, h-30), Vect(0, 0), Vect(0, 0), 200, 30));

            v.push_back(RectBody(Vect(0, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));
            v.push_back(RectBody(Vect(w-30, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));

            v.push_back(RectBody(Vect(w/2-50, 0), Vect(0, 0), Vect(0, 0), 100, 10, true));
            break;

        case 2:
            v.push_back(RectBody(Vect(w/3-100, h-30), Vect(0, 0), Vect(0, 0), 200, 30));
            v.push_back(RectBody(Vect(2*w/3-100, h-30), Vect(0, 0), Vect(0, 0), 200, 30));

            v.push_back(RectBody(Vect(0, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));
            v.push_back(RectBody(Vect(w-30, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));

            v.push_back(RectBody(Vect(w/2-100, 0), Vect(0, 0), Vect(0, 0), 200, 10, true));
            break;

        case 3:
            v.push_back(RectBody(Vect(w/3-100, h-30), Vect(0, 0), Vect(0, 0), 50, 30));
            v.push_back(RectBody(Vect(w/3+50, h-30), Vect(0, 0), Vect(0, 0), 50, 30));
            v.push_back(RectBody(Vect(2*w/3-100, h-30), Vect(0, 0), Vect(0, 0), 50, 30));
            v.push_back(RectBody(Vect(2*w/3+50, h-30), Vect(0, 0), Vect(0, 0), 50, 30));

            v.push_back(RectBody(Vect(0, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));
            v.push_back(RectBody(Vect(w-30, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));

            v.push_back(RectBody(Vect(w/2-100, 0), Vect(0, 0), Vect(0, 0), 200, 30));

            v.push_back(RectBody(Vect(w/3-50, h-10), Vect(0, 0), Vect(0, 0), 100, 10, true));
            v.push_back(RectBody(Vect(2*w/3-50, h-10), Vect(0, 0), Vect(0, 0), 100, 10, true));
            break;

        case 4:
            v.push_back(RectBody(Vect(w/3-100, h-10), Vect(0, 0), Vect(0, 0), 200, 10, true));
            v.push_back(RectBody(Vect(2*w/3-100, h-10), Vect(0, 0), Vect(0, 0), 200, 10, true));

            v.push_back(RectBody(Vect(0, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));
            v.push_back(RectBody(Vect(w-30, h/2-50), Vect(0, 0), Vect(0, 0), 30, 100));

            v.push_back(RectBody(Vect(w/2-100, 0), Vect(0, 0), Vect(0, 0), 200, 30));
            break;

        case 5:
            v.push_back(RectBody(Vect(w/3-100, h-30), Vect(0, 0), Vect(0, 0), 200, 30));
            v.push_back(RectBody(Vect(2*w/3-100, h-30), Vect(0, 0), Vect(0, 0), 200, 30));

            v.push_back(RectBody(Vect(0, h/2-50), Vect(0, 0), Vect(0, 0), 10, 100, true));
            v.push_back(RectBody(Vect(w-10, h/2-50), Vect(0, 0), Vect(0, 0), 10, 100, true));

            v.push_back(RectBody(Vect(w/2-100, 0), Vect(0, 0), Vect(0, 0), 200, 30));
            break;

        default:
            runningSimulation = false;
            break;
    }

    return v;
}