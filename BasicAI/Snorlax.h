#ifndef _BASICAI_SNORLAX_H_
#define _BASICAI_SNORLAX_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Snorlax : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Player* player;							// ponteiro para jogador
	Vector speed;								// velocidade e direção
	float factor;								// fator de escala

public:
	Snorlax(float pX, float pY, Player* p);		// construtor
	~Snorlax();									// destrutor

	void OnCollision(Object* obj);				// resolução da colisão
	void Update();								// atualização
	void Draw();								// desenho
};

// ---------------------------------------------------------------------------------

inline void Snorlax::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif