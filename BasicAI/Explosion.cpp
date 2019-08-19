/**********************************************************************************
// Explosion (C�digo Fonte)
// 
// Cria��o:		17 Mar 2013
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#include "BasicAI.h"
#include "Explosion.h"
#include "Random.h"
#include "Hud.h"

// ---------------------------------------------------------------------------------

Explosion::Explosion(float pX, float pY)
{
	// n�mero aleat�rio entre 0 e 1
	FloatRand color{ 0, 1 };

	// configura emissor de part�culas
	Emitter explosion;
	explosion.imgFile   = "Resources/Explo.png";	// arquivo de imagem
	explosion.angle     = 0.0f;						// dire��o da explos�o
	explosion.spread    = 180.0f;					// espalhamento em graus
	explosion.lifeTime  = 0.5f;						// tempo de vida em segundos
	explosion.genTime   = 0.000f;					// tempo entre gera��o de novas part�culas
	explosion.percToDim = 0.8f;						// desaparece ap�s 60% da vida
	explosion.minSpeed  = 25.0f;					// velocidade m�nima das part�culas
	explosion.maxSpeed  = 70.0f;					// velocidade m�xima das part�culas
	explosion.r = 1.0f;								// cor da part�cula entre 0 e 1
	explosion.g = 0.0f;								// cor da part�cula entre 0 e 1
	explosion.b = 0.0f;								// cor da part�cula entre 0 e 1
	explosion.a = 1.0f;								// transpar�ncia da part�cula

	// cria sistema de part�culas
	starsGen = new Particles(explosion);

	// gera 25 part�culas na posi��o indicada
	starsGen->Generate(pX, pY, 50);
	type = EXPLOSION;

	// incrementa contagem de part�culas
	Hud::particles += 50;
}

// ---------------------------------------------------------------------------------

Explosion::~Explosion()
{
	delete starsGen;

	// decrementa contagem de part�culas
	Hud::particles -= 50;
}

// -------------------------------------------------------------------------------

void Explosion::Update()
{
	// atualiza posi��o de cada part�cula
	starsGen->Update(gameTime);

	// remove da cena quando todas as part�culas est�o inativas
	if (starsGen->Inactive())
		BasicAI::scene->Delete();
}

// -------------------------------------------------------------------------------