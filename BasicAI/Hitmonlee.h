/**********************************************************************************
// Green (Arquivo de Cabe�alho)
//
// Cria��o:		15 Out 2012
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Objeto faz uma fuga suavizada
//
**********************************************************************************/

#ifndef _BASICAI_HITMONLEE_H_
#define _BASICAI_HITMONLEE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Hitmonlee : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Player* player;							// ponteiro para jogador
	Vector speed;								// velocidade e dire��o
	int distance;								// mant�m dist�ncia do jogador

public:
	Hitmonlee(float pX, float pY, Player* p);		// construtor
	~Hitmonlee();									// destrutor

	void OnCollision(Object* obj);				// resolu��o da colis�o
	void Update();								// atualiza��o
	void Draw();								// desenho
};

// ---------------------------------------------------------------------------------

inline void Hitmonlee::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif