#include "Hitmonlee.h"
#include "BasicAI.h"
#include "Random.h" 
#include "Explosion.h"

// ---------------------------------------------------------------------------------

Hitmonlee::Hitmonlee(float pX, float pY, Player* p)
{
	player = p;
	sprite = new Sprite("Resources/Hitmonlee.png");
	name = new Font("Resources/Tahoma14b.png");
	name->Spacing("Resources/Tahoma14b.dat");
	bbox = new Circle(20.0f);
	speed.angle = 0.0f;
	speed.magnitude = 0.0f;

	// mantém certa distância do jogador
	IntRand dist{ 100, 300 };
	distance = dist.Rand();

	MoveTo(pX, pY);
	type = HITMONLEE;
	++Hud::hitmonlee;

}

// ---------------------------------------------------------------------------------

Hitmonlee::~Hitmonlee()
{
	delete sprite;
	delete bbox;

	// decrementa contador
	--Hud::hitmonlee;
}

// -------------------------------------------------------------------------------

void Hitmonlee::OnCollision(Object* obj)
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

void Hitmonlee::Update()
{
	// a magnitude do vetor target controla quão 
	// rápido o objeto converge para a direção do alvo
	Vector target = Vector(speed.Angle(x, y, player->X(), player->Y()), 20.0f * gameTime);

	speed.Add(target);

	// limita a magnitude da velocidade para impedir 
	// seu crescimento indefinido na soma vetorial
	if (speed.magnitude > 10)
		speed.magnitude = 10.0f;

	// move o objeto pelo seu vetor velocidade
	Translate(speed.XCom() * 50.0f * gameTime, -speed.YCom() * 50.0f * gameTime);
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