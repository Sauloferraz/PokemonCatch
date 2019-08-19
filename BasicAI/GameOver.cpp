#include "GameOver.h"

#include "BasicAI.h"
#include "Hud.h"

void GameOver::Init() {
	sprite = new Sprite("Resources/GameOver.png");
	font = new Font("Resources/Tahoma14b.png");
	font->Spacing("Resources/Tahoma14b.dat");

	text << Hud::captures;

	BasicAI::scene = new Scene();
}

void GameOver::Update() {
	BasicAI::scene->Update();
	BasicAI::scene->CollisionDetection();
}

void GameOver::Draw() {
	BasicAI::scene->Draw();
	sprite->Draw(window->CenterX(), window->CenterY());
	font->Draw(window->CenterX(), window->CenterY(), text.str(), *new Color{0, 0, 0, 1}, 0.02, 1.4);
}

void GameOver::Finalize() {
	delete sprite;
}
