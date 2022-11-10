#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
const int NAME_LEN = 20;
const int MAX_PERSON_NUMBER = 1000;

typedef struct {
    int AccountNumber;
    int Balance;
    char Name[NAME_LEN];

} Person;

void ShowMenu(int *num);

void MakeAccount(Person *MaxP, int *PN);

void DepositMoney(Person *MaxP, int *PN);

void WithdrawMoney(Person *MaxP, int *PN);

void ShowAllAccInfo(Person *MaxP, int *PN);

enum {
    MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
};

int main(void) {
    int num = 0, PN = 0;
    Person MaxP[MAX_PERSON_NUMBER];

    while (1) {
        ShowMenu(&num);

        switch (num) {
            case MAKE:
                MakeAccount(MaxP, &PN);
                break;
            case DEPOSIT:
                DepositMoney(MaxP, &PN);
                break;
            case WITHDRAW:
                WithdrawMoney(MaxP, &PN);
                break;
            case INQUIRE:
                ShowAllAccInfo(MaxP, &PN);
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

void MakeAccount(Person *MaxP, int *PN) {
    cout << "[계좌개설]" << endl;
    cout << "계좌번호: ";
    cin >> MaxP[*PN].AccountNumber;
    cout << "이 름: ";
    cin >> MaxP[*PN].Name;
    cout << "입금액: ";
    cin >> MaxP[*PN].Balance;
    (*PN)++;
    cout << endl << endl;
}

void DepositMoney(Person *MaxP, int *PN) {
    int id = 0, balance = 0;
    cout << "[입  금]" << endl;
    cout << "계좌번호: ";
    cin >> id;
    for (int i = 0; i < *PN; i++) {
        if (MaxP[i].AccountNumber == id) {
            cout << "입금액: ";
            cin >> balance;
            MaxP[i].Balance += balance;
            cout << "입금완료" << endl << endl;
        } else if (i + 1 == *PN)
            cout << "해당 계좌번호가 존재하지 않습니다." << endl << endl;
    }
}

void WithdrawMoney(Person *MaxP, int *PN) {
    int id = 0, balance = 0;
    cout << "[출  금]" << endl;
    cout << "계좌번호: ";
    cin >> id;

    for (int i = 0; i < *PN; i++) {
        if (MaxP[i].AccountNumber == id) {
            cout << "출금액: ";
            cin >> balance;
            if (MaxP[i].Balance < balance) {
                cout << "출금 금액이 부족합니다." << endl << endl;
                break;
            } else {
                MaxP[i].Balance -= balance;
                cout << "출금완료" << endl << endl;
                break;
            }
        } else if (i + 1 == *PN)
            cout << "해당 계좌번호가 존재하지 않습니다." << endl << endl;
    }
}

void ShowAllAccInfo(Person *MaxP, int *PN) {
    cout << "[계좌정보 전체 출력]" << endl;
    for (int i = 0; i < *PN; i++) {
        cout << "계좌번호: " << MaxP[i].AccountNumber << endl;
        cout << "이  름: " << MaxP[i].Name << endl;
        cout << "잔  액: " << MaxP[i].Balance << endl;
        cout << "-----------------" << endl << endl;
    }
}

