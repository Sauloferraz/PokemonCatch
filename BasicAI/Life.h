#ifndef Life_h
#define Life_h

// Inclusões ------
#include "Object.h"
#include "Animation.h"
// ----------------

// Life --------------------
class Life : public Object {
private:
	TileSet* life;
	Animation* lifeAnim;

	float lifeSize = 188;
public:
	Life();
	~Life();
	void Update();
	void Draw();
	void Damage(float damage);
	int Size();
};
// ----------------------------

#endif 