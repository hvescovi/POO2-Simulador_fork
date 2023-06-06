#include "../hpp/Persistence.hpp"
#include <SDL.h>

bool Persistence::LoadSimulation(AppVar& global)
{
    return true;
}

bool Persistence::SaveResults(AppVar& global)
{
    /*
    COISAS PARA SALVAR
    tempo decorrido da simulação
    tempo limite da simulação
    quantidade de círculos carregados
    quantidade de círculos terminados
    vetor 
    */
    int timeSpent = (SDL_GetTicks() - global.ticksBeforeSimulation) / 1000;
    int timeLimit = global.ticksLimitPerSimulation / 1000;

    return true;
}