# Simulador de fuga de multidões
Este projeto é um programa que simula a fuga de pessoas de um local - representadas por circunferências - numa situação de emergência.

A simulação tem como objetivo comparar a variação no fluxo de saída das pessoas ao modificar variáveis do ambiente como largura das portas de saída e quantidade de portas de saída.

## Preparação
Execute o arquivo Python `src/bin/simGen.py` com o Python 3. No terminal, responda ao primeiro input com a alternativa 2 e depois siga sua intuição para os próximos inputs.

Em relação à quantidade de círculos, tente não exceder uma quantidade de 500 ou 600 pois pode não ter mais posições na tela para a adição de círculos. Em casos como este, o programa Python fica preso em um laço infinito.

Posteriormente serão gerados arquivos de simulação para alimentar o programa principal.

## Compilação
Para compilar o projeto, é preciso ter o Make instalado.

No linux, instale os recursos de desenvolvimento da biblioteca SDL2:
sudo apt-get install libsdl2-dev

Abra o terminal, selecione a pasta `src` e execute `make`. Dentro do arquivo makefile há configurações definidas para windows e linux.

Após a execução de `make`, execute o binário `Simulador` que estará na pasta `bin`.