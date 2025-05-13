#include <iostream>
#include <vector>

//this is for alias or create an additional name for another data type

typedef int tupii;
using nama = std::string; 

int main(){
    tupii num = 0;
    nama bro = "arii";
     
    std::cout << num << std::endl;
    std::cout << bro << std::endl;
    
    return 0;
}