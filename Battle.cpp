#include "stdafx.h"

bool Battle(Entity &player, Entity monster, int floor) {
	char sel[2] = { '\0', };

	printf("==============================================================================\n\n");
	printf("                 [WARNING!] %17s��(��) �����ߴ�!", monster.Name);
	printf("\n\n==============================================================================\n");
	Sleep(1500);
	system("cls");
	while (1) {
	select:
		printf("==============================================================================\n");
		printf("%17s�� ü�� : %5.1lf / %17s�� ü�� : %5.1lf\n", player.Name, player.HP, monster.Name, monster.HP);
		printf("                                 ������ �ұ�?\n");
		printf("                      1. ���� 2. ���� ��ų 3. ��� 4. ����\n");
		printf("==============================================================================\n> ");
		scanf("%s", sel);
		switch (sel[0]) {
		case '1':
			NormalAttack(player, monster);
			player.DEF = FALSE;
			Sleep(1000);
			break;
		case '2':
			if (player.Cooldown > 1) {
				printf("��Ÿ���Դϴ�.\n");
				Sleep(1500);
				system("cls");
				goto select;
			}
			else {
				SpecialSkill(player, monster);
				player.DEF = FALSE;
				break;
			}
		case '3':
			printf("�� �����ߴ�! (�������� ���ݸ� �޽��ϴ�.)\n");
			player.DEF = TRUE;
			Sleep(1500);
			break;
		case '4':
			system("cls");
			info(player);
			info(monster);
			system("pause");
			system("cls");
			goto select;
		default:
			system("cls");
			goto select;
		}
		player.Cooldown--;
		if (player.BuffDura > 0) player.BuffDura--;
		else {
			player.ATKBuff = 1;
			player.SPDBuff = 1;
			player.CRTBuff = 1;
		}
		if (monster.HP <= 0) {
			printf("%s�� ��������!\n", monster.Name);
			printf("�������� �¸��Ͽ���!\n");
			int EXP = monster.LV * (2 + rand() % 3);
			player.EXP += EXP;
			printf("%d EXP�� ȹ���ߴ�!\n", EXP);
			Sleep(1500);
			return TRUE;
		}
		int sel_;
		printf("%s�� ��!\n", monster.Name);
		printf("==============================================================================\n");
		printf("%17s�� ü�� : %5.1lf / %17s�� ü�� : %5.1lf\n", player.Name, player.HP, monster.Name, monster.HP);
		printf("                                 ������ �ұ�?\n");
		printf("                      1. ���� 2. ���� ��ų 3. ��� 4. ����\n");
		printf("==============================================================================\n> ");
		Sleep(1500);
	mon_sel_:
		sel_ = 1 + rand() % 100;
		if (1 <= sel_ && sel_ <= 50) {
			printf("%s�� ������ �����ߴ�!\n", monster.Name);
			NormalAttack(monster, player);
			monster.DEF = FALSE;
			Sleep(1000);
			system("cls");
		}
		else if (51 <= sel_ && sel_ <= 80) {
			if (player.Cooldown > 1) goto mon_sel_;
			else {
				printf("%s�� ��ų!\n", monster.Name);
				SpecialSkill(monster, player);
				monster.DEF = FALSE;
				Sleep(1500);
				system("cls");
			}
		}
		else if (81 <= sel_ && sel_ <= 100) {
			printf("%s�� �� �����ߴ�!\n", monster.Name);
			monster.DEF = TRUE;
			Sleep(1500);
			system("cls");
		}
		currentBuff(player, monster);
		currentPoison(player, monster);
		monster.Cooldown--;
		if (player.HP <= 0) {
			printf("%s�� ��������!\n", player.Name);
			printf("�������� �й��Ͽ���...\n");
			Sleep(1500);
			system("cls");
			return FALSE;
		}
		if (monster.HP <= 0) {
			printf("%s�� ��������!\n", monster.Name);
			printf("�������� �¸��Ͽ���!\n");
			int EXP = monster.LV * (2 + rand() % 3);
			player.EXP += EXP;
			printf("%d EXP�� ȹ���ߴ�!\n", EXP);
			Sleep(1500);
			return TRUE;
		}
	}
}
