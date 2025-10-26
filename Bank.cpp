#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    vector<long long> bal;
    int n;

    bool valid(int acc) {
        return acc > 0 && acc <= n;
    }

public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }

    bool transfer(int from, int to, long long amt) {
        if (!valid(from) || !valid(to) || bal[from - 1] < amt) return false;
        bal[from - 1] -= amt;
        bal[to - 1] += amt;
        return true;
    }

    bool deposit(int acc, long long amt) {
        if (!valid(acc)) return false;
        bal[acc - 1] += amt;
        return true;
    }

    bool withdraw(int acc, long long amt) {
        if (!valid(acc) || bal[acc - 1] < amt) return false;
        bal[acc - 1] -= amt;
        return true;
    }

    void printBalances() {
        cout << "Account balances: ";
        for (long long b : bal) {
            cout << b << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<long long> initialBalances = {1000, 2000, 3000, 4000, 5000};
    Bank bank(initialBalances);

    bank.printBalances();

    cout << "Transfer 500 from account 1 to account 3: ";
    cout << (bank.transfer(1, 3, 500) ? "Success" : "Failed") << endl;
    bank.printBalances();

    cout << "Deposit 1000 to account 2: ";
    cout << (bank.deposit(2, 1000) ? "Success" : "Failed") << endl;
    bank.printBalances();

    cout << "Withdraw 2000 from account 5: ";
    cout << (bank.withdraw(5, 2000) ? "Success" : "Failed") << endl;
    bank.printBalances();

    cout << "Attempt to withdraw 10000 from account 4: ";
    cout << (bank.withdraw(4, 10000) ? "Success" : "Failed") << endl;
    bank.printBalances();

    return 0;
}
