#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    float amount;

    Transaction(string t, float a) : type(t), amount(a) {}
};

class Account {
private:
    int accountNumber;
    string cardPIN;
    float balance;
    vector<Transaction> transactions;

public:
    Account(int accNum, string pin, float bal) : accountNumber(accNum), cardPIN(pin), balance(bal) {}

    void deposit(float amount) {
        balance += amount;
        transactions.emplace_back("Deposit", amount);
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            transactions.emplace_back("Withdrawal", amount);
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void transfer(Account &toAccount, float amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            toAccount.balance += amount;
            transactions.emplace_back("Transfer to Account " + to_string(toAccount.accountNumber), amount);
            toAccount.transactions.emplace_back("Transfer from Account " + to_string(accountNumber), amount);
            cout << "Transferred: " << amount << " to Account " << toAccount.accountNumber << endl;
        }
    }

    void displayMiniStatement() const {
        cout << "Mini Statement for Account " << accountNumber << ":" << endl;
        for (const auto &transaction : transactions) {
            cout << transaction.type << ": " << transaction.amount << endl;
        }
    }

    float getBalance() const {
        return balance;
    }

    string getCardPIN() const {
        return cardPIN;
    }
};

int main() {
    Account account1(123456, "1234", 1000.0);
    Account account2(654321, "4321", 500.0);

    account1.deposit(200);
    account1.withdraw(150);
    account1.transfer(account2, 300);
    account1.displayMiniStatement();

    cout << "Balance of Account 1: " << account1.getBalance() << endl;
    cout << "Balance of Account 2: " << account2.getBalance() << endl;

    cout << "Card PIN of Account 1: " << account1.getCardPIN() << endl;

    return 0;
}
