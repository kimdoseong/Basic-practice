#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

const int MAX_PERSON_NUMBER = 1000;
const int NAME_LEN = 20;
const int NORMALRATE = 3;
enum {
    MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};
enum {
    NORMAL = 1, CREDIT = 2
};
enum {
    A = 3, B = 2, C = 1
};

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

    virtual void Diposit(int balance) {
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

class NormalAccount : public Person {
private:
    int rate = NORMALRATE;
public:
    NormalAccount(int accountnumber, int balance, const char *name)
            : Person(accountnumber, balance, name) {}

    void Diposit(int balance) {
        Person::Diposit(balance);
        Person::Diposit(balance * (NORMALRATE / 100.0));
    }
};

class CreditAccount : public NormalAccount {
private:
    int Credit;
public:
    CreditAccount(int accountnumber, int balance, const char *name, int credit)
            : NormalAccount(accountnumber, balance, name), Credit(credit) {}

    void Diposit(int balance) {
        NormalAccount::Diposit(balance);
        Person::Diposit(balance * (Credit / 100.0));
    }
};


class AccountHandler {
private:
    Person *MaxP[MAX_PERSON_NUMBER];
    int PN;

public:
    AccountHandler();

    void ShowMenu(int *num);

    void MakeAccount(void);

    void DepositMoney(void);

    void WithdrawMoney(void);

    void ShowAllAccInfo(void) const;

    ~AccountHandler();

protected:
    void MakeNormalAccount(void);

    void MakeCreditAccount(void);
};

void AccountHandler::ShowMenu(int *num) {
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

void AccountHandler::MakeAccount() {
    int num;

    cout << "[계좌종류선택]" << endl;
    cout << "1.보통예금계좌 ";
    cout << "2.신용신뢰계좌" << endl;
    cout << "선택: ";
    cin >> num;
    cout << endl;

    if (num == NORMAL)
        MakeNormalAccount();
    else
        MakeCreditAccount();
    cout << endl << endl;
}

void AccountHandler::MakeNormalAccount() {
    int id, balance;
    char name[NAME_LEN];

    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌번호: : ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    cout << "이자율: " << NORMALRATE << endl << endl;

    MaxP[PN++] = new NormalAccount(id, balance, name);
}

void AccountHandler::MakeCreditAccount() {
    int id, balance;
    char name[NAME_LEN];
    int credit;
    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌번호: : ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    cout << "신용등급(1toA, 2toB, 3toC): ";
    cin >> credit;
    cout << endl;

    switch (credit) {
        case 1:
            MaxP[PN++] = new CreditAccount(id, balance, name, A);
            break;
        case 2:
            MaxP[PN++] = new CreditAccount(id, balance, name, B);
            break;
        case 3:
            MaxP[PN++] = new CreditAccount(id, balance, name, C);
            break;
    }
}


void AccountHandler::DepositMoney() {
    int id, balance;
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

void AccountHandler::WithdrawMoney() {
    int id, balance;
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

AccountHandler::AccountHandler() : PN(0) {}

void AccountHandler::ShowAllAccInfo(void) const {
    cout << "[계좌정보 전체 출력]" << endl;
    for (int i = 0; i < PN; i++) {
        MaxP[i]->Show();
    }
}

AccountHandler::~AccountHandler() {
    for (int i = 0; i < PN; i++)
        delete MaxP[i];
}

int main(void) {
    AccountHandler manager;
    int num = 0;

    while (1) {
        manager.ShowMenu(&num);

        switch (num) {
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.DepositMoney();
                break;
            case WITHDRAW:
                manager.WithdrawMoney();
                break;
            case INQUIRE:
                manager.ShowAllAccInfo();
                break;
            case EXIT:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
        }
    }
}
