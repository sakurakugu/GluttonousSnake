#include <stdio.h>
#include <stdlib.h>
#include "GlobalVariable.h" // ȫ�ֱ���
#include "DataManagement.h" // ���ݹ���
#include "UserControl.h"    // �û�����
#include "GluttonousSnake.h"  // ̰������Ϸ
#include "ShowPage.h"       // չʾҳ��
#include "PageControl.h"    // ҳ�����
#include "JudgePage.h"      // �ж�ҳ��
#include "CommonFun.h"      // ���ú���

#pragma warning(disable:4996)


extern User User1, User2; // ���ڼ�¼�û���Ϣ

int main()
{
	ReadGameSave(); // ��ȡ��Ϸ�浵
	while (1)
	{
		JudgePage();
	}

	return 0;
}




