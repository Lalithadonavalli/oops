1. Find Whether a Number is Even or Odd
#include <iostream>
using namespace std;
int main() {
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (number % 2 == 0) {
        cout << number << " is an even number." << endl;
    } else {
        cout << number << " is an odd number." << endl;
    }
    return 0;
}

2. Sum of Digits of a Number
#include <iostream>
using namespace std;
int main() {
    int number, sum = 0;
    cout << "Enter a number: ";
    cin >> number;
    while (number != 0) {
        sum += number % 10; 
        number /= 10;       
    }
    cout << "Sum of digits: " << sum << endl;
    return 0;
}

3. Check if a Number is Palindrome
#include <iostream>
using namespace std;
int main() {
    int number, reversed = 0, original, digit;
    cout << "Enter a number: ";
    cin >> number;
    original = number; 
    while (number != 0) {
        digit = number % 10;           
        reversed = reversed * 10 + digit; 
        number /= 10;                
    }
    if (original == reversed) {
        cout << original << " is a palindrome." << endl;
    } else {
        cout << original << " is not a palindrome." << endl;
    }

    return 0;
}

4. Find the Largest Element in an Array
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    cout << "The largest element is: " << largest << endl;

    return 0;
}

5. Calculate the Factorial of a Number
#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "The factorial of " << num << " is " << factorial(num) << endl;
    }

    return 0;
}

6. A Simple Bank Account Class
Create a class BankAccount that represents a bank account.
The class should have:
• Private data members: accountNumber, balance.
• Public methods:
• deposit(double amount) to deposit money into the
account.
• withdraw(double amount) to withdraw money from the
account.
• display() to display the account details
(accountNumber and balance).
#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor to initialize account number and balance
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance > 0 ? initialBalance : 0.0;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << fixed << setprecision(2) << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    // Method to display account details
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    // Create a bank account object
    BankAccount account("123456789", 1000.0);

    // Display initial account details
    account.display();

    // Perform deposit and withdrawal
    account.deposit(500.0);
    account.withdraw(300.0);
    account.withdraw(1500.0); // Attempt to overdraw

    // Display final account details
    account.display();

    return 0;
}

7. Extending the BankAccount Class for Different Account Types
Now, extend the previous BankAccount class to handle
different types of bank accounts:
1. Savings Account (inherits from BankAccount) with an
interest rate.
2. Checking Account (inherits from BankAccount) with a fee
for withdrawals.
The base class BankAccount should still provide basic
functionality, but now we want to add additional features to
the derived classes:
• SavingsAccount: Automatically apply interest every
month.
• CheckingAccount: Apply a withdrawal fee each time a
withdrawal is made.
  #include <iostream>
#include <iomanip>
using namespace std;

// Base class
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance)
        : accountNumber(accNum), balance(max(0.0, initialBalance)) {}

    virtual void deposit(double amount) { balance += max(0.0, amount); }
    virtual void withdraw(double amount) { if (amount <= balance) balance -= amount; }
    virtual void display() const {
        cout << "Account: " << accountNumber << ", Balance: $" << fixed << setprecision(2) << balance << endl;
    }
    virtual ~BankAccount() {}
};

// SavingsAccount
class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(string accNum, double balance, double rate)
        : BankAccount(accNum, balance), interestRate(rate) {}

    void applyInterest() { balance += balance * (interestRate / 100) / 12; }
    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// CheckingAccount
class CheckingAccount : public BankAccount {
    double withdrawalFee;

public:
    CheckingAccount(string accNum, double balance, double fee)
        : BankAccount(accNum, balance), withdrawalFee(fee) {}

    void withdraw(double amount) override {
        if (amount + withdrawalFee <= balance) balance -= (amount + withdrawalFee);
    }
    void display() const override {
        BankAccount::display();
        cout << "Withdrawal Fee: $" << fixed << setprecision(2) << withdrawalFee << endl;
    }
};

// Main
int main() {
    SavingsAccount savings("S123", 1000, 5);
    CheckingAccount checking("C456", 1000, 2.5);

    savings.deposit(500);
    savings.applyInterest();
    savings.display();

    checking.withdraw(100);
    checking.display();

    return 0;
}
