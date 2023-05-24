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

	//�\���ʒu
	Vec2 m_pos;


private:
	
	//�ړ���
	Vec2 m_vec;

	float m_left;
	float m_right;
	float m_top;
	float m_bottom;

	int m_playerHandle;
	
	float m_yAdd;

	int m_push;

};

