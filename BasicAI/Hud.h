/**********************************************************************************
// Hud (Arquivo de Cabeçalho)
//
// Criação:		02 Ago 2019
// Atualização:	02 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Heads Up Display
//
**********************************************************************************/

#ifndef _BASICAI_HUD_H_
#define _BASICAI_HUD_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
#include "Animation.h"
using std::stringstream;

// --------------------------------------------------------------------------------

class Hud : public Object
{
private:
	Font * font = nullptr;						// fonte para exibição normal
	Font * bold = nullptr;						// fonte para exibição negrito
	Sprite * infoBox = nullptr;					// área de informações do jogo
	stringstream text;							// texto temporário
	uint frameCount;							// contador de quadros por segundo
	float totalTime;							// tempo total transcorrido 
	uint fps;		
	// valor para exibição do fps
	Sprite* life = nullptr;

public:
	static uint missiles;						// número de mísseis na tela
	static uint oranges;						// número de inimigos laranja
	static uint magentas;						// número de inimigos rosa
	static uint blues;							// número de inimigos azul
	static uint greens;							// número de inimigos verde
	static uint particles;						// número de partículas ativas
	static uint captures;
	static uint muk;
	static uint snorlax;
	static uint caterpies;
	static uint zubats;
	static uint hitmonlee;

	Hud();										// construtor
	~Hud();										// destrutor

	void Update();								// atualização
	void Draw();								// desenho
};

// ------------------------------------------------------------------------------

#endif

