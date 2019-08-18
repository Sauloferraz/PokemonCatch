/**********************************************************************************
// Particles (C�digo Fonte)
// 
// Cria��o:		07 Out 2012
// Atualiza��o:	30 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define um sistema de part�culas
//
**********************************************************************************/

#include "Particles.h"
#include "Geometry.h"
#include <cmath>

// ---------------------------------------------------------------------------------

Particles::Particles(const Emitter & desc) : emitter(desc)
{
	sprite = new Sprite(desc.imgFile);
	timer.Start();
}

// ---------------------------------------------------------------------------------

Particles::~Particles()
{
	delete sprite;
	for (const auto & p : particles)
		delete p;
}

// ---------------------------------------------------------------------------------

void Particles::Build(float posX, float posY)
{
	// cria part�cula
	Particle * p = new Particle();

	// ajusta posi��o
	p->x = posX;
	p->y = posY;
	
	// pega um �ngulo aleat�rio a partir do �ngulo base e espalhamento
	float angle = emitter.angle + randSpread(mt);

	// mant�m �ngulo na faixa 0 a 359 graus
	if (angle > 360)
		angle -= 360;
	else 
		if (angle < 0)
		angle += 360;
	
	// ajusta vetor velocidade da part�cula
	p->speed.angle = angle;	
	p->speed.magnitude = randSpeed(mt);
	p->timeStamp = timer.Stamp();

	// insere part�cula no vetor de part�culas
	particles.push_back(p);
}

// ---------------------------------------------------------------------------------

void Particles::Generate(float x, float y, int amount)
{
	if (amount == 1)
	{
		// gera uma part�cula por vez
		if (timer.Elapsed(emitter.genTime)) 
		{
			Build(x, y);
			timer.Start();
		}
	} 
	else 
	{	
		// gera todas as part�culas de uma vez
		for (int i = 0; i < amount; ++i)
			Build(x, y);
	}
}

// ---------------------------------------------------------------------------------

void Particles::Update(float delta)
{
	float lifePercent = 0;
	float timeElapsed = 0;

	// percorre o vetor de part�culas
	auto i = particles.begin();
	while (i != particles.end())
	{
		// para cada part�cula
		Particle * p = *i;

		// atualiza a posi��o da part�cula usando seu vetor velocidade
		p->x += p->speed.XCom() * delta;
		p->y -= p->speed.YCom() * delta;
		
		// calcula o percentual de vida da part�cula
		timeElapsed = timer.Elapsed(p->timeStamp);
		lifePercent = timeElapsed/emitter.lifeTime;

		// torna a part�cula transparente com o passar do tempo
		if (lifePercent > emitter.percToDim)
		{
			// transpar�ncia cresce cubicamente com o tempo de vida
			emitter.a = 1.0f - pow(lifePercent, 3);
		}

		if (timeElapsed > emitter.lifeTime)
		{
			// remove a part�cula sem vida
			delete p;
			i = particles.erase(i);
		}
		else
		{
			// passa para pr�xima part�cula
			++i;
		}
	}
}

// ---------------------------------------------------------------------------------

void Particles::Draw(float z, float factor)
{
	float lifePercent = 0.0f;
	float timeElapsed = 0.0f;
	
	// para cada part�cula do vetor
	for (Particle * p : particles)
	{
		// calcula o percentual de vida da part�cula
		timeElapsed = timer.Elapsed(p->timeStamp);
		lifePercent = timeElapsed/emitter.lifeTime;

		// escala cresce quadraticamente com o tempo de vida
		float scale = 1.0f + pow(lifePercent, 2) * factor;

		// desenha part�cula
		sprite->Draw(p->x, p->y, z, scale, -p->speed.angle, Color(emitter.r, emitter.g, emitter.b, emitter.a));
	}	
}

// ---------------------------------------------------------------------------------
