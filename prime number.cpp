#include <iostream>

// Fungsi rekursif untuk memeriksa apakah bilangan prima
bool isPrime(int n, int divisor = 2) {
    if (n <= 2) {
        return (n == 2); // 2 adalah bilangan prima
    }
    if (n % divisor == 0) {
        return false; // Jika habis dibagi, bukan bilangan prima
    }
    if (divisor * divisor > n) {
        return true; // Tidak ada pembagi lain, bilangan prima
    }
    return isPrime(n, divisor + 1); // Periksa pembagi berikutnya
}

int main() {
    int n;
    std::cout << "Masukkan bilangan positif: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Input harus bilangan positif!" << std::endl;
    } else if (isPrime(n)) {
        std::cout << n << " adalah bilangan prima." << std::endl;
    } else {
        std::cout << n << " bukan bilangan prima." << std::endl;
    }

    return 0;
}