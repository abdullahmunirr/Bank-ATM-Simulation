#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Account
{
private:
    double balance = 0.0;
    string history;
    const double withdrawLimit = 1000;
    double withdrawTotal = 0;
    string accountType;
    
public:
    Account() : balance(0.0), history(""), withdrawTotal(0.0), accountType("Savings") {}
    
    double getBalance() const
    {
        return balance;
    }
    
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount" << endl;
            return;
        }
        
        balance += amount;
        history += "Deposited: $" + to_string(amount) + "\n";
        cout << "Deposited $" << amount << " successfully" << endl;
    }
    
    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount" << endl;
            return;
        }
        
        if (amount > balance)
        {
            cout << "Insufficient balance" << endl;
            return;
        }
        
        if (withdrawTotal + amount > withdrawLimit)
        {
            cout << "Daily withdrawal limit exceeded" << endl;
            return;
        }
        
        balance -= amount;
        withdrawTotal += amount;
        history += "Withdrew: $" + to_string(amount) + "\n";
        cout << "Withdrew $" << amount << " successfully" << endl;
    }
    
    string getHistory() const
    {
        if(history.empty())
        {
            cout << "No transaction History" << endl;
        }
        return history;
    }
    
    void resetWithdrawLimit()
    {
        withdrawTotal = 0.0;
    }
    
    string getAccountType() const
    {
        return accountType;
    }
    
    void setAccountType(const string& type)
    {
        accountType = type;
    }
    
    bool notifyWithdrawLimit() const
    {
        return withdrawTotal >= withdrawLimit * 0.8;
    }
    
    void exportTransactionHistory(const string& filename) const
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "Transaction History:" << endl;
            file << history;
            file.close();
            
            cout << "Transaction history exported to " << filename << endl;
        }
        
        else
        {
            cout << "Error exporting transaction history" << endl;
        }
    }
};

class User
{
private:
    string number;
    string pin;
    int failedAttempts = 0;
    bool locked;
    
    Account account;
    
public:
    User(string accNum, string pinCode, string accType)
    : number(accNum), pin(pinCode), failedAttempts(0), locked(false)
    {
        account.setAccountType(accType);
    }

    string getAccountNumber()
    {
        return number;
    }
    
    bool authenticate(const string& enteredPin)
    {
        if (locked)
        {
            cout << "Account is locked due to multiple failed attempts" << endl;
            return false;
        }
        
        if (pin == enteredPin)
        {
            failedAttempts = 0;
            return true;
        }
        
        failedAttempts++;
        if (failedAttempts >= 3)
        {
            locked = true;
            cout << "Account locked due to three consecutive failed attempts" << endl;
        }
        
        else
        {
            cout << "Incorrect PIN, " << (3 - failedAttempts) << " attempts remaining" << endl;
        }
        
        return false;
    }

    void changePin(const string& newPin)
    {
        pin = newPin;
        cout << "PIN changed successfully" << endl;
    }
    
    Account& getAccount()
    {
        return account;
    }
};

class ATM
{
private:
    User* currentUser;
    
    void displayMenu()
    {
        int choice;
        do
        {
            cout << endl << "--- ATM Menu ---" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. View Transaction History" << endl;
            cout << "5. Change PIN" << endl;
            cout << "6. Export Transaction History" << endl;
            cout << "7. Exit" << endl;
            
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch (choice)
            {
                case 1:
                {
                    cout << "Balance: $" << currentUser->getAccount().getBalance() << endl;
                    break;
                }
                    
                case 2:
                {
                    double amount;
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    currentUser->getAccount().deposit(amount);
                    break;
                }
                    
                case 3:
                {
                    double amount;
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    currentUser->getAccount().withdraw(amount);
                    if (currentUser->getAccount().notifyWithdrawLimit())
                    {
                        cout << "You are nearing your daily withdrawal limit" << endl;
                    }
                    break;
                }
                    
                case 4:
                {
                    cout << "Transaction History:" << endl;
                    cout << currentUser->getAccount().getHistory();
                    break;
                }
                    
                case 5:
                {
                    string newPin;
                    cout << "Enter new PIN: ";
                    cin >> newPin;
                    currentUser->changePin(newPin);
                    break;
                }
                    
                case 6:
                {
                    string filename;
                    cout << "Enter filename to export transaction history: ";
                    cin >> filename;
                    currentUser->getAccount().exportTransactionHistory(filename);
                    break;
                }
                    
                case 7:
                    cout << "Thank you for using the ATM.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 7);
    }
    
public:
    ATM() : currentUser(nullptr) {}
    
    void run()
    {
        cout << "Welcome to the ATM System" << endl;
        
        User user1("12345", "1111", "Savings");
        User user2("67890", "2222", "Checking");
        
        User users[] = { user1, user2 };
        
        string enteredAccountNumber, enteredPin;
        
        cout << "Enter your account number: ";
        cin >> enteredAccountNumber;
        
        cout << "Enter your PIN: ";
        cin >> enteredPin;
        
        for (int i = 0; i < 2; ++i)
        {
            if (users[i].getAccountNumber() == enteredAccountNumber && users[i].authenticate(enteredPin))
            {
                currentUser = &users[i];
                break;
            }
        }
        
        if (currentUser)
        {
            cout << "Login successful. Account type: " << currentUser->getAccount().getAccountType() << endl;
            displayMenu();
        }
        
        else
        {
            cout << "Invalid account number or PIN" << endl;
        }
    }
};

int main()
{
    ATM atm;
    atm.run();
    return 0;
}
