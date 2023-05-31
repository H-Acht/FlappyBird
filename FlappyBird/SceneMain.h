#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class Player;
class BackGround;
class Block;
class Score;
class GameOverScreen;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;
	
	virtual bool isEnd() { return m_isEnd; }

	//ゲームオーバー画面の表示
	void GameOverScreenUpdate();
	void GameOverScreenDraw();

private:
	bool m_isEnd;

	//ポインタ
	Player* m_pPlayer;
	BackGround* m_pBack;
	Block* m_pBlock;
	Score* m_pScore;
	
private:

	Vec2 m_pos;
	Vec2 m_textPos;
	Vec2 m_textPos2;
	Vec2 m_textPos3;
	Vec2 m_hiScore;

	LPCSTR font_path;

	int titleFont;
	int Font;

	int select;

	bool returnFlag;
	bool selectFlag;
	
};