#include "Block.h"

Block::Block():
	blockFlag(),
	dLeft(),
	dTop(),
	dRight(),
	dBottom(),
	uLeft(),
	uTop(),
	uRight(),
	uBottom(),
	passCount(0),
	pipeHandle(-1),
	m_timeCount(0)
{
}

Block::~Block()
{
	m_timeCount = 0;
}

void Block::Init()
{
	for (int i = 0; i < 2; i++)
	{
		m_pos[i].x = 1800;
		m_pos[i].y = 0;
		
		dLeft[i] = 1800;
		dRight[i] = 1860;
		dTop[i] = 0;
		dBottom[i] = 900;

		uLeft[i] = 1800;
		uRight[i] = 1860;
		uTop[i] = 0;
		uBottom[i] = 0;
	}
	passCount = 0;
}

void Block::Update()
{
	m_timeCount++;
	
	BlockUpdate(0, 6, 120);

	if (m_timeCount > 150)
	{
		BlockUpdate(1, 6, 120);
	}
}

void Block::Update2()
{	
	m_timeCount++;

	BlockUpdate(0, 7, 100);

	if (m_timeCount > 150)
	{
		BlockUpdate(1, 7, 100);
	}

}

void Block::Draw()
{
	for (int i = 0; i < 2; i++)
	{
		//デバッグ表示
		//下
		DrawBox(m_pos[i].x, m_pos[i].y, m_pos[i].x + 60, 900, GetColor(255, 0, 0), true);
		//上
		DrawBox(m_pos[i].x, 0, m_pos[i].x + 60, m_pos[i].y - 120, GetColor(255, 0, 0), true);

		//当たり判定
		DrawBox(dLeft[i], dTop[i], dRight[i], dBottom[i], GetColor(0, 0, 255), false);
		DrawBox(uLeft[i], uTop[i], uRight[i], uBottom[i], GetColor(0, 0, 255), false);
	}
}

void Block::BlockUpdate(int i, int speed, int narrowness)
{
	if (blockFlag[i] == true)
	{
		m_pos[i].x -= speed;

		dLeft[i] -= speed;
		dRight[i] -= speed;

		uLeft[i] -= speed;
		uRight[i] -= speed;

		if (m_pos[i].x <= 0)
		{
			passCount++;

			blockFlag[i] = false;
		}
	}
	else
	{
		m_pos[i].x = 1800;
		dLeft[i] = 1800;
		dRight[i] = 1860;

		uLeft[i] = 1800;
		uRight[i] = 1860;

		m_pos[i].y = GetRand(800);
		dTop[i] = m_pos[i].y;
		uBottom[i] = m_pos[i].y - narrowness;

		blockFlag[i] = true;

		if (m_pos[i].y < 200)
		{
			m_pos[i].x = 1800;

			blockFlag[i] = false;
		}
	}
}
