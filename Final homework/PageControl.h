#pragma once
#include <stdio.h>
#include "CommonFun.h"
#include "ShowPage.h"


extern int Page;
extern char key;
extern int InputError;
extern int RankPage;



// 主页面控制程序【已完成】
void HomeControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 2;// 开始新游戏
			break;
		case '2':
			Page = 13;// 游戏规则页面
			break;
		case '3':
			Page = 3;// 排行榜
			break;
		case '4':
			Page = 4;// 游戏设置
			break;
		case '0':
			Page = 0;// 退出游戏
			break;
		// 这一条是测试用的，用于美化更改页面
		case '5':
			Page = 22;// 退出游戏
			break;
		default:
			InputError=1; // 输入错误
			break;
	}
	return;
}

// 开始新游戏页面控制程序
void NewGameControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 7;// 贪吃蛇游戏
			break;
		// case '2':
		// 	Page = 8;// 双人模式
			break;
		case '0':
			Page = 1;// 返回主页面
			break;
		default:
			InputError = 1; // 输入错误
			break;

	}
	return;
}

// 排行榜页面控制程序【已完成】
void RankingListControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			RankPage--;// 上一页
			break;
		case '2':
			RankPage++;// 下一页
break;
		case '0':
			Page = 1;// 返回主页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
	}
	return;
}

// 游戏设置页面控制程序【已完成】
void SettingControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 11;// 第一个用户登录
			break;
		case '2':
			Page = 12;// 用户注销
			break;
		case '3':
			Page = 5;// 关于
			break;
		case '4':
			Page = 14;// 游戏设置页面
			break;
		case '5':
			OpenGameFile();
			break;
		case '0':
			Page = 1;// 返回主页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
	}
	return;
}

// 关于页面控制程序【已完成】
void AboutControl()
{
	InputChar();
	switch (key)
	{
		case '0':
			Page = 4;// 返回主页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
	}
	return;
}




// // 单人模式页面控制程序【没写完】
// void SingleModeControl()
// {
// 	InputChar();
// 	switch (key)
// 	{
// 		case '1':
// 			Page = 7;// 贪吃蛇游戏
// 			break;
// 		case '2':
// 			Page = 7;// 贪吃蛇游戏
// 			break;
// 		case '3':
// 			Page = 7;// 贪吃蛇游戏
// 			break;
// 		case '0':
// 			Page = 2;// 返回开始新游戏页面
// 			break;
// 		default:
// 			InputError = 1; // 输入错误
// 			break;
// 	}
// 	return;
// }
// // 双人模式页面控制程序【没写完】
// void DoubleModeControl()
// {
// 	InputChar();
// 	switch (key)
// 	{
// 	case '1':
// 		Page = 7;// 贪吃蛇游戏
// 		break;
// 	case '2':
// 		Page = 7;// 贪吃蛇游戏
// 		break;
// 	case '3':
// 		Page = 7;// 贪吃蛇游戏
// 		break;
// 	case '0':
// 		Page = 2;// 返回开始新游戏页面
// 		break;
// 	default:
// 		InputError = 1; // 输入错误
// 		break;
// 	}
// 	return;
// }


// 游戏结束控制页面
void GameEndControl()
{
	InputChar();
	 switch (key)
	 {
		case '1':
			Page = 7;// 贪吃蛇游戏
			break;
	 	case '0':
			Page = 2;// 返回开始新游戏页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
	}
	return;
}