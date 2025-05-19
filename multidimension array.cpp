#include <iostream>  
using namespace std;  

int main() {  
    int lapis, baris, kolom;  

    // Input ukuran array  
    cout << "Masukkan jumlah lapis: ";  
    cin >> lapis;  
    cout << "Masukkan jumlah baris per lapis: ";  
    cin >> baris;  
    cout << "Masukkan jumlah kolom per baris: ";  
    cin >> kolom;  

    int arr[lapis][baris][kolom];  

    // Input elemen  
    cout << "\nMasukkan elemen array 3D:\n";  
    for (int l = 0; l < lapis; l++) {  
        cout << "\nlapis " << l+1 << ":\n";  
        for (int b = 0; b < baris; b++) {  
            cout << "Baris " << b+1 << ":\n";  
            for (int k = 0; k < kolom; k++) {  
                cout << "Kolom " << k+1 << ": ";cin >> arr[l][b][k];  
            }  
        }  
    }  

    // Hitung total per lapisan  
    int total[lapis] = {0}; // Inisialisasi total dengan 0  
    for (int l = 0; l < lapis; l++) {  
        for (int b = 0; b < baris; b++) {  
            for (int k = 0; k < kolom; k++) {  
                total[l] = total [l] + arr[l][b][k];  
            }  
        }  
    }  

    // Output hasil  
    cout << "\nTotal Lapisan:\n";  
    for (int l = 0; l < lapis; l++) {  
        cout << "Total Lapisan " << l+1 << ": " << total[l] << endl;  
    }  

    return 0;  
}  