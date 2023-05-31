#include "Player.h"
#include "game.h"
#include "Block.h"

Player::Player() :
	m_yAdd(0),
	m_left(0),
	m_right(0),
	m_top(0),
	m_bottom(0),
	m_push(0),
	gameOver(false),
	PL(0),
	playerAnimation(0),
	extend(0.0f)
{
	m_playerHandle = LoadGraph("Data/Player.png");
}

Player::~Player()
{
	DeleteGraph(m_playerHandle);
}

void Player::Init()
{
	m_left = 280.0f;
	m_right = 320.0f;
	
	m_pos.x = 300.0f;
	m_pos.y = 300.0f;
	m_yAdd = 0.0f;

	extend = 0.5f;
}

void Player::Update(Block& block)
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

#if true
	if (padState & PAD_INPUT_4)
	{
		gameOver = true;
	}
#endif

	if (padState & PAD_INPUT_2)
	{
		if (m_push == 0)
		{
			m_yAdd = -8.0f;
			m_push = 1;
			animationFlag = true;
			
		}
	}
	else
	{
		m_push = 0;
	}

	m_pos.y += m_yAdd;
	m_yAdd += 0.6f;

	m_top = m_pos.y - 20.0f;
	m_bottom = m_pos.y + 20.0f;

	//当たり判定
	for (int i = 0; i < num; i++)
	{
		if ((m_right > block.dLeft[i]) &&
			(m_left < block.dRight[i]))
		{
			if ((m_bottom > block.dTop[i]) &&
				(m_top < block.dBottom[i]))
			{
				gameOver = true;
			}
		}

		if ((m_right > block.uLeft[i]) &&
			(m_left < block.uRight[i]))
		{
			if ((m_bottom > block.uTop[i]) &&
				(m_top < block.uBottom[i]))
			{
				gameOver = true;
			}
		}
	}

	//地面、天井の当たり判定
	if (m_top < 0 || m_bottom > 900)
	{
		//プレイヤーの高さ座標が300になる(仮)
		m_pos.y = 300;
		m_top = m_pos.y - 20.0f;
		m_bottom = m_pos.y + 20.0f;

	}

	if (animationFlag == true)
	{
		PL++;
		if (PL % 2 == 0)
		{
			playerAnimation++;
			extend = 0.5;
			if (playerAnimation == 1)
			{
				extend = 0.7;
			}
			else if (playerAnimation == 3)
			{
				extend = 0.3;
			}
			else if (playerAnimation == 5)
			{
				extend = 0.5;
				playerAnimation = 0;
			}
			PL = 0;
			if (playerAnimation == 0)
			{
				animationFlag = false;
			}
		}
	}
}

void Player::Draw()
{
	// プレイヤーの描画
	//DrawRotaGraph(m_pos.x, m_pos.y, 0.5, 0, m_playerHandle, true, false);
	DrawRotaGraph(m_pos.x, m_pos.y, extend, 0, m_playerHandle, true, false);

	//デバッグ
	DrawBox(m_left, m_top, m_right, m_bottom, GetColor(255, 255, 255), false);
}
