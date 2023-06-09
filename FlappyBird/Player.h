#pragma once
#include "Vec2.h"

class Block;

class Player
{
public:
	Player();
	virtual ~Player();

	void Init();
	void Update(Block& block);
	void Draw();

	//表示位置
	Vec2 m_pos;

	bool gameOver;

private:
	
	//移動量
	Vec2 m_vec;

	float m_left;
	float m_right;
	float m_top;
	float m_bottom;

	int m_playerHandle;
	
	float m_yAdd;

	int m_push;

	int PL;
	int playerAnimation;
	float extend;
	bool animationFlag;
};

