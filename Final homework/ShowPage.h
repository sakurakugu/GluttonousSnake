#pragma once
#include <stdio.h>


extern int HighestScore; // 最高得分
extern int Score_tmp;        // 当前得分
extern User User1; // 用户1
extern int len1, len2;   // 用于改变输出时的空格
extern int aaa;
extern int Page; // 页面

// 展示水平线【已完成】
void ShowHorizontal()
{
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    return;
}
// 展示空行【已完成】
void ShowBlankLine()
{
    printf("\t■                                                                   ■\n");
	return;
}
// 展示主页面【已完成】
void ShowHomePage()
{
    system("cls"); // 清屏
    printf("\n");
    ShowHorizontal();
    ShowBlankLine();
    printf("\t■                      ======贪吃蛇小游戏======                     ■\n");
    ShowBlankLine();
    printf("\t■");
    ChangeLen(8, (int)strlen(User1.name)); // 8是“用户名：”的长度
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("用户名：%s", User1.name);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    ShowBlankLine();
    printf("\t■");
    ChangeLen(10, getDigits(HighestScore));// 10是“最高得分：”的长度
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("最高得分：%d", HighestScore);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    ShowBlankLine();
    ShowBlankLine();
    printf("\t■                        1. 开始新游戏                              ■\n");
    ShowBlankLine();
    printf("\t■                        2. 游戏规则                                ■\n");
    ShowBlankLine();
    printf("\t■                        3. 排行榜                                  ■\n");
    ShowBlankLine();
    printf("\t■                        4. 设置                                    ■\n");
    ShowBlankLine();
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 退出游戏                                ■\n");
    ShowBlankLine();
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    ShowBlankLine();
    ShowHorizontal();
    printf("\t");

    return;
}

// 展示开始新游戏页面
void ShowNewGame()
{
    system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ========新的游戏========                     ■\n");
    ShowBlankLine();
    printf("\t■");
    ChangeLen(10, getDigits(HighestScore));// 10是“最高得分：”的长度
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("最高得分：%d", HighestScore);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    ShowBlankLine();
    printf("\t■");
    ChangeLen(10, getDigits(Score_tmp));// 10是“当前得分：”的长度
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("当前得分：%d", Score_tmp);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    ShowBlankLine();
    printf("\t■                                                                   ■\n");
    printf("\t■                        1. 贪吃蛇（单人模式）                      ■\n");
    printf("\t■                                                                   ■\n");
    // printf("\t■                        2. 蛇碰蛇（双人模式）                      ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}



// 展示设置页面
void ShowSetting()
{
	system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==========设置==========                     ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■");
    ChangeLen(8, (int)strlen(User1.name)); // 8是“用户名：”的长度
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("用户名：%s", User1.name);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        1. 用户登录（用户名更改）                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        2. 用户注销                                ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        3. 关于作者                                ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        4. 游戏设置                                ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        5. 打开存档                                ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}

// 展示关于页面
void ShowAbout()
{
    system("cls"); // 清屏
    printf("\n");
    ShowHorizontal();
    ShowBlankLine();
    printf("\t■                         ======关于======                          ■\n");
    ShowBlankLine();
    printf("\t■               当前游戏创建时间 2023年12月16日 14:30               ■\n");
    printf("\t■               当前游戏结束时间 2023年12月22日 11:40               ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■     目前已上传到 https://github.com/sakurakugu/GluttonousSnake    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■               这是我大一上程序设计实践课的期末作业                ■\n");// 关于作者
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    ShowBlankLine();
    printf("\t■                       0. 返回主页面                               ■\n");
    ShowBlankLine();
    printf("\t■                   ==按数字键 “0~9” 来选择==                       ■\n");
    ShowBlankLine();
    ShowHorizontal();
    printf("\t");

    return;
}

// // 展示单人模式页面
// void ShowSingleMode()
// {
//     system("cls"); // 清屏
//     printf("\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                      ===贪吃蛇（单人模式）===                     ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                              最高得分：%d                         ■\n", HighestScore);
//     printf("\t■                              当前得分：%d                         ■\n", User1.score);
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        1. 简单模式                                ■\n");//
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        2. 普通模式                                ■\n");//会生成小刺球，碰到会-2长度，生成10s后消失
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        3. 困难模式                                ■\n");//会生成小刺球，碰到会死亡，并有一个npc
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        0. 返回主页面                              ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t");
//     return;
// }
// // 展示双人模式页面
// void ShowDoubleMode()
// {
//     system("cls"); // 清屏
//     printf("\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                      ===蛇碰蛇（双人模式）===                     ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                              最高得分：%d                         ■\n", HighestScore);
//     printf("\t■                              当前得分：%d                         ■\n", User1.score);
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        1. 简单模式                                ■\n");//
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        2. 普通模式                                ■\n");//会生成小刺球，碰到会-2长度，生成10s后消失
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        3. 困难模式                                ■\n");//会生成小刺球，碰到会死亡，吃到小光球会清屏
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        0. 返回上一页面                            ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");// 一次会生成多个食物
//     printf("\t■                                                                   ■\n");// 按倒计时记录总分
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t");
//     return;
// }
// 展示打开双人模式后，第二个用户登录页面
// void ShowUser2Login()
// {
//     system("cls"); // 清屏
//     printf("\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                       ======用户B登录======                       ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        用户A：                                    ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        用户B：                                    ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        输入用户B的用户名：                        ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        是否输入密码：                             ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        1. 是   输入密码                           ■\n");//到输入密码页面后，下面的0改为取消输入密码，直接进入游戏
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        2. 否                                      ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                        0. 返回上一页面                            ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t");
//     return;
// }
// // 展示是否继续登录页面
// void ShowContinueLogin()
// {
// 	system("cls"); // 清屏
// 	printf("\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                       ======用户登录======                        ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
// 	printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
// 	printf("\t■                        是否继续登录：                             ■\n");
// 	printf("\t■                                                                   ■\n");
// 	printf("\t■                        1. 是   继续登录                           ■\n");
// 	printf("\t■                                                                   ■\n");
// 	printf("\t■                        2. 否   返回上一页面                       ■\n");
// 	printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■                                                                   ■\n");
// 	printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
//     printf("\t■                                                                   ■\n");
//     printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
//     printf("\t");
// 	return;
// }

// 展示游戏规则页面（原为展示打开游戏说明页面）
void ShowGameInstructions()
{
	system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                       ======游戏规则======                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■     贪吃蛇的游戏规则：                                            ■\n");
    printf("\t■         通过控制蛇的方向，去吃食物，以获得更长的身体，            ■\n");
    printf("\t■         看看可以获得多少分                                        ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        0. 返回上一页面                            ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");
    
    aaa=scanf("%d", &aaa);
    Page = 1;
    return;
}


// 展示游戏结束页面
void ShowGameEnd()
{
    // 这里使用vscode打开才是正确的
	system("cls"); // 清屏
    printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        ======最终结果======                       ■\n");
    printf("\t■         ■■■■■■          ■■         ■■   ■■        ■■■■■           ■\n");
    printf("\t■         ■    ■         ■  ■       ■   ■   ■       ■               ■\n");
    printf("\t■         ■             ■    ■      ■   ■   ■       ■               ■\n");
    printf("\t■         ■   ■■        ■■■■■■      ■   ■   ■       ■■■■■           ■\n");
    printf("\t■         ■    ■        ■    ■      ■   ■   ■       ■               ■\n");
    printf("\t■         ■■■■■■        ■    ■      ■   ■   ■       ■■■■■           ■\n");
    printf("\t■                                                                   ■\n");// 贪吃蛇没有GameWin
    printf("\t■         ■■■■■■        ■    ■        ■■■■■         ■■■■            ■\n");
    printf("\t■         ■    ■        ■    ■        ■             ■    ■          ■\n");
    printf("\t■         ■    ■        ■    ■        ■             ■    ■          ■\n");
    printf("\t■         ■    ■         ■  ■         ■■■■■         ■■■■            ■\n");
    printf("\t■         ■    ■         ■  ■         ■             ■   ■           ■\n");
    printf("\t■         ■■■■■■          ■■          ■■■■■         ■    ■          ■\n");
    printf("\t■                                                                   ■\n");
    ShowBlankLine();
    printf("\t■");
    ChangeLen(10, getDigits(User1.score));// 10是“最终得分：”的长度
    for (int i = 0; i < len1-2; i++) { printf(" "); }
    printf("最终得分：%d", User1.score);
    for (int i = 0; i < len2+2; i++) { printf(" "); }
    printf("■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■             1. 再来一局              0. 返回上一页面              ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                   ==按数字键 “0~9” 来选择==                       ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}


// 展示是否更改页面
void ShowIsChange()
{
	system("cls"); // 清屏
	printf("\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                        ======是否更改======                       ■\n");
	printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
	printf("\t■                        是否确认更改：                             ■\n");
	printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
	printf("\t■                        1. 是   更改                               ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                        2. 否   返回上一页面                       ■\n");
    printf("\t■                                                                   ■\n");
	printf("\t■                                                                   ■\n");
    printf("\t■                                                                   ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                                                                   ■\n");	
	printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
    printf("\t■                                                                   ■\n");
    printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
    printf("\t");

    return;
}

// 展示错误页面，用不上，所以懒得写了【已完成】
void ShowError()
{
	system("cls"); // 清屏
    printf("\n");
    ShowHorizontal();
    ShowBlankLine();
    printf("\t■                     ======锟斤拷锟斤拷======                      ■\n");
    ShowBlankLine();
    ShowBlankLine();
    printf("\t■   ■■■■■  ■■■■     ■■■■       ■■■■    ■■■■    ■\n");
    printf("\t■   ■          ■      ■   ■      ■   ■        ■  ■      ■  ■\n");
    printf("\t■   ■          ■      ■   ■      ■   ■        ■  ■      ■  ■\n");
    printf("\t■   ■          ■      ■   ■      ■   ■        ■  ■      ■  ■\n");
    printf("\t■   ■■■■■  ■■■■     ■■■■     ■        ■  ■■■■    ■\n");// 一个大写的Error
    printf("\t■   ■          ■  ■       ■  ■       ■        ■  ■  ■      ■\n");
    printf("\t■   ■          ■    ■     ■    ■     ■        ■  ■    ■    ■\n");
    printf("\t■   ■          ■      ■   ■      ■   ■        ■  ■      ■  ■\n");
    printf("\t■   ■■■■■  ■      ■   ■      ■     ■■■■    ■      ■  ■\n");
    ShowBlankLine();
    ShowBlankLine();
    printf("\t■                        0. 返回主页面                              ■\n");
    ShowBlankLine();
    printf("\t■                     ==按数字键 “0~9” 来选择==                   ■\n");
    ShowBlankLine();
    ShowHorizontal();
    printf("\t");

    int a=scanf("%d", &aaa);
    Page = 1;
    return;
}
