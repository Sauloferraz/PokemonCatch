#ifndef Tree_h
#define Tree_h

#include "Object.h"
#include "Sprite.h"

class Tree : public Object {
private:
	Sprite* sprite;
public:
	Tree(float x, float y);
	~Tree();

	void Update();
	void Draw();
};

#endif