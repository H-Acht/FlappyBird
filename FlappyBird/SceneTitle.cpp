#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneRule.h"

SceneTitle::SceneTitle() :
	m_isEnd(false),
	textPos(),
	titleFont(0),
	Font(0),
	select(0)
{
	//���\�[�X�ǂݍ���
	font_path = "Data/Font/azuki.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
}

SceneTitle::~SceneTitle()
{
	DeleteFontToHandle(titleFont);
	DeleteFontToHandle(Font);

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}

void SceneTitle::init()
{
	titleFont = CreateFontToHandle("�������t�H���g", 64, -1, -1);
	Font = CreateFontToHandle("�������t�H���g", 48, -1, -1);

	textPos.x = 550;
	textPos.y = 100;

	textPos2.x = 750;
	textPos2.y = 500;

	textPos3.x = 750;
	textPos3.y = 550;
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	static int push = 0;

	if (select == 0)
	{
		textPos2.x = 800;
		textPos3.x = 750;

		if (padState & PAD_INPUT_UP || padState & PAD_INPUT_DOWN)
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

		if (padState & PAD_INPUT_2)
		{
			return(new SceneMain);
		}
	}
	if (select == 1)
	{
		textPos2.x = 750;
		textPos3.x = 800;

		if (padState & PAD_INPUT_UP || padState & PAD_INPUT_DOWN)
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

		if (padState & PAD_INPUT_2)
		{
			return(new SceneRule);
		}
	}

	return this;
}

void SceneTitle::draw()
{
	DrawStringToHandle(textPos.x, textPos.y, "Flappy Heart(��)", GetColor(255, 255, 255), titleFont);
	DrawStringToHandle(textPos2.x, textPos2.y, "start", GetColor(255, 255, 255), Font);
	DrawStringToHandle(textPos3.x, textPos3.y, "Rule", GetColor(255, 255, 255), Font);

}