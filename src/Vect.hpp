#pragma once
#include <cmath>

class Vect
{
    public:
        // Coord x
        double x;

        // Coord y
        double y;

        // Construtor padrão.
        // Verificar se é necessário.
        Vect();
        Vect(double coordX, double coordY);
        Vect(Vect first, Vect last);

        Vect operator+ (const Vect& v) const
        {
            return Vect(x + v.x, y + v.y);
        }

        Vect operator- (const Vect& v)
        {
            return Vect(x - v.x, y - v.y);
        }

        double operator* (const Vect& v)
        {
            return x * v.x + y * v.y;
        }

        Vect operator* (const double& value)
        {
            return Vect(x * value, y * value);
        }

        Vect operator/ (const double& value)
        {
            return Vect(x / value, y / value);
        }

        Vect unitVect();
        double Module();
        double VSin();
        double VCos();
        double Argument();
        void IncArgument(double radInc);
};