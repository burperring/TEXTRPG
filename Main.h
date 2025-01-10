#pragma once
#include <iostream>
#include "Character.h"
#include "Monster.h"

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

void SetLvTable() {
	// KNIGHT
	tLvUpTable[JOB_KNIGHT - 1].iAttack = 5;
	tLvUpTable[JOB_KNIGHT - 1].iArmor = 10;
	tLvUpTable[JOB_KNIGHT - 1].iHP = 75;
	tLvUpTable[JOB_KNIGHT - 1].iMP = 15;

	// ARCHER
	tLvUpTable[JOB_ARCHER - 1].iAttack = 10;
	tLvUpTable[JOB_ARCHER - 1].iArmor = 5;
	tLvUpTable[JOB_ARCHER - 1].iHP = 50;
	tLvUpTable[JOB_ARCHER - 1].iMP = 25;

	// WIZARD
	tLvUpTable[JOB_WIZARD - 1].iAttack = 20;
	tLvUpTable[JOB_ARCHER - 1].iArmor = 3;
	tLvUpTable[JOB_ARCHER - 1].iHP = 20;
	tLvUpTable[JOB_ARCHER - 1].iMP = 50;
}

void SetMonsterTable() {
	// 고블린
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttack = 20;
	tMonsterArr[0].iArmor = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iGetExp = 1000;
	tMonsterArr[0].iGetGoldMin = 500;
	tMonsterArr[0].iGetGoldMax = 1500;

	// 트롤
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttack = 100;
	tMonsterArr[1].iArmor = 75;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iGetExp = 7000;
	tMonsterArr[1].iGetGoldMin = 6000;
	tMonsterArr[1].iGetGoldMax = 8000;

	// 드래곤
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttack = 350;
	tMonsterArr[2].iArmor = 300;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iGetExp = 30000;
	tMonsterArr[2].iGetGoldMin = 20000;
	tMonsterArr[2].iGetGoldMax = 50000;
}

void SetKnightWeaponStore() {
	// 단검
	strcpy_s(tStoreWeaponKnight[0].strName, "단검");
	strcpy_s(tStoreWeaponKnight[0].strTypeName, "기사무기");
	strcpy_s(tStoreWeaponKnight[0].strDesc, "수행기사가 사용하는 연습용 단검");
	tStoreWeaponKnight[0].iValue = 5;
	tStoreWeaponKnight[0].iPrice = 700;
	tStoreWeaponKnight[0].iSell = 500;
	tStoreWeaponKnight[0].iUserLevel = 1;
	tStoreWeaponKnight[0].eType = ITEM_TYPE(IT_WEAPON);

	// 장검
	strcpy_s(tStoreWeaponKnight[1].strName, "장검");
	strcpy_s(tStoreWeaponKnight[1].strTypeName, "기사무기");
	strcpy_s(tStoreWeaponKnight[1].strDesc, "정식기사가 사용하는 검");
	tStoreWeaponKnight[1].iValue = 25;
	tStoreWeaponKnight[1].iPrice = 30000;
	tStoreWeaponKnight[1].iSell = 25000;
	tStoreWeaponKnight[1].iUserLevel = 5;
	tStoreWeaponKnight[1].eType = ITEM_TYPE(IT_WEAPON);

	// 드래곤소드
	strcpy_s(tStoreWeaponKnight[2].strName, "드래곤소드");
	strcpy_s(tStoreWeaponKnight[2].strTypeName, "기사무기");
	strcpy_s(tStoreWeaponKnight[2].strDesc, "용을 죽이기 위해 만들어진 검");
	tStoreWeaponKnight[2].iValue = 125;
	tStoreWeaponKnight[2].iPrice = 150000;
	tStoreWeaponKnight[2].iSell = 120000;
	tStoreWeaponKnight[2].iUserLevel = 10;
	tStoreWeaponKnight[2].eType = ITEM_TYPE(IT_WEAPON);
}

void SetArcherWeaponStore() {
	// 나무활
	strcpy_s(tStoreWeaponArcher[0].strName, "나무활");
	strcpy_s(tStoreWeaponArcher[0].strTypeName, "궁수무기");
	strcpy_s(tStoreWeaponArcher[0].strDesc, "수행궁수가 사용하는 연습용 활");
	tStoreWeaponArcher[0].iValue = 6;
	tStoreWeaponArcher[0].iPrice = 700;
	tStoreWeaponArcher[0].iSell = 500;
	tStoreWeaponArcher[0].iUserLevel = 1;
	tStoreWeaponArcher[0].eType = ITEM_TYPE(IT_WEAPON);

	// 탄소섬유활
	strcpy_s(tStoreWeaponArcher[1].strName, "탄소섬유활");
	strcpy_s(tStoreWeaponArcher[1].strTypeName, "궁수무기");
	strcpy_s(tStoreWeaponArcher[1].strDesc, "정식궁수가 사용하는 활");
	tStoreWeaponArcher[1].iValue = 30;
	tStoreWeaponArcher[1].iPrice = 30000;
	tStoreWeaponArcher[1].iSell = 25000;
	tStoreWeaponArcher[1].iUserLevel = 5;
	tStoreWeaponArcher[1].eType = ITEM_TYPE(IT_WEAPON);

	// 드래곤보우
	strcpy_s(tStoreWeaponArcher[2].strName, "드래곤보우");
	strcpy_s(tStoreWeaponArcher[2].strTypeName, "궁수무기");
	strcpy_s(tStoreWeaponArcher[2].strDesc, "용을 잡기위해 만들어진 활");
	tStoreWeaponArcher[2].iValue = 135;
	tStoreWeaponArcher[2].iPrice = 150000;
	tStoreWeaponArcher[2].iSell = 120000;
	tStoreWeaponArcher[2].iUserLevel = 10;
	tStoreWeaponArcher[2].eType = ITEM_TYPE(IT_WEAPON);
}

void SetWizardWeaponStore() {
	// 완드
	strcpy_s(tStoreWeaponWizard[0].strName, "완드");
	strcpy_s(tStoreWeaponWizard[0].strTypeName, "마법사무기");
	strcpy_s(tStoreWeaponWizard[0].strDesc, "수행마법사가 사용하는 연습용 완드");
	tStoreWeaponWizard[0].iValue = 7;
	tStoreWeaponWizard[0].iPrice = 700;
	tStoreWeaponWizard[0].iSell = 500;
	tStoreWeaponWizard[0].iUserLevel = 1;
	tStoreWeaponWizard[0].eType = ITEM_TYPE(IT_WEAPON);

	// 스태프
	strcpy_s(tStoreWeaponWizard[1].strName, "스태프");
	strcpy_s(tStoreWeaponWizard[1].strTypeName, "마법사무기");
	strcpy_s(tStoreWeaponWizard[1].strDesc, "정식마법사가 사용하는 스태프");
	tStoreWeaponWizard[1].iValue = 35;
	tStoreWeaponWizard[1].iPrice = 30000;
	tStoreWeaponWizard[1].iSell = 25000;
	tStoreWeaponWizard[1].iUserLevel = 5;
	tStoreWeaponWizard[1].eType = ITEM_TYPE(IT_WEAPON);

	// 드래곤스태프
	strcpy_s(tStoreWeaponWizard[2].strName, "드래곤스태프");
	strcpy_s(tStoreWeaponWizard[2].strTypeName, "마법사무기");
	strcpy_s(tStoreWeaponWizard[2].strDesc, "드래곤을 잡기위해 만들어진 스태프");
	tStoreWeaponWizard[2].iValue = 150;
	tStoreWeaponWizard[2].iPrice = 150000;
	tStoreWeaponWizard[2].iSell = 120000;
	tStoreWeaponWizard[2].iUserLevel = 10;
	tStoreWeaponWizard[2].eType = ITEM_TYPE(IT_WEAPON);
}

void SetArmorStore() {
	// 기본갑옷
	strcpy_s(tStoreArmor[0].strName, "기본갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	strcpy_s(tStoreArmor[0].strDesc, "수행기사가 사용하는 방어구");
	tStoreArmor[0].iValue = 5;
	tStoreArmor[0].iPrice = 500;
	tStoreArmor[0].iSell = 300;
	tStoreArmor[0].eType = ITEM_TYPE(IT_ARMOR);

	// 정식갑옷
	strcpy_s(tStoreArmor[1].strName, "정식갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	strcpy_s(tStoreArmor[1].strDesc, "정식기사가 사용하는 방어구");
	tStoreArmor[1].iValue = 25;
	tStoreArmor[1].iPrice = 20000;
	tStoreArmor[1].iSell = 15000;
	tStoreArmor[1].eType = ITEM_TYPE(IT_ARMOR);

	// 드래곤아머
	strcpy_s(tStoreArmor[2].strName, "드래곤아머");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	strcpy_s(tStoreArmor[2].strDesc, "용을 잡기위해 만들어진 방어구");
	tStoreArmor[2].iValue = 75;
	tStoreArmor[2].iPrice = 100000;
	tStoreArmor[2].iSell = 80000;
	tStoreArmor[2].eType = ITEM_TYPE(IT_ARMOR);
}
