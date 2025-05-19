#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];   // Ambil elemen yang akan disisipkan
        int j = i - 1;

        // Geser elemen yang lebih besar dari key ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Sisipkan key di posisi yang tepat
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int data[] = {5, 3, 8, 4, 2};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Sebelum Insertion Sort: ";
    printArray(data, size);

    insertionSort(data, size);

    cout << "Setelah Insertion Sort: ";
    printArray(data, size);

    return 0;
}