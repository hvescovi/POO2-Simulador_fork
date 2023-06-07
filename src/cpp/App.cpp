#include "../hpp/App.hpp"
#include <string.h>
#include <iostream>
using namespace std;

App::App():
    global{},
    window{ NULL },
    renderer{ NULL },
    runningProgram{ true },
    runningSimulation{ true }
{}

int App::Execute()
{
    OnInit();

    // Estrutura que contém informações sobre eventos
    SDL_Event event;

    // Laço de repetição do programa
    while (runningProgram) 
    {
        // Carrega simulação
        OnBeforeSimulation();

        // Laço de repetição da simulação atual
        while (runningSimulation)
        {
            // Ticks atuais da execução do SDL. É utilizado em OnTimeDelay
            global.ST.ticks = SDL_GetTicks();

            // Checa por eventos e os percorre um por vez a partir de uma fila.
            // A fila é preenchida por eventos toda vez que o SDL detecta um input.
            // Lista de eventos : https://wiki.libsdl.org/SDL_Event#data_fields.
            while (SDL_PollEvent(&event))
            {
                OnEvent(event);
            }

            OnRenderClear();

            OnLoopThroughBodies();

            OnRenderPresent();

            if ((SDL_GetTicks() - global.ticksBeforeSimulation) >= global.ticksLimitPerSimulation)
                runningSimulation = false;

            global.ST.Delay();
        }

        // Salva dados da simulação
        OnAfterSimulation();
    }

    OnCleanup();

    return 0;
}
