#include "Mechanics.hpp"

void Mechanics::Move(Body& body, double rDT)
{
    // Posição no instante i + 1 = Posição no instante i + Velocidade * DT Real.
    body.position = body.position + (body.velocity * rDT);
}

void Mechanics::Accelerate(Body& body)
{
    // Nada por enquanto
}

void Mechanics::MustCollide(Body& body1, Body& body2)
{
    // Se o produto escalar entre o vetor formado pelos vetores de posição
    // e o vetor formado pelos vetores de velocidade for maior ou igual
    // a zero, as partículas não estão se aproximando
    if (Vect(body1.position, body1.position) *
        Vect(body1.velocity, body1.velocity) >= 0)
    {
        return false;
    }

    // Se a soma dos raios das partículas for menor que a distância 
    // entre as posições das partículas, não há colisão
    if (body1.radius + body1.radius <
        AppUtils::s_DistanceBetweenParticles(body1, body1))
    {
        return false;
    }

    return true;
}

void Mechanics::DoCollide(Body& body1, Body& body2)
{

}