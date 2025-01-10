#pragma once
#include "DefValue.h"

enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum EQUIP {
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};

struct _tagItem {
	char	strName[NAME_SIZE];
	char	strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int		iValue;
	int		iPrice;
	int		iSell;
	int		iUserLevel;
	char	strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory {
	_tagItem	tItem[INVENTORY_MAX];
	int			iTemCount;
	int			iGold;
};

_tagItem tStoreWeaponKnight[STORE_WEAPON_MAX] = {};
_tagItem tStoreWeaponArcher[STORE_WEAPON_MAX] = {};
_tagItem tStoreWeaponWizard[STORE_WEAPON_MAX] = {};
_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};
