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
#include "Magenta.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Magenta::Magenta(float pX, float pY, Player * p)
{
	player = p;
	sprite = new Sprite("Resources/nido.png");
	name = new Font("Resources/Tahoma14b.png");
	name->Spacing("Resources/Tahoma14b.dat");
	Point nido[25] =
	{
		Point(-29,-38), Point(-31,-33), Point(-41,-31), Point(-37,-19), Point(-34, -6),
		Point(-41, -3), Point(-40, 5), Point(-34, 8), Point(-32, 13), Point(-29, 23),
		Point(-12, 36), Point(8, 34), Point(20,28), Point(29, 10), Point(40,0),
		Point(29, -2), Point(28, -8), Point(27, -24), Point(30, -32), Point(25, -31),
		Point(24, -37), Point(11, -34), Point(5, -26), Point(-4, -36), Point(-10, -32)
	};

	bbox = new Poly(nido, 25);
	
	speed.angle = 0;
	speed.magnitude = 2.0f;
	
	MoveTo(pX, pY);
	type = MAGENTA;

	// incrementa contador
	++Hud::magentas;
}

// ---------------------------------------------------------------------------------

Magenta::~Magenta()
{
	delete sprite;
	delete bbox;

	// decrementa contador
	--Hud::magentas;
}

// -------------------------------------------------------------------------------

void Magenta::OnCollision(Object * obj)
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

void Magenta::Update()
{
	// ajusta ângulo do vetor 
	speed.angle = speed.Angle(x, y, player->X(), player->Y());
	//Rotate(200 * gameTime);

	// movimenta objeto pelo seu vetor velocidade
	Translate(speed.XCom() * 60.0f * gameTime, -speed.YCom() * 60.0f * gameTime);
}

// -------------------------------------------------------------------------------