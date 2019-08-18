// Incluclões ---
#include "Life.h"
// --------------

Life::Life() {

	life = new TileSet("Resources/Life.png", lifeSize, 3, 1, 1);
	lifeAnim = new Animation(life, 1, true);
	MoveTo(230, 40);
}

Life::~Life() {
	delete life;
}

void Life::Update() {

}

void Life::Draw() {
	lifeAnim->Draw(game->viewport.left + 140, game->viewport.top + 100, Layer::FRONT);
}

void Life::Damage(float damage) {
	lifeSize -= damage;
	if (lifeSize < 0) {
		lifeSize = 0;
	}

	life = new TileSet("Resources/Life.png", lifeSize, 3, 1, 1);
	lifeAnim = new Animation(life, 1, true);
	MoveTo(x - damage / 2, 40);
}

int Life::Size() {
	return lifeSize;
}
