#include "stdafx.h"

void LvCheck(Entity &Player){
	while (Player.EXP >= (int)(Player.LV * 2.5 * 5)) {
		Player.EXP -= (int)(Player.LV * 2.5 * 5);
		printf("Level UP! 현재 레벨 : %d\n", ++Player.LV);
		Player.MaxHP += 5;
		Player.HP = Player.MaxHP;
		Player.StatPoint += 3;
		info(Player);
		Sleep(1500);
		system("pause");
		system("cls");
	}
}

void Stat(Entity &Player) {
	int sel_stat, pointcnt = 1;
	bool continue_ = true;
	char yn[2];
	while (continue_) {
		continue_ = false;
		system("cls");
		info(Player);
		sel_stat = 0;
		printf("현재 스탯 포인트 : %d 포인트\n", Player.StatPoint);
		printf("1) ATK - 공격력 : 공격력이 증가합니다.\n");
		printf("2) SPD - 스피드 : 한 턴에 여러 번 공격 할 확률이 증가합니다.\n");
		printf("3) CRT - 치명타율 : 일반 공격 시 치명타가 등장할 확률이 증가합니다.\n");
		printf("강화시킬 스탯을 선택해주세요. 한번 강화 시 수정이 불가능합니다.\n> ");
		scanf("%d", &sel_stat);

		if (Player.StatPoint > 1) {
			printf("스탯 포인트를 얼마나 사용하시겠습니까?\n> ");
			scanf("%d", &pointcnt);
			if (pointcnt == 1) pointcnt = 1;
			else if (pointcnt > Player.StatPoint) {
				printf("소지중인 스탯 포인트 보다 많습니다. 1 포인트만 사용됩니다.\n");
				pointcnt = 1;
				Sleep(1500);
			}
			else if (pointcnt < 1) {
				printf("1 미만의 수가 입력되었습니다. 1 포인트만 사용됩니다.\n");
				pointcnt = 1;
				Sleep(1500);
			}
			system("cls");
		}

		switch (sel_stat) {
		case 1:
			system("cls");
			Player.ATK += pointcnt;
			printf("ATK가 %d 상승했습니다.\n", pointcnt);
			info(Player);
			Player.StatPoint -= pointcnt;
			if (Player.StatPoint > 0) {
				printf("스탯 강화를 계속 진행하시겠습니까? (Y/N)\n> ");
				scanf("%s", yn);

				if (yn[0] == 'Y' || yn[0] == 'y') continue_ = true;
			}
			break;
		case 2:
			system("cls");
			Player.SPD += pointcnt;
			printf("SPD가 %d 상승했습니다.\n", pointcnt);
			info(Player);
			Player.StatPoint -= pointcnt;
			if (Player.StatPoint > 0) {
				printf("스탯 강화를 계속 진행하시겠습니까? (Y/N)\n> ");
				scanf("%s", yn);

				if (yn[0] == 'Y' || yn[0] == 'y') continue_ = true;
			}
			break;
		case 3:
			system("cls");
			if (Player.CRT < 100) {
				Player.CRT += pointcnt;
				Player.StatPoint -= pointcnt;

				if (Player.CRT > 100) {
					printf("CRT가 100%%를 초과했습니다. 초과된 스탯은 포인트로 반환됩니다.\n");
					pointcnt += (int)(Player.CRT) - 100;
					Player.CRT = 100;
					printf("CRT가 1 상승했습니다.\n");
				}
				else printf("CRT가 %d 상승했습니다.\n", pointcnt);

				info(Player);

				if (Player.StatPoint > 0) {
					printf("스탯 강화를 계속 진행하시겠습니까? (Y/N)\n> ");
					scanf("%s", yn);
					system("pause");
					if (yn[0] == 'Y' || yn[0] == 'y') continue_ = true;
				}
				break;
			}
			else {
				printf("스탯 강화가 불가능 합니다.\n");
				system("pause");
			}
		default:
			continue_ = true;
		}
	}
}