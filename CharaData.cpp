#include "stdafx.h"


void NormalAttack(Entity &attack, Entity &defense) {
	double atkNumber = (attack.SPD * attack.SPDBuff) / 5;
	if (atkNumber < 1) atkNumber = 1;
	double damage = attack.ATK * attack.ATKBuff;
	double totalDamage = 0;

	for (int i = 0; i <= rand() % (int)atkNumber; i++) {
		if (defense.DEF == TRUE) {
			damage /= 2;
			defense.DEF = FALSE;
		}
		if ((rand() % 100 + 1) <= attack.CRT*attack.CRTBuff) {
			totalDamage += damage * 2;
			printf("[CRITICAL!] %s의 공격! %s는 %.1lf만큼의 피해를 입었다!\n", attack.Name, defense.Name, damage * 2);
			Sleep(500);
		}
		else {
			totalDamage += damage;
			printf("%s의 공격! %s는 %.1lf만큼의 피해를 입었다!\n", attack.Name, defense.Name, damage);
			Sleep(500);
		}
	}

	defense.HP -= totalDamage;
	return;
}
	
void info(Entity chara) {
	printf("%s의 정보", chara.Name);
	printf(" [ Lv.%d ] (%d / %d) \n", chara.LV, chara.EXP, (int)(chara.LV * 2.5 * 5));
	Sleep(250);
	double MaxHP_;
	if (chara.isDead == FALSE) MaxHP_ = chara.MaxHP;
	else MaxHP_ = 0;
	printf("MaxHP :  %.1lf\n", MaxHP_);
	Sleep(250);
	if (chara.HP > 0) printf("HP : %.1lf\n", chara.HP);
	else printf("HP : 0.0\n");
	Sleep(250);
	printf("ATK :  %.1lf\n", chara.ATK);
	Sleep(250);
	printf("SPD : %d\n", chara.SPD);
	Sleep(250);
	printf("CRT : %.1lf%%\n", chara.CRT);
	Sleep(1500);
	if (chara.BuffDura > 0) printf("Buff 남은 시간 : %d\n", chara.BuffDura);
}

void currentBuff(Entity &Player, Entity &Monster) {
	if ((Monster.ATKBuff != 1 || Monster.SPDBuff != 1) || Monster.CRTBuff != 1) {
		if (Monster.BuffDura > 0) Monster.BuffDura--;
		else {
			Monster.ATKBuff = 1;
			Monster.SPDBuff = 1;
			Monster.CRTBuff = 1;
			printf("%s의 버프가 해제되었다!\n", Monster.Name);
		}
	}
	if ((Player.ATKBuff != 1 || Player.SPDBuff != 1) || Player.CRTBuff != 1) {
		if (Player.BuffDura > 0) Player.BuffDura--;
		else {
			Player.ATKBuff = 1;
			Player.SPDBuff = 1;
			Player.CRTBuff = 1;
			printf("%s의 버프가 해제되었다!\n", Player.Name);
		}
	}
}
void currentPoison(Entity &Player, Entity &Monster) {
	if (Monster.PoisonDura > 0) {
		Monster.PoisonDura--;
		double PDamage = Player.ATK * 0.75;
		printf("독 효과로 %s는 %.1lf만큼의 피해를 입었다!\n", Monster.Name, PDamage);
		Monster.HP -= PDamage;
	}
	if (Player.PoisonDura > 0) {
		Player.PoisonDura--;
		double PDamage = Monster.ATK * 0.75;
		printf("독 효과로 %s는 %.1lf만큼의 피해를 입었다!\n", Player.Name, PDamage);
		Player.HP -= PDamage;
	}
}