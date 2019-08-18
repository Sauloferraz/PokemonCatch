/**********************************************************************************
// WaveM (Código Fonte)
//
// Criação:		06 Ago 2019
// Atualização:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#include "WaveMuk.h"
#include "BasicAI.h"
#include "Muk.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveMuk::WaveMuk() : posX(30, window->Width() - 30), posY(30, game->Height() - 30), secs(1.0f, 2.0f)
{
	// posição dos inimigos
	pX = posX.Rand();
	pY = posY.Rand();

	// atraso para a próxima onda 
	delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveMuk::~WaveMuk()
{

}

// -------------------------------------------------------------------------------

void WaveMuk::Update()
{
	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && Hud::muk < 1)
	{
		// toca som de nova onda
		BasicAI::audio->Play(MAGENTA);

		// adiciona novo inimigo
		BasicAI::scene->Add(new Muk(pX, pY, BasicAI::player), MOVING);

		// nova posição do inimigo
		pX = posX.Rand();
		pY = posY.Rand();

		// reinicia o timer
		timer.Start();
	}
}

// -------------------------------------------------------------------------------

void WaveMuk::Draw()
{

}

// -------------------------------------------------------------------------------
