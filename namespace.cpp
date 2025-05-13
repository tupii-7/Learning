#include <iostream>

namespace first{
    int x= 1;
}

namespace second{
    int x= 2;
}

int main(){
    int x = 0;
    using namespace first;

    std::cout << first::x << std::endl;

    return 0;
}