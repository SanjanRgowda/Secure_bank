#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string customerName;
    double currentBalance;
    int successfulDeposits;
    int successfulWithdrawals;
    int rejectedTransactions;
    bool isAccountCreated;

public:
    // Constructor
    BankAccount() {
        currentBalance = 0.0;
        successfulDeposits = 0;
        successfulWithdrawals = 0;
        rejectedTransactions = 0;
        isAccountCreated = false;
    }

    // 1. Create Account
    void createAccount(string accNum, string name, double openingBalance) {
        if (openingBalance < 0.0) {
            cout << "\n[Error] Opening balance cannot be negative. Account creation rejected.\n";
            rejectedTransactions++;
            isAccountCreated = false;
            return;
        }
        
        accountNumber = accNum;
        customerName = name;
        currentBalance = openingBalance;
        successfulDeposits = 0;
        successfulWithdrawals = 0;
        rejectedTransactions = 0;
        isAccountCreated = true;
        
        cout << "\n[Success] Account created successfully for " << customerName << " with balance: ₹" << fixed << setprecision(2) << currentBalance << "\n";
    }

    // Check if account exists
    bool hasAccount() const {
        return isAccountCreated;
    }

    // 2. Deposit Money
    void deposit(double amount) {
        if (amount <= 0.0) {
            cout << "\n[Rejected] Invalid deposit amount. Amount must be greater than zero.\n";
            rejectedTransactions++;
            return;
        }

        currentBalance += amount;
        successfulDeposits++;
        cout << "\n[Success] Deposited ₹" << fixed << setprecision(2) << amount << ". New Balance: ₹" << currentBalance << "\n";
    }

    // 3. Withdraw Money
    void withdraw(double amount) {
        if (amount <= 0.0) {
            cout << "\n[Rejected] Invalid withdrawal amount. Amount must be greater than zero.\n";
            rejectedTransactions++;
            return;
        }

        if (amount > currentBalance) {
            cout << "\n[Rejected: Insufficient balance] Withdrawal amount exceeds available balance (₹" << fixed << setprecision(2) << currentBalance << ").\n";
            rejectedTransactions++;
            return;
        }

        currentBalance -= amount;
        successfulWithdrawals++;
        cout << "\n[Success] Withdrawn ₹" << fixed << setprecision(2) << amount << ". Remaining Balance: ₹" << currentBalance << "\n";
    }

    // 4. Balance Enquiry
    void checkBalance() const {
        cout << "\n----------------------------------------\n";
        cout << "Current Available Balance: ₹" << fixed << setprecision(2) << currentBalance << "\n";
        cout << "----------------------------------------\n";
    }

    // 5. Display Account Details
    void displayAccount() const {
        cout << "\n========== ACCOUNT DETAILS ==========\n";
        cout << "Account Number  : " << accountNumber << "\n";
        cout << "Customer Name   : " << customerName << "\n";
        cout << "Current Balance : ₹" << fixed << setprecision(2) << currentBalance << "\n";
        cout << "=====================================\n";
    }

    // 6. Display Transaction Summary
    void displayTransactionSummary() const {
        cout << "\n========== TRANSACTION SUMMARY ==========\n";
        cout << "Successful Deposits     : " << successfulDeposits << "\n";
        cout << "Successful Withdrawals  : " << successfulWithdrawals << "\n";
        cout << "Rejected Transactions   : " << rejectedTransactions << "\n";
        cout << "Final Balance           : ₹" << fixed << setprecision(2) << currentBalance << "\n";
        cout << "=========================================\n";
    }
};

int main() {
    BankAccount account;
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "    SECUREBANK ACCOUNT MANAGEMENT       \n";
        cout << "========================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Balance Enquiry\n";
        cout << "5. Display Account Details\n";
        cout << "6. Display Transaction Summary\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        
        if (!(cin >> choice)) {
            cout << "\n[Error] Invalid input. Please enter a number between 1 and 7.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                string accNum, name;
                double openingBalance;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Customer Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Opening Balance: ₹";
                cin >> openingBalance;
                
                account.createAccount(accNum, name, openingBalance);
                break;
            }
            case 2: {
                if (!account.hasAccount()) {
                    cout << "\n[Error] No account found. Please create an account first.\n";
                    break;
                }
                double amount;
                cout << "Enter amount to deposit: ₹";
                cin >> amount;
                account.deposit(amount);
                break;
            }
            case 3: {
                if (!account.hasAccount()) {
                    cout << "\n[Error] No account found. Please create an account first.\n";
                    break;
                }
                double amount;
                cout << "Enter amount to withdraw: ₹";
                cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 4: {
                if (!account.hasAccount()) {
                    cout << "\n[Error] No account found. Please create an account first.\n";
                    break;
                }
                account.checkBalance();
                break;
            }
            case 5: {
                if (!account.hasAccount()) {
                    cout << "\n[Error] No account found. Please create an account first.\n";
                    break;
                }
                account.displayAccount();
                break;
            }
            case 6: {
                if (!account.hasAccount()) {
                    cout << "\n[Error] No account found. Please create an account first.\n";
                    break;
                }
                account.displayTransactionSummary();
                break;
            }
            case 7:
                cout << "\nThank you for using SecureBank. Goodbye!\n";
                break;
            default:
                cout << "\n[Error] Invalid menu choice. Please select between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}
