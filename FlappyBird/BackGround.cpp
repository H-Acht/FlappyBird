#include "BackGround.h"
#include "game.h"

namespace
{
	constexpr float kMoveSpeed = 2.0f;
}

BackGround::BackGround()
{
	m_backHandle = LoadGraph("Data/background.png");
}

BackGround::~BackGround()
{
	DeleteGraph(m_backHandle);
}

void BackGround::Init()
{
	m_pos[0].x = 0.0f;
	m_pos[1].x = 1800.0f;
}

void BackGround::Update()
{
	for (int i = 0; i < 2; i++)
	{
		m_pos[i].x -= kMoveSpeed;
		
		if (m_pos[i].x == -1800)
		{
			m_pos[i].x = 1800;
		}
	}
}

void BackGround::Draw()
{	
	for (int i = 0; i < 2; i++)
	{
		DrawModiGraph(m_pos[i].x, 0, m_pos[i].x + 1800, 0, m_pos[i].x + 1800, 900, m_pos[i].x, 900, m_backHandle, true);
	}
}
