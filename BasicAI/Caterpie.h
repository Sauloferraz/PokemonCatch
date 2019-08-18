#ifndef _BASICAI_CATERPIE_H_
#define _BASICAI_CATERPIE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

class Caterpie : public Object
{
private:
	Sprite* sprite;							// sprite do objeto
	Player* player;							// ponteiro para jogador
	Vector speed;								// velocidade e dire��o
	int distance;								// mant�m dist�ncia do jogador

public:
	Caterpie(float pX, float pY, Player* p);		// construtor
	~Caterpie();									// destrutor

	void OnCollision(Object* obj);				// resolu��o da colis�o
	void Update();								// atualiza��o
	void Draw();								// desenho
};

// ---------------------------------------------------------------------------------

inline void Caterpie::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif