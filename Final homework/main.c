#include <stdio.h>
#include <stdlib.h>
#include "GlobalVariable.h" // 全局变量
#include "DataManagement.h" // 数据管理
#include "UserControl.h"    // 用户控制
#include "GluttonousSnake.h"  // 贪吃蛇游戏
#include "ShowPage.h"       // 展示页面
#include "PageControl.h"    // 页面控制
#include "JudgePage.h"      // 判断页面
#include "CommonFun.h"      // 常用函数

#pragma warning(disable:4996)


extern User User1, User2; // 用于记录用户信息

int main()
{
	ReadGameSave(); // 读取游戏存档
	while (1)
	{
		JudgePage();
	}

	return 0;
}




