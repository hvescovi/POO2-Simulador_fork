#include "Vect.hpp"
#include <cmath>
#define PI 3.1415926535897932384626433832795

Vect::Vect():
    x{0},
    y{0}
{}

Vect::Vect(double coordX, double coordY):
    x{coordX},
    y{coordY}
{}

Vect::Vect(Vect first, Vect last):
    x{last.get_x() - first.get_x()},
    y{last.get_y() - first.get_y()}
{}

double Vect::get_x() { return x; }
double Vect::get_y() { return y; }

Vect Vect::unitVect()
{
    double vModule = this->Module();
    return Vect(x, y) / vModule;
}

double Vect::Module() 
{
    return pow(pow(x, 2.0) + pow(y, 2.0), 0.5);
}

double Vect::VSin() 
{ 
    return y / this->Module(); 
}

double Vect::VCos() 
{
    return x / this->Module();
}

double Vect::Argument()
{
    double vsin = this->VSin();
    double vcos = this->VCos();
    if (vsin < 0.0)
    {
        return 2 * PI - acos(vcos);
    }
    else if (vsin > 0.0)
    {
        return acos(vcos);
    }
    else if (vsin == 0.0 && vcos == 1.0)
    {
        return 0.0;
    }
    else //if (vsin == 0.0 && vcos == -1.0)
    {
        return PI;
    }
}

void Vect::IncArgument(double radInc)
{
    double module = this->Module();
    double incrementedAlpha = this->Argument() + radInc;
    x = module * cos(incrementedAlpha);
    y = module * sin(incrementedAlpha);
}
