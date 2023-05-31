#include "game.h"
#include "SceneMain.h"
#include "Player.h"
#include "Block.h"
#include "BackGround.h"
#include "Score.h"
#include "SceneTitle.h"

SceneMain::SceneMain() :
	m_isEnd(false),
	m_pPlayer(nullptr),
	m_pBack(nullptr),
	m_pBlock(nullptr),
	m_pScore(nullptr),
	titleFont(0),
	Font(0),
	select(0),
	returnFlag(false),
	selectFlag(false)
{
	//リソース読み込み
	font_path = "Data/Font/azuki.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
}

SceneMain::~SceneMain()
{
	m_pPlayer = nullptr;
	m_pBack = nullptr;
	m_pBlock = nullptr;
	m_pScore = nullptr;
	
	delete(m_pPlayer);
	delete(m_pBack);
	delete(m_pBlock);
	delete(m_pScore);

	DeleteFontToHandle(titleFont);
	DeleteFontToHandle(Font);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}

}

void SceneMain::init()
{
	// メモリの確保
	m_pPlayer = new Player;
	m_pBack = new BackGround;
	m_pBlock = new Block;
	m_pScore = new Score;

	// プレイヤーの初期化処理
	m_pPlayer->Init();
	m_pBack->Init();
	m_pBlock->Init();
	m_pScore->Init();


	titleFont = CreateFontToHandle("あずきフォント", 64, -1, -1);
	Font = CreateFontToHandle("あずきフォント", 48, -1, -1);

	m_pos.x = 500;
	m_pos.y = -600;

	m_textPos.x = 620;
	m_textPos.y = -500;

	m_textPos2.x = 600;
	m_textPos2.y = -250;

	m_textPos3.x = 780;
	m_textPos3.y = -250;

	m_hiScore.x = 690;
	m_hiScore.y = -400;
}

SceneBase* SceneMain::update()
{
	// プレイヤーのアップデート処理
	if (m_pPlayer->gameOver == false)
	{
		m_pPlayer->Update(*m_pBlock);
		m_pBack->Update();
		m_pBlock->Update();
		m_pScore->Update(*m_pBlock);
	}
	else
	{
		GameOverScreenUpdate();
	}
	
	if (returnFlag == true)
	{
		return (new SceneTitle);
	}

	return this;
}

void SceneMain::draw()
{
	// プレイヤーの描画
	m_pBack->Draw();
	m_pPlayer->Draw();
	m_pBlock->Draw();
	m_pScore->Draw();
	
	GameOverScreenDraw();
}

void SceneMain::GameOverScreenUpdate()
{
	if (m_pos.y < 200)
	{
		m_pos.y += 10;
		m_textPos.y += 10;
		m_textPos2.y += 10;
		m_textPos3.y += 10;
		m_hiScore.y += 10;
	}
	else
	{
		selectFlag = true;
	}

	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	static int push = 0;

	if (selectFlag == true)
	{
		if (select == 0)
		{
			m_textPos2.x = 600;
			m_textPos2.y = 550;

			m_textPos2.x += GetRand(5);
			m_textPos2.y += GetRand(5);

			if (padState & PAD_INPUT_LEFT || padState & PAD_INPUT_RIGHT)
			{
				if (push == 0)
				{
					select = 1;
				}
				push = 1;
			}
			else
			{
				push = 0;
			}

			if (padState & PAD_INPUT_1)
			{
				selectFlag = false;
				SceneMain::init();
			}
		}
		if (select == 1)
		{
			m_textPos3.x = 780;
			m_textPos3.y = 550;

			m_textPos3.x += GetRand(5);
			m_textPos3.y += GetRand(5);

			if (padState & PAD_INPUT_LEFT || padState & PAD_INPUT_RIGHT)
			{
				if (push == 0)
				{
					select = 0;
				}
				push = 1;
			}
			else
			{
				push = 0;
			}

			if (padState & PAD_INPUT_1)
			{
				selectFlag = false;
				returnFlag = true;
			}
		}
	}
}

void SceneMain::GameOverScreenDraw()
{
	DrawBox(m_pos.x - 5, m_pos.y - 5, m_pos.x + 505, m_pos.y + 505, GetColor(0, 0, 0), true);
	DrawBox(m_pos.x, m_pos.y, m_pos.x + 500, m_pos.y + 500, GetColor(255, 255, 255), true);
	DrawStringToHandle(m_textPos.x, m_textPos.y, "Gameover", GetColor(0, 0, 0), titleFont);
	DrawStringToHandle(m_textPos2.x, m_textPos2.y, "Retry", GetColor(0, 0, 0), Font);
	DrawStringToHandle(m_textPos3.x, m_textPos3.y, "Title", GetColor(0, 0, 0), Font);

	DrawStringToHandle(m_hiScore.x, m_hiScore.y, "Score", GetColor(0, 0, 0), Font);
	
}
