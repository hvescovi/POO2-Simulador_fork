#include "App.hpp"
#include <string.h>

App::App():
	global{},
	window{ NULL },
	renderer{ NULL },
	running{ true }
{}

int App::Execute()
{
	OnInit();

	OnBeforeLoop();

	// Estrutura que contém informações sobre eventos
	SDL_Event event;

	// Laço de repetição do simulador
	while (running) 
	{
		// Ticks atuais da execução do SDL. É utilizado em OnTimeDelay
		global.set_ticks(SDL_GetTicks());

		// Checa por eventos e os percorre um por vez a partir de uma fila.
		// A fila é preenchida por eventos toda vez que o SDL detecta um input.
		// Lista de eventos : https://wiki.libsdl.org/SDL_Event#data_fields.
		while (SDL_PollEvent(&event)) 
		{
			OnEvent(event);
		}

		OnRenderClear();

		OnLoopThroughParticles();

		OnRenderPresent();

		OnTimeDelay();
	}

	OnCleanup();

	return 0;
}
