#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CommonFun.h"
#pragma warning(disable:4996)


extern int InputError; // �������
extern int HighestScore; // ���ڼ�¼��ߵ÷�
extern int Page;
extern char key;
extern int User1Exist = 0; // �û�1�Ƿ����
extern int User2Exist = 0; // �û�2�Ƿ����
int UserLength1 = 0; // �û�������
int UserLength2 = 0; // ���볤��
extern int len1, len2;   // ���ڸı����ʱ�Ŀո�
int len3, len4;
int UserLen1, UserLen2, UserLen3, UserLen4; // ���ڸı����ʱ�Ŀո�

typedef struct User
{
	char name[20]; // �û���
	char password[20]; // ����
	int score; // ����
}User;

User User1 = { "EmptyUser", "0", 0 }; // �û�1
User User2 = { "EmptyUser", "0", 0 }; // �û�2


// �����û���
void InputUserName()
{
	char str[20] = {0};
	int aaa=scanf("%s", str);
	UserLength1 = (int)strlen(str);
	if (UserLength1 == 1)
	{
		switch (str[0])
		{
		case '0':
			Page = 4;// ������Ϸ����ҳ��
			break;
		default:
			InputError = 1; // �������
			break;
		}
	}
	else
	{
		strcpy(User1.name, str);
	}

	return;
}

// �Ƿ�ȷ���û���
void ConfirmUserName()
{
	int a;
	int aaa=scanf("%d", &a);
	switch (a)
	{
	case 0:
		User1Exist = 0;
		Page = 4;// ������Ϸ����ҳ��
		break;
	case 1:
		User1Exist = 1;
		break;
	default:
		InputError = 1; // �������
		break;
	}
	return;
}

// ��������
void InputPassword()
{
	char str[20] = {0};
	int aaa=scanf("%s", str);
	UserLength2 = (int)strlen(str);
	if (UserLength2 == 1)
	{
		switch (str[0])
		{
		case '1':
			User1.password[0] = '0';
			User1.password[1] = '\0';
			break;
		case '0':
			Page = 4;// ������Ϸ����ҳ��
			break;
		default:
			InputError = 1; // �������
			break;
		}
	}
	else
	{
		strcpy(User1.password, str);
	}
	return;
}

// �Ƿ�ȷ������
void ConfirmPassword()
{
	int a;
	int aaa=scanf("%d", &a);
	switch (a)
	{
	case 0:
		User1Exist = 0;
		Page = 4;// ������Ϸ����ҳ��
		break;
	case 1:
		User1Exist = 1;
		break;
	default:
		InputError = 1; // �������
		break;
	}
	return;
}

// չʾ�����û���ҳ��
void ShowInputUserName()
{
	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                       ======�û���¼======                        ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                    �������û���(С��20���ַ�)��                   ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                        0. ������һҳ��                            ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");

	return;
}

// չʾ�������û���ҳ��
void ShowInputedUserName()
{
	int len = 67 - UserLength1 - 8;
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

	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                       ======�û���¼======                        ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("�û�����%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	UserLen1=len1;
	UserLen2=len2;
	printf("��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                           ��ȷ���û�����                          ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                             1. ȷ��                               ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                             0. �˳�                               ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");
	return;
}

// չʾ����������ҳ��
void ShowInputPassword()
{
	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                       ======�û���¼======                        ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("�û�����%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	printf("��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                     ����������(1<�������<20)��                   ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                        1. ����������                              ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                        0. �˳�                                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");
	return;

}

// չʾ����������ҳ��
void ShowInputedPassword()
{
	int len = 67 - UserLength2 - 8;
	if (len % 2 == 0)
	{
		len3 = len / 2;
		len4 = len / 2;
	}
	else
	{
		len3 = len / 2;
		len4 = len / 2 + 1;
	}

	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                       ======�û���¼======                        ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("�û�����%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	printf("��\n");
	printf("\t��                                                                   ��\n");

	printf("\t��");
	for (int i = 0; i < len3; i++)
	{
		printf(" ");
	}
	printf("����Ϊ��%s", User1.password);
	for (int i = 0; i < len4; i++)
	{
		printf(" ");
	}
	printf("��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                            ��ȷ�����룺                           ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                             1. ȷ��                               ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                             0. �˳�                               ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");
	return;
}

// չʾ��¼�ɹ�ҳ��
void ShowLoginSuccess()
{
	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                       ======�û���¼======                        ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                           ��ϲ��¼�ɹ�                            ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                            0. ����                                ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");

	int aaa=scanf("%c", &key);
	Page = 1;
	return;
}

// չʾע���ɹ�ҳ��
void ShowLogoutSuccess()
{
	User1.name[0] = '\0';
	User1.password[0] = '\0';
	User2.name[0] = '\0';
	User2.password[0] = '\0';

	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                       ======�û���¼======                        ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                             ע���ɹ�                              ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                            0. ����                                ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                    ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");

	char str[20] = {0};
	int aaa=scanf("%s", str);
	Page = 4;
	return;
}

// ���û���Ϣд���ļ���ActiveUser.txt��
void InputActiveUser()
{
	FILE* file = fopen("GameSave\\ActiveUser.txt", "w");
	fprintf(file, "%s %s %d\n", User1.name, User1.password, User1.score);
	fclose(file);
}

// �û���¼ҳ����Ƴ���
void UserLogin()
{
	ShowInputUserName(); // չʾ�����û���ҳ��
	InputUserName();	// �����û���
	if (Page == 4) { return; }
	ShowInputedUserName(); // չʾ�������û���ҳ��
	ConfirmUserName(); // �Ƿ�ȷ���û���
	if (User1Exist == 1)
	{
		ShowInputPassword();
		InputPassword(); // ��������
		int len = (int)strlen(User1.password);
		if (len == 1 && User1.password[0] == '0') // ����������
		{
		}
		else
		{
			ShowInputedPassword(); // չʾ����������ҳ��
			if (Page == 4) { return; }
			ConfirmPassword(); // �Ƿ�ȷ������
		}
		if (User1Exist == 1)
		{
			InputActiveUser(); // ���û���Ϣд���ļ���ActiveUser.txt��
			ShowLoginSuccess(); // չʾ��¼�ɹ�ҳ��
		}
		else
		{
			Page = 4;// ������Ϸ����ҳ��
		}

	}
	if (Page == 4) { return; }
	int aaa=scanf("%c", &key);



	return;
}
