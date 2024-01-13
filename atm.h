#ifndef ATM_H
#define ATM_H
#include<string>

class Atm{
private:
    int age;
    char gender;
    unsigned long long account_number;
    double balance;
    int pine;

public:
    int id;
    std::string name;

    // CONSTRUCTOR - create new customer
    Atm(int id, std::string name, int age, char gender);

    // second ctor - create exist customer
    Atm(int id, std::string name, int age, char gender, unsigned long long account_number, int pine, double balance);

    // DTOR
    virtual ~Atm();

    // Get account no
    unsigned long long getAccountNo() const;

    // Get Bank Balance
    double getBalance() const;

    // Set/Update Bank Balance
    void setBalance(double amount);

    // Get ATM-Pine
    int getPine() const;

    // Set ATM-Pine
    bool setPine(int new_pine);

    // get Age
    int getAge() const;

    // Get Gender
    char getGender() const;
};

#endif