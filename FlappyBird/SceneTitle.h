#pragma once
#include "SceneBase.h"
#include "Vec2.h"
#include "DxLib.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void init() override;
	virtual void end() override {}

	virtual SceneBase* update() override;
	virtual void draw() override;

	virtual bool isEnd() { return m_isEnd; }
private:
	bool m_isEnd;

	Vec2 textPos;
	Vec2 textPos2;

	LPCSTR font_path;

	int titleFont;
	int Font;



};