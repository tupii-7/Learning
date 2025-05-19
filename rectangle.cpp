 #include<iostream>
 #include<iomanip>

 using std::cout;
 using std::endl;
 using std::string;

 int main(){
    int height, width;
    cout << "height: ";
    std::cin >> height;
    cout << "width: ";
    std::cin >> width;

    char symbol;
    cout << "symbol: ";
    std::cin >> symbol;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout << std::setw(3) << symbol;
        }
        cout << endl;
    }

    return 0;
 }