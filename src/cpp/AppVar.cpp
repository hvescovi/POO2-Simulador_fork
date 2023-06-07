#include "../hpp/AppVar.hpp"

AppVar::AppVar():
    width{},
    height{},
    simulationFileIndex{},
    simulationRectTemplate{},
    ticksLimitPerSimulation{},
    circumQty{},
    terminatedCircumQty{},
    circumVertexQuantity{},
    rectBodies{},
    circumBodies{},
    ST{}
{}

AppVar::AppVar(int pFps, int pWidth, int pHeigth, int ticksLimitPerSimulation, int circumVertexQuantity, vector<RectBody> rectBodies, vector<CircumBody> circumBodies):
    width{ pWidth },
    height{ pHeigth },
    simulationFileIndex{ 0 },
    simulationRectTemplate{ 1 },
    ticksLimitPerSimulation{ ticksLimitPerSimulation },
    circumQty{ 0 },
    terminatedCircumQty{ 0 },
    circumVertexQuantity{ circumVertexQuantity },
    rectBodies{ rectBodies },
    circumBodies{ circumBodies },
    ST{pFps}
    //gravity{ Vect(0, 9.80665) }
{}