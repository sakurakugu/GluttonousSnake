#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

#include "CommonFun.h"      // ���ú���
#include "GlobalVariable.h" // ȫ�ֱ���


struct User User1;

// ǽ�Ŀ����߶�
#define HEIGHT 21
#define WIDTH 69

extern char key; // ���ڽ��ռ���������ַ�
int Score = 0; // ���ڼ�¼��ǰ�÷�
extern Score_tmp; // ���ڼ�¼��ǰ�÷�

// ���ڼ�¼�ߵ�����,�ߵĳ������Ϊ������
int snakeX[HEIGHT * WIDTH];
int snakeY[HEIGHT * WIDTH];
int gameOver; // �����ж���Ϸ�Ƿ������0Ϊ������1Ϊ�����У�2Ϊ���¿�ʼ
int gamePause; // �����ж���Ϸ�Ƿ���ͣ��0Ϊû��ͣ��1Ϊ��ͣ
int direction; // ���ڼ�¼�ߵķ���
int foodX;
int foodY;
int snakeLength; // ���ڼ�¼�ߵĳ���
char Map[HEIGHT][WIDTH]; // ���ڼ�¼��ͼ
int initSpeed = 50; // ��ʼ�ٶ�
int SpeedRate = 4; // ����


extern int Speed; // ���ڼ�¼��ǰ�ٶȣ�Ĭ��Ϊ200
// ���ڼ�¼�û��Ĳ�����
extern char up1, down1, left1, right1;
// extern char up2, down2, left2, right2;
// ��ͣ��Ϸ�����ؿ���Ϸ�����˳���Ϸ��
extern char pause1, restart1, exit1;
extern int useArrowKeys; // û��ѡ��ʹ�÷����


// ��ʱ���ȡ������ĺ���
int RandTime()
{
    srand((unsigned)time(0));
    int a = rand();
    return a;
}

// ��ʼ������
void InitSetup()
{
    gameOver = 1; // ��Ϸ��ʼ����
    gamePause = 0; // ��Ϸû��ͣ
    direction = 0; // ��ʼ���ߵķ���
    snakeLength = 1; // �ߵĳ���Ĭ��Ϊ 1
    Score = 0;  // ��ʼ�÷�Ϊ 0

    // �趨�ߵĳ�ʼλ��Ϊ���м�
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;

    // �����ʼ��ʳ��λ��
    foodX = RandTime() % (HEIGHT - 2) + 1;
    foodY = RandTime() % (WIDTH - 2) + 1;
}

// �����ַ�
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
                case 72: direction = 2; gamePause = 0; break;//��
                case 80: direction = 3; gamePause = 0; break;//��
                case 75: direction = 0; gamePause = 0; break;//��
                case 77: direction = 1; gamePause = 0; break;//��
                }
            }
            else
            {
                key = (char)ch;
                if(key == pause1) { gamePause = 1; } // ��ͣ
                else if (key == restart1) { gameOver = 2; } //�ؿ�
                else if (key == exit1) { gameOver = 0; } //�˳�
                else { gamePause = 0; }
            }
        }
    }
    else
    {
        if (_kbhit())
        {
            key = _getch();
            // switch��֧�ֱ�����case��
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

// ���Ƶ�ͼ
void OutputMap()
{
    system("cls");
    printf("\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("\t");
        for (int j = 0; j < WIDTH; j++)
        {
            // �����ǽ��
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                printf("��");
            }
            // �������ͷ
            else if (i == snakeY[0] && j == snakeX[0])
            {
                printf("��");
            }
            // �����ʳ��
            else if (i == foodX && j == foodY)
            {
                printf("O");
            }
            // ����������հ�
            else
            {
                // �Ƿ��Ѵ�ӡ������ÿ�ζ�����
                int printed = 0;
                for (int k = 1; k < snakeLength; k++)
                {
                    // �����ǰ�����Ѵ�ӡ�������������Ǻ��ŵģ����ü�����ӡ�ˣ�ֱ����ֹѭ��
                    if (i == snakeY[k] && j == snakeX[k])
                    {
                        printf("��");
                        printed = 1;
                    }
                }
                // ���û�д�ӡ�������ӡ�հ�
                if (!printed)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\t��  �û�����%s  ��  ��ǰ�÷�: %d", User1.name, Score);
    int t = WIDTH - 27 - (int)strlen(User1.name) - getDigits(Score);
    for (int i = 0; i <t; i++) { printf(" "); }
    printf("��\n\t");
    for (int j = 0; j < WIDTH; j++) { printf("��"); }
    if (useArrowKeys) { printf("\n\t��  ���Ʒ��򣺡� �� �� ��  ��ͣ��%c �ؿ���%c �˳���%c", pause1, restart1, exit1); }
    else{printf("\n\t��  ���Ʒ���%c %c %c %c  ��ͣ��%c �ؿ���%c �˳���%c", up1, down1, left1, right1, pause1, restart1, exit1);}
    for (int i = 0; i < WIDTH - 46; i++) { printf(" "); } 
    printf("��\n\t");
    for (int j = 0; j < WIDTH; j++) { printf("��"); }
    printf("\t"); // ��������λ�����ͼ����
}

// �߼�����
void Iogic()
{
    // ���ڼ�¼��ͷ��λ��(previous:��һ����������ת)
    int prevX = snakeY[0];
    int prevY = snakeX[0];
    // ���ڼ�¼�����λ��
    int prev2X, prev2Y;
    // ��ͷ�ƶ�
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

    // ���������ͷ�ƶ����ڵ�ͼ�ϻ��ƣ�
    for (int i = 1; i < snakeLength; i++) {
        prev2X = snakeY[i];
        prev2Y = snakeX[i];
        snakeY[i] = prevX;
        snakeX[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    // �ж���Ϸ�Ƿ����
        // �ж���ͷ�Ƿ�����ǽ��
    if (snakeY[0] == 0 || snakeY[0] == HEIGHT - 1 || snakeX[0] == 0 || snakeX[0] == WIDTH - 1) {
        gameOver = 0;
    }
    // �ж���ͷ�Ƿ���������
    for (int i = 1; i < snakeLength; i++)
    {
        if (snakeY[0] == snakeY[i] && snakeX[0] == snakeX[i])
        {
            gameOver = 0;
        }
    }
    // �ж���ͷ�Ƿ�����ʳ��
    if (snakeY[0] == foodX && snakeX[0] == foodY)
    {
        Score += 10;
        // ��Ϊ��������Ϊ0������Ҫ��1�����Ҳ�Ҫ�����ڱ߽�
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
        else { printf("\n\t��Ϸ����ͣ�������������"); }
        Sleep(Speed); // ���ƶ����ٶ�
    }
    Score_tmp=Score;
    if (HighestScore < Score){HighestScore = Score;}
    if (User1.score < Score) { User1.score = Score; }
    if (gameOver == 2) { Page = 7; }else { Page = 22; }
    return 0;
}




