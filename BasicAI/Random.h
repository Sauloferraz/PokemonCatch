/**********************************************************************************
// Random (Arquivo de Cabe�alho)
//
// Cria��o:		03 Ago 2019
// Atualiza��o:	03 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Gerador de n�meros pseudoaleat�rios
//
**********************************************************************************/

#ifndef _DESENVJOGOS_RANDOM_H_
#define _DESENVJOGOS_RANDOM_H_

// -------------------------------------------------------------------------------

#include "Types.h"							// tipos espec�ficos da engine
#include <random>							// biblioteca random da STL
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

// -------------------------------------------------------------------------------

class Random
{
protected:
	static random_device seed;				// gerador n�o-determin�stico
	static mt19937 mt;						// gerador Mersenne Twister
};

// -------------------------------------------------------------------------------

class IntRand : public Random
{
private:
	uniform_int_distribution<int> dist;		// distribui��o uniforme

public:
	IntRand(int min, int max);				// construtor	
	int Rand();								// retorna n�mero aleat�rio
};

// -------------------------------------------------------------------------------

class FloatRand : public Random
{
private:
	uniform_real_distribution<float> dist;	// distribui��o uniforme

public:
	FloatRand(float min, float max);		// construtor	
	float Rand();							// retorna n�mero aleat�rio
};

// ---------------------------------------------------------------------------------

#endif
