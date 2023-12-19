#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "ShowPage.h"
extern int initSpeed; // ��ʼ�ٶ�
extern int SpeedRate; // ����
int SpeedRate_tmp; // ����
extern int Speed; // ���ڼ�¼��ǰ�ٶȣ�Ĭ��Ϊ200
extern int len1, len2;   // ���ڸı����ʱ�Ŀո�
extern int SortType;// ��������
extern char up1, down1, left1, right1, up2, down2, left2, right2;
extern char pause1, restart1, exit1;
struct User User1��User2; // �û�1���û�2

char color[9] = {"color 07"};// Ĭ����ɫ

int IsChangeKey = 0;// �Ƿ��Ѹ��İ���

/*ȫ�������*/

// ��Ϸ���ÿ��Ƴ�������ɡ�
void GameSettingControl()
{
    InputChar();
    switch (key)
    {
    case '1':
        Page = 15;// չʾ�Ƿ�ı���Ϸ�ٶ�
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
        Page = 4;// ������Ϸ����ҳ��
        break;
    default:
        InputError = 1; // �������
        break;
    }
    return;
}


// չʾ����Ϸ����ҳ�桾����ɡ�
void ShowGameSetting()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                       ======��Ϸ����======                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��           1. �ı����ƶ����ٶȵı������ٶ�=ԭ�ٶȡ�������           ��\n");// 1��2���Թ���һ��ҳ��
    printf("\t��                                                                   ��\n");
    printf("\t��           2. �ı��������                                         ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��           3. �ı���ɫ                                             ��\n");// 3��4���Թ���һ��ҳ��
    printf("\t��                                                                   ��\n");
    printf("\t��           4. ���İ���                                             ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��           5. �û�2��¼                                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��           6. �ָ�Ĭ������                                         ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}

// չʾ�ı��ٶȵ�ҳ�桾����ɡ�
void ShowChangeSpeed()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                       ======��Ϸ����======                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                          ��ʼ�ٶ�Ϊ: 50                           ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��");
    ChangeLen(12, getDigits(SpeedRate));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("��ǰ����Ϊ��%d", SpeedRate);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��");
    ChangeLen(16, getDigits(Speed));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("���ƶ����ٶ�Ϊ:%d", Speed);
    for (int i = 0; i < len2+1; i++) { printf(" "); }
    printf("��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                       ע���ٶ�=ԭ�ٶȡ�����                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                     ������Ҫ�ı�ı�������������                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");// ����һ��ҳ�棬��ʾ�Ƿ�ȷ�ϸı��ٶ�
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}
// �ı���Ϸ�ٶ�ҳ����Ƴ�������ɡ�
void ChangeSpeedControl()
{
	int a=scanf("%d", &SpeedRate_tmp);
	switch (SpeedRate_tmp)
	{
	case 0:
		Page = 14;// ������Ϸ����ҳ��
		break;
	default:
        Page = 16;
		break;
	}
	return;

}
// չʾ�Ƿ�����ٶ�ҳ�桾����ɡ�
void ShowIsChangeSpeed()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        ======�Ƿ����======                       ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��");
    ChangeLen(12, getDigits(SpeedRate_tmp));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("��ǰ����Ϊ��%d", SpeedRate_tmp);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    printf("\t��                                                                   ��\n");
    int speed = initSpeed * SpeedRate_tmp;
    printf("\t��");
    ChangeLen(16, getDigits(speed));
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("���ƶ����ٶ�Ϊ:%d", speed);
    for (int i = 0; i < len2+1; i++) { printf(" "); }
    printf("��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        �Ƿ���ģ�                                 ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        1. ��   ����                               ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ��   ������һҳ��                       ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}
// չʾ�Ƿ�ı���Ϸ�ٶȵ�ҳ�桾����ɡ�
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

// չʾ�ı���������ٶȵ�ҳ�桾�����ˡ�
// չʾ�޸��û���ҳ�桾����Ķ���
void ShowChangeUserName()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ======�޸��û���======                       ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                   ԭ�û�����                                      ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                   ����Ҫ���ĵ��û�����                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        1. ��һ��                                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}
// չʾ�޸�����ҳ�桾�����ˡ�
void ShowChangePassword()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                       ======�޸�����======                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                   ԭ���룺                                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                   ����Ҫ���ĵ����룺                              ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                   �ٴ�����Ҫ���ĵ����룺                          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        1. ��һ��                                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}


// չʾ�����������ҳ�桾����ɡ�
void ShowChangeRankingListRule()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                    ======�����������======                       ��\n");
    printf("\t��                                                                   ��\n");
    if (SortType == 1)
    {
        printf("\t��                 ��ǰ���а��������Ϊ���ȶ�����                    ��\n");
    }
    else
    {
        printf("\t��                ��ǰ���а��������Ϊ�����ȶ�����                   ��\n");
    }
    printf("\t��                                                                   ��\n");
    printf("\t��             ���ȶ�������ͬ�����£��û���˳�򲻻�ı䣩          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��             �����ȶ�������ͬ�����£��û���˳���ı䣩          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        1. ����Ϊ�ȶ�����                          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        2. ����Ϊ���ȶ�����                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        3. ��ת�����а�ҳ��                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}
// �ı����а����ҳ����Ƴ�������ɡ�
void ChangeRankingListRuleControl()
{
    InputChar();
    switch (key)
    {
    case '1':
        SortType = 1;// ����Ϊ���ȶ�����
        Page = 14;
        break;
    case '2':
        SortType = 2;// ����Ϊ�ȶ�����
        Page = 14;
        break;
    case '3':
        Page = 3;// ��ת�����а�ҳ��
        break;
    case '0':
        Page = 14;// ������Ϸ����ҳ��
        break;
    default:
        InputError = 1; // �������
        break;
    }
    return;
}


// չʾ������ɫҳ�桾����ɡ�
void ShowChangeColor()
{
	system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        ======������ɫ======                       ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                           �ı䱳��ɫ��ɫ                          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��        1����ɫ       2����ɫ      3����ɫ      4����ɫ            ��\n");
    printf("\t��        5����ɫ       6����ɫ      7����ɫ      8����ɫ            ��\n");
    printf("\t��        9����ɫ��     a������ɫ    b������ɫ    c������ɫ          ��\n");
    printf("\t��        d������ɫ     e������ɫ    f������ɫ    g������ɫ          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                           �ı�ͼ����ɫ                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��        h����ɫ       i����ɫ      j����ɫ      k����ɫ            ��\n");
    printf("\t��        l����ɫ       m����ɫ      n����ɫ      o����ɫ            ��\n");
    printf("\t��        p����ɫ��     q������ɫ    r������ɫ    s������ɫ          ��\n");
    printf("\t��        t������ɫ     u������ɫ    v������ɫ    w������ɫ          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��               ע������ɫ��ͼ����ɫ�޷���Ϊ��ͬ��ɫ                ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        x. ����ΪĬ����ɫ                          ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                     ==�������ַ��Ըı���ɫ==                      ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}
// �ı���ɫҳ����Ƴ�������ɡ�
void ChangeColorControl()
{
	InputChar();
	switch (key)
	{
	    case '0':
		    Page = 14;// ������Ϸ����ҳ��
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


// չʾ���İ���ҳ�桾����ɡ�
void ShowChangeKey()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ======���İ���======                         ��\n");
    printf("\t��                                                                   ��\n");
    if (IsChangeKey == 2)
    {
    printf("\t��                           �Ѹ������                              ��\n");
    }
    else if(IsChangeKey == 1)
    {
    printf("\t��                      �����ٰ������ַ��Ը���                       ��\n");
    }
    else
    {
    printf("\t��                                                                   ��\n");
    }
    printf("\t��                                                                   ��\n");
    printf("\t��        �û�A��                                                    ��\n");
    printf("\t��               1. ���ϣ�%c                                          ��\n",up1);
    printf("\t��               2. ���£�%c                                          ��\n",down1);
    printf("\t��               3. ����%c                                          ��\n",left1);
    printf("\t��               4. ���ң�%c                                          ��\n",right1);
    printf("\t��                                                                   ��\n");
    printf("\t��        �û�B��                                                    ��\n");
    printf("\t��               5. ���ϣ�%c                                          ��\n", up2);
    printf("\t��               6. ���£�%c                                          ��\n", down2);
    printf("\t��               7. ����%c                                          ��\n", left2);
    printf("\t��               8. ���ң�%c                                          ��\n", right2);
    printf("\t��                                                                   ��\n");
    printf("\t��               a. ��ͣ��Ϸ��%c                                      ��\n", pause1);
    printf("\t��               b. �ؿ���Ϸ��%c                                      ��\n", restart1);
    printf("\t��               c. �˳���Ϸ��%c                                      ��\n", exit1);
    printf("\t��                                                                   ��\n");
    printf("\t��                        9. �ָ�Ĭ�ϰ���                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}
// ���İ���ҳ����Ƴ�������ɡ�
void ChangeKeyControl()
{
    int aaa = 0;
	InputChar();
	switch (key)
	{
	case '0':
		Page = 14;// ������Ϸ����ҳ��
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
        Page = 19; // չʾ���İ���ҳ��
		break;
	}
	return;
}

// չʾ�Ƿ�ָ�Ĭ������ҳ�桾����ɡ�
void ShowResetDefault()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                         ===�ָ�Ĭ������===                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                          �Ƿ�ָ�Ĭ������                         ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        �������ǰ�û����ݣ�                       ��\n");
    printf("\t��                     ������ǰ��Ϸ���ûָ�Ĭ�ϣ�                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                            1. ȷ�ϻָ�                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                            0. ��һ��ҳ��                          ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
}
// �ָ�Ĭ������ҳ����Ƴ�������ɡ�
void ResetDefaultControl()
{
	InputChar();
	switch (key)
	{
	case '1':
		Page = 14;// ������Ϸ����ҳ��
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
		Page = 14;// չʾ�Ƿ�ָ�Ĭ������ҳ��
		break;
	case '0':
		Page = 14;// ������Ϸ����ҳ��
		break;
	default:
		InputError = 1; // �������
		break;
	}
	return;
}