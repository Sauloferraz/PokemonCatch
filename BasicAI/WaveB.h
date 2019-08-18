/**********************************************************************************
// WaveB (Arquivo de Cabe�alho)
//
// Cria��o:		06 Ago 2019
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Cria uma onda de inimigos Blue
//
**********************************************************************************/

#ifndef _BASICAI_WAVEB_H_
#define _BASICAI_WAVEB_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class WaveB : public Object
{
private:
	float pX, pY;				// posi��o dos inimigos 
	FloatRand posX;				// valor aleat�rio para posi��o X
	FloatRand posY;				// valor aleat�rio para posi��o Y
	FloatRand secs;				// valor aleat�rio de segundos
	Timer timer;				// medidor de tempo
	float delay;				// atraso para a pr�xima onda

public:
	WaveB();					// construtor
	~WaveB();					// destrutor

	void Update();				// atualiza��o
	void Draw();				// desenho
};

// ------------------------------------------------------------------------------

#endif
