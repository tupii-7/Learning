#include <iostream>
using namespace std;

int main() {
    char operasi;
    float angka1, angka2;

    cout << "Pilih operasi (+, -, *): " << endl;
    cin >> operasi;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    switch (operasi) {
        case '+':
            cout << "Hasil: " << angka1 + angka2 << endl;
            break;
        case '-':
            cout << "Hasil: " << angka1 - angka2 << endl;
            break;
        case '*':
            cout << "Hasil: " << angka1 * angka2 << endl;
            break;
        default:
            cout << "Operasi tidak valid!" << endl;
    }

    return 0;
}