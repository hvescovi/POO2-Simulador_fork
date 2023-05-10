#include "App.hpp"
#include "AppUtils.hpp"

void App::OnBeforeLoop()
{
    global.ticks = SDL_GetTicks();
    OnRenderClear();
    OnLoopThroughParticles();
    OnRenderPresent();
    OnTimeDelay();
    SDL_Delay((Uint32)2000);
}

void App::OnCleanup() 
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void App::OnEvent(SDL_Event event) 
{
    // Tipo de evento
    switch (event.type) 
    {
        // Tecla pressionada
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) 
            {
                // Escape (Esc)
                case SDLK_ESCAPE:
                    running = false;
                    break;

                default: break;
            }
            break;

        case SDL_QUIT:
            running = false;
            break;

        default: break;
    }
}

void App::OnInit()
{
    global = AppVar(60, 800, 600, 24, Particle::createVectorParticle3());

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
    {
        SDL_Log("SDL não pôde ser inicializado: ", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(
        "Simulador",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        global.width,
        global.height,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) 
    {
        SDL_Log("A janela SDL está com valor nulo. Erro: ", SDL_GetError());
        exit(1);
    }

    if (renderer == NULL)
    {
        SDL_Log("O renderizador SDL está com valor nulo. Erro: ", SDL_GetError());
        exit(1);
    }
}

void App::OnLoopThroughParticles()
{
    int i = 0;
    int j = 0;
    int size = (int)global.vectorParticle.size();
    while (i < size)
    {
        OnParticleMove(global.vectorParticle[i]);
        OnParticleBorderCollision(global.vectorParticle[i]);

        j = 0;
        while (j < size)
        {
            // N�o se pode verificar colis�o de um c�rculo
            // com ele mesmo
            if (i == j)
            {
                j += 1;
                continue;
            }

            OnParticleCollision(global.vectorParticle[i], global.vectorParticle[j]);

            j += 1;
        }

        OnRenderParticle(global.vectorParticle[i]);

        i += 1;
    }
}

void App::OnParticleBorderCollision(Particle& particle)
{
    bool verticalCollision = false;

    // Lateral esquerda
    if (particle.position.x - particle.radius <= 0)
    {
        verticalCollision = true;

        particle.position = Vect(particle.radius + 1, particle.position.y);

        particle.velocity = Vect(particle.velocity.x * -1, particle.velocity.y);
    }

    // Lateral direita
    if (!verticalCollision && particle.position.x + particle.radius >= global.width)
    {
        particle.position = Vect(global.width - particle.radius - 1, particle.position.y);

        particle.velocity = Vect(particle.velocity.x * -1, particle.velocity.y);
    }

    bool horizontalCollision = false;

    // Cima
    if (particle.position.y - particle.radius <= 0)
    {
        horizontalCollision = true;

        particle.position = Vect(particle.position.x, particle.radius + 1);

        particle.velocity = Vect(particle.velocity.x, particle.velocity.y * -1);
}

    // Baixo
    if (!horizontalCollision && particle.position.y + particle.radius >= global.height)
    {
        particle.position = Vect(particle.position.x, global.height - particle.radius - 1);

        particle.velocity = Vect(particle.velocity.x, particle.velocity.y * -1);
    }
}

void App::OnParticleCollision(Particle& particle1, Particle& particle2)
{
    // Se o produto escalar entre o vetor formado pelos vetores de posi��o
    // e o vetor formado pelos vetores de velocidade for maior ou igual
    // a zero, as part�culas n�o est�o se aproximando
    if (Vect(particle1.position, particle2.position) *
        Vect(particle1.velocity, particle2.velocity) >= 0)
    {
        return;
    }

    // Se a soma dos raios das part�culas for menor que a dist�ncia 
    // entre as posi��es das part�culas, n�o h� colis�o
    if (particle1.radius + particle2.radius <
        AppUtils::s_DistanceBetweenParticles(particle1, particle2))
    {
        SDL_Log("N�o vou colidir");
        return;
    }

    SDL_Log("Colis�o!");

    // Para maiores esclarecimentos,
    // https://www.vobarian.com/collisions/2dcollisions2.pdf
    // Este PDF tamb�m est� na pasta "Utilidades" deste reposit�rio

    // Acr�nimos:
    // v  -> Vetor
    // uV -> Vetor unit�rio
    // 1  -> Referente � part�cula 1
    // 2  -> Referente � part�cula 2
    // N  -> Normal (perpendicular)
    // T  -> Tangente
    // B  -> Before collision (Antes da colis�o)
    // A  -> After collision (Depois da colis�o)
    // c  -> Componente (grandeza escalar)
    // m  -> Massa

    // Passo 1 - Achar vetor unit�rio normal e vetor unit�rio tangente.
    // Eles formam "eixos" que ser�o utilizados em passos seguintes

    // "Eixo y"
    Vect uVN = Vect(particle1.position, particle2.position).unitVect();
    
    // "Eixo x"
    Vect uVT = Vect(-uVN.y, uVN.x);

    // Passo 2 - Criar os vetores de velocidade inicial 
    // (antes da colis�o) de ambos os c�rculos. 
    // OBS: Eles j� existem (objParticle.getVel())

    // Passo 3 - Projetar os vetores de velocidade inicial
    // nos vetores unit�rios normal e tangente.
    // Isto pode ser feito ao efetuar o produto escalar entre
    // os vetores unit�rios e os vetores de velocidade
    double v1NBc = uVN * particle1.velocity;
    double v1TBc = uVT * particle1.velocity;
    double v2NBc = uVN * particle2.velocity;
    double v2TBc = uVT * particle2.velocity;

    // Passo 4 - Encontrar as velocidades tangenciais
    // p�s-colis�o. Elas s�o iguais �s pr�-colis�o
    double v1TAc = v1TBc;
    double v2TAc = v2TBc;

    // Passo 5 - Encontrar as velocidades normais
    // p�s-colis�o. Utiliza-se as f�rmulas de momento
    // e de energia cin�tica em uma dimens�o
    double m1 = particle1.mass;
    double m2 = particle2.mass;
    double v1NAc = (v1NBc * (m1 - m2) + 2 * m2 * v2NBc) / (m1 + m2);
    double v2NAc = (v2NBc * (m2 - m1) + 2 * m1 * v1NBc) / (m1 + m2);

    // Passo 6 - Converter componentes normais e 
    // tangenciais em vetores
    Vect v1NA = uVN * v1NAc;
    Vect v1TA = uVT * v1TAc;
    Vect v2NA = uVN * v2NAc;
    Vect v2TA = uVT * v2TAc;

    // Passo 7 - Encontrar os vetores de velocidade
    // p�s-colis�o e aplic�-los �s part�culas
    particle1.velocity = v1NA + v1TA;
    particle2.velocity = v2NA + v2TA;
}

void App::OnParticleMove(Particle& particle)
{
    // Posi��o no instante i + 1 = Posi��o no instante i + Velocidade * DT Real.
    particle.position = particle.position + (particle.velocity * global.rDT);
}

void App::OnRenderClear()
{
    // Seta a cor atual para preto e o alfa para o m�ximo
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    // Preenche a tela com a cor atual
    SDL_RenderClear(renderer);
}

void App::OnRenderParticle(Particle particle) 
{
    SDL_SetRenderDrawColor(renderer, 64, 128, 255, SDL_ALPHA_OPAQUE);

    // Desenha a partícula
    AppUtils::s_DrawParticle(
        renderer,
        particle,
        global.particleVertexQuantity
    );

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

    // Desenha o vetor de velocidade da partícula
    AppUtils::s_DrawVect(
        renderer,
        particle.position,
        particle.position + particle.velocity
    );

    //SDL_Rect rect = { 100,100,440,280 };
    //SDL_FillRect(Main_Surface, &rect, SDL_MapRGB(Main_Surface->format, 255, 0, 0));
    //SDL_UpdateWindowSurface(Window);
    //SDL_RenderDrawRect(Renderer, &rect);
}

void App::OnRenderPresent()
{
    //Atualiza a janela com o renderizador
    SDL_RenderPresent(renderer);
}

void App::OnTimeDelay()
{
    // dT recebe a diferen�a de ticks entre o come�o da
    // execu��o do la�o e o final
    global.dT = SDL_GetTicks() - global.ticks;

    if (global.dT < global.dDT)
    {
        // Pausa a execu��o por um tempo para o FPS atingir
        // valores pr�ximos ao desejado
        SDL_Delay((Uint32)(global.dDT - global.dT));
    }

    // Mostra o FPS atual
    //SDL_Log("FPS: %i", 1000 / (SDL_GetTicks() - global.get_ticks()));

    // rDT recebe a diferen�a REAL de ticks entre o come�o
    // da execu��o do la�o e o final. (O tempo de execu��o 
    // deste m�todo tamb�m � relevante!)
    global.rDT = (SDL_GetTicks() - global.ticks) / 1000.0;
}