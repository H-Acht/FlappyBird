#pragma once
#include "Vec2.h"
#include "DxLib.h"

class Block
{
public:
	Block();
	virtual ~Block();

	void Init();

	/// <summary>
	/// ïÕxm[}
	/// </summary>
	void Update();

	/// <summary>
	/// ïÕxn[h
	/// </summary>
	void Update2();
	
	void Draw();

	float dLeft[2], dTop[2], dRight[2], dBottom[2];
	float uLeft[2], uTop[2], uRight[2], uBottom[2];

	bool blockFlag[2];

	int passCount;

private:
	
	/// <summary>
	/// BlockÌ¤Ê
	/// </summary>
	/// <param name="i">Ô</param>
	/// <param name="speed">¬³</param>
	/// <param name="narrowness">ÔÌ·³</param>
	void BlockUpdate(int i, int speed, int narrowness);

	Vec2 m_pos[2];

	int pipeHandle;

	int m_timeCount;
};

