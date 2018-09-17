#include "stdafx.h"
/*
//스킬 프로토타입입니다. 참고하여 제작해주세요.

void Skill01(Entity &Target) {
	printf("%s의 기도! %s는 체력을 10 회복했다!\n", Target.Name, Target.Name);
	Sleep(1500);
	if (Target.HP > Target.MaxHP - 10) Target.HP = Target.MaxHP;
	else Target.HP += 10;
}

void Skill02(Entity &Caster, Entity &Target) {
	printf("%s의 파이어 볼! %s는 25만큼의 피해를 입었다!\n", Caster.Name, Target.Name);
	Target.HP -= 25;
	Sleep(1500);
}

void Skill03(Entity &Target) {
	printf("%s의 전투 개시! %s의 공격력이 잠시 증가했다!\n", Target.Name);
	Target.ATKBuff = 1.5;
	Target.BuffDura = 3;
	Sleep(1500);
}
*/

void SpecialSkill(Entity &Caster, Entity &Other) {
	if (Caster.Name == "그림자") {
		switch (rand() % 4) {
		case 0:
			Mario_Skill(Caster, Other);
			break;
		case 1:
			Luigi_Skill(Caster, Other);
			break;
		case 2:
			Peach_Skill(Caster);
			break;
		case 3:
			Bowser_Skill(Caster);
			break;
		}
		Caster.Cooldown = 3;
		return;
	}
	if (Caster.Name == "마리오") { 
		Mario_Skill(Caster, Other);
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "루이지") { 
		Luigi_Skill(Caster, Other); 
		Caster.Cooldown = 4;
		return; 
	}
	if (Caster.Name == "피치") { 
		Peach_Skill(Caster);
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "쿠파") { 
		Bowser_Skill(Caster);
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "굼바" || Caster.Name == "그림자굼바") {
		Goomba_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if ((Caster.Name == "엉금엉금" || Caster.Name == "가시엉금") || Caster.Name == "그림자엉금") {
		Koopa_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if ((Caster.Name == "하잉바" || Caster.Name == "가시하잉바") || Caster.Name == "그림자하잉바") {
		Haingba_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "가시돌이" || Caster.Name == "그림자가시돌이") {
		Spike_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "김수한무" || Caster.Name == "그림자김수한무") {
		Kimsuhanmu_Skill(Caster, Other);
		Caster.Cooldown = 4;
		return;
	}
	if ((Caster.Name == "와르르" || Caster.Name == "좀비와르르") || Caster.Name == "그림자와르르") {
		Waruru_Skill(Caster);
		Caster.Cooldown = 3;
		return;
	}
	if (Caster.Name == "해머브러스") {
		Hammer_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "부메랑브러스") {
		Boomerang_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "파이어브러스") {
		Fire_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "그림자브러스") {
		switch (rand() % 3) {
		case 0:
			Hammer_Skill(Caster, Other);
			break;
		case 1:
			Boomerang_Skill(Caster, Other);
			break;
		case 2:
			Fire_Skill(Caster, Other);
			break;
		}
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "테트라" || Caster.Name == "그림자테트라") {
		Tetra_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}	
	if (Caster.Name == "마귀" || Caster.Name == "그림자마귀") {
		Magui_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}	
	if (Caster.Name == "가봉병" || Caster.Name == "그림자가봉병") {
		Gabong_Skill(Caster);
		Caster.Cooldown = 3;
		return;
	}
	if (Caster.Name == "뻐끔플라워") {
		Flowey_Skill(Caster, Other);
		Caster.Cooldown = 1;
		return;
	}
	if (Caster.Name == "포이즌뻐끔플라워") {
		FloweyP_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "아이스뻐끔플라워") {
		FloweyI_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "그림자뻐끔플라워") {
		switch (rand() % 3) {
		case 0:
			Flowey_Skill(Caster, Other);
			break;
		case 1:
			FloweyP_Skill(Caster, Other);
			break;
		case 2:
			FloweyI_Skill(Caster, Other);
			break;
		}
		Caster.Cooldown = 4;
		return;
	}
	if ((Caster.Name == "제비꽃씨" || Caster.Name == "반짝제비꽃씨") || Caster.Name == "그림자제비꽃씨") {
		Viola_Skill(Caster, Other);
		Caster.Cooldown = 1;
		return;
	}
	if ((Caster.Name == "각각" || Caster.Name == "깍깍") || Caster.Name == "그림자각각") {
		Gack_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "선인" || Caster.Name == "그림자선인") {
		Seonin_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}
	if ((Caster.Name == "헬리" || Caster.Name == "콥터") || Caster.Name == "그림자헬리콥터") {
		Helicopter_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}
	if ((Caster.Name == "맘모" || Caster.Name == "메가맘모") || Caster.Name == "그림자맘모") {
		Mammo_Skill(Caster, Other);
		Caster.Cooldown = 5;
		return;
	}
	if ((Caster.Name == "뼈다귀" || Caster.Name == "가시다귀") || Caster.Name == "그림자다귀") {
		Bone_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "빨강술사") {
		WizardR_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "파랑술사") {
		WizardB_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "노랑술사") {
		WizardY_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "그림자술사") {
		switch (rand() % 3) {
		case 0:
			WizardR_Skill(Caster, Other);
			break;
		case 1:
			WizardB_Skill(Caster, Other);
			break;
		case 2:
			WizardY_Skill(Caster, Other);
			break;
		}
		Caster.Cooldown = 3;
		return;
	}
}

void Mario_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE ) totalDamage = Caster.ATK * Caster.ATKBuff * 1.5 * 0.75;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.5;
	Target.HP -= totalDamage;
	printf("%s의 파이어 볼! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Luigi_Skill(Entity &Caster, Entity &Target) {
	Target.ATKBuff -= 0.5;
	Target.BuffDura = 3;
	printf("%s의 네거티브 댄스! %s의 공격력이 잠시 감소했다!\n", Caster.Name, Target.Name);
	Sleep(1500);
}

void Peach_Skill(Entity &Target) {
	double totalHeal = Target.LV * 3;
	if (Target.HP > Target.MaxHP - totalHeal) Target.HP = Target.MaxHP;
	else Target.HP += totalHeal;
	printf("%s의 기도! %s는 체력을 %.1lf 회복했다!\n", Target.Name, Target.Name, totalHeal);
	Sleep(1500);
}

void Bowser_Skill(Entity &Target) {
	printf("%s의 표효! %s의 공격력이 잠시 증가했다!\n", Target.Name, Target.Name);
	Target.ATKBuff += 0.5;
	Target.BuffDura = 3;
	Sleep(1500);
}

void Goomba_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE ) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s의 점프! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Koopa_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.5;
	Target.HP -= totalDamage;
	printf("%s의 돌진! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Haingba_Skill(Entity &Caster, Entity &Target) {
	printf("%s의 단단해지기! %s의 방어력이 잠시 증가했다!\n", Caster.Name, Target.Name);
	Target.ATKBuff -= 0.5;
	Target.BuffDura = 3;
	Sleep(1500);
}

void Spike_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s의 찌르기! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Kimsuhanmu_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	printf("%s의 가시돌이 공격! ", Caster.Name);
	for (int i = 0; i <= rand() % 5; i++) {
		Target.HP -= totalDamage;
		printf("%s는 %.1lf만큼의 피해를 입었다!\n", Target.Name, totalDamage);
		Sleep(250);
	}
	Sleep(1250);
}

void Waruru_Skill(Entity &Target) {
	double totalHeal = Target.LV * 2.5;
	printf("%s의 셀프 힐링! %s는 체력을 %.1lf 회복했다!\n", Target.Name, Target.Name, totalHeal);
	Sleep(1500);
	if (Target.HP > Target.MaxHP - totalHeal) Target.HP = Target.MaxHP;
	else Target.HP += totalHeal;
}

void Hammer_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 1.75;
	Target.HP -= totalDamage;
	printf("%s의 망치 던지기! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Boomerang_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;

	printf("%s의 부메랑 공격! ", Caster.Name);
	Target.HP -= totalDamage;
	printf("%s는 %.1lf만큼의 피해를 입었다!\n", Target.Name, totalDamage);
	Sleep(250);
	Target.HP -= totalDamage;
	printf("%s는 %.1lf만큼의 피해를 입었다!\n", Target.Name, totalDamage);
	Sleep(250);

	Sleep(1250);
}

void Fire_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.5 * 0.5;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.5;
	Target.HP -= totalDamage;
	printf("%s의 파이어 볼! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Tetra_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.25 * 0.5;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s의 돌 던지기! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Magui_Skill(Entity &Caster, Entity &Target) {
	double totalDamage, totalHeal;
	switch (rand() % 3) {
	case 0:
		Target.ATKBuff -= 0.5;
		Target.BuffDura = 3;
		printf("%s의 무기력 마법! %s의 공격력이 잠시 감소했다!\n", Caster.Name, Target.Name);
		break;
	case 1:
		totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
		Target.HP -= totalDamage;
		printf("%s의 마법 공격! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
		break;
	case 2:
		totalHeal = Caster.LV * 2.5;
		printf("%s의 회복 주문! %s는 체력을 %.1lf 회복했다!\n", Caster.Name, Caster.Name, totalHeal);
		if (Caster.HP > Caster.MaxHP - totalHeal) Caster.HP = Caster.MaxHP;
		else Caster.HP += totalHeal;
	}
	Sleep(1500);
}

void Gabong_Skill(Entity &Caster) {
	printf("%s의 정신 집중! %s의 치명타율이 잠시 증가했다!\n", Caster.Name, Caster.Name);
	Caster.CRTBuff += 1;
	Caster.BuffDura = 3;
	Sleep(1500);
}

void Flowey_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 2;
	Target.HP -= totalDamage;
	printf("%s의 물기! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void FloweyP_Skill(Entity &Caster, Entity &Target) {
	Target.PoisonDura = 3;
	printf("%s의 포이즌 브레스! %s는 독 상태에 걸렸다!\n", Caster.Name, Target.Name);
	Sleep(1500);
}

void FloweyI_Skill(Entity &Caster, Entity &Target) {
	Target.ATKBuff = 0;
	Target.BuffDura = 1;
	printf("%s의 아이스 브레스! %s는 다음 턴에 공격이 불가능해졌다!\n", Caster.Name, Target.Name);
	Sleep(1500);
}

void Viola_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	printf("%s의 연속 공격! ", Caster.Name);
	for (int i = 0; i < (3 + rand() % (3 - (Caster.SPD / 5))); i++) {
		totalDamage = Caster.ATK * Caster.ATKBuff * 0.5;
		Target.HP -= totalDamage;
		printf("%s는 %.1lf만큼의 피해를 입었다!\n", Target.Name, totalDamage);
	}
}

void Gack_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.25 * 0.8;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s의 몸 늘리기! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Seonin_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 2.2;
	Target.HP -= totalDamage;
	printf("%s의 내리찍기! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Helicopter_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 2.5;
	Target.HP -= totalDamage;
	printf("%s의 기습공격! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Mammo_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 2.75;
	Target.HP -= totalDamage;
	printf("%s의 급 돌진! %s는 %.1lf만큼의 피해를 입었다!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Bone_Skill(Entity &Caster, Entity &Target) {
	Target.ATKBuff = 0;
	Target.BuffDura = 3;
	printf("%s의 죽음의 숨결! %s는 %d턴 간 공격이 불가능해졌다!\n", Caster.Name, Target.Name, Target.BuffDura);
	Sleep(1500);
}

void WizardR_Skill(Entity &Caster, Entity &Target){
	Target.ATKBuff -= 0.7;
	Target.BuffDura = 5;
	printf("%s의 섀도우 스펠! %s의 공격력이 잠시 감소했다!\n", Caster.Name, Target.Name);
}

void WizardB_Skill(Entity &Caster, Entity &Target){
	Target.ATKBuff -= 0.7;
	Target.BuffDura = 5;
	printf("%s의 섀도우 스펠! %s의 스피드가 잠시 감소했다!\n", Caster.Name, Target.Name);
}

void WizardY_Skill(Entity &Caster, Entity &Target){
	Target.ATKBuff -= 0.7;
	Target.BuffDura = 5;
	printf("%s의 섀도우 스펠! %s의 치명타율이 잠시 감소했다!\n", Caster.Name, Target.Name);
}
