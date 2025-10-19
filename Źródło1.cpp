#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

int main()
{
    double balance = 0;
    double change;
    int choice;

    do
    {
        std::cout << "What do you want to do?\n";
        std::cout << "Press [1] to show balance\n";
        std::cout << "Press [2] to make a deposit\n";
        std::cout << "Press [3] to make a withdrawal\n";
        std::cout << "Press [4] to quit\n";
        std::cin >> choice;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (choice){
            case 1:
                std::cout << "The balance is: " << balance << "\n\n";
                break;
            case 2:
                std::cout << "\n" << "How much do you want to deposit: ";
                std::cin >> change;
                if (std::ceil(change*100)/100 == change && std::floor(change*100)/100 == change) {
                    balance += change;
                    std::cout << "\n";
                }
                else {
                    std::cout << "You typed incorrect number" << "\n\n";
                }
                break;
            case 3:
                std::cout << "\n" << "How much do you want to withdraw: ";
                std::cin >> change;
                if (std::ceil(change * 100) / 100 == change && std::floor(change * 100) / 100 == change) {
                    if (balance - change < 0) {
                        std::cout << "You cant withdraw more money than You have" << "\n\n";
                    }
                    else {
                        balance -= change;
                        std::cout << "\n\n";
                    }
                }
                else {
                    std::cout << "You typed incorrect number" << "\n\n";
                }
                break;
            case 4:
                std::cout << "Goodbye";
                break;
            default:
                std::cout << "Make a proper choice";
                break;
        }
    } while (choice!=4);

    return 0;
}