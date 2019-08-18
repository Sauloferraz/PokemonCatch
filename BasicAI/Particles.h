/**********************************************************************************
// Particles (Arquivo de Cabe�alho)
// 
// Cria��o:		07 Out 2012
// Atualiza��o:	30 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define um sistema de part�culas
//
**********************************************************************************/

#ifndef _DESENVJOGOS_PARTICLES_H_
#define _DESENVJOGOS_PARTICLES_H_

// ---------------------------------------------------------------------------------

#include "Sprite.h"											// desenho de sprites
#include "Timer.h"											// controle do tempo
#include "Types.h"											// tipos espec�ficos da engine
#include "Vector.h"											// representa��o de vetores
#include <vector>											// vetores de elementos
#include <random>											// n�meros aleat�rios

// ---------------------------------------------------------------------------------

using std::vector;
using std::random_device;
using std::uniform_real_distribution;
using std::mt19937;
using Rnd = uniform_real_distribution<float>;

// ---------------------------------------------------------------------------------

struct Emitter
{
	string imgFile;											// arquivo de imagem da part�cula
	float  angle;											// dire��o do emissor de part�culas
	float  spread;											// �ngulo de espalhamento das part�culas
	float  lifeTime;										// tempo de vida das part�culas
	float  genTime;											// tempo entre gera��o de part�culas
	float  percToDim;										// percentual de vida para come�ar a desaparecer
	float  minSpeed;										// velocidade m�nima das part�culas
	float  maxSpeed;										// velocidade m�xima das part�culas
	float  r, g, b, a;										// cor das part�culas
};

struct Particle
{
	float  x, y;											// posi��o da part�cula
	Vector speed;											// dire��o e velocidade
	llong  timeStamp;										// instante de cria��o
};

// ---------------------------------------------------------------------------------

class Particles
{
private:
	Emitter emitter;										// emissor de part�culas
	Sprite * sprite;										// sprite da part�cula	
	vector<Particle*> particles;							// vetor de part�culas

	Timer timer;											// controle de tempo
	
	random_device rd;										// gerador de semente
	mt19937 mt{ rd() };										// gerador de n�mero aleat�rio
	Rnd randSpread { -emitter.spread, emitter.spread };		// valores aleat�rios para o espalhamento
	Rnd randSpeed { emitter.minSpeed, emitter.maxSpeed };	// valores aleat�rios para a velocidade

	void Build(float posX, float posY);						// cria uma part�cula

public:
	Particles(const Emitter & desc);						// construtor
	~Particles();											// destrutor

	int  Size();											// retorna o n�mero de part�culas
	bool Inactive();										// retorna o estado das part�culas
	Emitter& Generator();									// retorna ponteiro para o emissor
	void Generate(float x, float y, int amount = 1);		// gera novas part�culas
	void Update(float delta);								// atualiza posi��o das part�culas por delta
	void Draw(float z, float factor = 0.0f);				// desenha part�culas		
}; 

// ---------------------------------------------------------------------------------

inline Emitter & Particles::Generator()
{ return emitter; }

inline int Particles::Size()
{ return particles.size(); }

inline bool Particles::Inactive()
{ return (particles.size() == 0); }

// ---------------------------------------------------------------------------------

#endif