#pragma once
// 数据管理
#include <stdio.h>
#include "UserControl.h"

extern int HighestScore; // 用于记录最高得分
extern User User1, User2; // 用于记录用户信息

// 读取游戏存档
void ReadGameSave()
{
	FILE* GameSave = fopen("GameSave/GameSave.txt", "r");
	int aaa;
	aaa = fscanf(GameSave, "%d\n", &HighestScore); // 读取最高得分
	aaa = fscanf(GameSave, "%s %s %d\n", User1.name, User1.password, &User1.score);
	aaa = fscanf(GameSave, "%s %s %d\n", User1.name, User1.password, &User1.score);
	fclose(GameSave);
	return;
}