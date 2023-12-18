#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct User
{
	char name[20]; // 用户名
	int score; // 分数
}User;


#define MAX_USERS 102 // 最大用户数量
struct User Users[MAX_USERS]; // 用户数组
struct User User1 = { "EmptyUser", 0 }; // 用户1
struct User User2 = { "", 0 }; // 用户2

#include "CommonFun.h"
#include "ShowPage.h"

#pragma warning(disable:4996)

// 函数声明
void InputGameSave();
void addUser();
void sortUsers();
void SaveUsers();

extern int HighestScore; // 用于记录最高得分
extern int Page;
extern char key;
extern int User1Exist = 0; // 用户1是否存在
extern int User2Exist = 0; // 用户2是否存在

// 已确认有用的
int UserLength1 = 0; // 用户名长度
extern int len1, len2;   // 用于改变输出时的空格
extern int InputError; // 输入错误
extern int UserCount; // 用户数量
extern int aaa; // 用于scanf的返回值
extern int RankPage; // 排行榜页数

// 设置
extern int SortType; // 排序方式






/*【用户登录及注销已完成】*/
// 输入用户名【已完成】
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
			Page = 4;// 返回游戏设置页面
			break;
		default:
			InputError = 1; // 输入错误
			break;
		}
	}
	else
	{
		strcpy(User1.name, str);
	}

	return;
}
// 是否确认用户名【已完成】
void ConfirmUserName()
{
	int a;
	int aaa=scanf("%d", &a);
	switch (a)
	{
	case 0:
		User1Exist = 0;
		Page = 4;// 返回游戏设置页面
		break;
	case 1:
		User1Exist = 1;
		break;
	default:
		InputError = 1; // 输入错误
		break;
	}
	return;
}
// 展示输入用户名页面【已完成】
void ShowInputUserName()
{
	system("cls"); // 清屏
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t■                       ======用户登录======                        ■\n");
	ShowBlankLine();
	printf("\t■                    请输入用户名(小于20个字符)：                   ■\n");
	ShowBlankLine();
	printf("\t■                        0. 返回上一页面                            ■\n");
	ShowBlankLine();
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	return;
}
// 展示已输入用户名页面【已完成】
void ShowInputedUserName()
{
	ChangeLen((int)strlen(User1.name), 8);
	system("cls"); // 清屏
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t■                       ======用户登录======                        ■\n");
	ShowBlankLine();
	printf("\t■");
	for (int i = 0; i < len1; i++)
	{
		printf(" ");
	}
	printf("用户名：%s", User1.name);
	for (int i = 0; i < len2; i++)
	{
		printf(" ");
	}
	printf("■\n");
	ShowBlankLine();
	printf("\t■                           请确认用户名：                          ■\n");
	ShowBlankLine();
	printf("\t■                             1. 确认                               ■\n");
	ShowBlankLine();
	printf("\t■                             0. 退出                               ■\n");
	ShowBlankLine();
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");
	return;
}
// 展示登录成功页面【已完成】
void ShowLoginSuccess()
{
	addUser(); // 添加用户
	HighestScore = Users[0].score; // 更新最高分
	system("cls"); // 清屏
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t■                       ======用户登录======                        ■\n");
	ShowBlankLine();
	printf("\t■                           恭喜登录成功                            ■\n");
	ShowBlankLine();
	printf("\t■                            0. 继续                                ■\n");
	ShowBlankLine();
	printf("\t■                      ==按数字键 “0~9” 来选择==                    ■\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	int aaa=scanf("%c", &key);
	Page = 1;
	return;
}
// 展示注销成功页面【已完成】
void ShowLogoutSuccess()
{
	system("cls"); // 清屏
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t■                       ======用户注销======                        ■\n");
	ShowBlankLine();
	printf("\t■                        是否继续注销：                             ■\n");
	ShowBlankLine();
	printf("\t■                        1. 是   退出登录                           ■\n");
	ShowBlankLine();
	printf("\t■                        0. 否   返回上一页面                       ■\n");
	ShowBlankLine();
	printf("\t■                      ==按数字键 “0~9” 来选择==                  ■\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	InputChar();
	switch (key)
	{
		case '1':
			User1Exist = 0;
			User2Exist = 0;
			Page = 4;// 返回游戏设置页面
			break;
		case '0':
			Page = 1;// 返回游戏设置页面
			return;
		default:
			InputError = 1; // 输入错误
			return;

	}
	addUser(); // 添加用户进入用户数组
	sortUsers(); // 排序
	SaveUsers(); // 保存用户信息
	HighestScore=Users[0].score; // 更新最高分
	strcpy(User1.name, "EmptyUser"); // 用户1的用户名为“EmptyUser”
	User1.score = 0; // 用户1的分数为0
	User1Exist = 0; // 用户1不存在
	User2.name[0]='\0'; // 用户2的用户名为“EmptyUser”
	User2.score = 0; // 用户2的分数为0
	User2Exist = 0; // 用户2不存在

	system("cls"); // 清屏
	printf("\n");
	ShowHorizontal();
	ShowBlankLine();
	printf("\t■                       ======用户注销======                        ■\n");
	ShowBlankLine();
	printf("\t■                             注销成功                              ■\n");
	ShowBlankLine();
	printf("\t■                            0. 继续                                ■\n");
	ShowBlankLine();
	printf("\t■                    ==按数字键 “0~9” 来选择==                    ■\n");
	ShowBlankLine();
	ShowHorizontal();
	printf("\t");

	char str[20] = {0};
	int aaa=scanf("%s", str);
	Page = 4;
	return;
}
// udge函数用于判断用户是否存在【已完成】
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
	return 0;
}
// 用户登录页面控制程序【已完成】
void UserLogin()
{
	ShowInputUserName(); // 展示输入用户名页面
	InputUserName();	// 输入用户名
	if (Page == 4) { return; }
	ShowInputedUserName(); // 展示已输入用户名页面
	ConfirmUserName(); // 是否确认用户名
	if (User1Exist == 1)
	{
		udge(User1.name);
		InputGameSave();
		ShowLoginSuccess(); // 展示登录成功页面
	}
	else
	{
		Page = 4;// 返回游戏设置页面
	}

	int aaa=scanf("%c", &key);

	return;
}
// 读取游戏存档【已完成】
void ReadGameSave()
{
	FILE* GameSave = fopen("GameSave/GameSave.txt", "r");
	aaa = fscanf(GameSave, "%s %d\n", User1.name, &User1.score);
	aaa = fscanf(GameSave, "%s %d\n", User2.name, &User2.score);
	fclose(GameSave);
	return;
}
// 将当前用户信息写入文件“GameSave.txt”【已完成】
void InputGameSave()
{
	FILE* file = fopen("GameSave\\GameSave.txt", "w");
	fprintf(file, "%s %d\n%s %d\n",User1.name, User1.score, User2.name, User2.score);
	fclose(file);

}


/*【排行榜已完成】*/

// 添加用户【已完成】
void addUser()
{
	int cnt = 0;
	for (int i = 0; i < UserCount; i++) {
		if (strcmp(Users[i].name, User1.name) == 0) // 如果找到了用户
		{
			if(Users[i].score> User1.score)
			{
				User1.score = Users[i].score; // 更新用户分数
				cnt = 1;
			}
			else
			{
				Users[i].score = User1.score; // 更新用户分数
				cnt = 1;
			}
			return;
		}
	}
	
	if(User2.name[0]=='\0')//如果用户2不存在
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
			if (strcmp(Users[i].name, User2.name) == 0) // 如果找到了用户
			{
				if (Users[i].score > User2.score)
				{
					User1.score = Users[i].score; // 更新用户分数
					cnt = 2;
				}
				else
				{
					Users[i].score = User2.score; // 更新用户分数
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
// 读取用户信息【已完成】
void ReadUsers()
{

	FILE* file = fopen("GameSave/Users.txt", "r");
	int i = 0;
	while (fscanf(file, "%s %d", Users[i].name, &Users[i].score) != EOF) // 如果读到文件末尾则停止读取
	{
		i++;
	}
	fclose(file);

	UserCount = i; // 用户数量
}
// 比较函数，用于qsort排序【已完成】(不稳定)
int compare(const void* a, const void* b) {
	return ((User*)b)->score - ((User*)a)->score;
}
// 归并排序【已完成】(稳定)
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
//按照分数排序【已完成】
void sortUsers()
{
	if (SortType == 1)
	{
		merge_sort(0, UserCount - 1); // 归并排序
		// 倒序
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
		qsort(Users, UserCount, sizeof(User), compare); // C语言的快速排序
	}
}
// 储存用户信息【已完成】
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
// 0. 退出游戏【已完成】
void ExitGame()
{
	ReadUsers();
	addUser();
	sortUsers();
	SaveUsers();
	exit(0);
}
// 展示排行榜头部【已完成】
void ShowRankingListHead()
{
	system("cls"); // 清屏
	printf("\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■                      =========排行榜=========                     ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■ ----------------------------------------------------------------- ■\n");
	printf("\t■    排名                      用户名                  分数         ■\n");
	return;
}
// 展示排行榜的一行【已完成】
void ShowRankingListLine(int i)
{
	if (i >= 100)
	{
		printf("\t■    %03d.                      %s", i, Users[i].name);
	}
	else
	{
		printf("\t■     %02d.                      %s", i, Users[i].name);
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
	
	printf("■\n");
	return;
}
// 展示排行榜中部【已完成】
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
// 展示排行榜尾部【已完成】
void ShowRankingListTail()
{
	printf("\t■ ----------------------------------------------------------------- ■\n");
	printf("\t■    1.《 上一页                                    2. 下一页 》    ■\n");
	printf("\t■                     ==按数字“0”返回上一页面==                     ■\n");
	printf("\t■                                                                   ■\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t");

	return;
}
// 展示排行榜页面【已完成】
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