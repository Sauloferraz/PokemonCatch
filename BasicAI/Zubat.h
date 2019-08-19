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
	Vector speed;								// velocidade e direção
	int distance;								// mantém distância do jogador

public:
	Zubat(float pX, float pY, Player* p);		// construtor
	~Zubat();									// destrutor

	void OnCollision(Object* obj);				// resolução da colisão
	void Update();								// atualização
	void Draw();								// desenho
};

// ---------------------------------------------------------------------------------

inline void Zubat::Draw()
{
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
}

// ---------------------------------------------------------------------------------


#endif