#include "Tree.h"

Tree::Tree(float x, float y) {
	bbox = new Circle(4);
	MoveTo(x, y, 0.02);

	sprite = new Sprite("Resources/tree.png");
}

Tree::~Tree() {
	delete sprite;
}

void Tree::Update() {}

void Tree::Draw() {
	sprite->Draw(x, y, z);
}
