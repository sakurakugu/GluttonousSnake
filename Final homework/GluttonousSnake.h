#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// 墙的宽度与高度
#define WIDTH 21
#define HEIGHT 69

extern char key; // 用于接收键盘输入的字符
int Score = 0; // 用于记录当前得分

// 用于记录蛇的坐标,蛇的长度最大为格子数
int snakeX[WIDTH * HEIGHT];
int snakeY[WIDTH * HEIGHT];
int gameOver; // 用于判断游戏是否结束
int direction; // 用于记录蛇的方向
int foodX;
int foodY;
int snakeLength; // 用于记录蛇的长度
char Map[WIDTH][HEIGHT]; // 用于记录地图
int Speed = 200; // 用于记录当前速度，默认为200

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
    gameOver = 1; // 游戏没结束
    direction = 0; // 初始化蛇的方向
    snakeLength = 1; // 蛇的长度默认为 1
    Score = 0;  // 初始得分为 0

    // 设定蛇的初始位置为正中间
    snakeX[0] = HEIGHT / 2;
    snakeY[0] = WIDTH / 2;

    // 随机初始的食物位置
    foodX = RandTime() % (WIDTH - 2) + 1;
    foodY = RandTime() % (HEIGHT - 2) + 1;
}

// 输入字符
void InputChar_Game()
{
    if (_kbhit())
    {
        key = _getch();
        switch (key)
        {
        case 'w':
            direction = 2;
            break;
        case 's':
            direction = 3;
            break;
        case 'a':
            direction = 0;
            break;
        case 'd':
            direction = 1;
            break;
        case 'x': // 按下 x 键退出游戏
            gameOver = 1;
            break;
        }
    }
}

// 绘制地图
void Draw()
{
    system("cls");
    printf("\n");
    for (int i = 0; i < WIDTH; i++)
    {
        printf("\t");
        for (int j = 0; j < HEIGHT; j++)
        {
            // 如果是墙壁
            if (i == 0 || i == WIDTH - 1 || j == 0 || j == HEIGHT - 1)
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
    printf("\t当前得分: %d\n", Score);
    printf("\t"); // 保持输入位置与地图对齐
}

// 逻辑处理
void Iogic()
{
    // 用于记录蛇头的位置
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

    // 蛇身跟随蛇头移动
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
    if (snakeY[0] == 0 || snakeY[0] == WIDTH - 1 || snakeX[0] == 0 || snakeX[0] == HEIGHT - 1) {
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
        // 因为余数可能为0，所以要加1
        foodX = RandTime() % (WIDTH - 2) + 1;
        foodY = RandTime() % (HEIGHT - 2) + 1;
        snakeLength++;
    }
}


int GluttonousSnake()
{
    InitSetup();
    while (gameOver)
    {
        Draw();
        InputChar_Game();
        Iogic();
        Sleep(Speed); // 蛇移动的速度
    }
    return 0;
}




