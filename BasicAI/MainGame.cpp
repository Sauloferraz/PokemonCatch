#include "Engine.h"	
#include "Resources.h"
#include "Intro.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	// cria motor do jogo
	Engine* engine = new Engine();

	// configura janela
	engine->window->Mode(WINDOWED);
	engine->window->Size(1366, 768);
	engine->window->Color(0, 0, 0);
	engine->window->Title("Catch'em All!");
	engine->window->Icon(IDI_ICON);
	engine->window->Cursor(IDC_CURSOR);
	engine->window->HideCursor(true);

	// configura dispositivo gráfico
	engine->graphics->VSync(true);

	// cria o jogo
	Game* game = new Intro();

	// inicia execução
	int status = engine->Start(game);

	// destrói motor 
	delete engine;

	// encerra programa
	return status;
}

// ----------------------------------------------------------------------------