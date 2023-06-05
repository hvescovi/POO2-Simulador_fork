#include "../hpp/Vect.hpp"

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
    x{last.x - first.x},
    y{last.y - first.y}
{}

Vect Vect::unitVect()
{
    double vModule = Module();
    return Vect(x, y) / vModule;
}

double Vect::Module() 
{
    return std::sqrt(x * x + y * y);
}

void Vect::setModule(double mod)
{
    double k = mod / Module();

    x = x * k;
    y = y * k;
}

double Vect::s_Distance(Vect& v1, Vect& v2)
{
    return Vect(v1, v2).Module();
}

double Vect::s_AngleBetween(Vect& v1, Vect& v2)
{
    if ((v1.Module() <= 0.5) || (v2.Module() <= 0.5))
        return 0;

    return std::acos((v1 * v2) / (v1.Module() * v2.Module()));
}

double Vect::VSin() 
{ 
    return y / Module(); 
}

double Vect::VCos() 
{
    return x / Module();
}

double Vect::Argument()
{
    double vsin = VSin();
    double vcos = VCos();
    if (vsin < 0.0)
    {
        return 2 * PI - std::acos(vcos);
    }
    else if (vsin > 0.0)
    {
        return std::acos(vcos);
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
    double module = Module();
    double incrementedAlpha = Argument() + radInc;
    x = module * std::cos(incrementedAlpha);
    y = module * std::sin(incrementedAlpha);
}