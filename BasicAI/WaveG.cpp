/**********************************************************************************
// WaveG (C�digo Fonte)
//
// Cria��o:		06 Ago 2019
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Cria uma onda de inimigos Green
//
**********************************************************************************/

#include "WaveG.h"
#include "BasicAI.h"
#include "Green.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveG::WaveG() : secs(8.0f, 10.0f)
{
	// atraso para a pr�xima onda 
	delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveG::~WaveG()
{

}

// -------------------------------------------------------------------------------

void WaveG::Update()
{
	// contador de inimigos
	static uint counter = 1;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && Hud::greens < 5)
	{
		if (counter > 0)
		{
			// toca som de nova onda
			BasicAI::audio->Play(GREEN);

			// adiciona nova inimigo
			BasicAI::scene->Add(new Green(50, 50, BasicAI::player), MOVING);
			BasicAI::scene->Add(new Green(game->Width() - 50, 50, BasicAI::player), MOVING);
			BasicAI::scene->Add(new Green(game->Width() - 50, game->Height() - 50, BasicAI::player), MOVING);
			BasicAI::scene->Add(new Green(50, game->Height() - 50, BasicAI::player), MOVING);

			delay = 0.450f;
			timer.Start();
			--counter;
		}
		else
		{
			// nova onda
			counter = 2;
			delay = secs.Rand();
			timer.Start();
		}
	}
}

// -------------------------------------------------------------------------------

void WaveG::Draw()
{
	
}

// -------------------------------------------------------------------------------
