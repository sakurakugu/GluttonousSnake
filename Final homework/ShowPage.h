#pragma once
#include <stdio.h>


extern int HighestScore; // ��ߵ÷�
extern int Score_tmp;        // ��ǰ�÷�
extern User User1; // �û�1
extern int len1, len2;   // ���ڸı����ʱ�Ŀո�
extern int aaa;
extern int Page; // ҳ��

// չʾˮƽ�ߡ�����ɡ�
void ShowHorizontal()
{
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    return;
}
// չʾ���С�����ɡ�
void ShowBlankLine()
{
    printf("\t��                                                                   ��\n");
	return;
}
// չʾ��ҳ�桾����ɡ�
void ShowHomePage()
{
    system("cls"); // ����
    printf("\n");
    ShowHorizontal();
    ShowBlankLine();
    printf("\t��                      ======̰����С��Ϸ======                     ��\n");
    ShowBlankLine();
    printf("\t��");
    ChangeLen(8, (int)strlen(User1.name)); // 8�ǡ��û��������ĳ���
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("�û�����%s", User1.name);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    ShowBlankLine();
    printf("\t��");
    ChangeLen(10, getDigits(HighestScore));// 10�ǡ���ߵ÷֣����ĳ���
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("��ߵ÷֣�%d", HighestScore);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    ShowBlankLine();
    ShowBlankLine();
    printf("\t��                        1. ��ʼ����Ϸ                              ��\n");
    ShowBlankLine();
    printf("\t��                        2. ��Ϸ����                                ��\n");
    ShowBlankLine();
    printf("\t��                        3. ���а�                                  ��\n");
    ShowBlankLine();
    printf("\t��                        4. ����                                    ��\n");
    ShowBlankLine();
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. �˳���Ϸ                                ��\n");
    ShowBlankLine();
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    ShowBlankLine();
    ShowHorizontal();
    printf("\t");

    return;
}

// չʾ��ʼ����Ϸҳ��
void ShowNewGame()
{
    system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ========�µ���Ϸ========                     ��\n");
    ShowBlankLine();
    printf("\t��");
    ChangeLen(10, getDigits(HighestScore));// 10�ǡ���ߵ÷֣����ĳ���
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("��ߵ÷֣�%d", HighestScore);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    ShowBlankLine();
    printf("\t��");
    ChangeLen(10, getDigits(Score_tmp));// 10�ǡ���ǰ�÷֣����ĳ���
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("��ǰ�÷֣�%d", Score_tmp);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    ShowBlankLine();
    printf("\t��                                                                   ��\n");
    printf("\t��                        1. ̰���ߣ�����ģʽ��                      ��\n");
    printf("\t��                                                                   ��\n");
    // printf("\t��                        2. �����ߣ�˫��ģʽ��                      ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}



// չʾ����ҳ��
void ShowSetting()
{
	system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==========����==========                     ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��");
    ChangeLen(8, (int)strlen(User1.name)); // 8�ǡ��û��������ĳ���
    for (int i = 0; i < len1; i++) { printf(" "); }
    printf("�û�����%s", User1.name);
    for (int i = 0; i < len2; i++) { printf(" "); }
    printf("��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        1. �û���¼���û������ģ�                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        2. �û�ע��                                ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        3. ��������                                ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        4. ��Ϸ����                                ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        5. �򿪴浵                                ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}

// չʾ����ҳ��
void ShowAbout()
{
    system("cls"); // ����
    printf("\n");
    ShowHorizontal();
    ShowBlankLine();
    printf("\t��                         ======����======                          ��\n");
    ShowBlankLine();
    printf("\t��               ��ǰ��Ϸ����ʱ�� 2023��12��16�� 14:30               ��\n");
    printf("\t��               ��ǰ��Ϸ����ʱ�� 2023��12��22�� 11:40               ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��     Ŀǰ���ϴ��� https://github.com/sakurakugu/GluttonousSnake    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��               �����Ҵ�һ�ϳ������ʵ���ε���ĩ��ҵ                ��\n");// ��������
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    ShowBlankLine();
    printf("\t��                       0. ������ҳ��                               ��\n");
    ShowBlankLine();
    printf("\t��                   ==�����ּ� ��0~9�� ��ѡ��==                       ��\n");
    ShowBlankLine();
    ShowHorizontal();
    printf("\t");

    return;
}

// // չʾ����ģʽҳ��
// void ShowSingleMode()
// {
//     system("cls"); // ����
//     printf("\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                      ===̰���ߣ�����ģʽ��===                     ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                              ��ߵ÷֣�%d                         ��\n", HighestScore);
//     printf("\t��                              ��ǰ�÷֣�%d                         ��\n", User1.score);
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        1. ��ģʽ                                ��\n");//
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        2. ��ͨģʽ                                ��\n");//������С����������-2���ȣ�����10s����ʧ
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        3. ����ģʽ                                ��\n");//������С��������������������һ��npc
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        0. ������ҳ��                              ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t");
//     return;
// }
// // չʾ˫��ģʽҳ��
// void ShowDoubleMode()
// {
//     system("cls"); // ����
//     printf("\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                      ===�����ߣ�˫��ģʽ��===                     ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                              ��ߵ÷֣�%d                         ��\n", HighestScore);
//     printf("\t��                              ��ǰ�÷֣�%d                         ��\n", User1.score);
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        1. ��ģʽ                                ��\n");//
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        2. ��ͨģʽ                                ��\n");//������С����������-2���ȣ�����10s����ʧ
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        3. ����ģʽ                                ��\n");//������С�����������������Ե�С���������
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        0. ������һҳ��                            ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");// һ�λ����ɶ��ʳ��
//     printf("\t��                                                                   ��\n");// ������ʱ��¼�ܷ�
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t");
//     return;
// }
// չʾ��˫��ģʽ�󣬵ڶ����û���¼ҳ��
// void ShowUser2Login()
// {
//     system("cls"); // ����
//     printf("\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                       ======�û�B��¼======                       ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        �û�A��                                    ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        �û�B��                                    ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        �����û�B���û�����                        ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        �Ƿ��������룺                             ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        1. ��   ��������                           ��\n");//����������ҳ��������0��Ϊȡ���������룬ֱ�ӽ�����Ϸ
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        2. ��                                      ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                        0. ������һҳ��                            ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t");
//     return;
// }
// // չʾ�Ƿ������¼ҳ��
// void ShowContinueLogin()
// {
// 	system("cls"); // ����
// 	printf("\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                       ======�û���¼======                        ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
// 	printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
// 	printf("\t��                        �Ƿ������¼��                             ��\n");
// 	printf("\t��                                                                   ��\n");
// 	printf("\t��                        1. ��   ������¼                           ��\n");
// 	printf("\t��                                                                   ��\n");
// 	printf("\t��                        2. ��   ������һҳ��                       ��\n");
// 	printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t��                                                                   ��\n");
// 	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");
//     printf("\t��                                                                   ��\n");
//     printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
//     printf("\t");
// 	return;
// }

// չʾ��Ϸ����ҳ�棨ԭΪչʾ����Ϸ˵��ҳ�棩
void ShowGameInstructions()
{
	system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                       ======��Ϸ����======                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��     ̰���ߵ���Ϸ����                                            ��\n");
    printf("\t��         ͨ�������ߵķ���ȥ��ʳ��Ի�ø��������壬            ��\n");
    printf("\t��         �������Ի�ö��ٷ�                                        ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        0. ������һҳ��                            ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                    ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");
    
    aaa=scanf("%d", &aaa);
    Page = 1;
    return;
}


// չʾ��Ϸ����ҳ��
void ShowGameEnd()
{
    // ����ʹ��vscode�򿪲�����ȷ��
	system("cls"); // ����
    printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        ======���ս��======                       ��\n");
    printf("\t��         ������������          ����         ����   ����        ����������           ��\n");
    printf("\t��         ��    ��         ��  ��       ��   ��   ��       ��               ��\n");
    printf("\t��         ��             ��    ��      ��   ��   ��       ��               ��\n");
    printf("\t��         ��   ����        ������������      ��   ��   ��       ����������           ��\n");
    printf("\t��         ��    ��        ��    ��      ��   ��   ��       ��               ��\n");
    printf("\t��         ������������        ��    ��      ��   ��   ��       ����������           ��\n");
    printf("\t��                                                                   ��\n");// ̰����û��GameWin
    printf("\t��         ������������        ��    ��        ����������         ��������            ��\n");
    printf("\t��         ��    ��        ��    ��        ��             ��    ��          ��\n");
    printf("\t��         ��    ��        ��    ��        ��             ��    ��          ��\n");
    printf("\t��         ��    ��         ��  ��         ����������         ��������            ��\n");
    printf("\t��         ��    ��         ��  ��         ��             ��   ��           ��\n");
    printf("\t��         ������������          ����          ����������         ��    ��          ��\n");
    printf("\t��                                                                   ��\n");
    ShowBlankLine();
    printf("\t��");
    ChangeLen(10, getDigits(User1.score));// 10�ǡ����յ÷֣����ĳ���
    for (int i = 0; i < len1-2; i++) { printf(" "); }
    printf("���յ÷֣�%d", User1.score);
    for (int i = 0; i < len2+2; i++) { printf(" "); }
    printf("��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��             1. ����һ��              0. ������һҳ��              ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                   ==�����ּ� ��0~9�� ��ѡ��==                       ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}


// չʾ�Ƿ����ҳ��
void ShowIsChange()
{
	system("cls"); // ����
	printf("\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                        ======�Ƿ����======                       ��\n");
	printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
	printf("\t��                        �Ƿ�ȷ�ϸ��ģ�                             ��\n");
	printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
	printf("\t��                        1. ��   ����                               ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                        2. ��   ������һҳ��                       ��\n");
    printf("\t��                                                                   ��\n");
	printf("\t��                                                                   ��\n");
    printf("\t��                                                                   ��\n");
	printf("\t��                                                                   ��\n");
	printf("\t��                                                                   ��\n");	
	printf("\t��                      ==�����ּ� ��0~9�� ��ѡ��==                  ��\n");
    printf("\t��                                                                   ��\n");
    printf("\t������������������������������������������������������������������������������������������������������������������������������������������\n");
    printf("\t");

    return;
}

// չʾ����ҳ�棬�ò��ϣ���������д�ˡ�����ɡ�
void ShowError()
{
	system("cls"); // ����
    printf("\n");
    ShowHorizontal();
    ShowBlankLine();
    printf("\t��                     ======����======                      ��\n");
    ShowBlankLine();
    ShowBlankLine();
    printf("\t��   ����������  ��������     ��������       ��������    ��������    ��\n");
    printf("\t��   ��          ��      ��   ��      ��   ��        ��  ��      ��  ��\n");
    printf("\t��   ��          ��      ��   ��      ��   ��        ��  ��      ��  ��\n");
    printf("\t��   ��          ��      ��   ��      ��   ��        ��  ��      ��  ��\n");
    printf("\t��   ����������  ��������     ��������     ��        ��  ��������    ��\n");// һ����д��Error
    printf("\t��   ��          ��  ��       ��  ��       ��        ��  ��  ��      ��\n");
    printf("\t��   ��          ��    ��     ��    ��     ��        ��  ��    ��    ��\n");
    printf("\t��   ��          ��      ��   ��      ��   ��        ��  ��      ��  ��\n");
    printf("\t��   ����������  ��      ��   ��      ��     ��������    ��      ��  ��\n");
    ShowBlankLine();
    ShowBlankLine();
    printf("\t��                        0. ������ҳ��                              ��\n");
    ShowBlankLine();
    printf("\t��                     ==�����ּ� ��0~9�� ��ѡ��==                   ��\n");
    ShowBlankLine();
    ShowHorizontal();
    printf("\t");

    int a=scanf("%d", &aaa);
    Page = 1;
    return;
}
