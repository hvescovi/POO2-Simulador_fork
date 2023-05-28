// void App::OnParticleBorderCollision(Particle& particle)
// {
//     bool verticalCollision = false;

//     // Lateral esquerda
//     if (particle.position.x - particle.radius <= 0)
//     {
//         verticalCollision = true;

//         particle.position = Vect(particle.radius + 1, particle.position.y);

//         particle.velocity = Vect(particle.velocity.x * -1, particle.velocity.y);
//     }

//     // Lateral direita
//     if (!verticalCollision && particle.position.x + particle.radius >= global.width)
//     {
//         particle.position = Vect(global.width - particle.radius - 1, particle.position.y);

//         particle.velocity = Vect(particle.velocity.x * -1, particle.velocity.y);
//     }

//     bool horizontalCollision = false;

//     // Acima
//     if (particle.position.y - particle.radius <= 0)
//     {
//         horizontalCollision = true;

//         particle.position = Vect(particle.position.x, particle.radius + 1);

//         particle.velocity = Vect(particle.velocity.x, particle.velocity.y * -1);
// }

//     // Abaixo
//     if (!horizontalCollision && particle.position.y + particle.radius >= global.height)
//     {
//         particle.position = Vect(particle.position.x, global.height - particle.radius - 1);

//         particle.velocity = Vect(particle.velocity.x, particle.velocity.y * -1);
//     }
// }

// void App::OnParticleCollision(Particle& particle1, Particle& particle2)
// {
//     // Se o produto escalar entre o vetor formado pelos vetores de posição
//     // e o vetor formado pelos vetores de velocidade for maior ou igual
//     // a zero, as partículas não estão se aproximando
//     if (Vect(particle1.position, particle2.position) *
//         Vect(particle1.velocity, particle2.velocity) >= 0)
//     {
//         return;
//     }

//     // Se a soma dos raios das partículas for menor que a distância 
//     // entre as posições das partículas, não há colisão
//     if (particle1.radius + particle2.radius <
//         AppUtils::s_DistanceBetweenParticles(particle1, particle2))
//     {
//         return;
//     }

//     // Para maiores esclarecimentos,
//     // https://www.vobarian.com/collisions/2dcollisions2.pdf
//     // Este PDF também está na pasta "Utilidades" deste repositório

//     // Acrônimos:
//     // v  -> Vetor
//     // uV -> Vetor unitário
//     // 1  -> Referente à partícula 1
//     // 2  -> Referente à partícula 2
//     // N  -> Normal (perpendicular)
//     // T  -> Tangente
//     // B  -> Before collision (Antes da colisão)
//     // A  -> After collision (Depois da colisão)
//     // c  -> Componente (grandeza escalar)
//     // m  -> Massa

//     // Passo 1 - Achar vetor unitário normal e vetor unitário tangente.
//     // Eles formam "eixos" que serão utilizados em passos seguintes

//     // "Eixo y"
//     Vect uVN = Vect(particle1.position, particle2.position).unitVect();
    
//     // "Eixo x"
//     Vect uVT = Vect(-uVN.y, uVN.x);

//     // Passo 2 - Criar os vetores de velocidade inicial 
//     // (antes da colisão) de ambos os círculos. 
//     // OBS: Eles já existem (obj_particula.velocidade)

//     // Passo 3 - Projetar os vetores de velocidade inicial
//     // nos vetores unitários normal e tangente.
//     // Isto pode ser feito ao efetuar o produto escalar entre
//     // os vetores unitários e os vetores de velocidade
//     double v1NBc = uVN * particle1.velocity;
//     double v1TBc = uVT * particle1.velocity;
//     double v2NBc = uVN * particle2.velocity;
//     double v2TBc = uVT * particle2.velocity;

//     // Passo 4 - Encontrar as velocidades tangenciais
//     // pós-colisão. Elas são iguais às pré-colisão
//     double v1TAc = v1TBc;
//     double v2TAc = v2TBc;

//     // Passo 5 - Encontrar as velocidades normais
//     // pós-colisão. Utiliza-se as fórmulas de momento
//     // e de energia cinética em uma dimensão
//     double m1 = particle1.mass;
//     double m2 = particle2.mass;
//     double v1NAc = (v1NBc * (m1 - m2) + 2 * m2 * v2NBc) / (m1 + m2);
//     double v2NAc = (v2NBc * (m2 - m1) + 2 * m1 * v1NBc) / (m1 + m2);

//     // Passo 6 - Converter componentes normais e 
//     // tangenciais em vetores
//     Vect v1NA = uVN * v1NAc;
//     Vect v1TA = uVT * v1TAc;
//     Vect v2NA = uVN * v2NAc;
//     Vect v2TA = uVT * v2TAc;

//     // Passo 7 - Encontrar os vetores de velocidade
//     // pós-colisão e aplicá-los às partículas
//     particle1.velocity = v1NA + v1TA;
//     particle2.velocity = v2NA + v2TA;
// }

// void App::OnParticleMove(Particle& particle)
// {
//     // Posição no instante i + 1 = Posição no instante i + Velocidade * DT Real.
//     particle.position = particle.position + (particle.velocity * global.ST.rDT);
// }

// void App::OnRenderParticle(Particle particle) 
// {
//     SDL_SetRenderDrawColor(renderer, 64, 128, 255, SDL_ALPHA_OPAQUE);

//     // Desenha a partícula
//     AppUtils::s_DrawParticle(
//         renderer,
//         particle,
//         global.particleVertexQuantity
//     );

//     SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

//     // Desenha o vetor de velocidade da partícula
//     AppUtils::s_DrawVect(
//         renderer,
//         particle.position,
//         particle.position + particle.velocity
//     );
// }