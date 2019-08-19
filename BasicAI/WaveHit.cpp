/**********************************************************************************
// WaveHit (C�digo Fonte)
//
// Cria��o:		06 Ago 2019
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#include "WaveHit.h"
#include "BasicAI.h"
#include "Hitmonlee.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveHit::WaveHit() : posX(50, window->Width() - 50), posY(50, game->Height() - 50), secs(8.0f, 10.0f)
{
	// posi��o dos inimigos
	pX = posX.Rand();
	pY = posY.Rand();

	// atraso para a pr�xima onda 
	delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveHit::~WaveHit()
{

}

// -------------------------------------------------------------------------------

void WaveHit::Update()
{
	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && Hud::magentas < 1)
	{
		// toca som de nova onda
		BasicAI::audio->Play(MAGENTA);

		// adiciona novo inimigo
		BasicAI::scene->Add(new Hitmonlee(pX, pY, BasicAI::player), MOVING);

		// nova posi��o do inimigo
		pX = posX.Rand();
		pY = posY.Rand();

		// reinicia o timer
		timer.Start();
	}
}

// -------------------------------------------------------------------------------

void WaveHit::Draw()
{

}

// -------------------------------------------------------------------------------
