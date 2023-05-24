#pragma once
#include "Vec2.h"

class Block;

class Score
{
public:
	Score();
	virtual ~Score();

	void Init();
	void Update(Block& block);
	void Draw();

private:
	Vec2 m_pos;

	int numFontHandle[10];
	int a[3];

};

