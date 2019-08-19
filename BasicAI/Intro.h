#ifndef Intro_h
#define Intro_h

// Inclusoes ----------
#include "Game.h"
#include "Animation.h"
#include "Background.h"
#include "Audio.h"
// --------------------

// Intro ----------------------------
class Intro : public Game {
private:
	// Logomarca ------------------
	TileSet* glasses = nullptr;
	Animation* glassesA = nullptr;
	// ----------------------------

	Background* background = nullptr;

	float alpha = 0.0f;	// Traparência da logomarca
	float timer = 8.0f;	// Cronômetro da cena (Segundos)

	bool start = false;	// Detecta se audio já começou
	bool start2 = false;	// Detecta se audio já começou

public:
	void Init();		// Inicializa a senha
	void Finalize();	// Finaliza a senha
	void Update();		// Atualiza a senha
	void Draw();		// Desenha a senha
};
// ----------------------------------

#endif
