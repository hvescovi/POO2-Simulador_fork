#include "../hpp/Mechanics.hpp"
#include <algorithm>
#include <limits.h>
#include <iostream>

#define PI       3.1415926535897932384626433832795
#define PI_DIV_2 1.5707963267948966192313216916398

void Mechanics::CircumMove(CircumBody& circum, double rDT)
{
    // Posição no instante i + 1 = Posição no instante i + Velocidade * DT Real.
    circum.position = circum.position + (circum.velocity * rDT);
}

void Mechanics::CircumAccelerate(CircumBody& circum, double rDT)
{
    // Velocidade no instante i + 1 = Velocidade no instante i + Aceleração * DT Real.
    circum.velocity = circum.velocity + (circum.acceleration * rDT);

    if (circum.velocity.Module() > circum.maxVel)
        circum.velocity.setModule(circum.maxVel);
}

void Mechanics::CircumCollision(CircumBody& circum1, CircumBody& circum2)
{
    // Se o produto escalar entre o vetor formado pelos vetores de posição
    // e o vetor formado pelos vetores de velocidade for maior ou igual
    // a zero, os corpos circulares não estão se aproximando
    if (Vect(circum1.position, circum2.position) *
        Vect(circum1.velocity, circum2.velocity) >= 0)
    {
        return;
    }

    // Se a soma dos raios dos corpos circulares for menor que a distância 
    // entre as posições deles, não há colisão
    if (circum1.radius + circum2.radius <
        Vect::s_Distance(circum1.position, circum2.position))
    {
        return;
    }

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

double clamp(double value, double min, double max)
{
    return std::max(min, std::min(value, max));
}

void Mechanics::CircumRectCollision(CircumBody& circum, RectBody& rect)
{
    // Para maiores esclarecimentos sobre a detecção de colisão,
    // https://youtu.be/_xj8FyG-aac

    // Vetor do ponto mais próximo entre o corpo circular
    // e retangular (Nearest Point)
    Vect vNP = Vect(
        clamp(circum.position.x, rect.position.x, rect.position.x + rect.width),
        clamp(circum.position.y, rect.position.y, rect.position.y + rect.height)
    );

    // Vetor criado a partir da posição do corpo circular e NP
    Vect vNPPos = Vect(vNP, circum.position);

    // Se a distância entre a posição do corpo circular e NP
    // for maior que a medida do raio, não há colisão
    if (vNPPos.Module() > circum.radius)
        return;

    // Se o retângulo for um terminador, o círculo que colidir com ele
    // deverá ser terminado
    if (rect.terminator)
    {
        circum.terminated = true;
        return;
    }

    // Se o ângulo entre vNPPos e o vetor de velocidade do corpo
    // circular for menor que 90°, não há colisão
    // (Lembrando que vNPPos vai de NP até a Posição do corpo)
    if (Vect::s_AngleBetween(vNPPos, circum.velocity) < PI_DIV_2)
        return;

    // Teste para saber se o vetor de velocidade está
    // "acima" de vNPPos: 

    // Se o argumento de vVelocityTest ficar abaixo de 180°,
    // o vetor de velocidade do corpo circular está acima de vNPPos.

    // Se o argumento de vVelocityTest ficar acima de 180°,
    // o vetor de velocidade do corpo circular está abaixo de vNPPos.
    Vect vVelocityTest = Vect(circum.velocity.x, circum.velocity.y);
    vVelocityTest.IncArgument(-vNPPos.Argument());

    if (vVelocityTest.Argument() <= PI)
        // Incrementa o argumento do vetor de velocidade do corpo
        // circular com o seguinte ângulo em radianos:
        // 180° - 2 * Ângulo entre vetor de velocidade e vNPPos
        circum.velocity.IncArgument(PI - 2 * Vect::s_AngleBetween(circum.velocity, vNPPos));
    else
        // Para este caso, o incremento deve ser negativo
        circum.velocity.IncArgument(-(PI - 2 * Vect::s_AngleBetween(circum.velocity, vNPPos)));
}

void Mechanics::AttractToTerminator(CircumBody& circum,  std::vector<RectBody> rectBodies, double accel)
{
    int i = 0;
    int rectSize = rectBodies.size();

    // Índice do retângulo terminador mais próximo do círculo
    int iNearest = -1;

    // Controle de inicialização da variável vShortest
    bool firstTerminator = true;

    // Ao final do laço, este será o vetor da posição do 
    // círculo até o centro do retângulo mais próximo
    Vect vShortest = Vect();

    // Vetor da posição do círculo até 
    // o centro do retângulo atual do laço
    Vect vCurr = Vect();

    double vShortestMod;

    while (i < rectSize)
    {
        if (!rectBodies[i].terminator)
        {
            i += 1;
            continue;
        }

        if (firstTerminator)
        {
            vShortest = Vect(
                circum.position, 
                Vect(
                    rectBodies[i].position.x + (rectBodies[i].width  / 2),
                    rectBodies[i].position.y + (rectBodies[i].height / 2)
                )
            );

            firstTerminator = false;
            iNearest = i;
            i += 1;
            continue;
        }

        vCurr = Vect(
            circum.position, 
            Vect(
                rectBodies[i].position.x + (rectBodies[i].width  / 2),
                rectBodies[i].position.y + (rectBodies[i].height / 2)
            )
        );

        if (vCurr.Module() < vShortest.Module()) 
        {
            vShortest = vCurr;
            iNearest = i; 
        }

        i += 1;
    }

    // Se iNearest for -1, não há terminadores
    if (iNearest == -1)
    {
        return;
    }

    // Constante de proporção da semelhança de triângulos
    double k = accel / vShortest.Module();

    circum.acceleration = Vect(vShortest * k);
}