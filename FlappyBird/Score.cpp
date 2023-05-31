#include "Score.h"
#include "Block.h"

Score::Score():
	numFontHandle(),
	a(),
	scoreBoardHandle(-1)
{
	scoreBoardHandle = LoadGraph("Data/Score/ScoreBoard.png");
}

Score::~Score()
{
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(numFontHandle[i]);
	}
	DeleteGraph(scoreBoardHandle);

}

void Score::Init()
{
	m_pos.x = 900;
	m_pos.y = 200;
	LoadDivGraph("Data/numFont.png", 10, 10, 1, 16, 16, numFontHandle);
}

void Score::Update(Block& block)
{
	a[0] = (block.passCount % 10);			//1‚ÌˆÊ
	a[1] = ((block.passCount / 10) % 10);	//10‚ÌˆÊ
	a[2] = ((block.passCount / 100) % 10);	//100‚ÌˆÊ
}

void Score::Draw()
{
	DrawModiGraph(680, 40, 920, 40, 920, 155, 680, 155, scoreBoardHandle, true);

	DrawRotaGraph(740, 100, 4.0, 0, numFontHandle[a[2]], true, false);
	DrawRotaGraph(800, 100, 4.0, 0, numFontHandle[a[1]], true, false);
	DrawRotaGraph(860, 100, 4.0, 0, numFontHandle[a[0]], true, false);
}
