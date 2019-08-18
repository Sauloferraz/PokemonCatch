/**********************************************************************************
// Object (Arquivo de Cabe�alho)
//
// Cria��o:		01 Out 2007
// Atualiza��o:	02 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Essa � a classe base para todos objetos do jogo.
//
//				Um objeto do jogo � qualquer coisa que poss�mos querer desenhar
//				ou interagir dentro do jogo. Por exemplo, um soldado, um pr�dio,
//				um proj�til, uma forma geom�trica, etc.
//
**********************************************************************************/

#ifndef _DESENVJOGOS_OBJECT_H_
#define _DESENVJOGOS_OBJECT_H_

// -----------------------------------------------------------------------------

#include "Types.h"				// tipos espec�ficos do motor
#include "Game.h"				// representa��o de um jogo
#include "Window.h"				// janela utilizada no jogo
#include "Geometry.h"			// geometria para a bounding box

// -----------------------------------------------------------------------------

class Object
{
protected:
	static Window* & window;	// janela do jogo
	static Game*   & game;		// jogo em que o objeto est� inserido
	static float   & gameTime;	// tempo do �ltimo quadro

	float x, y, z;				// coordenadas do objeto
	float scale;				// escala do objeto
	float rotation;				// rota��o do objeto
	uint type;					// tipo do objeto
	Geometry * bbox;			// bounding box do objeto

public:
	Object();					// construtor padr�o de um objeto
	virtual ~Object();			// destrutor virtual

	// ------------------------
	// fun��es virtuais	
	// ------------------------
	// podem ser sobrescritas na classe derivada
	// e chamadas corretamente mesmo usando um
	// ponteiro para a classe base

	// retorna coordenada x do objeto
	virtual float X() const;

	// retorna coordenada y do objeto
	virtual float Y() const;

	// retorna coordenada z do objeto
	virtual float Z() const;

	// retorna a escala do objeto
	virtual float Scale() const;

	// retorna a rota��o do objeto
	virtual float Rotation() const;

	// retorna tipo do objeto
	virtual uint Type() const;

	// retorna a bounding box do objeto
	virtual Geometry * BBox() const;

	// move o objeto por (dx, dy, dz)
	virtual void Translate(float dx, float dy, float dz = 0.0f);

	// move o objeto para as coordenadas (px, py, pz)
	virtual void MoveTo(float px, float py, float pz);

	// move o objeto para as coordenadas (px, py)
	virtual void MoveTo(float px, float py);

	// amplia ou reduz objeto pelo fator
	virtual void Scale(float factor);

	// ajusta escala para novo valor
	virtual void ScaleTo(float factor);

	// rotaciona geometria pelo �ngulo
	virtual void Rotate(float angle);

	// ajusta rota��o para novo valor
	virtual void RotateTo(float angle);

	// faz a resolu��o de colis�o do objeto
	virtual void OnCollision(Object * obj);

	// ------------------------
	// fun��es virtuais puras	
	// ------------------------	 
	// devem ser obrigatoriamente sobrescritas na classe derivada

	// atualiza estado do objeto
	virtual void Update() = 0;

	// desenha o objeto na tela
	virtual void Draw() = 0;
};

// -----------------------------------------------------------------------------
// M�todos Inline

// retorna coordenada x do objeto
inline float Object::X() const
{ return x; }

// retorna coordenada y do objeto
inline float Object::Y() const
{ return y; }

// retorna coordenada z do objeto
inline float Object::Z() const
{ return z; }

// retorna a escala do objeto
inline float Object::Scale() const
{ return scale; }

// retorna a rota��o do objeto
inline float Object::Rotation() const
{ return rotation; }

// retorna o tipo do objeto
inline uint Object::Type() const
{ return type; }

// retorna a bounding box do objeto
inline Geometry * Object::BBox() const
{ return bbox; }

// -----------------------------------------------------------------------------

#endif


