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
         * onde o 'first' é o primeiro vetor, que servirá como 
         * origem (0,0) e o 'last' é o outro vetor.
         * Em suma, o cálculo fica {last - first}.
         * 
         * \param first Vetor inicial
         * \param last Vetor final
        */
        Vect(Vect first, Vect last);

        /**
         * \return (v1.x + v2.x, v1.y + v2.y)
        */
        Vect operator+ (const Vect& v) const
        {
            return Vect(x + v.x, y + v.y);
        }

        /**
         * \return (v1.x - v2.x, v1.y - v2.y)
        */
        Vect operator- (const Vect& v)
        {
            return Vect(x - v.x, y - v.y);
        }

        /**
         * \return v1.x * v2.x + v1.y * v2.y (Produto escalar)
        */
        double operator* (const Vect& v)
        {
            return x * v.x + y * v.y;
        }

        /**
         * \return (v.x * valor, v.y * valor)
        */
        Vect operator* (const double& value)
        {
            return Vect(x * value, y * value);
        }

        /**
         * \return (v.x / valor, v.y / valor)
        */
        Vect operator/ (const double& value)
        {
            return Vect(x / value, y / value);
        }

        /**
         * \return Vetor unitário do vetor-instância
        */
        Vect unitVect();

        /**
         * \return Módulo do vetor
        */
        double Module();

        void setModule(double mod);

        static double s_Distance(Vect& v1, Vect& v2);

        static double s_AngleBetween(Vect& v1, Vect& v2);

        /**
         * \return Seno do argumento do vetor
        */
        double VSin();

        /**
         * \return Cosseno do argumento do vetor
        */
        double VCos();

        /**
         * \return Argumento do vetor (ângulo em relação à
         * parte positiva do eixo X)
        */
        double Argument();

        /**
         * Rotaciona o vetor. Mais precisamente, incrementa seu argumento
         * 
         * \param radInc Incremento desejado em radianos
        */
        void IncArgument(double radInc);
};