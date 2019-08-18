/**********************************************************************************
// WallHit (C�digo Fonte)
// 
// Cria��o:		03 Ago 2019
// Atualiza��o:	03 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "BasicAI.h"
#include "WallHit.h"
#include "Random.h"
#include "Hud.h"

// ---------------------------------------------------------------------------------

WallHit::WallHit(float pX, float pY)
{
	// calcula �ngulo base e ajusta coordenadas da explos�o
	float base;
	if (pX < 50)
	{
		base = 0.0f;
		pX = 50;
	}
	else if (pX > game->Width() - 50)
	{
		base = 180.0f;
		pX = game->Width() - 50;
	}
	else if (pY < 50)
	{
		base = 270.0f;
		pY = 50;
	}
	else
	{
		base = 90.0f;
		pY = game->Height() - 50;
	}

	// n�mero aleat�rio entre 0 e 1
	FloatRand color{ 0, 1 };
	
	// configura emissor de part�culas
	Emitter explosion;
	explosion.imgFile   = "Resources/Star.png";		// arquivo de imagem
	explosion.angle     = base;						// dire��o da explos�o
	explosion.spread    = 80.0f;					// espalhamento em graus
	explosion.lifeTime  = 1.0f;						// tempo de vida em segundos
	explosion.genTime   = 0.000f;					// tempo entre gera��o de novas part�culas
	explosion.percToDim = 0.6f;						// desaparece ap�s 60% da vida
	explosion.minSpeed  = 25.0f;					// velocidade m�nima das part�culas
	explosion.maxSpeed  = 250.0f;					// velocidade m�xima das part�culas
	explosion.r = color.Rand();						// cor da part�cula entre 0 e 1
	explosion.g = color.Rand();						// cor da part�cula entre 0 e 1
	explosion.b = color.Rand();						// cor da part�cula entre 0 e 1
	explosion.a = 1.0f;								// transpar�ncia da part�cula

	// cria sistema de part�culas
	starsGen = new Particles(explosion);

	// gera 50 part�culas na posi��o do mouse
	starsGen->Generate(pX, pY, 25);
	type = WALLHIT;

	// incrementa contagem de part�culas
	Hud::particles += 25;
}

// ---------------------------------------------------------------------------------

WallHit::~WallHit()
{
	delete starsGen;

	// decrementa contagem de part�culas
	Hud::particles -= 25;
}

// -------------------------------------------------------------------------------

void WallHit::Update()
{
	// atualiza posi��o de cada part�cula
	starsGen->Update(gameTime);

	// remove da cena quando todas as part�culas est�o inativas
	if (starsGen->Inactive())
		BasicAI::scene->Delete();
}

// -------------------------------------------------------------------------------