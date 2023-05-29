#include "AppVar.hpp"

AppVar::AppVar():
    width{},
    height{},
    rectBodies{},
    circumBodies{},
    circumVertexQuantity{},
    ST{}
{}

AppVar::AppVar(int pFps, int pWidth, int pHeigth, int circumVertexQuantity, vector<RectBody> rectBodies, vector<CircumBody> circumBodies):
    width{ pWidth },
    height{ pHeigth },
    rectBodies{ rectBodies },
    circumBodies{ circumBodies },
    circumVertexQuantity{ circumVertexQuantity },
    ST{pFps}
    //gravity{ Vect(0, 9.80665) }
{}