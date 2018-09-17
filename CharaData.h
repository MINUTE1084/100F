#pragma once

struct Entity {
	char *Name;
	double HP;
	double ATK;
	int SPD;
	double CRT;
	double MaxHP;
	int LV = 1;
	int EXP = 0;
	int Cooldown = 0;
	double ATKBuff = 1;
	double SPDBuff = 1;
	double CRTBuff = 1;
	int BuffDura = 0;
	int PoisonDura = 0;
	int StatPoint = 0;
	bool DEF = FALSE;
	bool isDead = FALSE;
};

void NormalAttack(Entity &attack, Entity &defense);
void info(Entity chara);
void currentBuff(Entity &Player, Entity &Monster);
void currentPoison(Entity &Player, Entity &Monster);