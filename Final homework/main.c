#include <stdio.h>
#include <stdlib.h>


#include "GlobalVariable.h" // ȫ�ֱ�������
#include "UserControl.h"    // �û�����
#include "GluttonousSnake.h"// ̰������Ϸ
#include "ShowPage.h"       // չʾҳ��
#include "PageControl.h"    // ҳ�����
#include "JudgePage.h"      // �ж�ҳ��
#include "CommonFun.h"      // ���ú���
#include "Setting.h"        // ��Ϸ����

#pragma warning(disable:4996)//�ر�scanf����

int main()
{

	CheckGameSave(); // �����Ϸ�浵�Ƿ����
	ReadGameSave(); // ��ȡ��Ϸ�浵
	ReadUsers();    // ��ȡ�û���Ϣ
	HighestScore = Users[0].score; // ������߷�

	while (1){JudgePage();}
	
	return 0;
}




