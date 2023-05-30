#include "../hpp/SimulationTime.hpp"
#include <SDL.h>

SimulationTime::SimulationTime():
    fps{ 0 },
    ticks{ 0 },
    dDT{ 0 },
    dT{ 0 },
    rDT{ 0 }
{}

SimulationTime::SimulationTime(int fps):
    fps{ fps },
    ticks{ 0 },
    dDT{ 1000.0 / fps },
    dT{ 0 },
    rDT{ 0 }
{}

void SimulationTime::Delay()
{
    // dT recebe a diferença de ticks entre o começo da
    // execução do laço e o final
    dT = SDL_GetTicks() - ticks;

    if (dT < dDT)
    {
        // Pausa a execução por um tempo para o FPS atingir
        // valores próximos ao desejado
        SDL_Delay((Uint32)(dDT - dT));
    }

    // Mostra o FPS atual
    //std::cout << "FPS: " << 1000 / (SDL_GetTicks() - global.get_ticks()) << std::endl;

    // rDT recebe a diferençaa REAL de ticks entre o começo
    // da execução do laço e o final. (O tempo de execução 
    // deste método também é relevante!)
    rDT = (SDL_GetTicks() - ticks) / 1000.0;
}