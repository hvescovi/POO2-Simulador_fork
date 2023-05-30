#pragma once
#include "RectBody.hpp"
#include "CircumBody.hpp"

class Mechanics
{
    public:
        static void CircumMove          (CircumBody& circum,  double      rDT    );
        static void CircumAccelerate    (CircumBody& circum,  double      rDT    );
        static void CircumCollision     (CircumBody& circum1, CircumBody& circum2);
        static void CircumRectCollision (CircumBody& circum,  RectBody&   rect   );
};