#pragma once
#include "Vect.hpp"
class Button
{
	private:
		// Posi��o do canto superior esquerdo do bot�o
		Vect position;

		// Largura e altura
		int width, height;

		// Est� pressionado -> Verdadeiro ou Falso
		bool isPressed;

	public:
		// Contrutor vazio.
		Button();

		/**
		 * Construtor. Inicializa um bot�o a partir
		 * de uma posi��o, largura e altura
		 * 
		 * \param position Vetor posi��o
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