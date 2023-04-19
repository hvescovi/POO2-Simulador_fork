#pragma once
class Vect
/** Vetor. Utiliza-se para representar e calcular grandezas vetoriais. */
{
    private:
        // Coordenada x.
        double x;

        // Coordenada y.
        double y;

    public:
        // Construtor vazio.
        Vect();

        /**
         * Construtor. Inicializa um vetor a partir de uma 
         * coordenada X e uma coordenada Y.
         *
         * \param coordX Coordenada X;
         * \param coordY Coordenada Y.
         */
        Vect(double coordX, double coordY);

        /**
         * Construtor. Inicializa um vetor a partir 
         * de outros dois vetores.
         *
         * \param firstCoords Vetor inicial
         * \param lastCoords Vetor final
         */
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
        /** Produto escalar */
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

        double get_x();
        double get_y();

        // \return Vetor unit�rio
        Vect unitVect();

        /** \return M�dulo do vetor */
        double Module();

        /** \return Seno do argumento do vetor */
        double VSin();

        /** \return Cosseno do argumento do vetor */
        double VCos();

        /** \return Argumento do vetor */
        double Argument();

        /**
         * Altera as coordenadas do vetor de modo
         * a incrementar seu argumento.
         * 
         * \param radInc Incremento em radianos
         * \return void
         */
        void IncArgument(double radInc);
};