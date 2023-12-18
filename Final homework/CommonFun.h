#pragma once
// 常用函数

#include <stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

extern char key;
extern int InputError;
extern int len1, len2;   // 用于改变输出时的空格
extern User User1, User2; // 用于记录用户信息

// 输入字符
void InputChar()
{
    int aaa = scanf("%c", &key);
    return;
}



// 打印输入错误
void ShowInputError()
{
	printf("输入错误，请重新输入！\n\t");
	InputError = 0;
	return;
}

// 打开游戏存档所在的文件夹
void OpenGameFile()
{
	system("explorer.exe .\\GameSave");/*"explorer.exe .\\游戏存档.txt*/
	return;
}

// 获取数字的位数
int getDigits(int num) {
    int digits = 0;
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

// 改变前后输出时的空格
void ChangeLen(int a, int b)
{
    int Len = 67; // 总长度
    int len = Len - a - b;
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

    return;
}


