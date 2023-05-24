#include "game.h"
#include "SceneTitle.h"
#include "SceneMain.h"

SceneTitle::SceneTitle() :
	m_isEnd(false),
	textPos(),
	titleFont(0),
	Font(0)
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
}

SceneBase* SceneTitle::update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (padState & PAD_INPUT_1)
	{
		return(new SceneMain);
	}

	if (padState & PAD_INPUT_DOWN)
	{

	}

	return this;
}

void SceneTitle::draw()
{
	DrawStringToHandle(textPos.x, textPos.y, "Flappy Heart(��)", GetColor(255, 255, 255), titleFont);
	DrawStringToHandle(textPos2.x, textPos2.y, "start", GetColor(255, 255, 255), Font);

}