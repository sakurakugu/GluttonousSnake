#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "ShowPage.h"
extern int initSpeed; // 初始速度
extern int SpeedRate; // 倍率
int SpeedRate_tmp; // 倍率
extern int Speed; // 用于记录当前速度，默认为200
extern int len1, len2;   // 用于改变输出时的空格
extern int SortType;// 排序类型
extern char up1, down1, left1, right1, up2, down2, left2, right2;
extern char pause1, restart1, exit1;
struct User User1，User2; // 用户1和用户2

char color[9] = {"color 07"};// 默认颜色

int IsChangeKey = 0;// 是否已更改按键

/*全部已完成*/

// 游戏设置控制程序【已完成】
void GameSettingControl()
{
    InputChar();
    switch (key)
    {
    case '1':
        Page = 15;// 展示是否改变游戏速度
        break;
    case '2':
        Page = 17;
        break;
    case '3':
        Page = 18;
        break;
    case '4':
        Page = 19;
        break;
    case '5':
		Page = 21;
		break;
    case '6':
		Page = 20;
		break;
    case '0':
        Page = 4;// 返回游戏设置页面
        break;
    default:
        InputError = 1; // 输入错误
        break;
    }
    return;
}


// 展示打开游戏设置页面【已完成】
void ShowGameSetting()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       ======游戏设置======                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           1. 改变蛇移动的速度的倍数（速度=原速度×倍数）           ■\n");// 1、2可以共用一个页面
    printf("\t■                                                                   ■\n");
    printf("\t■           2. 改变排序规则                                         ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           3. 改变颜色                                             ■\n");// 3、4可以共用一个页面
    printf("\t■                                                                   ■\n");
    printf("\t■           4. 更改按键                                             ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           5. 用户2登录                                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           6. 恢复默认设置                                         ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}

// 展示改变速度的页面【已完成】
void ShowChangeSpeed()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       ======游戏设置======                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                          初始速度为: 50                           ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■");
    ChangeLen(12, getDigits(SpeedRate));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("当前倍数为：%d", SpeedRate);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■");
    ChangeLen(16, getDigits(Speed));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("蛇移动的速度为:%d", Speed);
    for (int i = 0; i < len2+1; i++) { printf(" "); }
    printf("■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       注：速度=原速度×倍数                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                     请输入要改变的倍数（整数）：                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");// 再来一个页面，显示是否确认改变速度
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}
// 改变游戏速度页面控制程序【已完成】
void ChangeSpeedControl()
{
	int a=scanf("%d", &SpeedRate_tmp);
	switch (SpeedRate_tmp)
	{
	case 0:
		Page = 14;// 返回游戏设置页面
		break;
	default:
        Page = 16;
		break;
	}
	return;

}
// 展示是否更改速度页面【已完成】
void ShowIsChangeSpeed()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        ======是否更改======                       ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■");
    ChangeLen(12, getDigits(SpeedRate_tmp));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("当前倍数为：%d", SpeedRate_tmp);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    printf("\t■                                                                   ■\n");
    int speed = initSpeed * SpeedRate_tmp;
    printf("\t■");
    ChangeLen(16, getDigits(speed));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("蛇移动的速度为:%d", speed);
    for (int i = 0; i < len2+1; i++) { printf(" "); }
    printf("■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        是否更改：                                 ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        1. 是   更改                               ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 否   返回上一页面                       ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}
// 展示是否改变游戏速度的页面【已完成】
void IsChangeSpeedControl()
{
    InputChar();
    switch (key)
    {
    case '1':
        Page = 14;
        Speed = initSpeed * SpeedRate_tmp;
        SpeedRate = SpeedRate_tmp;
        break;
    case '0':
        Page = 14;
        Speed = initSpeed * SpeedRate;
    }
    return;
}

// 展示改变刺球生成速度的页面【被吃了】
// 展示修改用户名页面【不想改动】
void ShowChangeUserName()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ======修改用户名======                       ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                   原用户名：                                      ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                   输入要更改的用户名：                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        1. 下一步                                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}
// 展示修改密码页面【被吃了】
void ShowChangePassword()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       ======修改密码======                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                   原密码：                                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                   输入要更改的密码：                              ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                   再次输入要更改的密码：                          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        1. 下一步                                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}


// 展示更改排序规则页面【已完成】
void ShowChangeRankingListRule()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                    ======更改排序规则======                       ■\n");
    printf("\t■                                                                   ■\n");
    if (SortType == 1)
    {
        printf("\t■                 当前排行榜排序规则为：稳定排序                    ■\n");
    }
    else
    {
        printf("\t■                当前排行榜排序规则为：不稳定排序                   ■\n");
    }
    printf("\t■                                                                   ■\n");
    printf("\t■             （稳定排序：相同分数下，用户名顺序不会改变）          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■             （不稳定排序：相同分数下，用户名顺序会改变）          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        1. 更改为稳定排序                          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        2. 更改为不稳定排序                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        3. 跳转到排行榜页面                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}
// 改变排行榜规则页面控制程序【已完成】
void ChangeRankingListRuleControl()
{
    InputChar();
    switch (key)
    {
    case '1':
        SortType = 1;// 更改为不稳定排序
        Page = 14;
        break;
    case '2':
        SortType = 2;// 更改为稳定排序
        Page = 14;
        break;
    case '3':
        Page = 3;// 跳转到排行榜页面
        break;
    case '0':
        Page = 14;// 返回游戏设置页面
        break;
    default:
        InputError = 1; // 输入错误
        break;
    }
    return;
}


// 展示更改颜色页面【已完成】
void ShowChangeColor()
{
	system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        ======更改颜色======                       ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                           改变背景色颜色                          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■        1：黑色       2：蓝色      3：绿色      4：青色            ■\n");
    printf("\t■        5：红色       6：紫色      7：黄色      8：白色            ■\n");
    printf("\t■        9：灰色：     a：亮蓝色    b：亮绿色    c：亮青色          ■\n");
    printf("\t■        d：亮红色     e：亮紫色    f：亮黄色    g：亮白色          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                           改变图标颜色                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■        h：黑色       i：蓝色      j：绿色      k：青色            ■\n");
    printf("\t■        l：红色       m：紫色      n：黄色      o：白色            ■\n");
    printf("\t■        p：灰色：     q：亮蓝色    r：亮绿色    s：亮青色          ■\n");
    printf("\t■        t：亮红色     u：亮紫色    v：亮黄色    w：亮白色          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■               注：背景色与图标颜色无法改为相同颜色                ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        x. 重置为默认颜色                          ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                     ==按上述字符以改变颜色==                      ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}
// 改变颜色页面控制程序【已完成】
void ChangeColorControl()
{
	InputChar();
	switch (key)
	{
	    case '0':
		    Page = 14;// 返回游戏设置页面
		    break;
        case 'x':
            color[7] = '0';
            color[8] = '7';
			system(color);
			break;
		case '1':
            color[7] = '0';
            system(color);
            break;
        case '2':
			color[7] = '1';
            system(color);
            break;
        case '3':
            color[7] = '2';
            system(color);
            break;
        case '4':
            color[7] = '3';
            system(color);
            break;
        case '5':
            color[7] = '4';
            system(color);
            break;
        case '6':
            color[7] = '5';
            system(color);
            break;
        case '7':
            color[7] = '6';
            system(color);
            break;
        case '8':
            color[7] = '7';
            system(color);
            break;
        case '9':
            color[7] = '8';
            system(color);
            break;
        case 'a':
            color[7] = '9';
            system(color);
            break;
        case 'b':
            color[7] = 'a';
            system(color);
            break;
        case 'c':
            color[7] = 'b';
            system(color);
            break;
        case 'd':
            color[7] = 'c';
            system(color);
            break;
        case 'e':
            color[7] = 'd';
            system(color);
            break;
        case 'f':
            color[7] = 'e';
            system(color); 
            break;
        case 'g':
            color[7] = 'f';
            system(color);
            break;
        case 'h':
            color[8] = '0';
            system(color);
            break;
        case 'i':
            color[8] = '1';
            system(color);
            break;
        case 'j':
            color[8] = '2';
            system(color);
            break;
        case 'k':
            color[8] = '3';
            system(color);
            break;
        case 'l':
            color[8] = '4';
            system(color);
            break;
        case 'm':
            color[8] = '5';
            system(color);
            break;
        case 'n':
            color[8] = '6';
            system(color);
            break;
        case 'o':
            color[8] = '7';
            system(color);
            break;
        case 'p':
            color[8] = '8';
            system(color);
            break;
        case 'q':
            color[8] = '9';
            system(color);
            break;
        case 'r':
            color[8] = 'a';
            system(color);
            break;
        case 's':
            color[8] = 'b';
            system(color);
            break;
        case 't':
            color[8] = 'c';
            system(color);
            break;
        case 'u':
            color[8] = 'd';
            system(color);
            break;
        case 'v':
            color[8] = 'e';
            system(color);
            break;
        case 'w':
            color[8] = 'f';
            system(color);
            break;
	    default:
		    Page = 18;
		break;
	}
	return;
}


// 展示更改按键页面【已完成】
void ShowChangeKey()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ======更改按键======                         ■\n");
    printf("\t■                                                                   ■\n");
    if (IsChangeKey == 2)
    {
    printf("\t■                           已更改完成                              ■\n");
    }
    else if(IsChangeKey == 1)
    {
    printf("\t■                      现在再按任意字符以更改                       ■\n");
    }
    else
    {
    printf("\t■                                                                   ■\n");
    }
    printf("\t■                                                                   ■\n");
    printf("\t■        用户A：                                                    ■\n");
    printf("\t■               1. 向上：%c                                          ■\n",up1);
    printf("\t■               2. 向下：%c                                          ■\n",down1);
    printf("\t■               3. 向左：%c                                          ■\n",left1);
    printf("\t■               4. 向右：%c                                          ■\n",right1);
    printf("\t■                                                                   ■\n");
    printf("\t■        用户B：                                                    ■\n");
    printf("\t■               5. 向上：%c                                          ■\n", up2);
    printf("\t■               6. 向下：%c                                          ■\n", down2);
    printf("\t■               7. 向左：%c                                          ■\n", left2);
    printf("\t■               8. 向右：%c                                          ■\n", right2);
    printf("\t■                                                                   ■\n");
    printf("\t■               a. 暂停游戏：%c                                      ■\n", pause1);
    printf("\t■               b. 重开游戏：%c                                      ■\n", restart1);
    printf("\t■               c. 退出游戏：%c                                      ■\n", exit1);
    printf("\t■                                                                   ■\n");
    printf("\t■                        9. 恢复默认按键                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}
// 更改按键页面控制程序【已完成】
void ChangeKeyControl()
{
    int aaa = 0;
	InputChar();
	switch (key)
	{
	case '0':
		Page = 14;// 返回游戏设置页面
        IsChangeKey = 0;
		break;
    case '1':
		IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        up1 = key;
        IsChangeKey = 2;
		break;
    case '2':
        IsChangeKey = 1;
		system("cls");
		ShowChangeKey();
        aaa = getchar();
		InputChar();
		down1 = key;
		IsChangeKey = 2;
        break;
    case '3':
        IsChangeKey = 1;
		system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        left1 = key;
        IsChangeKey = 2;
		break;
    case '4':
        IsChangeKey = 1;
		system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        right1 = key;
        IsChangeKey = 2;
		break;
    case '5':
        IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        up2 = key;
        IsChangeKey = 2;
        break;
    case '6':
        IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        down2 = key;
        IsChangeKey = 2;
        break;
    case '7':
        IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        left2 = key;
        IsChangeKey = 2;
        break;
    case '8':
        IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa=getchar();
        InputChar();
        right2 = key;
        IsChangeKey = 2;
        break;
    case 'a':
		IsChangeKey = 1;
		system("cls");
		ShowChangeKey();
		aaa = getchar();
		InputChar();
		pause1 = key;
		IsChangeKey = 2;
		break;
    case 'b':
        IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        restart1 = key;
        IsChangeKey = 2;
        break;
    case 'c':
        IsChangeKey = 1;
        system("cls");
        ShowChangeKey();
        aaa = getchar();
        InputChar();
        exit1 = key;
        IsChangeKey = 2;
        break;
    case '9':
        up1 = 'w', down1 = 's', left1 = 'a', right1 = 'd', up2 = 'i', down2 = 'k', left2 = 'j', right2 = 'l',pause1 = 'p', restart1 = 'r', exit1 = 'x';
	default:
        Page = 19; // 展示更改按键页面
		break;
	}
	return;
}

// 展示是否恢复默认设置页面【已完成】
void ShowResetDefault()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                         ===恢复默认设置===                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                          是否恢复默认设置                         ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        将清除当前用户数据！                       ■\n");
    printf("\t■                     并将当前游戏设置恢复默认！                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                            1. 确认恢复                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                            0. 上一个页面                          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}
// 恢复默认设置页面控制程序【已完成】
void ResetDefaultControl()
{
	InputChar();
	switch (key)
	{
	case '1':
		Page = 14;// 返回游戏设置页面
        strcpy(User1.name, "EmptyUser");
        User1.score=0;
        strcpy(User2.name, "EmptyUser");
		User2.score=0;
        Speed = 200;
        SpeedRate = 4;
        SortType = 1;
        up1 = 'w', down1 = 's', left1 = 'a', right1 = 'd', up2 = 'i', down2 = 'k', left2 = 'j', right2 = 'l',pause1 = 'p', restart1 = 'r', exit1 = 'x';
		break;
	case '2':
		Page = 14;// 展示是否恢复默认设置页面
		break;
	case '0':
		Page = 14;// 返回游戏设置页面
		break;
	default:
		InputError = 1; // 输入错误
		break;
	}
	return;
}