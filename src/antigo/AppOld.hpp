// class App
// {
//     public:
//         App();

//         /**
//          * Atualiza a posição das partículas baseando-se em suas
//          * velocidades e no tempo entre frames.
//          * 
//          * \param particle Partícula
//          */
//         void OnParticleMove(Particle& particle);

//         /**
//          * Verifica colisão entre duas partículas e, caso haja,
//          * calcula as velocidades pós-colisão.
//          * 
//          * \param particle1 Partícula 1
//          * \param particle2 Partícula 2
//          */
//         void OnParticleCollision(Particle& particle1, Particle& particle2);

//         /**
//          * Verifica colisão entre partícula e borda e, caso
//          * haja, inverte componentes do vetor de velocidade.
//          * 
//          * \param particle Partícula
//          */
//         void OnParticleBorderCollision(Particle& particle);

//         /**
//         * Renderiza uma partícula.
//         * 
//         * \param particle
//         */
//         void OnRenderParticle(Particle particle);

//         /**
//          * OnTimeDelay mantém o contador de FPS perto do desejado, uniformizando
//          * o comportamento do simulador e economizando recursos.
//          */
//         void OnTimeDelay();