#pragma once
#include "ShowPage.h"
#include "PageControl.h"
#include "CommonFun.h"
#include "UserControl.h"
#include "Setting.h"

extern int Page;
extern int InputError;
extern int User1Exist;
extern int User2Exist;

//  �ж����ĸ�ҳ��
void JudgePage()
{
	switch (Page)
	{
	case 0:
		ExitGame();// �˳���Ϸ
		break;
	case 1:
		ShowHomePage();// չʾ��ҳ��
		HomeControl();// ��ҳ����Ƴ���		
		break;
	case 2:
		ShowNewGame();// չʾ��ʼ����Ϸҳ��
		NewGameControl();// ��ʼ����Ϸҳ����Ƴ���
		break;
	case 3:
		ShowRankingList();// չʾ���а�
		RankingListControl();// ���а�ҳ����Ƴ���
		break;
	case 4:
		ShowSetting();// չʾ��Ϸ����
		SettingControl();// ��Ϸ����ҳ����Ƴ���
		break;
	case 5:
		ShowAbout();// չʾ����
		AboutControl();// ����ҳ����Ƴ���
		break;
	case 6:
		ShowSingleMode();// չʾ����ģʽ
		SingleModeControl();// ����ģʽҳ����Ƴ���
		break;
	case 7:
		GluttonousSnake();// ̰������Ϸ
		break;
	case 8:
		if (User1Exist == User2Exist)// ����û�1���û�2�����ڻ��߶�������
		{
			ShowDoubleMode();// չʾ˫��ģʽ
			DoubleModeControl();// ˫��ģʽҳ����Ƴ���
			break;
		}
		// �������ִ������Ĵ��룬��ת���ڶ����û���¼ҳ��
	case 9:
		ShowUser2Login();// չʾ�ڶ����û���¼ҳ��
		//User2LoginControl();// �ڶ����û���¼ҳ����Ƴ���
		break;
	case 10:
		GluttonousSnake();// ��������ʱ��̰������Ϸ���棬��Ϊ��ûд��������Ϸ��ûд�꡿
		// ��������Ϸ
		break;
	case 11:
		UserLogin(); // �û���¼
		break;
	case 12:
		ShowLogoutSuccess(); // չʾע���ɹ�
		break;
	case 13:
		ShowGameInstructions(); // չʾ��Ϸ˵��
		break;
	case 14:
		ShowGameSetting(); // չʾ��Ϸ����
		GameSettingControl(); // ��Ϸ����ҳ����Ƴ���
		break;
	case 15:
		ShowChangeSpeed();
		ChangeSpeedControl(); // �ı���Ϸ�ٶ�ҳ����Ƴ���
	case 16:
		ShowIsChangeSpeed(); // չʾ�Ƿ�ı���Ϸ�ٶ�
		IsChangeSpeedControl(); // �Ƿ�ı���Ϸ�ٶ�ҳ����Ƴ���
		break;
	case 17:
		ShowChangeRankingListRule(); // չʾ�Ƿ�ı����а����
		ChangeRankingListRuleControl(); // �Ƿ�ı����а����ҳ����Ƴ���
		break;
	case 18:
		ShowChangeColor(); // չʾ�Ƿ�ı���ɫ
		ChangeColorControl(); // �Ƿ�ı���ɫҳ����Ƴ���
		break;
	case 19:
		ShowChangeKey(); // չʾ�Ƿ�ı䰴��
		ChangeKeyControl(); // �Ƿ�ı䰴��ҳ����Ƴ���
		break;
	case 20:
		ShowResetDefault(); // չʾ�Ƿ�����Ĭ��
		ResetDefaultControl(); // �Ƿ�����Ĭ��ҳ����Ƴ���
		break;
	case 21:
		UserLogin2(); // �û���¼

	default:
		InputError = 1; // �������
		break;
	}
	
	return;
}