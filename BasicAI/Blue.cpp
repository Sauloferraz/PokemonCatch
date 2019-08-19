/**********************************************************************************
// Blue (C�digo Fonte)
// 
// Cria��o:		10 Out 2012
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Objeto faz uma persegui��o suavizada
//
**********************************************************************************/

#include "BasicAI.h"
#include "Blue.h"
#include "Random.h" 
#include "Hud.h"
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Blue::Blue(float pX, float pY, Player* p)
{
	player = p;
	sprite = new Sprite("Resources/Bulba.png");
	bbox   = new Circle(20.0f);
	name = new Font("Resources/Tahoma14b.png");
	name->Spacing("Resources/Tahoma14b.dat");
	speed.angle = 0.0f;
	speed.magnitude = 0.0f;
	MoveTo(pX, pY);
	factor = 2.0f;
	type = BLUE;

	// incrementa contador
	++Hud::blues;
}

// ---------------------------------------------------------------------------------

Blue::~Blue()
{
	delete sprite;
	delete bbox;

	// decrementa contador
	--Hud::blues;
}

// -------------------------------------------------------------------------------

void Blue::OnCollision(Object * obj)
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

void Blue::Update()
{
	// a magnitude do vetor 'target' controla qu�o 
	// r�pido o objeto converge para a dire��o do alvo
	Vector target = Vector(speed.Angle(x, y, player->X(), player->Y()), 2.0f * gameTime);
	speed.Add(target);
	
	// limita a magnitude da velocidade para impedir 
	// que ela cres�a indefinidamente pelo soma vetorial
	if (speed.magnitude > 4.5)
		speed.magnitude = 4.5f;

	// move o objeto pelo seu vetor velocidade
	Translate(speed.XCom() * 50.0f * gameTime, -speed.YCom() * 50.0f * gameTime);

	// aplica fator de escala
	//Scale(1.0f + factor * gameTime);

	// amplia e reduz objeto
	/*if (scale < 0.85f)
		factor = 0.25f;
	if (scale > 1.00f)
		factor = -0.25f;*/

	// mant�m o objeto dentro do mundo do jogo
	if (x < 50)
		MoveTo(50, y);
	if (y < 50)
		MoveTo(x, 50);
	if (x > game->Width() - 50)
		MoveTo(game->Width() - 50, y);
	if (y > game->Height() - 50)
		MoveTo(x, game->Height() - 50);
}

// -------------------------------------------------------------------------------