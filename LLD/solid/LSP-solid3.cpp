#include <bits/stdc++.h>
using namespace std;

class Account
{
protected:
    double amount;

public:
    Account(double a) : amount(a) {};
    double getAmount() { return amount; }
    virtual void deposit(double amount) = 0;
};

class Withdrawable : public Account
{
public:
    Withdrawable(double a) : Account(a) {}
    virtual void withdraw(double amount) = 0;
};

class FD : public Account
{
public:
    FD(double a) : Account(a) {}
    void deposit(double a) override
    {
        amount += a;
    }
};
class Savings : public Withdrawable
{
public:
    Savings(double a) : Withdrawable(a) {};
    void deposit(double a) override
    {
        amount += a;
    }
    void withdraw(double a) override
    {
        if (amount - a < 0)
        {
            throw "not enough balance";
        }
        else
            amount -= a;
    }
};
class Current : public Withdrawable
{
    Current(double a) : Withdrawable(a) {};
    void deposit(double a) override
    {
        amount += a;
    }
    void withdraw(double a) override
    {
        if (amount - a < 0)
        {
            throw "not enough balance";
        }
        else
            amount -= a;
    }
};

int main()
{

    return 0;
}