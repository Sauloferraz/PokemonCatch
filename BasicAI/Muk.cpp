/**********************************************************************************
// Magenta (Código Fonte)
//
// Criação:		10 Out 2012
// Atualização:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descrição:	Objeto faz um perseguição direta
//
**********************************************************************************/

#include "BasicAI.h"
#include "Muk.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Muk::Muk(float pX, float pY, Player* p)
{
	player = p;
	sprite = new Sprite("Resources/muk.png");
	bbox = new Circle(18.0f);

	speed.angle = 0;
	speed.magnitude = 2.0f;

	MoveTo(pX, pY);
	type = MUK;

	// incrementa contador
	++Hud::muk;
}

// ---------------------------------------------------------------------------------

Muk::~Muk()
{
	delete sprite;
	delete bbox;

	// decrementa contador
	--Hud::muk;
}

// -------------------------------------------------------------------------------

void Muk::OnCollision(Object* obj)
{
	if (obj->Type() == MISSILE)
	{
		BasicAI::scene->Delete(obj, STATIC);
		BasicAI::scene->Delete(this, MOVING);
		BasicAI::scene->Add(new Explosion(x, y), STATIC);
		BasicAI::audio->Play(EXPLODE);
		++Hud::captures;
	}
}

// -------------------------------------------------------------------------------

void Muk::Update()
{
	// ajusta ângulo do vetor 
	speed.angle = speed.Angle(x, y, player->X(), player->Y());
	//Rotate(200 * gameTime);

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed.XCom() * 60.0f * gameTime, -speed.YCom() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------