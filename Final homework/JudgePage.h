#pragma once
#include "ShowPage.h"
#include "PageControl.h"
#include "CommonFun.h"
#include "UserControl.h"
#include "Setting.h"

extern int Page;
extern int InputError;
extern int User1Exist;
extern int User2Exist;

//  判断是哪个页面
void JudgePage()
{
	switch (Page)
	{
	case 0:
		ExitGame();// 退出游戏
		break;
	case 1:
		ShowHomePage();// 展示主页面
		HomeControl();// 主页面控制程序		
		break;
	case 2:
		ShowNewGame();// 展示开始新游戏页面
		NewGameControl();// 开始新游戏页面控制程序
		break;
	case 3:
		ShowRankingList();// 展示排行榜
		RankingListControl();// 排行榜页面控制程序
		break;
	case 4:
		ShowSetting();// 展示游戏设置
		SettingControl();// 游戏设置页面控制程序
		break;
	case 5:
		ShowAbout();// 展示关于
		AboutControl();// 关于页面控制程序
		break;
	case 6:
		ShowSingleMode();// 展示单人模式
		SingleModeControl();// 单人模式页面控制程序
		break;
	case 7:
		GluttonousSnake();// 贪吃蛇游戏
		break;
	case 8:
		if (User1Exist == User2Exist)// 如果用户1和用户2都存在或者都不存在
		{
			ShowDoubleMode();// 展示双人模式
			DoubleModeControl();// 双人模式页面控制程序
			break;
		}
		// 否则继续执行下面的代码，跳转到第二个用户登录页面
	case 9:
		ShowUser2Login();// 展示第二个用户登录页面
		//User2LoginControl();// 第二个用户登录页面控制程序
		break;
	case 10:
		GluttonousSnake();// 这里先暂时用贪吃蛇游戏代替，因为还没写蛇碰蛇游戏【没写完】
		// 蛇碰蛇游戏
		break;
	case 11:
		UserLogin(); // 用户登录
		break;
	case 12:
		ShowLogoutSuccess(); // 展示注销成功
		break;
	case 13:
		ShowGameInstructions(); // 展示游戏说明
		break;
	case 14:
		ShowGameSetting(); // 展示游戏设置
		GameSettingControl(); // 游戏设置页面控制程序
		break;
	case 15:
		ShowChangeSpeed();
		ChangeSpeedControl(); // 改变游戏速度页面控制程序
	case 16:
		ShowIsChangeSpeed(); // 展示是否改变游戏速度
		IsChangeSpeedControl(); // 是否改变游戏速度页面控制程序
		break;
	case 17:
		ShowChangeRankingListRule(); // 展示是否改变排行榜规则
		ChangeRankingListRuleControl(); // 是否改变排行榜规则页面控制程序
		break;
	case 18:
		ShowChangeColor(); // 展示是否改变颜色
		ChangeColorControl(); // 是否改变颜色页面控制程序
		break;
	case 19:
		ShowChangeKey(); // 展示是否改变按键
		ChangeKeyControl(); // 是否改变按键页面控制程序
		break;
	case 20:
		ShowResetDefault(); // 展示是否重置默认
		ResetDefaultControl(); // 是否重置默认页面控制程序
		break;
	case 21:
		UserLogin2(); // 用户登录

	default:
		InputError = 1; // 输入错误
		break;
	}
	
	return;
}