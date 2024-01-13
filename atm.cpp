#include <cstdlib>
#include <ctime>
#include "atm.h"

// Function to generate a random account number
unsigned long long generateAccountNumber() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random 12-digit account number
    unsigned long long accountNumber = 0;
    for (int i = 0; i < 12; ++i) {
        accountNumber = accountNumber * 10 + (std::rand() % 10);
    }

    return accountNumber;
}

// Function to generate a random 4-digit PIN
int generatePIN() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Generate a random 4-digit PIN
    int pin = rand() % 10000;

    // Ensure the PIN is exactly 4 digits
    while (pin < 1000) {
        pin = pin * 10 + rand() % 10;
    }

    return pin;
}

// CONSTRUCTOR - create new customer
Atm::Atm(int id, std::string name, int age, char gender) : id(id), name(name), age(age), gender(gender){
    balance = 0;
    account_number = generateAccountNumber();
    pine = generatePIN();
}

// second ctor - create exist customer
Atm::Atm(int id, std::string name, int age, char gender, unsigned long long account_number, int pine, double balance) : id(id), name(name), age(age), gender(gender), account_number(account_number), pine(pine), balance(balance){}

// DTOR
Atm::Atm::~Atm(){}

// Get account no
unsigned long long Atm::getAccountNo() const{
    return account_number;
}

// Get Bank Balance
double Atm::getBalance() const{
    return balance;
}

// Set/Update Bank Balance
void Atm::setBalance(double amount){
    balance = amount;
}

// Get ATM-Pine
int Atm::getPine() const{
    return pine;
}

// Set ATM-Pine
bool Atm::setPine(int new_pine){
    if(999 < new_pine && new_pine < 10000){
        this->pine = new_pine;
        return true;
    }
    return false;
}

// Get Age
int Atm::getAge() const{
    return age;
}
// Get Gender
char Atm::getGender() const{
    return gender;
}