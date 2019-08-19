#ifndef _BASICAI_ZUBAT_H_
#define _BASICAI_ZUBAT_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Zubat : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Player* player;							// ponteiro para jogador
	Vector speed;								// velocidade e dire��o
	int distance;								// mant�m dist�ncia do jogador

public:
	Zubat(float pX, float pY, Player* p);		// construtor
	~Zubat();									// destrutor

	void OnCollision(Object* obj);				// resolu��o da colis�o
	void Update();								// atualiza��o
	void Draw();								// desenho
};

// ---------------------------------------------------------------------------------

inline void Zubat::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif