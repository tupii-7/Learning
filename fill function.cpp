#include<iostream>

int main(){

    //std::fill() = fill a range of element with specified value
    //std::fill(begin, end, value)


    const int size = 5;
    std::string food[size];

    std::fill(food, food + size, "megono");

    for(std::string foods : food){
        std::cout << foods << '\n';
    }
    return 0;
}