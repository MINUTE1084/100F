#include "stdafx.h"

void LvCheck(Entity &Player){
	while (Player.EXP >= (int)(Player.LV * 2.5 * 5)) {
		Player.EXP -= (int)(Player.LV * 2.5 * 5);
		printf("Level UP! ���� ���� : %d\n", ++Player.LV);
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
	char yn[2];
sel_stat:
	system("cls");
	info(Player);
	sel_stat = 0;
	printf("���� ���� ����Ʈ : %d ����Ʈ\n", Player.StatPoint);
	printf("1) ATK - ���ݷ� : ���ݷ��� �����մϴ�.\n");
	printf("2) SPD - ���ǵ� : �� �Ͽ� ���� �� ���� �� Ȯ���� �����մϴ�.\n");
	printf("3) CRT - ġ��Ÿ�� : �Ϲ� ���� �� ġ��Ÿ�� ������ Ȯ���� �����մϴ�.\n");
	printf("��ȭ��ų ������ �������ּ���. �ѹ� ��ȭ �� ������ �Ұ����մϴ�.\n> ");
	scanf("%d", &sel_stat);

	if (Player.StatPoint > 1) {
		printf("���� ����Ʈ�� �󸶳� ����Ͻðڽ��ϱ�?\n> ");
		scanf("%d", &pointcnt);
		if (pointcnt == 1) pointcnt = 1;
		else if (pointcnt > Player.StatPoint) {
			printf("�������� ���� ����Ʈ ���� �����ϴ�. 1 ����Ʈ�� ���˴ϴ�.\n");
			pointcnt = 1;
			Sleep(1500);
		}
		else if (pointcnt < 1) {
			printf("1 �̸��� ���� �ԷµǾ����ϴ�. 1 ����Ʈ�� ���˴ϴ�.\n");
			pointcnt = 1;
			Sleep(1500);
		}
		system("cls");
	}

	switch (sel_stat) {
	case 1:
		system("cls");
		Player.ATK += pointcnt;
		printf("ATK�� %d ����߽��ϴ�.\n", pointcnt);
		info(Player);
		Player.StatPoint -= pointcnt;
		if (Player.StatPoint > 0) {
			printf("���� ��ȭ�� ��� �����Ͻðڽ��ϱ�? (Y/N)\n> ");
			scanf("%s", yn);

			if (yn[0] == 'Y' || yn[0] == 'y') goto sel_stat;
		}
		break;
	case 2:
		system("cls");
		Player.SPD += pointcnt;
		printf("SPD�� %d ����߽��ϴ�.\n", pointcnt);
		info(Player);
		Player.StatPoint -= pointcnt;
		if (Player.StatPoint > 0) {
			printf("���� ��ȭ�� ��� �����Ͻðڽ��ϱ�? (Y/N)\n> ");
			scanf("%s", yn);

			if (yn[0] == 'Y' || yn[0] == 'y') goto sel_stat;
		}
		break;
	case 3:
		system("cls");
		if (Player.CRT < 100) {
			Player.CRT += pointcnt;
			Player.StatPoint -= pointcnt;

			if (Player.CRT > 100) {
				printf("CRT�� 100%%�� �ʰ��߽��ϴ�. �ʰ��� ������ ����Ʈ�� ��ȯ�˴ϴ�.\n");
				pointcnt += (int)(Player.CRT) - 100;
				Player.CRT = 100;
				printf("CRT�� 1 ����߽��ϴ�.\n");
			}
			else printf("CRT�� %d ����߽��ϴ�.\n", pointcnt);

			info(Player);

			if (Player.StatPoint > 0) {
				printf("���� ��ȭ�� ��� �����Ͻðڽ��ϱ�? (Y/N)\n> ");
				scanf("%s", yn);
				system("pause");
				if (yn[0] == 'Y' || yn[0] == 'y') goto sel_stat;
			}
			break;
		}
		else {
			printf("���� ��ȭ�� �Ұ��� �մϴ�.\n");
			system("pause");
		}
	default:
		goto sel_stat;
	}
}