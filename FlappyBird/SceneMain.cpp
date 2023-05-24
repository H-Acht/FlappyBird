#include "game.h"
#include "SceneMain.h"
#include "Player.h"
#include "Block.h"
#include "BackGround.h"
#include "Score.h"

SceneMain::SceneMain() :
	m_isEnd(false),
	m_pPlayer(nullptr),
	m_pBack(nullptr),
	m_pBlock(nullptr),
	m_pScore(nullptr)
{
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
}

SceneBase* SceneMain::update()
{
	// プレイヤーのアップデート処理
	m_pPlayer->Update(*m_pBlock);
	m_pBack->Update();
	m_pBlock->Update();
	m_pScore->Update(*m_pBlock);


	return this;
}

void SceneMain::draw()
{
	// プレイヤーの描画
	m_pBack->Draw();
	m_pPlayer->Draw();
	m_pBlock->Draw();
	m_pScore->Draw();

	DrawFormatString(0, 60, GetColor(255, 255, 255), "Score -> %d", m_pBlock->passCount);
}
