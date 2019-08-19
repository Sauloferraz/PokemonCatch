#ifndef GameOver_h
#define GameOver_h

#include "Game.h"
#include "Sprite.h"
#include "Font.h"
#include <sstream>
using std::stringstream;

class GameOver : public Game {
private:
	Sprite* sprite;
	Font* font;

	stringstream text;

public:
	void Init();					// inicializa��o
	void Update();					// atualiza��o
	void Draw();					// desenho
	void Finalize();				// finaliza��o
};

#endif
