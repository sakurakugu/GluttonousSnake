#pragma once
#include <stdio.h>
#include <windows.h>

// 游戏设置控制程序
void GameSettingControl()
{
    InputChar();
    switch (key)
    {
    case '1':
        Page = 15;// 打开游戏设置页面
        break;
    case '2':
        Page = 16;// 打开游戏设置页面
        break;
    case '3':
        Page = 17;// 打开游戏设置页面
        break;
    case '4':
        Page = 18;// 打开游戏设置页面
        break;
    case '5':
        Page = 19;// 打开游戏设置页面
        break;
    case '6':
        Page = 20;// 打开游戏设置页面
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


// 展示打开游戏设置页面
void ShowGameSetting()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       ======游戏设置======                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           1. 改变蛇移动的速度的倍数（速度=原速度×倍数）          ■\n");// 1、2可以共用一个页面
    printf("\t■                                                                   ■\n");
    printf("\t■           2. 改变刺球生成的速度                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           3. 碰到墙是否死亡                                       ■\n");// 3、4可以共用一个页面
    printf("\t■                                                                   ■\n");
    printf("\t■           4. 改变排序规则                                         ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           5. 改变颜色                                             ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           6. 更改按键                                             ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}

// 展示改变速度的页面
void ShowChangeSpeed()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       ======游戏设置======                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                    原速度为：                                     ■\n");
    printf("\t■                    当前的倍数为：                                 ■\n");//10
    printf("\t■                    蛇移动的速度为:                                ■\n");
    printf("\t■                     （速度=原速度×倍数）                         ■\n");
    printf("\t■           当前的倍数为：                                          ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■           请输入要改变的倍数（整数）：                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");// 再来一个页面，显示是否确认改变速度
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}

// 展示修改用户名页面
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

// 展示更改按键页面
void ShowChangeKey()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ======更改按键======                         ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■        用户A：                                                    ■\n");
    printf("\t■               1. 向上                                             ■\n");
    printf("\t■               2. 向下                                             ■\n");
    printf("\t■               3. 向左                                             ■\n");
    printf("\t■               4. 向右                                             ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■        用户B：                                                    ■\n");
    printf("\t■               1. 向上                                             ■\n");
    printf("\t■               2. 向下                                             ■\n");
    printf("\t■               3. 向左                                             ■\n");
    printf("\t■               4. 向右                                             ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}