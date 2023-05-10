#include "AppVar.hpp"

AppVar::AppVar():
    fps{},
    ticks{},
    dDT{},
    dT{},
    width{},
    height{},
    vectorParticle{},
    particleVertexQuantity{},
    rDT{}
{}

AppVar::AppVar(int pFps, int pWidth, int pHeigth, int particleVertexQuantity, std::vector<Particle> vectorParticle):
    fps{ pFps },
    ticks{ 0 },
    dDT{ 1000.0 / pFps },
    dT{ 0 },
    width{ pWidth },
    height{ pHeigth },
    vectorParticle{ vectorParticle },
    particleVertexQuantity{ particleVertexQuantity },
    rDT{ 0 }
    //gravity{ Vect(0, 9.80665) }
{}