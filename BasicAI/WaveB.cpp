/**********************************************************************************
// WaveB (C�digo Fonte)
//
// Cria��o:		06 Ago 2019
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Cria uma onda de inimigos Blue
//
**********************************************************************************/

#include "WaveB.h"
#include "BasicAI.h"
#include "Blue.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveB::WaveB() : posX(0, window->Width()), posY(0,window->Height()), secs(2.0f, 4.0f)
{
	// posi��o dos inimigos
	pX = posX.Rand();
	pY = posY.Rand();

	// atraso para a pr�xima onda 
	delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveB::~WaveB()
{

}

// -------------------------------------------------------------------------------

void WaveB::Update()
{
	// contador de inimigos
	static uint counter = 1;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && Hud::blues < 5)
	{
		if (counter > 0)
		{
			// toca som de nova onda
			BasicAI::audio->Play(BLUE);

			// adiciona nova inimigo
			BasicAI::scene->Add(new Blue(pX, pY, BasicAI::player), MOVING);

			delay = 0.450f;
			timer.Start();
			--counter;
		}
		else
		{
			// nova posi��o do inimigo
			pX = posX.Rand();
			pY = posY.Rand();

			// nova onda
			counter = 1;
			delay = secs.Rand();
			timer.Start();
		}
	}
}

// -------------------------------------------------------------------------------

void WaveB::Draw()
{
	
}

// -------------------------------------------------------------------------------
