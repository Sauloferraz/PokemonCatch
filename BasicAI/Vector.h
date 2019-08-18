/**********************************************************************************
// Vector (Arquivo de Cabe�alho)
// 
// Cria��o:		18 Nov 2011
// Atualiza��o:	16 Jul 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Classe para representar um vetor
//
**********************************************************************************/

#ifndef _DESENVJOGOS_VECTOR_H_
#define _DESENVJOGOS_VECTOR_H_

// --------------------------------------------------------------------------------

#include <cmath>

// --------------------------------------------------------------------------------

class Vector
{
private:
	static const double PI;									// constante PI

public:
	float angle;											// �ngulo do vetor com a horizontal
	float magnitude;										// magnitude do vetor

	Vector();												// construtor padr�o
	Vector(float ang, float mag);							// constructor com �ngulo e magnitude

	void Rotate(float theta);								// rotaciona vetor por �ngulo em graus
	void Scale(float factor);								// amplia ou reduz vetor por um fator
	void Add(const Vector& v);							    // adiciona vetor recebido por par�metro
	
	static float Angle(float x1, float y1, 
		               float x2, float y2);					// retorna o �ngulo formado pelos pontos (x1,y1) e (x2,y2)
	
	static float Distance(float x1, float y1, 
		                  float x2, float y2);				// retorna a dist�ncia entre os pontos (x1,y1) e (x2,y2) 

	float XCom() const;										// retorna componente X do vetor
	float YCom() const; 									// retorna componente Y do vetor
	float Radians() const;									// retorna �ngulo em radianos
}; 

// ---------------------------------------------------------------------------------
// Fun��es Membro Inline

// retorna componente X do vetor
inline float Vector::XCom() const
{ return magnitude * cos(Radians()); }	

// retorna componente Y do vetor
inline float Vector::YCom() const
{ return magnitude * sin(Radians()); }	

// retorna �ngulo em radianos
inline float Vector::Radians() const
{ return float(angle * PI / 180.0); }

// ------------------------------------------------------------------------------



#endif