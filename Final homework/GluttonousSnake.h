#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// ǽ�Ŀ����߶�
#define WIDTH 21
#define HEIGHT 69

extern char key; // ���ڽ��ռ���������ַ�
int Score = 0; // ���ڼ�¼��ǰ�÷�

// ���ڼ�¼�ߵ�����,�ߵĳ������Ϊ������
int snakeX[WIDTH * HEIGHT];
int snakeY[WIDTH * HEIGHT];
int gameOver; // �����ж���Ϸ�Ƿ����
int direction; // ���ڼ�¼�ߵķ���
int foodX;
int foodY;
int snakeLength; // ���ڼ�¼�ߵĳ���
char Map[WIDTH][HEIGHT]; // ���ڼ�¼��ͼ
int Speed = 200; // ���ڼ�¼��ǰ�ٶȣ�Ĭ��Ϊ200

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
    gameOver = 1; // ��Ϸû����
    direction = 0; // ��ʼ���ߵķ���
    snakeLength = 1; // �ߵĳ���Ĭ��Ϊ 1
    Score = 0;  // ��ʼ�÷�Ϊ 0

    // �趨�ߵĳ�ʼλ��Ϊ���м�
    snakeX[0] = HEIGHT / 2;
    snakeY[0] = WIDTH / 2;

    // �����ʼ��ʳ��λ��
    foodX = RandTime() % (WIDTH - 2) + 1;
    foodY = RandTime() % (HEIGHT - 2) + 1;
}

// �����ַ�
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
        case 'x': // ���� x ���˳���Ϸ
            gameOver = 1;
            break;
        }
    }
}

// ���Ƶ�ͼ
void Draw()
{
    system("cls");
    printf("\n");
    for (int i = 0; i < WIDTH; i++)
    {
        printf("\t");
        for (int j = 0; j < HEIGHT; j++)
        {
            // �����ǽ��
            if (i == 0 || i == WIDTH - 1 || j == 0 || j == HEIGHT - 1)
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
    printf("\t��ǰ�÷�: %d\n", Score);
    printf("\t"); // ��������λ�����ͼ����
}

// �߼�����
void Iogic()
{
    // ���ڼ�¼��ͷ��λ��
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

    // ���������ͷ�ƶ�
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
    if (snakeY[0] == 0 || snakeY[0] == WIDTH - 1 || snakeX[0] == 0 || snakeX[0] == HEIGHT - 1) {
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
        // ��Ϊ��������Ϊ0������Ҫ��1
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
        Sleep(Speed); // ���ƶ����ٶ�
    }
    return 0;
}




