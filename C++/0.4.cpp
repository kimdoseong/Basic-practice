#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
const int MAX_PERSON_NUMBER = 1000;
const int NAME_LEN = 20;


void ShowMenu(int *num);

void MakeAccount(void);

void DepositMoney(void);

void WithdrawMoney(void);

void ShowAllAccInfo(void);

class Person {
private:
    int AccountNumber;
    int Balance;
    std::string Name;

public:
    Person(int accountnumber, int balance, const char *name)
            : AccountNumber(accountnumber), Balance(balance) {
        Name = name;
    }

    Person(const Person &copy)
            : AccountNumber(copy.AccountNumber), Balance(copy.Balance) {
        Name = copy.Name;
    }

    int GetAccountNumber() const {
        return AccountNumber;
    }

    void Diposit(int balance) {
        Balance += balance;
    }

    int WithDraw(int balance) {
        if (Balance < balance) {
            cout << "출금 금액이 부족합니다." << endl << endl;
            return -1;
        } else {
            Balance -= balance;
            cout << "출금완료" << endl << endl;
            return 0;
        }
    }

    void Show() const {
        cout << "계좌번호: " << AccountNumber << endl;
        cout << "이  름: " << Name << endl;
        cout << "잔  액: " << Balance << endl;
        cout << "-----------------" << endl << endl;
    }
};


enum {
    MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};
int PN = 0;
Person *MaxP[MAX_PERSON_NUMBER];

int main(void) {
    int num = 0;

    while (1) {
        ShowMenu(&num);

        switch (num) {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
        }
    }
}


void ShowMenu(int *num) {
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
    cout << "선택: ";
    cin >> *num;
    cout << endl << endl;
}

void MakeAccount() {
    int id;
    char name[NAME_LEN];
    int money;

    cout << "[계좌개설]" << endl;
    cout << "계좌번호: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> money;

    MaxP[PN++] = new Person(id, money, name);
    cout << endl << endl;
}

void DepositMoney() {
    int id;
    int balance;
    cout << "[입  금]" << endl;
    cout << "계좌번호: ";
    cin >> id;
    for (int i = 0; i < PN; i++) {
        if (MaxP[i]->GetAccountNumber() == id) {
            cout << "입금액: ";
            cin >> balance;
            MaxP[i]->Diposit(balance);
            cout << "입금완료" << endl << endl;
        } else if (i + 1 == PN)
            cout << "해당 계좌번호가 존재하지 않습니다." << endl << endl;
    }
}

void WithdrawMoney() {
    int id = 0, balance = 0;
    cout << "[출  금]" << endl;
    cout << "계좌번호: ";
    cin >> id;

    for (int i = 0; i < PN; i++) {
        if (MaxP[i]->GetAccountNumber() == id) {
            cout << "출금액: ";
            cin >> balance;
            MaxP[i]->WithDraw(balance);
        } else if (i + 1 == PN)
            cout << "해당 계좌번호가 존재하지 않습니다." << endl << endl;
    }
}


void ShowAllAccInfo(void) {
    cout << "[계좌정보 전체 출력]" << endl;
    for (int i = 0; i < PN; i++) {
        MaxP[i]->Show();
    }
}