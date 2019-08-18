#include "Caterpie.h"
#include "BasicAI.h"
#include "Random.h" 
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Caterpie::Caterpie(float pX, float pY, Player* p)
{
	player = p;
	sprite = new Sprite("Resources/pika.png");
	bbox = new Circle(20.0f);
	speed.angle = 0.0f;
	speed.magnitude = 0.0f;

	// mantém certa distância do jogador
	IntRand dist{ 100, 300 };
	distance = dist.Rand();

	MoveTo(pX, pY);
	type = GREEN;
	++Hud::caterpies;

}

// ---------------------------------------------------------------------------------

Caterpie::~Caterpie()
{
	delete sprite;
	delete bbox;

	// decrementa contador
	--Hud::caterpies;
}

// -------------------------------------------------------------------------------

void Caterpie::OnCollision(Object* obj)
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

void Caterpie::Update()
{
	// a magnitude do vetor target controla quão 
	// rápido o objeto converge para a direção do alvo
	Vector target = Vector(speed.Angle(x, y, player->X(), player->Y()), 5.0f * gameTime);

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
	Translate(speed.XCom() * 30.0f * gameTime, -speed.YCom() * 30.0f * gameTime);
	Rotate(50 * gameTime);

	// mantém o objeto dentro do mundo do jogo
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