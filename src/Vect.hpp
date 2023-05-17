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
         * 
         * 
         * \param v Vetor do lado direito do operador de soma
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

        /**
         * Vetor unitário do vetor
         * 
         * \return Vect
        */
        Vect unitVect();

        /**
         * Módulo do vetor.
         * 
         * \return double 
        */
        double Module();

        /**
         * Retorna o seno do ângulo do vetor em
         * relação ao eixo X.
         * 
         * \return double
        */
        double VSin();

        /**
         * Retorna o cosseno do ângulo do vetor em
         * relação ao eixo Y.
         * 
         * \return double
        */
        double VCos();

        double Argument();

        void IncArgument(double radInc);
};