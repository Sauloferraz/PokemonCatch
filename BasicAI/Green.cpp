/**********************************************************************************
// Green (C�digo Fonte)
// 
// Cria��o:		15 Out 2012
// Atualiza��o:	10 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Objeto faz uma fuga suavizada
//
**********************************************************************************/

#include "Green.h"
#include "BasicAI.h"
#include "Random.h" 
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Green::Green(float pX, float pY, Player * p)
{
	player = p;
	sprite = new Sprite("Resources/pika.png");
	Point pika[11] =
	{
		Point(0,19),Point(14, 13),Point(14.6, 3),Point(13.6, -6),
		Point(19, -18.5),Point(6.8, -12),Point(-6.6, -12),Point(-19, -18),
		Point(-13, -6.3),Point(-14.6, 3),Point(-16, 10)
	};

	bbox = new Poly(pika, 11);
	name = new Font("Resources/Tahoma14b.png");
	name->Spacing("Resources/Tahoma14b.dat");
	speed.angle = 0.0f;
	speed.magnitude = 0.0f;

	// mant�m certa dist�ncia do jogador
	IntRand dist{ 100, 300 };
	distance = dist.Rand();

	MoveTo(pX, pY);
	type = GREEN;
	++Hud::greens;

}

// ---------------------------------------------------------------------------------

Green::~Green()
{
	delete sprite;
	delete bbox;

	// decrementa contador
	--Hud::greens;
}

// -------------------------------------------------------------------------------

void Green::OnCollision(Object * obj)
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

void Green::Update()
{
	// a magnitude do vetor target controla qu�o 
	// r�pido o objeto converge para a dire��o do alvo
	Vector target = Vector(speed.Angle(x, y, player->X(), player->Y()), 20.0f * gameTime);
	
	// fugir se o player chegar muito perto
	if (speed.Distance(x, y, player->X(), player->Y()) < distance)
	{
		target.Rotate(180.0f);
		target.magnitude = 20.0f * gameTime;
	}

	speed.Add(target);
	
	// limita a magnitude da velocidade para impedir 
	// seu crescimento indefinido na soma vetorial
	if (speed.magnitude > 5)
		speed.magnitude = 5.0f;

	// move o objeto pelo seu vetor velocidade
	Translate(speed.XCom() * 50.0f * gameTime, -speed.YCom() * 50.0f * gameTime);
	//Rotate(50 * gameTime);

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