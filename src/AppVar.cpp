#include "AppVar.hpp"

AppVar::AppVar():
    width{},
    height{},
    bodies{},
    particleVertexQuantity{},
    ST{}
{}

AppVar::AppVar(int pFps, int pWidth, int pHeigth, int particleVertexQuantity, std::vector<Body> bodies):
    width{ pWidth },
    height{ pHeigth },
    bodies{ bodies },
    particleVertexQuantity{ particleVertexQuantity },
    ST{pFps}
    //gravity{ Vect(0, 9.80665) }
{}