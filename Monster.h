#pragma once
#include "DefValue.h"

enum MAP_TYPE{
	MT_NONE,
	MT_EASY,
	MT_NOMAL,
	MT_HARD,
	MT_BACK
};

struct _tagMonster {
	char strName[NAME_SIZE];
	int iAttack;
	int iArmor;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iGetExp;
	int iGetGoldMin;
	int iGetGoldMax;
};

_tagMonster tMonsterArr[MT_BACK - 1] = {};
