#include "stdafx.h"

bool Battle(Entity &player, Entity monster, int floor) {
	char sel[2] = { '\0', };

	printf("==============================================================================\n\n");
	printf("                 [WARNING!] %17s이(가) 등장했다!", monster.Name);
	printf("\n\n==============================================================================\n");
	Sleep(1500);
	system("cls");
	while (1) {
	select:
		printf("==============================================================================\n");
		printf("%17s의 체력 : %5.1lf / %17s의 체력 : %5.1lf\n", player.Name, player.HP, monster.Name, monster.HP);
		printf("                                 무엇을 할까?\n");
		printf("                      1. 공격 2. 고유 스킬 3. 방어 4. 스탯\n");
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
				printf("쿨타임입니다.\n");
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
			printf("방어를 선택했다! (데미지를 절반만 받습니다.)\n");
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
			printf("%s는 쓰러졌다!\n", monster.Name);
			printf("전투에서 승리하였다!\n");
			int EXP = monster.LV * (2 + rand() % 3);
			player.EXP += EXP;
			printf("%d EXP를 획득했다!\n", EXP);
			Sleep(1500);
			return TRUE;
		}
		int sel_;
		printf("%s의 턴!\n", monster.Name);
		printf("==============================================================================\n");
		printf("%17s의 체력 : %5.1lf / %17s의 체력 : %5.1lf\n", player.Name, player.HP, monster.Name, monster.HP);
		printf("                                 무엇을 할까?\n");
		printf("                      1. 공격 2. 고유 스킬 3. 방어 4. 스탯\n");
		printf("==============================================================================\n> ");
		Sleep(1500);
	mon_sel_:
		sel_ = 1 + rand() % 100;
		if (1 <= sel_ && sel_ <= 50) {
			printf("%s는 공격을 선택했다!\n", monster.Name);
			NormalAttack(monster, player);
			monster.DEF = FALSE;
			Sleep(1000);
			system("cls");
		}
		else if (51 <= sel_ && sel_ <= 80) {
			if (player.Cooldown > 1) goto mon_sel_;
			else {
				printf("%s의 스킬!\n", monster.Name);
				SpecialSkill(monster, player);
				monster.DEF = FALSE;
				Sleep(1500);
				system("cls");
			}
		}
		else if (81 <= sel_ && sel_ <= 100) {
			printf("%s는 방어를 선택했다!\n", monster.Name);
			monster.DEF = TRUE;
			Sleep(1500);
			system("cls");
		}
		currentBuff(player, monster);
		currentPoison(player, monster);
		monster.Cooldown--;
		if (player.HP <= 0) {
			printf("%s는 쓰러졌다!\n", player.Name);
			printf("전투에서 패배하였다...\n");
			Sleep(1500);
			system("cls");
			return FALSE;
		}
		if (monster.HP <= 0) {
			printf("%s는 쓰러졌다!\n", monster.Name);
			printf("전투에서 승리하였다!\n");
			int EXP = monster.LV * (2 + rand() % 3);
			player.EXP += EXP;
			printf("%d EXP를 획득했다!\n", EXP);
			Sleep(1500);
			return TRUE;
		}
	}
}
