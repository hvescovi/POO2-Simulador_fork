#include "RectBody.hpp"
#include "CircumBody.hpp"

class Mechanics
{
    public:
        static void CircumMove           (CircumBody& circum,  double      rDT    );
        static void CircumAccelerate     (CircumBody& circum,  double      rDT    );
        static bool CircumMustCollide    (CircumBody& circum1, CircumBody& circum2);
        static void CircumDoCollide      (CircumBody& circum1, CircumBody& circum2);
        static bool CircumRectMustCollide(CircumBody& circum,  RectBody&   rect   );
        static void CircumRectDoCollide  (CircumBody& circum,  RectBody&   rect   );
};