#include <iostream>

using namespace std;
using number = long long; // Use long long for larger Fibonacci numbers
number fibonacchi_linear(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    number a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cout << "Masukkan nilai n: ";
    cin >> n;

    number result = fibonacchi_linear(n);
    cout << "Fibonacci ke-" << n << " adalah: " << result << endl;

    return 0;
}