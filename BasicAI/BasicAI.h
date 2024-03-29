/**********************************************************************************
// BasicAI (Arquivo de Cabe�alho)
// 
// Cria��o:		23 Out 2012
// Atualiza��o:	11 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Demonstra��o de scrolling e IA
//
**********************************************************************************/

#ifndef _BASICAI_H_
#define _BASICAI_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Scene.h"
#include "Background.h"
#include "Player.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

enum { PLAYER, MISSILE, BLUE, GREEN, MAGENTA, ORANGE, WALLHIT, 
	   THEME, START, FIRE, EXPLODE, HITWALL, EXPLOSION, MUK, ZUBAT, HITMONLEE, GEAR };

// ------------------------------------------------------------------------------

class BasicAI : public Game
{
private:
	Background * backg = nullptr;	// pano de fundo
	Sprite* sprite;
	Hud * hud = nullptr;			// heads up display
	bool viewBBox = false;			// bouding box vis�vel

public:
	static Player * player;			// ponteiro para o jogador
	static Audio * audio;			// sitema de �udio
	static Scene * scene;			// cena do jogo
	static bool viewHUD;			// hud vis�vel

	void Init();					// inicializa��o
	void Update();					// atualiza��o
	void Draw();					// desenho
	void Finalize();				// finaliza��o
};

// ---------------------------------------------------------------------------------

#endif