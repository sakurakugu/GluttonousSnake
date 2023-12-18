#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CommonFun.h"
#pragma warning(disable:4996)


extern int InputError; // 输入错误
extern int HighestScore; // 用于记录最高得分
extern int Page;
extern char key;
extern int User1Exist = 0; // 用户1是否存在
extern int User2Exist = 0; // 用户2是否存在
int UserLength1 = 0; // 用户名长度
int UserLength2 = 0; // 密码长度
extern int len1, len2;   // 用于改变输出时的空格
int len3, len4;
int UserLen1, UserLen2, UserLen3, UserLen4; // 用于改变输出时的空格

typedef struct User
{
	char name[20]; // 用户名
	char password[20]; // 密码
	int score; // 分数
}User;

User User1 = { "EmptyUser", "0", 0 }; // 用户1
User User2 = { "EmptyUser", "0", 0 }; // 用户2


// 输入用户名
void InputUserName()
{
	char str[20] = {0};
	int aaa=scanf("%s", str);
	UserLength1 = (int)strlen(str);
	if (UserLength1 == 1)
	{
		switch (str[0])
		{
		case '0':
			Page = 4;// 返回游戏设置页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
		}
	}
	else
	{
		strcpy(User1.name, str);
	}

	return;
}

// 是否确认用户名
void ConfirmUserName()
{
	int a;
	int aaa=scanf("%d", &a);
	switch (a)
	{
	case 0:
		User1Exist = 0;
		Page = 4;// 返回游戏设置页面
		break;
	case 1:
		User1Exist = 1;
		break;
	default:
		InputError = 1; // 输入错误
		break;
	}
	return;
}

// 输入密码
void InputPassword()
{
	char str[20] = {0};
	int aaa=scanf("%s", str);
	UserLength2 = (int)strlen(str);
	if (UserLength2 == 1)
	{
		switch (str[0])
		{
		case '1':
			User1.password[0] = '0';
			User1.password[1] = '\0';
			break;
		case '0':
			Page = 4;// 返回游戏设置页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
		}
	}
	else
	{
		strcpy(User1.password, str);
	}
	return;
}

// 是否确认密码
void ConfirmPassword()
{
	int a;
	int aaa=scanf("%d", &a);
	switch (a)
	{
	case 0:
		User1Exist = 0;
		Page = 4;// 返回游戏设置页面
		break;
	case 1:
		User1Exist = 1;
		break;
	default:
		InputError = 1; // 输入错误
		break;
	}
	return;
}

// 展示输入用户名页面
void ShowInputUserName()
{
	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                       ======用户登录======                        ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                    请输入用户名(小于20个字符)：                   ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                        0. 返回上一页面                            ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");

	return;
}

// 展示已输入用户名页面
void ShowInputedUserName()
{
	int len = 67 - UserLength1 - 8;
	if (len % 2 == 0)
	{
		len1 = len / 2;
		len2 = len / 2;
	}
	else
	{
		len1 = len / 2;
		len2 = len / 2 + 1;
	}

	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                       ======用户登录======                        ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("用户名：%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	UserLen1=len1;
	UserLen2=len2;
	printf("■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                           请确认用户名：                          ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                             1. 确认                               ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                             0. 退出                               ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");
	return;
}

// 展示请输入密码页面
void ShowInputPassword()
{
	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                       ======用户登录======                        ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("用户名：%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	printf("■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                     请输入密码(1<密码个数<20)：                   ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                        1. 不输入密码                              ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                        0. 退出                                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");
	return;

}

// 展示已输入密码页面
void ShowInputedPassword()
{
	int len = 67 - UserLength2 - 8;
	if (len % 2 == 0)
	{
		len3 = len / 2;
		len4 = len / 2;
	}
	else
	{
		len3 = len / 2;
		len4 = len / 2 + 1;
	}

	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                       ======用户登录======                        ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("用户名：%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	printf("■\n");
	printf("\t■                                                                   ■\n");

	printf("\t■");
	for (int i = 0; i < len3; i++)
	{
		printf(" ");
	}
	printf("密码为：%s", User1.password);
	for (int i = 0; i < len4; i++)
	{
		printf(" ");
	}
	printf("■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                            请确认密码：                           ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                             1. 确认                               ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                             0. 退出                               ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");
	return;
}

// 展示登录成功页面
void ShowLoginSuccess()
{
	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                       ======用户登录======                        ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                           恭喜登录成功                            ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                            0. 继续                                ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");

	int aaa=scanf("%c", &key);
	Page = 1;
	return;
}

// 展示注销成功页面
void ShowLogoutSuccess()
{
	User1.name[0] = '\0';
	User1.password[0] = '\0';
	User2.name[0] = '\0';
	User2.password[0] = '\0';

	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                       ======用户登录======                        ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                             注销成功                              ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                            0. 继续                                ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                    ==按数字键 “0~9” 来选择==                    ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");

	char str[20] = {0};
	int aaa=scanf("%s", str);
	Page = 4;
	return;
}

// 将用户信息写入文件“ActiveUser.txt”
void InputActiveUser()
{
	FILE* file = fopen("GameSave\\ActiveUser.txt", "w");
	fprintf(file, "%s %s %d\n", User1.name, User1.password, User1.score);
	fclose(file);
}

// 用户登录页面控制程序
void UserLogin()
{
	ShowInputUserName(); // 展示输入用户名页面
	InputUserName();	// 输入用户名
	if (Page == 4) { return; }
	ShowInputedUserName(); // 展示已输入用户名页面
	ConfirmUserName(); // 是否确认用户名
	if (User1Exist == 1)
	{
		ShowInputPassword();
		InputPassword(); // 输入密码
		int len = (int)strlen(User1.password);
		if (len == 1 && User1.password[0] == '0') // 不输入密码
		{
		}
		else
		{
			ShowInputedPassword(); // 展示已输入密码页面
			if (Page == 4) { return; }
			ConfirmPassword(); // 是否确认密码
		}
		if (User1Exist == 1)
		{
			InputActiveUser(); // 将用户信息写入文件“ActiveUser.txt”
			ShowLoginSuccess(); // 展示登录成功页面
		}
		else
		{
			Page = 4;// 返回游戏设置页面
		}

	}
	if (Page == 4) { return; }
	int aaa=scanf("%c", &key);



	return;
}
