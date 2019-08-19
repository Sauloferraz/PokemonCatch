/**********************************************************************************
// BasicAI (Código Fonte)ddddd
// Compilador:	Visual C++ 2019
//
// Descrição:	Demonstração de scrolling e IA
//
**********************************************************************************/

#include "BasicAI.h"
#include "Delay.h"
#include "Tree.h"
#include "Engine.h"
#include "GameOver.h"
#include "Life.h"

// ------------------------------------------------------------------------------
Player* BasicAI::player = nullptr;
Audio* BasicAI::audio = nullptr;
Scene* BasicAI::scene = nullptr;
bool     BasicAI::viewHUD = false;
// ------------------------------------------------------------------------------

void BasicAI::Init() {
	game->Size(1600, 900);

	// cria sistema de áudio
	audio = new Audio();
	//audio->Add(START, "Resources/Start.wav");
	audio->Add(THEME, "Resources/Theme.wav");
	audio->Add(FIRE, "Resources/Fire.wav", 2);
	audio->Add(HITWALL, "Resources/Hitwall.wav", 5);
	audio->Add(EXPLODE, "Resources/Explode.wav", 5);
	audio->Add(ORANGE, "Resources/Orange.wav", 1);
	audio->Add(MAGENTA, "Resources/Magenta.wav", 2);
	audio->Add(BLUE, "Resources/Blue.wav", 2);
	audio->Add(GREEN, "Resources/Green.wav", 2);

	// ajusta volumes
	//audio->Volume(START, 0.80f);
	audio->Volume(FIRE, 0.20f);
	audio->Volume(EXPLODE, 0.25f);
	audio->Volume(ORANGE, 0.90f);
	audio->Volume(MAGENTA, 0.50f);
	audio->Volume(BLUE, 0.20f);
	audio->Volume(GREEN, 0.75f);

	// carrega/incializa objetos
	backg = new Background("Resources/Space.png");
	sprite = new Sprite("Resources/space4k.png");
	player = new Player();
	scene = new Scene();

	// calcula posição para manter viewport centralizada
	float difx = (game->Width() - window->Width()) / 2.0f;
	float dify = (game->Height() - window->Height()) / 2.0f;

	// inicializa viewport para o centro do background
	viewport.left = 0.0f + difx;
	viewport.right = viewport.left + window->Width();
	viewport.top = 0.0f + dify;
	viewport.bottom = viewport.top + window->Height();

	// cria o Heads Up Display
	hud = new Hud();

	// adiciona objetos na cena
	scene->Add(player, MOVING);
	scene->Add(new Delay(), STATIC);
	scene->Add(new Tree(250, 500), STATIC);
	scene->Add(new Tree(1200, 250), STATIC);
	scene->Add(new Tree(1500, 850), STATIC);
	scene->Add(new Life(), STATIC);
}

// ------------------------------------------------------------------------------

void BasicAI::Update() {
	// sai com o pressionamento da tecla ESC
	window->CloseOnEscape();

	// atualiza o heads up display
	hud->Update();

	// ---------------------------------------------------
	// atualiza a viewport
	// ---------------------------------------------------
	viewport.left = player->X() - window->CenterX();
	viewport.right = player->X() + window->CenterX();
	viewport.top = player->Y() - window->CenterY();
	viewport.bottom = player->Y() + window->CenterY();

	if (viewport.left < 0) {
		viewport.left = 0;
		viewport.right = float(window->Width());
	} else if (viewport.right > game->Width()) {
		viewport.left = float(game->Width() - window->Width());
		viewport.right = float(game->Width());
	}

	if (viewport.top < 0) {
		viewport.top = 0;
		viewport.bottom = float(window->Height());
	} else if (viewport.bottom > game->Height()) {
		viewport.top = float(game->Height() - window->Height());
		viewport.bottom = float(game->Height());
	}
	// ---------------------------------------------------

	// ativa ou desativa a bounding box
	if (window->KeyCtrl('B'))
		viewBBox = !viewBBox;

	// ativa ou desativa o heads up display
	if (window->KeyCtrl('H'))
		viewHUD = !viewHUD;

	// atualiza cena e calcula colisões
	if (player->isDead()) {
		Engine::Next<GameOver>();
	} else {
		scene->Update();
		scene->CollisionDetection();
	}
	
}

// ------------------------------------------------------------------------------

void BasicAI::Draw() {
	// desenha pano de fundo
	//backg->Draw(viewport);
	sprite->Draw((game->Width())/2, (game->Height())/2, 0.98);

	// desenha heads up display
	if (viewHUD)
		hud->Draw();

	// desenha a cena
	scene->Draw();

	// desenha bounding box
	if (viewBBox)
		scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void BasicAI::Finalize() {
	delete audio;
	delete hud;
	delete scene;
	delete backg;
}