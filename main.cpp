#include<iostream>
#include<string>
#include "atm.h"
using namespace std;

#define ATM_WELCOME_ "\n\t---- <> ---- WELCOME TO MY ATM ---- <> ----\t"
#define END_LINE "\t-------------------------------------------\n"
#define RECIVE_MONEY "Please collect your money.\nThanks for visiting..."
#define LOW_BALANCE "SORRY! YOUR BAL IS LOW."
#define WARNING "PLEASE CHOOSE ONE"
#define MALE 'M'
#define FEMALE 'F'

inline void AgeLimitDes(const Atm *customer, string limit_age){
    if(customer->getGender() == MALE){
        cout << "\t-- He is " << limit_age << "." << endl;
    }
    else if(customer->getGender() == FEMALE){
        cout << "\t-- She is " << limit_age << "." << endl;
    }
}

void PrintCustomerDetails(const Atm *customer){
    cout << ATM_WELCOME_ << endl;
    cout << "\n\t-- Your ID: " << customer->id << " | " << "Gender: " << customer->getGender() << " | " << "Age: " << customer->getAge() << endl;
    cout << "\t-- Hi " << customer->name << " have a good day." << endl;
    cout << "\t-- A/c No: " << customer->getAccountNo() << " | " << "ATM Pine: " << customer->getPine() << endl;
    if(customer->getAge() < 13){
        AgeLimitDes(customer, "Child");
    }
    else if(customer->getAge() >= 13 && customer->getAge() < 18){
        AgeLimitDes(customer,"Teenger");
    }
    else if(customer->getAge() >= 18 && customer->getAge() < 21){
        AgeLimitDes(customer, "Adult");
    }
    else if(customer->getAge() >= 21 && customer->getAge() <= 40){
        AgeLimitDes(customer, "Young");
    }
    else{
        AgeLimitDes(customer, "Old");
    }
    cout << "\t-- Availble Balance is " << customer->getBalance() << "\n\n" << END_LINE << endl;
}

// Convert Upper to lower
char upper(char ch){
    return (ch - 97) + 'A'; 
}
// Convert Default Upper Case
char UpdateGenderText(char ch){
    if(ch >= 65 && ch <= 90) return ch;
    else return upper(ch);
}

int main(){
    // Take Customer Details - Input From User
    Atm *customer; // Create a new user
    int id, age, pine; double balance; unsigned long long account_no; string name; char gender;
    cout << "Are you new user? If 'Yes' press '1': "; int ask; cin >> ask; cout << endl;
    cout << "Enter Customer-ID: "; cin >> id; 
    cout << "Enter Customer Name: "; cin >> name; 
    cout << "Enter Customer Age: "; cin >> age;
    cout << "Enter Customer Gender: "; cin >> gender; gender = UpdateGenderText(gender);
    if(ask == 1){
        customer = new Atm(id, name, age, gender);
        PrintCustomerDetails(customer);
    }
    else{
        cout << "Enter Account number: "; cin >> account_no;
        cout << "Enter ATM - Pine: "; cin >> pine;
        cout << "Enter Amount Balance: "; cin >> balance;
        customer = new Atm(id, name, age, gender, account_no, pine, balance);
        PrintCustomerDetails(customer);
    }

    // Ask For Which Types of transcation
    int i;
    for(i=0; i<10; i++){
        int askMoreOperation = 1; 
        if(i != 0){
            cout << "If You want to Retry? If 'Yes' press 1: "; cin >> askMoreOperation;
        }
        if(askMoreOperation != 1){
            cout << "Good Day!! '" << customer->name << "' Thanks for using ATM!" << endl;
            break;
        }
        int enterPine; cout << "Enter Atm Pine: "; cin >> enterPine;
        if(enterPine < 1000 || enterPine > 10000){
            cout << "Please enter 4-digit Pine: "; cin >> enterPine;
        }
        if(enterPine != customer->getPine()){
            cout << "Wrong Pine Please try Later..." << endl;
            break;
        }
        printf("Choose Transaction:\n1. CASH WITHDRAWAL\n2. CHECK BALANCE\n3. FAST CASH\n4. TO DEPOSIT MONEY\n5. RESET PINE\n>> "); int Option; cin >> Option;
        switch (Option) {
        case 1: // CASH WITHDRAWAL
            double amount; cout << "Enter withdrawal Amount: "; cin >> amount;
            if(((int)amount % 100 == 0) && (amount <= customer->getBalance())){
                double new_balance = customer->getBalance() - amount;
                customer->setBalance(new_balance);
                cout << RECIVE_MONEY << endl;
            }
            else{
                cout << LOW_BALANCE << endl;
            }
            break;
        case 2: // CHECK BALANCE
            cout << "AVAILBLE BALANCE: " << customer->getBalance() << endl;
            break;
        case 3: // FAST CASE
            int fastOption; cout << "CHOOSE ONE AT-LEAST: \n1. 10,000\n2. 5,000\n3. 2,000\n4. 1,000\n>> "; cin>>fastOption;
            switch (fastOption){
                case 1:
                    if(10000 <= customer->getBalance()){
                        customer->setBalance(customer->getBalance() - 10000);
                        cout << RECIVE_MONEY << endl;
                    }
                    else{
                        cout << LOW_BALANCE << endl;
                    }
                    break;
                case 2:
                    if(5000 <= customer->getBalance()){
                        customer->setBalance(customer->getBalance() - 5000);
                        cout << RECIVE_MONEY << endl;
                    }
                    else{
                        cout << LOW_BALANCE << endl;
                    }
                    break;
                case 3:
                    if(2000 <= customer->getBalance()){
                        customer->setBalance(customer->getBalance() - 2000);
                        cout << RECIVE_MONEY << endl;
                    }
                    else{
                        cout << LOW_BALANCE << endl;
                    }
                    break;
                case 4:
                    if(1000 <= customer->getBalance()){
                        customer->setBalance(customer->getBalance() - 1000);
                        cout << RECIVE_MONEY << endl;
                    }
                    else{
                        cout << LOW_BALANCE << endl;
                    }
                    break;
                default:
                    cout << WARNING << endl;
            }
            break;
        case 4: // TO DEPOSIT MONEY
            double new_amount; cout << "Enter Amount: "; cin >> new_amount;
            customer->setBalance(customer->getBalance() + new_amount);
            cout << "Your ATM Bank A/c XX" << customer->getAccountNo() % 1000 <<" has been Credited with Rs." << new_amount << " by Transfer. Avl Bal in your A/c is Rs. " << customer->getBalance() << ". Thanks..." << endl;
            break;
        case 5: // RESET PINE
            int new_Pine; cout << "Enter new Pine: "; cin >> new_Pine;
            if(customer->setPine(new_Pine)){
                cout << "Your Pine has been Updated..." << endl;
            }
            else{
                cout << "Sorry! You entered wrong pine. Plaese try later." << endl;
            }
            break;
        default:
            cout << WARNING << endl;
            break;
        }
        cout << "\n\n";
    }
    if(i == 10){
        cout << "Sorry You have tried many times." << endl;
    }
    delete customer;
    return 0;
}