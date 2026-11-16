#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
 
using namespace std;
 
class BankAccount
{
private:
    string accountNumber;
    string customerName;
    double currentBalance;
 
    int successfulDeposits;
    int successfulWithdrawals;
    int rejectedTransactions;
 
    bool isAccountCreated;
 
public:
    BankAccount()
    {
        accountNumber = "";
        customerName = "";
        currentBalance = 0.0;
 
        successfulDeposits = 0;
        successfulWithdrawals = 0;
        rejectedTransactions = 0;
 
        isAccountCreated = false;
    }
 
    bool hasAccount() const
    {
        return isAccountCreated;
    }
 
    void createAccount(const string &accNum,
                       const string &name,
                       double openingBalance)
    {
        if (isAccountCreated)
        {
            cout << "\n[Error] Account already exists.\n";
            return;
        }
 
        if (openingBalance < 0)
        {
            cout << "\n[Rejected] Opening balance cannot be negative.\n";
            rejectedTransactions++;
            return;
        }
 
        accountNumber = accNum;
        customerName = name;
        currentBalance = openingBalance;
 
        isAccountCreated = true;
 
        cout << "\n[Success] Account created successfully.\n";
        cout << "Welcome, " << customerName << "!\n";
        cout << "Opening Balance: ₹"
             << fixed << setprecision(2)
             << currentBalance << endl;
    }
 
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "\n[Rejected] Deposit amount must be greater than zero.\n";
            rejectedTransactions++;
            return;
        }
 
        currentBalance += amount;
        successfulDeposits++;
 
        cout << "\n[Success] Deposit completed.\n";
        cout << "Deposited Amount : ₹" << amount << endl;
        cout << "Current Balance  : ₹" << currentBalance << endl;
    }
 
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "\n[Rejected] Withdrawal amount must be greater than zero.\n";
            rejectedTransactions++;
            return;
        }
 
        if (amount > currentBalance)
        {
            cout << "\n[Rejected] Insufficient balance.\n";
            cout << "Available Balance : ₹" << currentBalance << endl;
 
            rejectedTransactions++;
            return;
        }
 
        currentBalance -= amount;
        successfulWithdrawals++;
 
        cout << "\n[Success] Withdrawal completed.\n";
        cout << "Withdrawn Amount : ₹" << amount << endl;
        cout << "Remaining Balance: ₹" << currentBalance << endl;
    }
 
    void checkBalance() const
    {
        cout << "\n-------- BALANCE ENQUIRY --------\n";
        cout << "Available Balance : ₹"
             << fixed << setprecision(2)
             << currentBalance << endl;
        cout << "---------------------------------\n";
    }
 
    void displayAccount() const
    {
        cout << "\n--------- ACCOUNT DETAILS ---------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Customer Name  : " << customerName << endl;
        cout << "Current Balance: ₹"
             << fixed << setprecision(2)
             << currentBalance << endl;
        cout << "-----------------------------------\n";
    }
 
    void displayTransactionSummary() const
    {
        cout << "\n------ TRANSACTION SUMMARY ------\n";
        cout << "Successful Deposits    : "
             << successfulDeposits << endl;
 
        cout << "Successful Withdrawals : "
             << successfulWithdrawals << endl;
 
        cout << "Rejected Transactions  : "
             << rejectedTransactions << endl;
 
        cout << "Final Balance          : ₹"
             << fixed << setprecision(2)
             << currentBalance << endl;
 
        cout << "---------------------------------\n";
    }
};
 
int main()
{
    BankAccount account;
    int choice;
 
    do
    {
        cout << "\n==========================================\n";
        cout << "   SECUREBANK ACCOUNT MANAGEMENT SYSTEM\n";
        cout << "==========================================\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Balance Enquiry\n";
        cout << "5. Display Account Details\n";
        cout << "6. Display Transaction Summary\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
 
        if (!(cin >> choice))
        {
            cout << "\n[Error] Invalid input. Enter a number between 1 and 7.\n";
 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
 
        switch (choice)
        {
        case 1:
        {
            string accNum;
            string name;
            double openingBalance;
 
            cout << "Enter Account Number: ";
            cin >> accNum;
 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
 
            cout << "Enter Customer Name: ";
            getline(cin, name);
 
            cout << "Enter Opening Balance: ₹";
 
            if (!(cin >> openingBalance))
            {
                cout << "\n[Error] Invalid balance input.\n";
 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
 
            account.createAccount(
                accNum,
                name,
                openingBalance);
 
            break;
        }
 
        case 2:
        {
            if (!account.hasAccount())
            {
                cout << "\n[Error] Please create an account first.\n";
                break;
            }
 
            double amount;
 
            cout << "Enter Deposit Amount: ₹";
 
            if (!(cin >> amount))
            {
                cout << "\n[Error] Invalid amount entered.\n";
 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
 
            account.deposit(amount);
            break;
        }
 
        case 3:
        {
            if (!account.hasAccount())
            {
                cout << "\n[Error] Please create an account first.\n";
                break;
            }
 
            double amount;
 
            cout << "Enter Withdrawal Amount: ₹";
 
            if (!(cin >> amount))
            {
                cout << "\n[Error] Invalid amount entered.\n";
 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
 
            account.withdraw(amount);
            break;
        }
 
        case 4:
        {
            if (!account.hasAccount())
            {
                cout << "\n[Error] Please create an account first.\n";
                break;
            }
 
            account.checkBalance();
            break;
        }
 
        case 5:
        {
            if (!account.hasAccount())
            {
                cout << "\n[Error] Please create an account first.\n";
                break;
            }
 
            account.displayAccount();
            break;
        }
 
        case 6:
        {
            if (!account.hasAccount())
            {
                cout << "\n[Error] Please create an account first.\n";
                break;
            }
 
            account.displayTransactionSummary();
            break;
        }
 
        case 7:
        {
            cout << "\nThank you for using SecureBank. Goodbye!\n";
            break;
        }
 
        default:
        {
            cout << "\n[Error] Invalid menu choice. Please select between 1 and 7.\n";
        }
        }
 
    } while (choice != 7);
 
    return 0;
}
