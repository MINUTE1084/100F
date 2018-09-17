#include "stdafx.h"
/*
//��ų ������Ÿ���Դϴ�. �����Ͽ� �������ּ���.

void Skill01(Entity &Target) {
	printf("%s�� �⵵! %s�� ü���� 10 ȸ���ߴ�!\n", Target.Name, Target.Name);
	Sleep(1500);
	if (Target.HP > Target.MaxHP - 10) Target.HP = Target.MaxHP;
	else Target.HP += 10;
}

void Skill02(Entity &Caster, Entity &Target) {
	printf("%s�� ���̾� ��! %s�� 25��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name);
	Target.HP -= 25;
	Sleep(1500);
}

void Skill03(Entity &Target) {
	printf("%s�� ���� ����! %s�� ���ݷ��� ��� �����ߴ�!\n", Target.Name);
	Target.ATKBuff = 1.5;
	Target.BuffDura = 3;
	Sleep(1500);
}
*/

void SpecialSkill(Entity &Caster, Entity &Other) {
	if (Caster.Name == "�׸���") {
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
	if (Caster.Name == "������") { 
		Mario_Skill(Caster, Other);
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "������") { 
		Luigi_Skill(Caster, Other); 
		Caster.Cooldown = 4;
		return; 
	}
	if (Caster.Name == "��ġ") { 
		Peach_Skill(Caster);
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "����") { 
		Bowser_Skill(Caster);
		Caster.Cooldown = 4;
		return;
	}
	if (Caster.Name == "����" || Caster.Name == "�׸��ڱ���") {
		Goomba_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if ((Caster.Name == "���ݾ���" || Caster.Name == "���þ���") || Caster.Name == "�׸��ھ���") {
		Koopa_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if ((Caster.Name == "���׹�" || Caster.Name == "�������׹�") || Caster.Name == "�׸������׹�") {
		Haingba_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "���õ���" || Caster.Name == "�׸��ڰ��õ���") {
		Spike_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "����ѹ�" || Caster.Name == "�׸��ڱ���ѹ�") {
		Kimsuhanmu_Skill(Caster, Other);
		Caster.Cooldown = 4;
		return;
	}
	if ((Caster.Name == "�͸���" || Caster.Name == "����͸���") || Caster.Name == "�׸��ڿ͸���") {
		Waruru_Skill(Caster);
		Caster.Cooldown = 3;
		return;
	}
	if (Caster.Name == "�ظӺ귯��") {
		Hammer_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "�θ޶��귯��") {
		Boomerang_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "���̾�귯��") {
		Fire_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "�׸��ں귯��") {
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
	if (Caster.Name == "��Ʈ��" || Caster.Name == "�׸�����Ʈ��") {
		Tetra_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}	
	if (Caster.Name == "����" || Caster.Name == "�׸��ڸ���") {
		Magui_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}	
	if (Caster.Name == "������" || Caster.Name == "�׸��ڰ�����") {
		Gabong_Skill(Caster);
		Caster.Cooldown = 3;
		return;
	}
	if (Caster.Name == "�����ö��") {
		Flowey_Skill(Caster, Other);
		Caster.Cooldown = 1;
		return;
	}
	if (Caster.Name == "�����𻵲��ö��") {
		FloweyP_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "���̽������ö��") {
		FloweyI_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "�׸��ڻ����ö��") {
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
	if ((Caster.Name == "����ɾ�" || Caster.Name == "��¦����ɾ�") || Caster.Name == "�׸�������ɾ�") {
		Viola_Skill(Caster, Other);
		Caster.Cooldown = 1;
		return;
	}
	if ((Caster.Name == "����" || Caster.Name == "���") || Caster.Name == "�׸��ڰ���") {
		Gack_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "����" || Caster.Name == "�׸��ڼ���") {
		Seonin_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}
	if ((Caster.Name == "�︮" || Caster.Name == "����") || Caster.Name == "�׸����︮����") {
		Helicopter_Skill(Caster, Other);
		Caster.Cooldown = 3;
		return;
	}
	if ((Caster.Name == "����" || Caster.Name == "�ް�����") || Caster.Name == "�׸��ڸ���") {
		Mammo_Skill(Caster, Other);
		Caster.Cooldown = 5;
		return;
	}
	if ((Caster.Name == "���ٱ�" || Caster.Name == "���ôٱ�") || Caster.Name == "�׸��ڴٱ�") {
		Bone_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "��������") {
		WizardR_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "�Ķ�����") {
		WizardB_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "�������") {
		WizardY_Skill(Caster, Other);
		Caster.Cooldown = 2;
		return;
	}
	if (Caster.Name == "�׸��ڼ���") {
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
	printf("%s�� ���̾� ��! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Luigi_Skill(Entity &Caster, Entity &Target) {
	Target.ATKBuff -= 0.5;
	Target.BuffDura = 3;
	printf("%s�� �װ�Ƽ�� ��! %s�� ���ݷ��� ��� �����ߴ�!\n", Caster.Name, Target.Name);
	Sleep(1500);
}

void Peach_Skill(Entity &Target) {
	double totalHeal = Target.LV * 3;
	if (Target.HP > Target.MaxHP - totalHeal) Target.HP = Target.MaxHP;
	else Target.HP += totalHeal;
	printf("%s�� �⵵! %s�� ü���� %.1lf ȸ���ߴ�!\n", Target.Name, Target.Name, totalHeal);
	Sleep(1500);
}

void Bowser_Skill(Entity &Target) {
	printf("%s�� ǥȿ! %s�� ���ݷ��� ��� �����ߴ�!\n", Target.Name, Target.Name);
	Target.ATKBuff += 0.5;
	Target.BuffDura = 3;
	Sleep(1500);
}

void Goomba_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE ) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s�� ����! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Koopa_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.5;
	Target.HP -= totalDamage;
	printf("%s�� ����! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Haingba_Skill(Entity &Caster, Entity &Target) {
	printf("%s�� �ܴ�������! %s�� ������ ��� �����ߴ�!\n", Caster.Name, Target.Name);
	Target.ATKBuff -= 0.5;
	Target.BuffDura = 3;
	Sleep(1500);
}

void Spike_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s�� ���! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Kimsuhanmu_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	printf("%s�� ���õ��� ����! ", Caster.Name);
	for (int i = 0; i <= rand() % 5; i++) {
		Target.HP -= totalDamage;
		printf("%s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Target.Name, totalDamage);
		Sleep(250);
	}
	Sleep(1250);
}

void Waruru_Skill(Entity &Target) {
	double totalHeal = Target.LV * 2.5;
	printf("%s�� ���� ����! %s�� ü���� %.1lf ȸ���ߴ�!\n", Target.Name, Target.Name, totalHeal);
	Sleep(1500);
	if (Target.HP > Target.MaxHP - totalHeal) Target.HP = Target.MaxHP;
	else Target.HP += totalHeal;
}

void Hammer_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 1.75;
	Target.HP -= totalDamage;
	printf("%s�� ��ġ ������! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Boomerang_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;

	printf("%s�� �θ޶� ����! ", Caster.Name);
	Target.HP -= totalDamage;
	printf("%s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Target.Name, totalDamage);
	Sleep(250);
	Target.HP -= totalDamage;
	printf("%s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Target.Name, totalDamage);
	Sleep(250);

	Sleep(1250);
}

void Fire_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.5 * 0.5;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.5;
	Target.HP -= totalDamage;
	printf("%s�� ���̾� ��! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Tetra_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.25 * 0.5;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s�� �� ������! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Magui_Skill(Entity &Caster, Entity &Target) {
	double totalDamage, totalHeal;
	switch (rand() % 3) {
	case 0:
		Target.ATKBuff -= 0.5;
		Target.BuffDura = 3;
		printf("%s�� ����� ����! %s�� ���ݷ��� ��� �����ߴ�!\n", Caster.Name, Target.Name);
		break;
	case 1:
		totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
		Target.HP -= totalDamage;
		printf("%s�� ���� ����! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
		break;
	case 2:
		totalHeal = Caster.LV * 2.5;
		printf("%s�� ȸ�� �ֹ�! %s�� ü���� %.1lf ȸ���ߴ�!\n", Caster.Name, Caster.Name, totalHeal);
		if (Caster.HP > Caster.MaxHP - totalHeal) Caster.HP = Caster.MaxHP;
		else Caster.HP += totalHeal;
	}
	Sleep(1500);
}

void Gabong_Skill(Entity &Caster) {
	printf("%s�� ���� ����! %s�� ġ��Ÿ���� ��� �����ߴ�!\n", Caster.Name, Caster.Name);
	Caster.CRTBuff += 1;
	Caster.BuffDura = 3;
	Sleep(1500);
}

void Flowey_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 2;
	Target.HP -= totalDamage;
	printf("%s�� ����! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void FloweyP_Skill(Entity &Caster, Entity &Target) {
	Target.PoisonDura = 3;
	printf("%s�� ������ �극��! %s�� �� ���¿� �ɷȴ�!\n", Caster.Name, Target.Name);
	Sleep(1500);
}

void FloweyI_Skill(Entity &Caster, Entity &Target) {
	Target.ATKBuff = 0;
	Target.BuffDura = 1;
	printf("%s�� ���̽� �극��! %s�� ���� �Ͽ� ������ �Ұ���������!\n", Caster.Name, Target.Name);
	Sleep(1500);
}

void Viola_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	printf("%s�� ���� ����! ", Caster.Name);
	for (int i = 0; i < (3 + rand() % (3 - (Caster.SPD / 5))); i++) {
		totalDamage = Caster.ATK * Caster.ATKBuff * 0.5;
		Target.HP -= totalDamage;
		printf("%s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Target.Name, totalDamage);
	}
}

void Gack_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff * 1.25 * 0.8;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 1.25;
	Target.HP -= totalDamage;
	printf("%s�� �� �ø���! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Seonin_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 2.2;
	Target.HP -= totalDamage;
	printf("%s�� �������! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Helicopter_Skill(Entity &Caster, Entity &Target) {
	double totalDamage = Caster.ATK * Caster.ATKBuff * 2.5;
	Target.HP -= totalDamage;
	printf("%s�� �������! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Mammo_Skill(Entity &Caster, Entity &Target) {
	double totalDamage;
	if (Target.DEF == TRUE) totalDamage = Caster.ATK * Caster.ATKBuff;
	else totalDamage = Caster.ATK * Caster.ATKBuff * 2.75;
	Target.HP -= totalDamage;
	printf("%s�� �� ����! %s�� %.1lf��ŭ�� ���ظ� �Ծ���!\n", Caster.Name, Target.Name, totalDamage);
	Sleep(1500);
}

void Bone_Skill(Entity &Caster, Entity &Target) {
	Target.ATKBuff = 0;
	Target.BuffDura = 3;
	printf("%s�� ������ ����! %s�� %d�� �� ������ �Ұ���������!\n", Caster.Name, Target.Name, Target.BuffDura);
	Sleep(1500);
}

void WizardR_Skill(Entity &Caster, Entity &Target){
	Target.ATKBuff -= 0.7;
	Target.BuffDura = 5;
	printf("%s�� ������ ����! %s�� ���ݷ��� ��� �����ߴ�!\n", Caster.Name, Target.Name);
}

void WizardB_Skill(Entity &Caster, Entity &Target){
	Target.ATKBuff -= 0.7;
	Target.BuffDura = 5;
	printf("%s�� ������ ����! %s�� ���ǵ尡 ��� �����ߴ�!\n", Caster.Name, Target.Name);
}

void WizardY_Skill(Entity &Caster, Entity &Target){
	Target.ATKBuff -= 0.7;
	Target.BuffDura = 5;
	printf("%s�� ������ ����! %s�� ġ��Ÿ���� ��� �����ߴ�!\n", Caster.Name, Target.Name);
}
