#pragma once
// ���ݹ���
#include <stdio.h>
#include "UserControl.h"

extern int HighestScore; // ���ڼ�¼��ߵ÷�
extern User User1, User2; // ���ڼ�¼�û���Ϣ

// ��ȡ��Ϸ�浵
void ReadGameSave()
{
	FILE* GameSave = fopen("GameSave/GameSave.txt", "r");
	int aaa;
	aaa = fscanf(GameSave, "%d\n", &HighestScore); // ��ȡ��ߵ÷�
	aaa = fscanf(GameSave, "%s %s %d\n", User1.name, User1.password, &User1.score);
	aaa = fscanf(GameSave, "%s %s %d\n", User1.name, User1.password, &User1.score);
	fclose(GameSave);
	return;
}