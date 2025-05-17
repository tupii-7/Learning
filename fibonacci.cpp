#include <iostream>

// Fungsi rekursif untuk menghitung bilangan Fibonacci ke-n
long int fibonacci(long int n) {
    if (n <= 1) {
        return n; // Basis: Fibonacci(0) = 0, Fibonacci(1) = 1
    }
    return fibonacci(n - 1) + fibonacci(n - 2); // Rekursif
}

int main() {
    long int n;
    std::cout << "Masukkan bilangan positif: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Input harus bilangan positif!" << std::endl;
    } else {
        std::cout << "Bilangan Fibonacci ke-" << n << " adalah " << fibonacci(n) << std::endl;
    }

    return 0;
}