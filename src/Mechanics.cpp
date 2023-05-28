#include "Mechanics.hpp"
#include <typeinfo>

void Mechanics::CircumMove(CircumBody& circum, double rDT)
{
    // Posição no instante i + 1 = Posição no instante i + Velocidade * DT Real.
    circum.position = circum.position + (circum.velocity * rDT);
}

void Mechanics::CircumAccelerate(CircumBody& circum, double rDT)
{
    // Velocidade no instante i + 1 = Velocidade no instante i + Aceleração * DT Real.
    circum.velocity = circum.velocity + (circum.acceleration * rDT);
}

bool Mechanics::CircumMustCollide(CircumBody& circum1, CircumBody& circum2)
{
    // Se o produto escalar entre o vetor formado pelos vetores de posição
    // e o vetor formado pelos vetores de velocidade for maior ou igual
    // a zero, os corpos circulares não estão se aproximando
    if (Vect(circum1.position, circum2.position) *
        Vect(circum1.velocity, circum2.velocity) >= 0)
    {
        return false;
    }

    // Se a soma dos raios dos corpos circulares for menor que a distância 
    // entre as posições deles, não há colisão
    if (circum1.radius + circum2.radius <
        Vect::s_Distance(circum1.position, circum2.position))
    {
        return false;
    }

    return true;
}

void Mechanics::CircumDoCollide(CircumBody& circum1, CircumBody& circum2)
{
    // Para maiores esclarecimentos,
    // https://www.vobarian.com/collisions/2dcollisions2.pdf

    // Acrônimos:
    // v  -> Vetor
    // uV -> Vetor unitário
    // 1  -> Referente ao corpo circular 1
    // 2  -> Referente ao corpo circular 2
    // N  -> Normal (perpendicular)
    // T  -> Tangente
    // B  -> Before collision (Antes da colisão)
    // A  -> After collision (Depois da colisão)
    // c  -> Componente (grandeza escalar)
    // m  -> Massa

    // Passo 1 - Achar vetor unitário normal e vetor unitário tangente.
    // Eles formam "eixos" que serão utilizados em passos seguintes

    // "Eixo y"
    Vect uVN = Vect(circum1.position, circum2.position).unitVect();
    
    // "Eixo x"
    Vect uVT = Vect(-uVN.y, uVN.x);

    // Passo 2 - Criar os vetores de velocidade inicial 
    // (antes da colisão) de ambos os corpos circulares. 
    // OBS: Eles já existem (obj_corpo_circular.velocidade)

    // Passo 3 - Projetar os vetores de velocidade inicial
    // nos vetores unitários normal e tangente.
    // Isto pode ser feito ao efetuar o produto escalar entre
    // os vetores unitários e os vetores de velocidade
    double v1NBc = uVN * circum1.velocity;
    double v1TBc = uVT * circum1.velocity;
    double v2NBc = uVN * circum2.velocity;
    double v2TBc = uVT * circum2.velocity;

    // Passo 4 - Encontrar as velocidades tangenciais
    // pós-colisão. Elas são iguais às pré-colisão
    double v1TAc = v1TBc;
    double v2TAc = v2TBc;

    // Passo 5 - Encontrar as velocidades normais
    // pós-colisão. Utiliza-se as fórmulas de momento
    // e de energia cinética em uma dimensão
    double m1 = circum1.mass;
    double m2 = circum2.mass;
    double v1NAc = (v1NBc * (m1 - m2) + 2 * m2 * v2NBc) / (m1 + m2);
    double v2NAc = (v2NBc * (m2 - m1) + 2 * m1 * v1NBc) / (m1 + m2);

    // Passo 6 - Converter componentes normais e 
    // tangenciais em vetores
    Vect v1NA = uVN * v1NAc;
    Vect v1TA = uVT * v1TAc;
    Vect v2NA = uVN * v2NAc;
    Vect v2TA = uVT * v2TAc;

    // Passo 7 - Encontrar os vetores de velocidade
    // pós-colisão e aplicá-los aos corpos circulares
    circum1.velocity = v1NA + v1TA;
    circum2.velocity = v2NA + v2TA;
}