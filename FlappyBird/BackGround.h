#pragma once
#include "Vec2.h"

class BackGround
{
public:
	BackGround();
	virtual ~BackGround();

	void Init();
	void Update();
	void Draw();
private:

	//�\���ʒu
	Vec2 m_pos[2];

	int m_backHandle;
};

