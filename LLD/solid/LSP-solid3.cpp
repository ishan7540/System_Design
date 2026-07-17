#include <iostream>
#include <stdexcept>
#include <memory>

// Base Account Class
class Account
{
protected:
    double amount;

public:
    Account(double a) : amount(a) {}

    // Virtual destructor is mandatory for polymorphic base classes
    virtual ~Account() = default;

    double getAmount() { return amount; }

    // Implemented here to avoid DRY violations in derived classes
    virtual void deposit(double a)
    {
        if (a <= 0)
        {
            throw std::invalid_argument("Deposit amount must be positive");
        }
        amount += a;
    }
};

// Interface/Intermediate class for accounts that allow withdrawals
class Withdrawable : public Account
{
public:
    Withdrawable(double a) : Account(a) {}

    virtual void withdraw(double a)
    {
        if (a <= 0)
        {
            throw std::invalid_argument("Withdrawal amount must be positive");
        }
        if (amount - a < 0)
        {
            throw std::runtime_error("Insufficient balance");
        }
        amount -= a;
    }
};

class FD : public Account
{
public:
    FD(double a) : Account(a) {}
};

class Savings : public Withdrawable
{
public:
    Savings(double a) : Withdrawable(a) {}
};

class Current : public Withdrawable
{
public:
    Current(double a) : Withdrawable(a) {}
};

int main()
{
    try
    {
        std::unique_ptr<Account> myFD = std::make_unique<FD>(1000.0);
        std::unique_ptr<Withdrawable> mySavings = std::make_unique<Savings>(500.0);

        std::cout << "Initial FD Balance: $" << myFD->getAmount() << "\n";
        std::cout << "Initial Savings Balance: $" << mySavings->getAmount() << "\n";

        myFD->deposit(500.0);
        std::cout << "FD after deposit: $" << myFD->getAmount() << "\n";

        mySavings->withdraw(200.0);
        std::cout << "Savings after withdrawal: $" << mySavings->getAmount() << "\n";

        std::cout << "Attempting to overdraw Savings...\n";
        mySavings->withdraw(1000.0); // This will throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Transaction Error: " << e.what() << "\n";
    }

    return 0;
}