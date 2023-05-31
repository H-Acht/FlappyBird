#include "Block.h"

namespace
{
	constexpr float kWide = 1950;
	constexpr float kDrawWide = kWide - 1800;
}

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
	pipeHandle(),
	m_timeCount(0),
	narrow(0),
	passFlag(false)
{
	LoadDivGraph("Data/Pipes.png", 15, 15, 1, 32, 32, pipeHandle);
}

Block::~Block()
{
	for (int i = 0; i < 15; i++)
	{
		DeleteGraph(pipeHandle[i]);
	}
}

void Block::Init()
{
	for (int i = 0; i < num; i++)
	{
		m_pos[i].x = 1800;
		m_pos[i].y = 0;
		
		dLeft[i] = 1800;
		dRight[i] = kWide;
		dTop[i] = 0;
		dBottom[i] = 900;

		uLeft[i] = 1800;
		uRight[i] = kWide;
		uTop[i] = 0;
		uBottom[i] = 0;
	}
	passCount = 0;
	m_timeCount = 0;
}

void Block::Update()
{
	m_timeCount++;

	narrow = 125;

	BlockUpdate(0, 4, narrow);

	if (m_timeCount > 150)
	{
		BlockUpdate(1, 4, narrow);
	}
	if (m_timeCount > 300)
	{
		BlockUpdate(2, 4, narrow);
	}
}

void Block::Draw()
{
	for (int i = 0; i < num; i++)
	{
#if false
		//デバッグ表示
		//下
		DrawBox(m_pos[i].x, m_pos[i].y, m_pos[i].x + kDrawWide, 900, GetColor(255, 0, 0), true);
		//上
		DrawBox(m_pos[i].x, 0, m_pos[i].x + kDrawWide, m_pos[i].y - narrow, GetColor(255, 0, 0), true);

		//当たり判定
		DrawBox(dLeft[i], dTop[i], dRight[i], dBottom[i], GetColor(0, 0, 255), false);
		DrawBox(uLeft[i], uTop[i], uRight[i], uBottom[i], GetColor(0, 0, 255), false);
#endif
		//下
		DrawModiGraph(m_pos[i].x, m_pos[i].y + 200, m_pos[i].x + kDrawWide, m_pos[i].y + 200,
			m_pos[i].x + kDrawWide, 900, m_pos[i].x, 900, 
			pipeHandle[0], true);
		
		DrawModiGraph(m_pos[i].x, m_pos[i].y, m_pos[i].x + kDrawWide, m_pos[i].y, 
			m_pos[i].x + kDrawWide, m_pos[i].y + 200, m_pos[i].x, m_pos[i].y + 200,
			pipeHandle[6], true);

		//上
		DrawModiGraph(m_pos[i].x, 0, m_pos[i].x + kDrawWide, 0,
			m_pos[i].x + kDrawWide, m_pos[i].y - narrow, m_pos[i].x, m_pos[i].y - narrow,
			pipeHandle[0], true);
		
		DrawModiGraph(m_pos[i].x, m_pos[i].y - narrow - 200, m_pos[i].x + kDrawWide, m_pos[i].y - narrow - 200,
			m_pos[i].x + kDrawWide, m_pos[i].y - narrow, m_pos[i].x, m_pos[i].y - narrow,
			pipeHandle[8], true);
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

		if (m_pos[i].x <= -kDrawWide)
		{
			passCount++;
			blockFlag[i] = false;
		}
	}
	else
	{
		m_pos[i].x = 1800;
		dLeft[i] = 1800;
		dRight[i] = kWide;

		uLeft[i] = 1800;
		uRight[i] = kWide;

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
