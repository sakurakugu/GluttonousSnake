#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "CommonFun.h"      // 常用函数
#include "GlobalVariable.h" // 全局变量


struct User User1;

// 墙的宽度与高度
#define HEIGHT 21
#define WIDTH 69

extern char key; // 用于接收键盘输入的字符
int Score = 0; // 用于记录当前得分
extern Score_tmp; // 用于记录当前得分

// 用于记录蛇的坐标,蛇的长度最大为格子数
int snakeX[HEIGHT * WIDTH];
int snakeY[HEIGHT * WIDTH];
int gameOver; // 用于判断游戏是否结束，0为结束，1为进行中，2为重新开始
int gamePause; // 用于判断游戏是否暂停，0为没暂停，1为暂停
int direction; // 用于记录蛇的方向
int foodX;
int foodY;
int snakeLength; // 用于记录蛇的长度
char Map[HEIGHT][WIDTH]; // 用于记录地图
int initSpeed = 50; // 初始速度
int SpeedRate = 4; // 倍率


extern int Speed; // 用于记录当前速度，默认为200
// 用于记录用户的操作键
extern char up1, down1, left1, right1;
// extern char up2, down2, left2, right2;
// 暂停游戏键，重开游戏键，退出游戏键
extern char pause1, restart1, exit1;
extern int useArrowKeys; // 没有选择使用方向键


// 按时间获取随机数的函数
int RandTime()
{
    srand((unsigned)time(0));
    int a = rand();
    return a;
}

// 初始化设置
void InitSetup()
{
    gameOver = 1; // 游戏开始进行
    gamePause = 0; // 游戏没暂停
    direction = 0; // 初始化蛇的方向
    snakeLength = 1; // 蛇的长度默认为 1
    Score = 0;  // 初始得分为 0

    // 设定蛇的初始位置为正中间
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;

    // 随机初始的食物位置
    foodX = RandTime() % (HEIGHT - 2) + 1;
    foodY = RandTime() % (WIDTH - 2) + 1;
}

// 输入字符
void InputChar_Game()
{
    if (useArrowKeys)
    {
        if (_kbhit())
        {
            int ch = _getch();
       
            if (ch == 224) {
                ch = _getch();
                switch (ch) {
                case 72: direction = 2; gamePause = 0; break;//上
                case 80: direction = 3; gamePause = 0; break;//下
                case 75: direction = 0; gamePause = 0; break;//左
                case 77: direction = 1; gamePause = 0; break;//右
                }
            }
            else
            {
                key = (char)ch;
                if(key == pause1) { gamePause = 1; } // 暂停
                else if (key == restart1) { gameOver = 2; } //重开
                else if (key == exit1) { gameOver = 0; } //退出
                else { gamePause = 0; }
            }
        }
    }
    else
    {
        if (_kbhit())
        {
            key = _getch();
            // switch不支持变量在case中
            if (key == up1) { direction = 2; gamePause = 0; }
            else if (key == down1) { direction = 3; gamePause = 0; }
            else if (key == left1) { direction = 0; gamePause = 0; }
            else if (key == right1) { direction = 1; gamePause = 0; }
            else if (key == pause1) { gamePause = 1; }
            else if (key == restart1) { gameOver = 2; }
            else if (key == exit1) { gameOver = 0; }
            else { gamePause = 0; }

        }
    }
}

// 绘制地图
void OutputMap()
{
    system("cls");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("\t");
        for (int j = 0; j < WIDTH; j++)
        {
            // 如果是墙壁
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                printf("■");
            }
            // 如果是蛇头
            else if (i == snakeY[0] && j == snakeX[0])
            {
                printf("■");
            }
            // 如果是食物
            else if (i == foodX && j == foodY)
            {
                printf("O");
            }
            // 如果是蛇身或空白
            else
            {
                // 是否已打印了蛇身，每次都更新
                int printed = 0;
                for (int k = 1; k < snakeLength; k++)
                {
                    // 如果当前坐标已打印了蛇身，则蛇身不是横着的，不用继续打印了，直接终止循环
                    if (i == snakeY[k] && j == snakeX[k])
                    {
                        printf("□");
                        printed = 1;
                    }
                }
                // 如果没有打印蛇身，则打印空白
                if (!printed)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\t■  用户名：%s  ■  当前得分: %d", User1.name, Score);
    int t = WIDTH - 27 - (int)strlen(User1.name) - getDigits(Score);
    for (int i = 0; i <t; i++) { printf(" "); }
    printf("■\n\t");
    for (int j = 0; j < WIDTH; j++) { printf("■"); }
    if (useArrowKeys) { printf("\n\t■  控制方向：↑ ↓ ← →  暂停：%c 重开：%c 退出：%c", pause1, restart1, exit1); }
    else{printf("\n\t■  控制方向：%c %c %c %c  暂停：%c 重开：%c 退出：%c", up1, down1, left1, right1, pause1, restart1, exit1);}
    for (int i = 0; i < WIDTH - 46; i++) { printf(" "); } 
    printf("■\n\t");
    for (int j = 0; j < WIDTH; j++) { printf("■"); }
    printf("\t"); // 保持输入位置与地图对齐
}

// 逻辑处理
void Iogic()
{
    // 用于记录蛇头的位置(previous:上一个，用于中转)
    int prevX = snakeY[0];
    int prevY = snakeX[0];
    // 用于记录蛇身的位置
    int prev2X, prev2Y;
    // 蛇头移动
    switch (direction)
    {
    case 0:
        snakeX[0]--;
        break;
    case 1:
        snakeX[0]++;
        break;
    case 2:
        snakeY[0]--;
        break;
    case 3:
        snakeY[0]++;
        break;
    }

    // 蛇身跟随蛇头移动（在地图上绘制）
    for (int i = 1; i < snakeLength; i++) {
        prev2X = snakeY[i];
        prev2Y = snakeX[i];
        snakeY[i] = prevX;
        snakeX[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    // 判断游戏是否结束
        // 判断蛇头是否碰到墙壁
    if (snakeY[0] == 0 || snakeY[0] == HEIGHT - 1 || snakeX[0] == 0 || snakeX[0] == WIDTH - 1) {
        gameOver = 0;
    }
    // 判断蛇头是否碰到蛇身
    for (int i = 1; i < snakeLength; i++)
    {
        if (snakeY[0] == snakeY[i] && snakeX[0] == snakeX[i])
        {
            gameOver = 0;
        }
    }
    // 判断蛇头是否碰到食物
    if (snakeY[0] == foodX && snakeX[0] == foodY)
    {
        Score += 10;
        // 因为余数可能为0，所以要加1，并且不要出现在边界
        int t;
        t = RandTime() % (HEIGHT - 2);
        switch (t)
        {
        case 0:
            t += 2;
            break;
        case 1:
            t++;

            break;
        case HEIGHT - 2:
            t--;
            break;
        default:
            break;
        }
        foodX = t;
        t = RandTime() % (WIDTH - 2);
        switch (t)
        {
        case 0:
            t += 2;
            break;
        case 1:
            t++;
            break;
        case WIDTH - 2:
            t--;
            break;
        default:
            break;
        }
        foodY =  t;
        snakeLength++;
    }
}


int GluttonousSnake()
{
    InitSetup();
    while (gameOver==1)
    {
        OutputMap();
        InputChar_Game();
        if (!gamePause) {Iogic();}
        else { printf("\n\t游戏已暂停，按任意键继续"); }
        Sleep(Speed); // 蛇移动的速度
    }
    Score_tmp=Score;
    if (HighestScore < Score){HighestScore = Score;}
    if (User1.score < Score) { User1.score = Score; }
    if (gameOver == 2) { Page = 7; }else { Page = 22; }
    return 0;
}




