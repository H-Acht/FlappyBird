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
	/// 難易度ノーマル
	/// </summary>
	void Update();

	/// <summary>
	/// 難易度ハード
	/// </summary>
	void Update2();
	
	void Draw();

	float dLeft[2], dTop[2], dRight[2], dBottom[2];
	float uLeft[2], uTop[2], uRight[2], uBottom[2];

	bool blockFlag[2];

	int passCount;

private:
	
	/// <summary>
	/// Blockの共通処理
	/// </summary>
	/// <param name="i">番号</param>
	/// <param name="speed">速さ</param>
	/// <param name="narrowness">隙間の狭さ</param>
	void BlockUpdate(int i, int speed, int narrowness);

	Vec2 m_pos[2];

	int pipeHandle;

	int m_timeCount;
};

