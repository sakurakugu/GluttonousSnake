#pragma once
// ���ú���

#include <stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

extern char key;
extern int InputError;
extern int len1, len2;   // ���ڸı����ʱ�Ŀո�
extern User User1, User2; // ���ڼ�¼�û���Ϣ

/*ȫ�������*/

// �����ַ�������ɡ�
void InputChar()
{
    int aaa = scanf("%c", &key);
    return;
}

// ��ӡ�����������ɡ�
void ShowInputError()
{
	printf("����������������룡\n\t");
	InputError = 0;
	return;
}

// ����Ϸ�浵���ڵ��ļ��С�����ɡ�
void OpenGameFile()
{
	system("explorer.exe .\\GameSave");/*"explorer.exe .\\��Ϸ�浵.txt*/
	return;
}

// ��ȡ���ֵ�λ��������ɡ�
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

// �ı�ǰ�����ʱ�Ŀո�����ɡ�
void ChangeLen(int a, int b)
{
    int Len = 67; // �ܳ���
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


