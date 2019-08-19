/**********************************************************************************
// Green (Arquivo de Cabeçalho)
//
// Criação:		15 Out 2012
// Atualização:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Objeto faz uma fuga suavizada
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
	Vector speed;								// velocidade e direção
	int distance;								// mantém distância do jogador

public:
	Hitmonlee(float pX, float pY, Player* p);		// construtor
	~Hitmonlee();									// destrutor

	void OnCollision(Object* obj);				// resolução da colisão
	void Update();								// atualização
	void Draw();								// desenho
};

// ---------------------------------------------------------------------------------

inline void Hitmonlee::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif