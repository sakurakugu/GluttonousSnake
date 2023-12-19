#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct User
{
	char name[20]; // �û���
	int score; // ����
}User;


#define MAX_USERS 102 // ����û�����
struct User Users[MAX_USERS]; // �û�����
struct User User1 = { "EmptyUser", 0 }; // �û�1
struct User User2 = { "", 0 }; // �û�2

#include "CommonFun.h"
#include "ShowPage.h"

#pragma warning(disable:4996)

// ��������
void InputGameSave();
void addUser();
void sortUsers();
void SaveUsers();

extern int HighestScore; // ���ڼ�¼��ߵ÷�
extern int Page;
extern char key;
extern int User1Exist = 0; // �û�1�Ƿ����
extern int User2Exist = 0; // �û�2�Ƿ����

// ��ȷ�����õ�
int UserLength1 = 0,UserLength2 = 0; // �û�������
extern int len1, len2;   // ���ڸı����ʱ�Ŀո�
extern int InputError; // �������
extern int UserCount; // �û�����
extern int aaa; // ����scanf�ķ���ֵ
extern int RankPage; // ���а�ҳ��
extern int Speed; // ���ڼ�¼��ǰ�ٶȣ�Ĭ��Ϊ200
extern int len1, len2;   // ���ڸı����ʱ�Ŀո�
extern int SortType;// ��������
extern char up1, down1, left1, right1, up2, down2, left2, right2;// ���ڼ�¼�û��Ĳ�����
extern char pause1, restart1, exit1;

// ����
int SortType=1; // ����ʽ


/*ȫ�������*/



/*���û���¼��ע������ɡ�*/
// �����û���������ɡ�
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
// �Ƿ�ȷ���û���������ɡ�
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
// չʾ�����û���ҳ�桾����ɡ�
void ShowInputUserName()
{
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û���¼======                        ��\n");
	ShowBlankLine();
	printf("\t��                    �������û���(С��20���ַ�)��                   ��\n");
	ShowBlankLine();
	printf("\t��                        0. ������һҳ��                            ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	return;
}
// չʾ�������û���ҳ�桾����ɡ�
void ShowInputedUserName()
{
	ChangeLen((int)strlen(User1.name), 8);
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û���¼======                        ��\n");
	ShowBlankLine();
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
	ShowBlankLine();
	printf("\t��                           ��ȷ���û�����                          ��\n");
	ShowBlankLine();
	printf("\t��                             1. ȷ��                               ��\n");
	ShowBlankLine();
	printf("\t��                             0. �˳�                               ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");
	return;
}
// չʾ��¼�ɹ�ҳ�桾����ɡ�
void ShowLoginSuccess()
{
	addUser(); // ����û�
	HighestScore = Users[0].score; // ������߷�
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û���¼======                        ��\n");
	ShowBlankLine();
	printf("\t��                           ��ϲ��¼�ɹ�                            ��\n");
	ShowBlankLine();
	printf("\t��                            0. ����                                ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	int aaa=scanf("%c", &key);
	Page = 1;
	return;
}
// չʾע���ɹ�ҳ�桾����ɡ�
void ShowLogoutSuccess()
{
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û�ע��======                        ��\n");
	ShowBlankLine();
	printf("\t��                        �Ƿ����ע����                             ��\n");
	ShowBlankLine();
	printf("\t��                        1. ��   �˳���¼                           ��\n");
	ShowBlankLine();
	printf("\t��                        0. ��   ������һҳ��                       ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	InputChar();
	switch (key)
	{
		case '1':
			User1Exist = 0;
			User2Exist = 0;
			Page = 4;// ������Ϸ����ҳ��
			break;
		case '0':
			Page = 4;// ������Ϸ����ҳ��
			return;
		default:
			InputError = 1; // �������
			return;

	}
	addUser(); // ����û������û�����
	sortUsers(); // ����
	SaveUsers(); // �����û���Ϣ
	HighestScore=Users[0].score; // ������߷�
	strcpy(User1.name, "EmptyUser"); // �û�1���û���Ϊ��EmptyUser��
	User1.score = 0; // �û�1�ķ���Ϊ0
	User1Exist = 0; // �û�1������
	strcpy(User2.name, "EmptyUser"); // �û�2���û���Ϊ��EmptyUser��
	User2.score = 0; // �û�2�ķ���Ϊ0
	User2Exist = 0; // �û�2������

	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û�ע��======                        ��\n");
	ShowBlankLine();
	printf("\t��                             ע���ɹ�                              ��\n");
	ShowBlankLine();
	printf("\t��                            0. ����                                ��\n");
	ShowBlankLine();
	printf("\t��                    ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	char str[20] = {0};
	int aaa=scanf("%s", str);
	Page = 4;
	return;
}
// udge���������ж��û��Ƿ���ڡ�����ɡ�
int udge(char* name)
{
	int i;
	for (i = 0; i < MAX_USERS; i++)
	{
		if (strcmp(Users[i].name, name) == 0)
		{
			User1.score = Users[i].score;
			return 1;
		}
	}
	if(strcmp(User2.name, "EmptyUser") != 0)// ����û�2����
	{
		for (i = 0; i < MAX_USERS; i++)
		{
			if (strcmp(Users[i].name, name) == 0)
			{
				User2.score = Users[i].score;
				return 1;
			}
		}
	}
	return 0;
}
// �û���¼ҳ����Ƴ�������ɡ�
void UserLogin()
{
	ShowInputUserName(); // չʾ�����û���ҳ��
	InputUserName();	// �����û���
	if (Page == 4) { return; }
	ShowInputedUserName(); // չʾ�������û���ҳ��
	ConfirmUserName(); // �Ƿ�ȷ���û���
	if (User1Exist == 1)
	{
		udge(User1.name);
		InputGameSave();
		ShowLoginSuccess(); // չʾ��¼�ɹ�ҳ��
	}
	else
	{
		Page = 4;// ������Ϸ����ҳ��
	}

	int aaa=scanf("%c", &key);

	return;
}
// ��ȡ��Ϸ�浵������ɡ�
void ReadGameSave()
{
	FILE* GameSave = fopen("GameSave/GameSave.txt", "r");
	aaa = fscanf(GameSave, "�û�1��\n");
	aaa = fscanf(GameSave, "�û�����       %s\n",User1.name);
	aaa = fscanf(GameSave, "��  ����       %d\n", &User1.score);
	aaa = fscanf(GameSave, "��ǰ�ٶȣ�     %d\n", &Speed);
	aaa = fscanf(GameSave, "��ǰ����ʽ�� %d\n", &SortType);
	aaa = fscanf(GameSave, "��ǰ������     %c %c %c %c\n\n", &up1, &down1, &left1, &right1);

	aaa = fscanf(GameSave, "����������     %c %c %c\n\n",&pause1, &restart1, &exit1);

	aaa = fscanf(GameSave, "�û�2��\n");
	aaa = fscanf(GameSave, "�û�����       %s\n", User2.name);
	aaa = fscanf(GameSave, "��  ����       %d\n", &User2.score);
	aaa = fscanf(GameSave, "��ǰ�ٶȣ�     %d\n", &Speed);
	aaa = fscanf(GameSave, "��ǰ����ʽ�� %d\n", &SortType);
	aaa = fscanf(GameSave, "��ǰ������     %c %c %c %c\n\n", &up2, &down2, &left2, &right2);
	fclose(GameSave);
	return;
}
// ����ǰ�û���Ϣд���ļ���GameSave.txt��������ɡ�
void InputGameSave()
{
	FILE* GameSave = fopen("GameSave\\GameSave.txt", "w");
	fprintf(GameSave, "�û�1��\n");
	fprintf(GameSave, "�û�����       %s\n", User1.name);
	fprintf(GameSave, "��  ����       %d\n", User1.score);
	fprintf(GameSave, "��ǰ�ٶȣ�     %d\n", Speed);
	fprintf(GameSave, "��ǰ����ʽ�� %d\n", SortType);
	fprintf(GameSave, "��ǰ������     %c %c %c %c\n\n", up1, down1, left1, right1);

	fprintf(GameSave, "����������     %c %c %c\n\n", pause1, restart1, exit1);

	fprintf(GameSave, "�û�2��\n");
	fprintf(GameSave, "�û�����       %s\n", User2.name);
	fprintf(GameSave, "��  ����       %d\n", User2.score);
	fprintf(GameSave, "��ǰ�ٶȣ�     %d\n", Speed);
	fprintf(GameSave, "��ǰ����ʽ�� %d\n", SortType);
	fprintf(GameSave, "��ǰ������     %c %c %c %c\n\n", up2, down2, left2, right2);

	fclose(GameSave);

}

/*���û�2��¼��ע������ɡ�*/
// �����û���������ɡ�
void InputUserName2()
{
	char str[20] = { 0 };
	int aaa = scanf("%s", str);
	UserLength2 = (int)strlen(str);
	if (UserLength2 == 1)
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
		strcpy(User2.name, str);
	}

	return;
}
// �Ƿ�ȷ���û���������ɡ�
void ConfirmUserName2()
{
	int a;
	int aaa = scanf("%d", &a);
	switch (a)
	{
	case 0:
		User2Exist = 0;
		Page = 4;// ������Ϸ����ҳ��
		break;
	case 1:
		User2Exist = 1;
		break;
	default:
		InputError = 1; // �������
		break;
	}
	return;
}
// չʾ�����û���ҳ�桾����ɡ�
void ShowInputUserName2()
{
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û���¼======                        ��\n");
	ShowBlankLine();
	printf("\t��                �������û�2���û���(С��20���ַ�)��                ��\n");
	ShowBlankLine();
	printf("\t��                        0. ������һҳ��                            ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	return;
}
// չʾ�������û���ҳ�桾����ɡ�
void ShowInputedUserName2()
{
	ChangeLen((int)strlen(User2.name), 8);
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û���¼======                        ��\n");
	ShowBlankLine();
	printf("\t��");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("�û�����%s", User2.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	printf("��\n");
	ShowBlankLine();
	printf("\t��                       ��ȷ���û�2���û�����                       ��\n");
	ShowBlankLine();
	printf("\t��                             1. ȷ��                               ��\n");
	ShowBlankLine();
	printf("\t��                             0. �˳�                               ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");
	return;
}
// չʾ��¼�ɹ�ҳ�桾����ɡ�
void ShowLoginSuccess2()
{
	addUser(); // ����û�
	HighestScore = Users[0].score; // ������߷�
	system("cls"); // ����
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t��                       ======�û���¼======                        ��\n");
	ShowBlankLine();
	printf("\t��                           ��ϲ��¼�ɹ�                            ��\n");
	ShowBlankLine();
	printf("\t��                            0. ����                                ��\n");
	ShowBlankLine();
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	int aaa = scanf("%c", &key);
	Page = 1;
	return;
}
// �û�2��¼ҳ����Ƴ�������ɡ�
void UserLogin2()
{
	ShowInputUserName2(); // չʾ�����û���ҳ��
	InputUserName2();	// �����û���
	if (Page == 14) { return; }
	ShowInputedUserName2(); // չʾ�������û���ҳ��
	ConfirmUserName2(); // �Ƿ�ȷ���û���
	if (User2Exist == 1)
	{
		udge(User2.name);
		InputGameSave();
		ShowLoginSuccess(); // չʾ��¼�ɹ�ҳ��
	}
	else
	{
		Page = 14;// ������Ϸ����ҳ��
	}

	int aaa = scanf("%c", &key);

	return;
}



/*�����а�����ɡ�*/
// ����û�������ɡ�
void addUser()
{
	int cnt = 0;
	for (int i = 0; i < UserCount; i++) {
		if (strcmp(Users[i].name, User1.name) == 0) // ����ҵ����û�
		{
			if(Users[i].score> User1.score)
			{
				User1.score = Users[i].score; // �����û�����
				cnt = 1;
			}
			else
			{
				Users[i].score = User1.score; // �����û�����
				cnt = 1;
			}
			return;
		}
	}
	
	if(strcmp(User2.name,"EmptyUser")==0)//����û�2������
	{
		if (UserCount <= MAX_USERS - 2)
		{
			Users[UserCount] = User1;
		}
		else
		{
			Users[MAX_USERS - 2] = User1;
		}
		UserCount++;
	}
	else
	{
		for (int i = 0; i < UserCount; i++) {
			if (strcmp(Users[i].name, User2.name) == 0) // ����ҵ����û�
			{
				if (Users[i].score > User2.score)
				{
					User1.score = Users[i].score; // �����û�����
					cnt = 2;
				}
				else
				{
					Users[i].score = User2.score; // �����û�����
					cnt = 2;
				}
				return;
			}
		}
		if (UserCount <= MAX_USERS - 2)
		{
			Users[UserCount] = User1;
			Users[UserCount + 1] = User2;
		}
		else
		{
			Users[MAX_USERS - 2] = User1;
			Users[MAX_USERS - 1] = User2;
		}
		UserCount+=2;

	}
}
// ��ȡ�û���Ϣ������ɡ�
void ReadUsers()
{

	FILE* file = fopen("GameSave/Users.txt", "r");
	int i = 0;
	while (fscanf(file, "%s %d", Users[i].name, &Users[i].score) != EOF) // ��������ļ�ĩβ��ֹͣ��ȡ
	{
		i++;
	}
	fclose(file);

	UserCount = i; // �û�����
}
// �ȽϺ���������qsort��������ɡ�(���ȶ�)
int compare(const void* a, const void* b) {
	return ((User*)b)->score - ((User*)a)->score;
}
// �鲢��������ɡ�(�ȶ�)
void merge_sort(int l, int r)
{
	if (l >= r) return;
	struct User tmp[MAX_USERS];
	int mid = (l + r) >> 1;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
		if (Users[i].score<= Users[j].score) tmp[k++] = Users[i++];
		else tmp[k++] = Users[j++];

	while (i <= mid) tmp[k++] = Users[i++];
	while (j <= r) tmp[k++] = Users[j++];

	for (i = l, j = 0; i <= r; i++, j++) Users[i]= tmp[j];
}
//���շ�����������ɡ�
void sortUsers()
{
	if (SortType == 1)
	{
		merge_sort(0, UserCount - 1); // �鲢����
		// ����
		int i = 0, j = UserCount - 1;
		while (i < j)
		{
			User tmp = Users[i];
			Users[i] = Users[j];
			Users[j] = tmp;
			i++;
			j--;
		}
	}
	else
	{
		qsort(Users, UserCount, sizeof(User), compare); // C���ԵĿ�������
	}
}
// �����û���Ϣ������ɡ�
void SaveUsers()
{
	FILE* file = fopen("GameSave/Users.txt", "w");
	for (int i = 0; i < UserCount; i++)
	{
		fprintf(file, "%s %d\n", Users[i].name, Users[i].score);
	}
	fclose(file);

	return;
}
// 0. �˳���Ϸ������ɡ�
void ExitGame()
{
	ReadUsers();
	addUser();
	sortUsers();
	SaveUsers();
	InputGameSave();
	exit(0);
}
// չʾ���а�ͷ��������ɡ�
void ShowRankingListHead()
{
	system("cls"); // ����
	printf("\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                      =========���а�=========                     ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t�� ----------------------------------------------------------------- ��\n");
	printf("\t��    ����                      �û���                  ����         ��\n");
	return;
}
// չʾ���а��һ�С�����ɡ�
void ShowRankingListLine(int i)
{
	if (i >= 100)
	{
		printf("\t��    %03d.                      %s", i, Users[i].name);
	}
	else
	{
		printf("\t��     %02d.                      %s", i, Users[i].name);
	}

	for (int j = 0; j < 24 - (int)strlen(Users[i].name); j++)
	{
		printf(" ");
	}
	printf("%d", Users[i].score);
	for (int j = 0; j < 13 - getDigits(Users[i].score); j++)
	{
		printf(" ");
	}
	
	printf("��\n");
	return;
}
// չʾ���а��в�������ɡ�
void ShowRankingListBody()
{
	if(RankPage<=0){RankPage=1;}
	int i= RankPage*10-10;
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	ShowRankingListLine(i++);
	return;
}
// չʾ���а�β��������ɡ�
void ShowRankingListTail()
{
	printf("\t�� ----------------------------------------------------------------- ��\n");
	printf("\t��    1.�� ��һҳ                                    2. ��һҳ ��    ��\n");
	printf("\t��                     ==�����֡�0��������һҳ��==                     ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t");

	return;
}
// չʾ���а�ҳ�桾����ɡ�
void ShowRankingList()
{
	ReadUsers();
	addUser();
	sortUsers();
	SaveUsers();
	ShowRankingListHead();
	ShowRankingListBody();
	ShowRankingListTail();
	return;
}