#include <stdio.h>
#include <stdlib.h>


#include "GlobalVariable.h" // 全局变量定义
#include "UserControl.h"    // 用户控制
#include "GluttonousSnake.h"// 贪吃蛇游戏
#include "ShowPage.h"       // 展示页面
#include "PageControl.h"    // 页面控制
#include "JudgePage.h"      // 判断页面
#include "CommonFun.h"      // 常用函数
#include "Setting.h"        // 游戏设置

#pragma warning(disable:4996)//关闭scanf报错

int main()
{

	CheckGameSave(); // 检查游戏存档是否存在
	ReadGameSave(); // 读取游戏存档
	ReadUsers();    // 读取用户信息
	HighestScore = Users[0].score; // 更新最高分

	while (1){JudgePage();}
	
	return 0;
}




