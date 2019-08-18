/**********************************************************************************
// WaveG (Arquivo de Cabe�alho)
//
// Cria��o:		06 Ago 2019
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Cria uma onda de inimigos Green
//
**********************************************************************************/

#ifndef _BASICAI_WAVESNORLAX_H_
#define _BASICAI_WAVESNORLAX_H_

// --------------------------------------------------------------------------------

#include "Object.h"
#include "Timer.h"
#include "Random.h"

// --------------------------------------------------------------------------------

class WaveSnorlax : public Object
{
private:
	FloatRand secs;				// valor aleat�rio de segundos
	Timer timer;				// medidor de tempo
	float delay;				// atraso para a pr�xima onda

public:
	WaveSnorlax();					// construtor
	~WaveSnorlax();					// destrutor

	void Update();				// atualiza��o
	void Draw();				// desenho
};

// ------------------------------------------------------------------------------

#endif