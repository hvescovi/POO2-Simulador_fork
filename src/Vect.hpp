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

        /**
         * Construtor. Inicializa um Vetor
         * 
         * \param coordX Coordenada X do vetor
         * \param coordY Coordenada Y do vetor 
        */
        Vect(double coordX, double coordY);
        
        /**
         * Construtor. Inicializa um Vetor com base em dois vetores,
         * onde o 'first' é o início do primeiro vetor, que servirá como 
         * origem (0,0) e o 'last' é o final do vetor.
         * Em suma, o cálculo fica {last - first}.
         * 
         * \param first Vetor inicial
         * \param last Vetor final
        */
        Vect(Vect first, Vect last);

        /**
         * Sobrecarga de operador de soma.
         * Ele soma o vetor com o vetor passado de parâmetro.
         * 
         * \param v Vetor passado por parâmetro
         * 
         * \return Vect
        */
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