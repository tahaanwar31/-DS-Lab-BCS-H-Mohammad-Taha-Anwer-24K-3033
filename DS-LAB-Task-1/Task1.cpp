#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int* balance;
public:
    BankAccount() {
        balance = new int(0);
    }

    BankAccount(int balanceP) {
        balance = new int(balanceP);
    }

    BankAccount(const BankAccount& a) {
        balance = new int(*a.balance);
    }

    ~BankAccount() {
        delete balance;
    }

    void printbalance() {
        cout << "Balance: $" << *balance << endl;
    }

    void modifybalance(int balanceP) {
        *balance = *balance + balanceP;
    }
};

int main() {
    BankAccount account1;
    account1.printbalance();

    BankAccount account2(1000);
    account2.printbalance();

    BankAccount account3(account2);
    account3.modifybalance(-200);
    account3.printbalance();

    account2.printbalance();
}
