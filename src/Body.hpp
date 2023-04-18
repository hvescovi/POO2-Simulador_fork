#pragma once
#include "Vect.hpp"
class Body
{
	protected:
		// Vetor de posi��o
		Vect position;

		// Vetor de velocidade
		Vect velocity;

		//Vect acceleration;

		// �rea
		double area;

		// Massa
		double mass;

		//double density;

	public:
		// Construtor padr�o.
		Body();

		/**
		 * Construtor. Inicializa uma part�cula.
		 *
		 * \param initialPosition Vetor de posi��o inicial
		 * \param initalVelocity Vetor de velocidade inicial
		 * \param area �rea
		 */
		Body(Vect initialPosition, Vect initalVelocity, double area);

		Vect get_pos();
		void set_pos(Vect pos);

		Vect get_vel();
		void set_vel(Vect newVel);

		double get_area();
		double get_mass();
};

