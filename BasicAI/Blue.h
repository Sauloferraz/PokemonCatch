/**********************************************************************************
// Blue (Arquivo de Cabe�alho)
// 
// Cria��o:		10 Out 2012
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Objeto faz uma persegui��o suavizada
//
**********************************************************************************/

#ifndef _BASICAI_BLUE_H_
#define _BASICAI_BLUE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"
#include "Font.h"

// ---------------------------------------------------------------------------------

class Blue : public Object
{
private:
	Sprite * sprite;							// sprite do objeto
	Player * player;							// ponteiro para jogador
	Font* name;
	Vector speed;								// velocidade e dire��o
	float factor;								// fator de escala
	
public:
	Blue(float pX, float pY, Player * p);		// construtor
	~Blue();									// destrutor
	
	void OnCollision(Object* obj);				// resolu��o da colis�o
	void Update();								// atualiza��o
	void Draw();								// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Blue::Draw() {
	sprite->Draw(x, y, Layer::MIDBACK, scale, rotation);
	name->Draw(x - game->viewport.left - 15, y - game->viewport.top - 35, "Bulbasaur", *new Color(0, 0, 0, 1));
}

// ---------------------------------------------------------------------------------


#endif