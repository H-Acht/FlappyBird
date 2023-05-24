#pragma once
#include "Vec2.h"
#include "DxLib.h"

class Block
{
public:
	Block();
	virtual ~Block();

	void Init();

	/// <summary>
	/// ��Փx�m�[�}��
	/// </summary>
	void Update();

	/// <summary>
	/// ��Փx�n�[�h
	/// </summary>
	void Update2();
	
	void Draw();

	float dLeft[2], dTop[2], dRight[2], dBottom[2];
	float uLeft[2], uTop[2], uRight[2], uBottom[2];

	bool blockFlag[2];

	int passCount;

private:
	
	/// <summary>
	/// Block�̋��ʏ���
	/// </summary>
	/// <param name="i">�ԍ�</param>
	/// <param name="speed">����</param>
	/// <param name="narrowness">���Ԃ̋���</param>
	void BlockUpdate(int i, int speed, int narrowness);

	Vec2 m_pos[2];

	int pipeHandle;

	int m_timeCount;
};

