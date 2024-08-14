#include <iostream>

using namespace std;

const int nameLen = 20;
const int maxCus = 100;

void ShowMenu();
void MakeAcc();		//계좌개설
void DepositsMoney();	//입금
void WithdrawalsMoney();	//출금
void ShowAccInfo();

enum {Make = 1, Deposits, Withdrawals, Show, Exit};

struct Account
{
	int accID;		//계좌 ID
	int balance;	//잔액
	char cusName[nameLen];	//고객 이름
};

Account account[maxCus];
int accNum = 0;

int main(void) {
	while (1) {
		int userInput = 0;
		ShowMenu();
		cin >> userInput;

		switch (userInput)
		{
		case Make:
			MakeAcc();
			break;
		case Deposits:
			DepositsMoney();
			break;
		case Withdrawals:
			WithdrawalsMoney();
			break;
		case Show:
			ShowAccInfo();
			break;
		case Exit:
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}

void ShowMenu() {
	cout << endl;
	cout << "-------------------Menu--------------------" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌 정보" << endl;
	cout << "5. 프로그램 종료" << endl << endl;
	cout << "선택: ";
}
void MakeAcc() {
	cout << endl;
	cout << "[계좌 개설]" << endl;
	cout << "계좌 ID: ";
	cin >> account[accNum].accID;
	cout << endl;
	cout << "이름: ";
	cin >> account[accNum].cusName;
	cout << endl;
	cout << "입금액: ";
	cin >> account[accNum].balance;

	accNum++;
}
void DepositsMoney() {
	int id = 0;
	int money = 0;

	cout << endl;
	cout << "[입금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	for (int i = 0; i <= accNum; i++) {
		if (account[i].accID == id) {
			cout << "입금액: ";
			cin >> money;
			account[i].balance += money;
			cout << "입금완료: " << endl;
			return;
		}
	}
	cout << "잘못된 계좌 ID 입니다." << endl;
}
void WithdrawalsMoney() {
	int id;
	int money;

	cout << endl;
	cout << "[출금]" << endl;
	cout << "계좌 ID: ";
	cin >> id;
	for (int i = 0; i <= accNum; i++) {
		if (account[i].accID == id) {
			cout << "출금액: ";
			cin >> money;
			account[i].balance -= money;
			cout << "출금완료: " << endl;
		}
	}
	cout << "잘못된 계좌 ID 입니다." << endl;
}
void ShowAccInfo() {
	cout << endl;
	cout << "[모든 계좌 정보]" << endl;
	for (int i = 0; i < accNum; i++) {
		cout << "계좌 ID: " << account[i].accID << endl;
		cout << "이름: " << account[i].cusName << endl;
		cout << "잔액: " << account[i].balance << endl << endl;
	}
}