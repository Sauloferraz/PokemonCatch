/**********************************************************************************
// Explosion (Arquivo de Cabe�alho)
// 
// Cria��o:		17 Mar 2013
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Efeito de explos�o usando sistema de part�culas
//
**********************************************************************************/

#ifndef _BASICAI_EXPLOSION_H_
#define _BASICAI_EXPLOSION_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Particles.h"

// ---------------------------------------------------------------------------------

class Explosion : public Object
{
private:
	Particles * starsGen;				// sistema de part�culas
	
public:
	Explosion(float pX, float pY);		// construtor
	~Explosion();						// destrutor

	int Size();							// quantidade de part�culas
	void Update();						// atualiza��o
	void Draw();						// desenho
}; 

// ---------------------------------------------------------------------------------

inline int Explosion::Size()
{	return starsGen->Size(); }

inline void Explosion::Draw()
{	starsGen->Draw(Layer::MIDDLE, 0.0f); }

// ---------------------------------------------------------------------------------


#endif