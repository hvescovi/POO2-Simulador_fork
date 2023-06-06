#pragma once
#include <vector>
#include "AppVar.hpp"

class Persistence
{
    public:
        static bool LoadSimulation(AppVar &global);
        static bool SaveResults(AppVar& global);
};