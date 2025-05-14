#include<iostream>

int main(){
    srand(time(0));
    int randomnumber = rand()% 5 + 1;

    switch (randomnumber)
    {
    case 1: std::cout << "win a sticker\n";
        break;
    case 2: std::cout << "win a pen\n";
        break;
    case 3: std::cout << "win a lunch\n";
        break;
    case 4: std::cout << "win a house\n";
        break;
    case 5: std::cout << "win a bicycle\n";
        break;
    }
    return 0;
}