#pragma once
#include <stdio.h>
#include "CommonFun.h"
#include "ShowPage.h"

extern int Page;
extern char key;
extern int InputError;

// ��ҳ����Ƴ���
void HomeControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 2;// ��ʼ����Ϸ
			break;
		case '2':
			Page = 3;// ���а�
			break;
		case '3':
			Page = 4;// ��Ϸ����
			break;
		case '4':
			Page = 5;// ����
			break;
		case '0':
			Page = 0;// �˳���Ϸ
			break;
		default:
			InputError=1; // �������
			break;
	}
	return;
}

// ��ʼ����Ϸҳ����Ƴ���
void NewGameControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 6;// ����ģʽ
			break;
		case '2':
			Page = 8;// ˫��ģʽ
			break;
		case '0':
			Page = 1;// ������ҳ��
			break;
		default:
			InputError = 1; // �������
			break;

	}
	return;
}

// ���а�ҳ����Ƴ���
void RankingListControl()
{
	InputChar();
	switch (key)
	{
		case '0':
			Page = 1;// ������ҳ��
			break;
		default:
			InputError = 1; // �������
			break;
	}
	return;
}

// ��Ϸ����ҳ����Ƴ���
void SettingControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 11;// ��һ���û���¼
			break;
		case '2':
			Page = 12;// �û�ע��
			break;
		case '5':
			OpenGameFile();
			break;
		case '0':
			Page = 1;// ������ҳ��
			break;
		default:
			InputError = 1; // �������
			break;
	}
	return;
}

// ����ҳ����Ƴ���
void AboutControl()
{
	InputChar();
	switch (key)
	{
		case '0':
			Page = 1;// ������ҳ��
			break;
		default:
			InputError = 1; // �������
			break;
	}
	return;
}

// ����ģʽҳ����Ƴ���ûд�꡿
void SingleModeControl()
{
	InputChar();
	switch (key)
	{
		case '1':
			Page = 7;// ̰������Ϸ
			break;
		case '2':
			Page = 7;// ̰������Ϸ
			break;
		case '3':
			Page = 7;// ̰������Ϸ
			break;
		case '0':
			Page = 2;// ���ؿ�ʼ����Ϸҳ��
			break;
		default:
			InputError = 1; // �������
			break;
	}
	return;
}

// ˫��ģʽҳ����Ƴ���ûд�꡿
void DoubleModeControl()
{
	InputChar();
	switch (key)
	{
	case '1':
		Page = 7;// ̰������Ϸ
		break;
	case '2':
		Page = 7;// ̰������Ϸ
		break;
	case '3':
		Page = 7;// ̰������Ϸ
		break;
	case '0':
		Page = 2;// ���ؿ�ʼ����Ϸҳ��
		break;
	default:
		InputError = 1; // �������
		break;
	}
	return;
}

