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

#ifndef _BASICAI_GREEN_H_
#define _BASICAI_GREEN_H_

// ---------------------------------------------------------------------------------

#include "Object.h"	
#include "Types.h"
#include "Sprite.h"
#include "Vector.h"
#include "Player.h"
#include "Font.h"

// ---------------------------------------------------------------------------------

class Green : public Object
{
private:
	Sprite * sprite;							// sprite do objeto
	Player * player;							// ponteiro para jogador
	Font* name;
	Vector speed;								// velocidade e dire��o
	int distance;								// mant�m dist�ncia do jogador
	
public:
	Green(float pX, float pY, Player * p);		// construtor
	~Green();									// destrutor
	
	void OnCollision(Object* obj);				// resolu��o da colis�o
	void Update();								// atualiza��o
	void Draw();								// desenho
}; 

// ---------------------------------------------------------------------------------

inline void Green::Draw()
{ sprite->Draw(x, y, Layer::MIDBACK, scale, rotation); 
name->Draw(x - game->viewport.left, y - game->viewport.top - 35, "Pikachu", *new Color(0, 0, 0, 1));
}

// ---------------------------------------------------------------------------------


#endif