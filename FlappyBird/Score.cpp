#include "Score.h"
#include "Block.h"

Score::Score():
	numFontHandle(),
	a()
{

}

Score::~Score()
{
	for (int i = 0; i < 10; i++)
	{
		DeleteGraph(numFontHandle[i]);
	}
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
	DrawBox(800, 50, 1000, 150, GetColor(255, 100, 100), true);
	DrawBox(800, 50, 1000, 150, GetColor(255,0,0), false);

	DrawRotaGraph(840, 100, 4.0, 0, numFontHandle[a[2]], true, false);
	DrawRotaGraph(900, 100, 4.0, 0, numFontHandle[a[1]], true, false);
	DrawRotaGraph(960, 100, 4.0, 0, numFontHandle[a[0]], true, false);
}
