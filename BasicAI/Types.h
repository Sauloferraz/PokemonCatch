/**********************************************************************************
// Types (Arquivo de Cabe�alho)
// 
// Cria��o:		02 Abr 2011
// Atualiza��o:	02 Ago 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Isola os tipos espec�ficos da plataforma fornecendo tipos
//				consistentes para o Motor de Jogo.
//
**********************************************************************************/

#ifndef _DESENVJOGOS_TYPES_H_
#define _DESENVJOGOS_TYPES_H_

// nomes para tipos padr�es da linguagem C++ usados na engine
typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef unsigned long		ulong;
typedef long long			llong;
typedef unsigned long long	ullong;
typedef unsigned int		uint;

struct Canvas
{
	float width;			// largura da �rea do jogo
	float height;			// altura da �rea do jogo
	float centerX;			// centro da �rea do jogo no eixo x
	float centerY;			// centro da �rea do jogo no eixo y
};

struct ViewPort
{
	float left;				// coordenada x1
	float top;				// coordenada y1
	float right;			// coordenada x2
	float bottom;			// coordenada y2
};

#endif