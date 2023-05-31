#pragma once
#include "Vec2.h"
#include "DxLib.h"

namespace
{
	//ƒuƒƒbƒN‚Ì”
	constexpr int num = 3;
}

class Block
{
public:
	Block();
	virtual ~Block();

	void Init();
	void Update();
	void Draw();

	float dLeft[3], dTop[3], dRight[3], dBottom[3];
	float uLeft[3], uTop[3], uRight[3], uBottom[3];

	bool blockFlag[3];

	int passCount;

private:
	
	/// <summary>
	/// Block‚Ì‹¤’Êˆ—
	/// </summary>
	/// <param name="i">”Ô†</param>
	/// <param name="speed">‘¬‚³</param>
	/// <param name="narrowness">Œ„ŠÔ‚Ì‹·‚³</param>
	void BlockUpdate(int i, int speed, int narrowness);

	Vec2 m_pos[3];

	int pipeHandle[15];

	int m_timeCount;

	int narrow;

	bool passFlag;
};

//git‚É‚±‚İ‚Á‚Æ
