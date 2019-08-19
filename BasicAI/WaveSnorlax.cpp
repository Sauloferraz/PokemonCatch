#include "WaveSnorlax.h"
#include "BasicAI.h"
#include "Snorlax.h"
#include "Hud.h"

// ------------------------------------------------------------------------------

WaveSnorlax::WaveSnorlax() : secs(22.0f, 25.0f)
{
	// atraso para a próxima onda 
	delay = secs.Rand();
}

// ------------------------------------------------------------------------------

WaveSnorlax::~WaveSnorlax()
{

}

// -------------------------------------------------------------------------------

void WaveSnorlax::Update()
{
	// contador de inimigos
	static uint counter = 1;

	// se passou o tempo de atraso
	if (timer.Elapsed(delay) && Hud::snorlax < 1)
	{
		if (counter > 0)
		{
			// toca som de nova onda
			BasicAI::audio->Play(GREEN);

			// adiciona nova inimigo
			BasicAI::scene->Add(new Snorlax(50, 50, BasicAI::player), MOVING);
			delay = 0.450f;
			timer.Start();
			--counter;
		}
		else
		{
			// nova onda
			counter = 1;
			delay = secs.Rand();
			timer.Start();
		}
	}
}

// -------------------------------------------------------------------------------

void WaveSnorlax::Draw()
{

}

// -------------------------------------------------------------------------------
