#include <iostream>
#include <iomanip>

void showbalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
    double balance = 0;
    int choice = 0;
do
{
    std::cout << "******************\n";
    std::cout << "enter your choice:\n";
    std::cout << "******************\n";
    std::cout << "1. show balance\n";
    std::cout << "2. deposit money\n";
    std::cout << "3. withdraw money\n";
    std::cout << "4. exit\n";
    std::cin >> choice;

    std::cin.clear();
    fflush(stdin);

    switch (choice)
    {
        case 1: showbalance(balance);
            showbalance(balance);
            break;
        case 2: balance += deposit();
            break;
        case 3: balance -= withdraw(balance);
            showbalance(balance);
            break;
        case 4: std::cout << "thanks for visiting\n";
            break;
        default:std::cout << "invalid\n";
    }
} while (choice != 4);

return 0;
}
void showbalance(double balance){
    std::cout << "your balance is: $" << std::setprecision(2) << std::fixed << balance << "\n";
}
double deposit(){
    double amount = 0;

    std::cout << "enter amount to deposit: ";
    std::cin >> amount;

    if(amount > 0){
        return amount;
    }
    else{
        std::cout << "thats not valid amount : " << "\n";
        return 0;
    }

    return amount;
}
double withdraw(double balance){
    double amount = 0;
    
    std::cout << "enter amount to withdraw: ";
    std::cin >> amount;

    if(amount > balance){
        std::cout << "insufficient funds\n";
        return 0;
    }
    else if(amount < 0){
        std::cout << "thats not valid amount\n";
        return 0;
    }
    else{
        return amount;
    }
}