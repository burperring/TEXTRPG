#include <time.h>
#include "Main.h"

using namespace std;

_tagPlayer SetPlayerData(_tagPlayer tPlayer) {
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "원하는 직업을 선택하세요 : ";
		cin >> iJob;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 0;
	tPlayer.tInventory.iTemCount = 0;

	switch (tPlayer.eJob){
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttack = 15;
		tPlayer.iArmor = 15;
		tPlayer.iHP = 500;
		tPlayer.iHPMax = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttack = 20;
		tPlayer.iArmor = 10;
		tPlayer.iHP = 400;
		tPlayer.iHPMax = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttack = 25;
		tPlayer.iArmor = 5;
		tPlayer.iHP = 300;
		tPlayer.iHPMax = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	}

	return tPlayer;
}

_tagPlayer SelectMap(_tagPlayer tPlayer) {
	int iMenu;

	while (true) {
		system("cls");

		cout << "******************** 맵 ********************" << endl;
		cout << "1. 쉬움" << endl;
		cout << "2. 보통" << endl;
		cout << "3. 어려움" << endl;
		cout << "4. 뒤로가기" << endl;
		cout << "맵을 선택하세요 : ";
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MT_BACK)
			return tPlayer;

		_tagMonster tMonster = tMonsterArr[iMenu - 1];

		while (true) {
			system("cls");

			switch (iMenu) {
			case MT_EASY:
				cout << "******************** 쉬움 ********************" << endl;
				break;
			case MT_NOMAL:
				cout << "******************** 보통 ********************" << endl;
				break;
			case MT_HARD:
				cout << "******************** 어려움 ********************" << endl;
				break;
			}

			// 플레이어 정보 출력
			cout << "==================== Player ====================" << endl;
			cout << "이름 : " << tPlayer.strName << "\t\t직업 : "
				<< tPlayer.strJobName << endl;
			cout << "레벨 : " << tPlayer.iLevel << "\t\t경험치 : "
				<< tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

			// 공격력 표시 (무기를 착용할 경우 해당 정보도 표기)
			if (tPlayer.bEquip[EQ_WEAPON] == true) {
				cout << "공격력 : " << tPlayer.iAttack << "+" << tPlayer.tEquip[EQ_WEAPON].iValue;
			}
			else {
				cout << "공격력 : " << tPlayer.iAttack;
			}

			// 방어력 표기 (방어구를 착용할 경우 해당 정보도 표기)
			if (tPlayer.bEquip[EQ_ARMOR] == true) {
				cout << "\t방어력 : " << tPlayer.iArmor << "+" << tPlayer.tEquip[EQ_ARMOR].iValue << endl;
			}
			else {
				cout << "\t방어력 : " << tPlayer.iArmor << endl;
			}

			// 남은 정보 표기
			cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax
				<< "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMP << endl;

			if (tPlayer.bEquip[EQ_WEAPON])
				cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
			else
				cout << "장착무기 : 없음";

			if (tPlayer.bEquip[EQ_ARMOR])
				cout << "\t\t장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
			else
				cout << "\t\t장착방어구 : 없음" << endl;

			cout << "보유골드 : " << tPlayer.tInventory.iGold << "Gold" << endl << endl;

			// 몬스터 정보 출력
			cout << "==================== Monster ====================" << endl;
			cout << "이름 : " << tMonster.strName << "\t\t레벨 : "
				<< tMonster.iLevel << endl;
			cout << "공격력 : " << tMonster.iAttack << "\t\t방어력 : "
				<< tMonster.iArmor << endl;
			cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax
				<< "\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
			cout << "획득경험치 : " << tMonster.iGetExp << "\t획득골드 : "
				<< tMonster.iGetGoldMin << " ~ " << tMonster.iGetGoldMax << endl << endl;

			cout << "1. 공격" << endl;
			cout << "2. 도망가기" << endl;
			cout << "메뉴를 선택하세요 : ";
			cin >> iMenu;

			if (cin.fail()){
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}

			if (iMenu == BATTLE_BACK)
				break;

			switch (iMenu)
			{
			case BATTLE_ATTACK:
				// 데미지 체크
				int iDamage = tPlayer.iAttack - tMonster.iArmor;
				iDamage = iDamage < 1 ? 1 : iDamage;

				tMonster.iHP -= iDamage;

				cout << tPlayer.strName << "가 " << tMonster.strName << "에게 "
					<< iDamage << "만큼 피해를 입혔습니다." << endl;

				// 몬스터 사망 체크
				if (tMonster.iHP <= 0) {
					cout << tMonster.strName << "가 사망했습니다." << endl;

					tPlayer.iExp += tMonster.iGetExp;
					int iGold = rand() % (tMonster.iGetGoldMax - tMonster.iGetGoldMin + 1)
						+ tMonster.iGetGoldMin;
					tPlayer.tInventory.iGold += iGold;

					cout << tMonster.iGetExp << "경험치를 획득했습니다." << endl;
					cout << iGold << "Gold를 획득했습니다." << endl;

					tMonster.iHP = tMonster.iHPMax;
					tMonster.iMP = tMonster.iMPMax;

					// 플레이어 레벨업 체크
					if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1]) {
						// 경험치 차감 및 레벨업 진행
						tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];
						tPlayer.iLevel++;

						// 능력치 상승
						int iJobIndex = tPlayer.eJob - 1;
						tPlayer.iAttack += tLvUpTable[iJobIndex].iAttack;
						tPlayer.iArmor += tLvUpTable[iJobIndex].iArmor;
						tPlayer.iHPMax += tLvUpTable[iJobIndex].iHP;
						tPlayer.iHP = tPlayer.iHPMax;
						tPlayer.iMPMax += tLvUpTable[iJobIndex].iMP;
						tPlayer.iMP = tPlayer.iMPMax;
					}

					system("pause");
					break;
				}

				// 몬스터가 살아있다면 플레이어를 공격한다.
				iDamage = tMonster.iAttack - tPlayer.iArmor;
				iDamage = iDamage < 1 ? 1 : iDamage;

				// 플레이어 HP 감소
				tPlayer.iHP -= iDamage;
				cout << tMonster.strName << "가 " << tPlayer.strName << "에게 "
					<< iDamage << "만큼 피해릴 입혔습니다." << endl;

				// 플레이어 사망 체크
				if (tPlayer.iHP <= 0) {
					cout << tPlayer.strName << "플레이어가 사망했습니다." << endl;

					int iExp = tPlayer.iExp * .1f;
					int iGold = tPlayer.tInventory.iGold * .1f;

					tPlayer.iExp -= iExp;
					tPlayer.tInventory.iGold -= iGold;

					cout << iExp << "경험치를 잃었습니다." << endl;
					cout << iGold << "Gold를 잃었습니다." << endl;

					tPlayer.iHP = tPlayer.iHPMax;
					tPlayer.iMP = tPlayer.iMPMax;
				}

				system("pause");

				break;
			}

		}
	}

	return tPlayer;
}

_tagPlayer SelectStore(_tagPlayer tPlayer) {
	int iMenu;

	while (true) {
		system("cls");
		cout << "******************** 상점 ********************" << endl;
		cout << "1. 무기상점" << endl;
		cout << "2. 방어구상점" << endl;
		cout << "3. 뒤로가기" << endl;
		cout << "상점을 선택하세요 : ";
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == SM_BACK)
			return tPlayer;

		switch (iMenu) {
		case SM_WEAPON:
			while (true) {
				// 판매목록 보여주기
				system("cls");
				cout << "******************** 무기상점 ********************" << endl;
				if (tPlayer.eJob == JOB_KNIGHT) {
					for (int i = 0; i < STORE_WEAPON_MAX; i++) {
						cout << i + 1 << ". 이름 : " << tStoreWeaponKnight[i].strName
							<< "\t종류 : " << tStoreWeaponKnight[i].strTypeName << endl;
						cout << "착용레벨 : " << tStoreWeaponKnight[i].iUserLevel << endl;
						cout << "공격력 : " << tStoreWeaponKnight[i].iValue << endl;
						cout << "구매가격 : " << tStoreWeaponKnight[i].iPrice
							<< "\t판매가격 : " << tStoreWeaponKnight[i].iSell << endl;
						cout << "설명 : " << tStoreWeaponKnight[i].strDesc << endl << endl;
					}
				}
				else if (tPlayer.eJob == JOB_ARCHER) {
					for (int i = 0; i < STORE_WEAPON_MAX; i++) {
						cout << i + 1 << ". 이름 : " << tStoreWeaponArcher[i].strName
							<< "\t종류 : " << tStoreWeaponArcher[i].strTypeName << endl;
						cout << "착용레벨 : " << tStoreWeaponArcher[i].iUserLevel << endl;
						cout << "공격력 : " << tStoreWeaponArcher[i].iValue << endl;
						cout << "구매가격 : " << tStoreWeaponArcher[i].iPrice
							<< "\t판매가격 : " << tStoreWeaponArcher[i].iSell << endl;
						cout << "설명 : " << tStoreWeaponArcher[i].strDesc << endl << endl;
					}
				}
				else if (tPlayer.eJob == JOB_WIZARD) {
					for (int i = 0; i < STORE_WEAPON_MAX; i++) {
						cout << i + 1 << ". 이름 : " << tStoreWeaponWizard[i].strName
							<< "\t종류 : " << tStoreWeaponWizard[i].strTypeName << endl;
						cout << "착용레벨 : " << tStoreWeaponWizard[i].iUserLevel << endl;
						cout << "공격력 : " << tStoreWeaponWizard[i].iValue << endl;
						cout << "구매가격 : " << tStoreWeaponWizard[i].iPrice
							<< "\t판매가격 : " << tStoreWeaponWizard[i].iSell << endl;
						cout << "설명 : " << tStoreWeaponWizard[i].strDesc << endl << endl;
					}
				}

				cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl << endl;
				cout << "보유금액 : " << tPlayer.tInventory.iGold << "Gold" << endl;
				cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iTemCount << endl;
				cout << "구입할 아이템을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == STORE_WEAPON_MAX + 1)
					break;
				else if (iMenu > STORE_WEAPON_MAX + 1 || iMenu < 1) {
					cout << "잘못된 입력입니다." << endl;
					system("pause");
					continue;
				}

				int iWeaponIndex = iMenu - 1;

				// 인벤토리가 꽉 찼는지 검사
				if (tPlayer.tInventory.iTemCount == INVENTORY_MAX) {
					cout << "가방이 가득 찼습니다." << endl;
					system("pause");
					continue;
				}
				// 돈이 부족한 경우
				else if (tPlayer.tInventory.iGold < tStoreWeaponKnight[iWeaponIndex].iPrice ||
					tPlayer.tInventory.iGold < tStoreWeaponArcher[iWeaponIndex].iPrice ||
					tPlayer.tInventory.iGold < tStoreWeaponWizard[iWeaponIndex].iPrice) {
					cout << "보유금액이 부족합니다." << endl;
					system("pause");
					continue;
				}

				// 인벤토리에 무기 추가하기
				if (tPlayer.eJob == JOB_KNIGHT)
					tPlayer.tInventory.tItem[tPlayer.tInventory.iTemCount]
					= tStoreWeaponKnight[iWeaponIndex];
				else if (tPlayer.eJob == JOB_ARCHER)
					tPlayer.tInventory.tItem[tPlayer.tInventory.iTemCount]
					= tStoreWeaponArcher[iWeaponIndex];
				else if (tPlayer.eJob == JOB_WIZARD)
					tPlayer.tInventory.tItem[tPlayer.tInventory.iTemCount]
					= tStoreWeaponWizard[iWeaponIndex];

				tPlayer.tInventory.iTemCount++;

				// 골드 차감
				if (tPlayer.eJob == JOB_KNIGHT) {
					tPlayer.tInventory.iGold -= tStoreWeaponKnight[iWeaponIndex].iPrice;
					cout << tStoreWeaponKnight[iWeaponIndex].strName
						<< "아이템을 구매했습니다." << endl;
					system("pause");
				}
				else if (tPlayer.eJob == JOB_ARCHER) {
					tPlayer.tInventory.iGold -= tStoreWeaponArcher[iWeaponIndex].iPrice;
					cout << tStoreWeaponArcher[iWeaponIndex].strName
						<< "아이템을 구매했습니다." << endl;
					system("pause");
				}
				else if (tPlayer.eJob == JOB_WIZARD) {
					tPlayer.tInventory.iGold -= tStoreWeaponWizard[iWeaponIndex].iPrice;
					cout << tStoreWeaponWizard[iWeaponIndex].strName
						<< "아이템을 구매했습니다." << endl;
					system("pause");
				}
			}
			break;
		case SM_ARMOR:
			while (true) {
				system("cls");
				cout << "******************** 방어구상점 ********************" << endl;
				for (int i = 0; i < STORE_ARMOR_MAX; i++) {
					cout << i + 1 << ". 이름 : " << tStoreArmor[i].strName
						<< "\t종류 : " << tStoreArmor[i].strTypeName << endl;
					cout << "착용레벨 : " << tStoreArmor[i].iUserLevel << endl;
					cout << "방어력 : " << tStoreArmor[i].iValue << endl;
					cout << "구매가격 : " << tStoreArmor[i].iPrice
						<< "\t판매가격 : " << tStoreArmor[i].iSell << endl << endl;
				}

				cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl << endl;
				cout << "보유금액 : " << tPlayer.tInventory.iGold << endl;
				cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iTemCount << endl;
				cout << "구입할 아이템을 선택하세요 : ";
				cin >> iMenu;

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == STORE_ARMOR_MAX + 1)
					break;
				else if (iMenu > STORE_ARMOR_MAX + 1 || iMenu < 1) {
					cout << "잘못된 입력입니다." << endl;
					system("pause");
					continue;
				}

				int iArmorIndex = iMenu - 1;

				// 인벤토리 남은 공간 검사
				if (tPlayer.tInventory.iTemCount == INVENTORY_MAX) {
					cout << "가방이 가득 찼습니다." << endl;
					system("pause");
					continue;
				}
				else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice) {
					cout << "보유금액이 부족합니다." << endl;
					system("pause");
					continue;
				}

				tPlayer.tInventory.tItem[tPlayer.tInventory.iTemCount]
					= tStoreArmor[iArmorIndex];

				tPlayer.tInventory.iTemCount++;

				tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;
				cout << tStoreArmor[iArmorIndex].strName << " 아이템을 구매하였습니다." << endl;
				system("pause");
			}
			break;
		}
	}

	return tPlayer;
}

_tagPlayer SelectInventory(_tagPlayer tPlayer) {
	int iMenu;

	while (true) {
		system("cls");
		cout << "******************** 가방 ********************" << endl;
		cout << "=================== Player ===================" << endl;
		
		cout << "이름 : " << tPlayer.strName << "\t\t직업 : "
			<< tPlayer.strJobName << endl;
		cout << "레벨 : " << tPlayer.iLevel << "\t\t경험치 : "
			<< tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

		// 무기를 장착하고 있을 경우
		if (tPlayer.bEquip[EQ_WEAPON] == true) {
			cout << "공격력 : " << tPlayer.iAttack << "+" << tPlayer.tEquip[EQ_WEAPON].iValue;
		}
		else {
			cout << "공격력 : " << tPlayer.iAttack;
		}

		// 방어구를 장착하고 있을 경우
		if (tPlayer.bEquip[EQ_ARMOR] == true) {
			cout << "\t방어력 : " << tPlayer.iArmor << "+" << tPlayer.tEquip[EQ_ARMOR].iValue << endl;
		}
		else {
			cout << "\t방어력 : " << tPlayer.iArmor << endl;
		}

		cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax
			<< "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

		if (tPlayer.bEquip[EQ_WEAPON])
			cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
		else
			cout << "장착무기 : 없음";

		if (tPlayer.bEquip[EQ_ARMOR])
			cout << "\t\t장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
		else
			cout << "\t\t장착방어구 : 없음" << endl;

		cout << "보유골드 : " << tPlayer.tInventory.iGold << "Gold" << endl;
		cout << "==============================================" << endl << endl;

		// 인벤토리 아이템 목록
		for (int i = 0; i < tPlayer.tInventory.iTemCount; i++) {
			cout << i + 1 << ". 이름 : " << tPlayer.tInventory.tItem[i].strName
				<< "\t종류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;

			if (tPlayer.tInventory.tItem[i].eType == IT_WEAPON) {
				cout << "공격력 : " << tPlayer.tInventory.tItem[i].iValue << endl;
			}
			else if (tPlayer.tInventory.tItem[i].eType == IT_ARMOR) {
				cout << "방어력 : " << tPlayer.tInventory.tItem[i].iValue << endl;
			}
			cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
		}

		cout << tPlayer.tInventory.iTemCount + 1 << ". 뒤로가기" << endl;
		cout << "장착할 아이템을 선택하세요 : ";
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == tPlayer.tInventory.iTemCount + 1)
			return tPlayer;
		else if (iMenu < 1 || iMenu > tPlayer.tInventory.iTemCount + 1) {
			cout << "잘못된 입력입니다." << endl;
			system("pause");
			continue;
		}

		// 장착할 아이템 정보 확인
		int iItemIdx = iMenu - 1;
		EQUIP eq;

		switch (tPlayer.tInventory.tItem[iItemIdx].eType) {
		case IT_WEAPON:
			eq = EQ_WEAPON;
			break;
		case IT_ARMOR:
			eq = EQ_ARMOR;
			break;
		}

		// 아이템이 장착되어 있는 경우 장착된 아이템과 교환해줘야 한다.
		if (tPlayer.bEquip[eq] == true) {
			_tagItem tSwap = tPlayer.tEquip[eq];
			tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[iItemIdx];
			tPlayer.tInventory.tItem[iItemIdx] = tSwap;
		}
		// 아이템이 장착되어 있지 않을 경우 아이템을 장착하고 인벤토리 1칸을 비워준다.
		// 배열을 밀어내는 작업이 필요
		else {
			tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[iItemIdx];

			for (int i = iItemIdx; i < tPlayer.tInventory.iTemCount - 1; i++) {
				tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
			}
			tPlayer.tInventory.iTemCount--;

			// 장착했기 때문에 true로 변환
			tPlayer.bEquip[eq] = true;
		}

		cout << tPlayer.tEquip[eq].strName << "아이템을 장착했습니다." << endl;
		system("pause");
	}
}

int main() {
	srand((unsigned int)time(0));

	// Set Player Level Up Table
	SetLvTable();

	// Set Player
	_tagPlayer tPlayer = {};
	tPlayer = SetPlayerData(tPlayer);

	// Set Monster
	SetMonsterTable();

	// Set Weapon
	SetKnightWeaponStore();
	SetArcherWeaponStore();
	SetWizardWeaponStore();
	SetArmorStore();

	while (true) {
		system("cls");

		cout << "******************** 로비 ********************" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_MAP:
			tPlayer = SelectMap(tPlayer);
			break;
		case MM_STORE:
			tPlayer = SelectStore(tPlayer);
			break;
		case MM_INVENTORY:
			tPlayer = SelectInventory(tPlayer);
			break;
		default:
			cout << "잘못된 선택입니다." << endl;
			break;
		}
	}
}
