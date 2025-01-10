#pragma once
#include "defValue.h"
#include "Item.h"

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

struct _tagPlayer {
	char			strName[NAME_SIZE];
	char			strJobName[NAME_SIZE];
	JOB				eJob;
	int				iAttack;
	int				iArmor;
	int				iHP;
	int				iHPMax;
	int				iMP;
	int				iMPMax;
	int				iExp;
	int				iLevel;
	_tagItem		tEquip[EQ_MAX];
	bool			bEquip[EQ_MAX];
	_tagInventory	tInventory;
};

struct _tagLevelUpStatus {
	int iAttack;
	int iArmor;
	int iHP;
	int iMP;
};

const int iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000,
									70000, 100000,150000, 200000, 400000 };

_tagLevelUpStatus tLvUpTable[JOB_END - 1] = {};
