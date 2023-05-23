#pragma once
#include "Vect.hpp"
class Button
{
    public:
        // Posição do canto superior esquerdo do botão
        Vect position;

        // Largura e altura
        int width, height;

        // Está pressionado -> Verdadeiro ou Falso
        bool isPressed;

        // Contrutor vazio.
        Button();

        /**
         * Construtor. Inicializa um botão a partir
         * de uma posição, largura e altura
         * 
         * \param position Vetor posição
         * \param width Largura
         * \param height Altura
         */
        Button(Vect position, int width, int height);

        Vect get_pos();
        int get_w();
        int get_h();

        bool get_isPressed();
        void not_isPressed();
};