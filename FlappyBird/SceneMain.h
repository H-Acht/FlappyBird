#pragma once
#include "SceneBase.h"


class Player;
class BackGround;
class Block;
class Score;

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

private:
	bool m_isEnd;

	//ƒ|ƒCƒ“ƒ^
	Player* m_pPlayer;
	BackGround* m_pBack;
	Block* m_pBlock;
	Score* m_pScore;
};