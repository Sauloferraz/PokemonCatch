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
	void Init();					// inicialização
	void Update();					// atualização
	void Draw();					// desenho
	void Finalize();				// finalização
};

#endif
