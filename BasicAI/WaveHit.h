/**********************************************************************************
// WaveHit (Arquivo de Cabe�alho)
//
// Cria��o:		06 Ago 2019
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Cria uma onda de inimigos Magenta
//
**********************************************************************************/

#ifndef _BASICAI_WAVEHIT_H_
#define _BASICAI_WAVEHIT_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class WaveHit : public Object
{
private:
	float pX, pY;				// posi��o dos inimigos 
	FloatRand posX;				// valor aleat�rio para posi��o X
	FloatRand posY;				// valor aleat�rio para posi��o Y
	FloatRand secs;				// valor aleat�rio de segundos
	Timer timer;				// medidor de tempo
	float delay;				// atraso para a pr�xima onda

public:
	WaveHit();						// construtor
	~WaveHit();					// destrutor

	void Update();				// atualiza��o
	void Draw();				// desenho
};

// ------------------------------------------------------------------------------

#endif
