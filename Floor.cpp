#include "stdafx.h"

void Floor(Entity* player, Entity monster[], int minMob, int maxMob, int floor, int &whoPlayer) {
	bool hasKey = FALSE;
	int mobCount = maxMob - minMob, cnt, killCount = 0;
	int monsterKey;
	char whoFight[2];
	if (mobCount == 0) monsterKey = 0;
	else monsterKey = minMob + rand() % mobCount;
	while (1) {
		cnt = 1;
		int selFight = 0;
		printf("==========================[ %3d F ]==========================\n", floor);
		for (int i = minMob; i < maxMob; i++)
			if (monster[i].isDead != TRUE)
				printf("                %2d) %17s (Lv.%2d)\n", 1+i-minMob, monster[i].Name, monster[i].LV);
		printf("           %2d) ĳ���� ��ü (���� ĳ���� : %6s)\n", mobCount+1, player[whoPlayer].Name);
		printf("                    ������ �ο�ðڽ��ϱ�?\n> ");
		scanf("%s", whoFight);
		system("cls");
		selFight = atoi(whoFight);
		selFight--;
		if (selFight == mobCount) {
			whoPlayer = charaSel(player);
			continue;
		}
		whoFight[0] += minMob;
		for (int i = minMob; i < maxMob; i++) {
			if (i == selFight) {
				if (monster[selFight].isDead == TRUE) {
					printf("�̹� ������ �Ϸ�� �� �Դϴ�.\n");
					Sleep(1500);
					system("pause");
					system("cls");
				}
				else {
					if (Battle(player[whoPlayer], monster[selFight], floor) == TRUE) {
						if (monsterKey == selFight) hasKey = TRUE;
						monster[selFight].isDead = TRUE;
						killCount++;
						if (hasKey == TRUE) printf("���踦 ȹ���ߴ�!\n");
						else printf("�� ���ʹ� ���踦 ������ ���� �ʾҴ�...\n");
						Sleep(1500);
						system("pause");
						system("cls");
						break;
					}
					else {
						player[whoPlayer].isDead = TRUE;
						if (((player[0].isDead == TRUE) && (player[1].isDead == TRUE)) && ((player[2].isDead == TRUE) && (player[3].isDead == TRUE))) {
							printf("GAME OVER\n");
							return;
						}
						else {
							printf("�ٸ� ĳ���͸� ����ּ���.\n");
							Sleep(1500);
							system("pause");
							system("cls");
							whoPlayer = charaSel(player);
							continue;
						}
					}
				}
			}
		}
		LvCheck(player[whoPlayer]);
		if (killCount != mobCount) {
			if (hasKey == TRUE) {
				char yn[2] = { '\0', };
				printf("���� �������� �̵��Ͻðڽ��ϱ�? (Y/N) > ");
				scanf("%s", yn);
				if (yn[0] == 'y' || yn[0] == 'Y') break;
			}
		}
		else break;
	}
	player[whoPlayer].HP = player[whoPlayer].MaxHP;
	player[whoPlayer].BuffDura = 0;
	player[whoPlayer].ATKBuff = 1;
	player[whoPlayer].SPDBuff = 1;
	player[whoPlayer].CRTBuff = 1;
	for (int i = minMob; i < maxMob; i++) monster[i].isDead = FALSE;
}

void BossFloor(Entity* player, Entity* Boss, int whoBoss, int &whoPlayer, int bossPower) {
	Boss[whoBoss] = { "�׸���" };

	bool isKilled = FALSE;
	char whoFight[2] = "\0";
select_:
	printf("=====================[ %3d F ]=====================\n", (whoBoss + 1) * 10);
	printf("                1) %17s (Lv.%2d)\n", Boss[whoBoss].Name, Boss[whoBoss].LV);
	printf("           2) ĳ���� ��ü (���� ĳ���� : %6s)\n", player[whoPlayer].Name);
	printf("                    ������ �ο�ðڽ��ϱ�?\n");
	scanf("%s", &whoFight);
	system("cls");
	int selFight = atoi(whoFight);
	if (selFight == 2) {
		whoPlayer = charaSel(player);
		Sleep(1500);
		system("cls");
		goto select_;
	}

	Boss[whoBoss] = { "�׸���",
		player[whoPlayer].HP / bossPower,
		player[whoPlayer].ATK / bossPower,
		player[whoPlayer].SPD / bossPower,
		player[whoPlayer].CRT / bossPower,
		player[whoPlayer].MaxHP / bossPower,
		player[whoPlayer].LV };

	if (Battle(player[whoPlayer], Boss[whoBoss], (whoBoss+1)*10)) isKilled = TRUE;
	else{
		player[whoPlayer].isDead = TRUE;
		if (((player[0].isDead == TRUE)&&(player[1].isDead == TRUE))&&((player[2].isDead == TRUE)&&(player[3].isDead == TRUE))) {
			printf("GAME OVER\n");
			return;
		}
		else {
			printf("�ٸ� ĳ���͸� ����ּ���.\n");
			Sleep(1500);
			system("pause");
			system("cls"); 
			whoPlayer = charaSel(player);
			goto select_;
		}
	}
	if (whoBoss == 9) {
		printf("��� ���� Ŭ���� �߽��ϴ�! �����մϴ�!\n");
		printf("GAME CLEAR\n");
		return;
	}
	printf("������ �����Ͽ���! ���� ���������� �̵��մϴ�.\n");
	Sleep(1500);
	system("pause");
	system("cls");

	player[whoPlayer].HP = player[whoPlayer].MaxHP;
	for (int i = 0; i < 4; i++) player[i].isDead = FALSE;
	LvCheck(player[whoPlayer]);
}