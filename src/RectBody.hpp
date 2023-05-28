#include "Body.hpp"
#include "Vect.hpp"

class RectBody : public Body
{
    public:
        double height;

        double width;

        // Construtor padrão.
        RectBody();

        RectBody(Vect initialPosition, Vect initalVelocity, Vect initialAcceleration, double height, double width);
};