#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Binary Search
int binarySearch(const vector<int>& arr, int target, size_t& memoryAccessed) {
    int left = 0, right = arr.size() - 1;
    memoryAccessed = sizeof(left) + sizeof(right);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        memoryAccessed += sizeof(mid) + sizeof(arr[mid]);
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Jump Search
int jumpSearch(const vector<int>& arr, int target, size_t& memoryAccessed) {
    int n = arr.size();
    int step = sqrt(n), prev = 0;
    memoryAccessed = sizeof(n) + sizeof(step) + sizeof(prev);

    while (prev < n && arr[prev] < target) {
        memoryAccessed += sizeof(arr[prev]);
        prev += step;
    }

    int start = max(0, prev - step);
    for (int i = start; i <= min(prev, n - 1); ++i) {
        memoryAccessed += sizeof(arr[i]);
        if (arr[i] == target) return i;
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(const vector<int>& arr, int target, size_t& memoryAccessed) {
    int left = 0, right = arr.size() - 1;
    memoryAccessed = sizeof(left) + sizeof(right);

    while (left <= right && target >= arr[left] && target <= arr[right]) {
        if (left == right) {
            memoryAccessed += sizeof(arr[left]);
            return (arr[left] == target) ? left : -1;
        }
        int pos = left + ((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]);
        memoryAccessed += sizeof(pos) + sizeof(arr[pos]);

        if (arr[pos] == target) return pos;
        if (arr[pos] < target) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

// Fibonacci Search
int fibonacciSearch(const vector<int>& arr, int target, size_t& memoryAccessed) {
    int n = arr.size();
    int fibMMm2 = 0, fibMMm1 = 1, fibM = fibMMm2 + fibMMm1;
    memoryAccessed = sizeof(n) + sizeof(fibMMm2) + sizeof(fibMMm1) + sizeof(fibM);

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        memoryAccessed += sizeof(i) + sizeof(arr[i]);

        if (arr[i] < target) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (arr[i] > target) {
            fibM = fibMMm2;
            fibMMm1 -= fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return i;
        }
    }

    if (fibMMm1 && offset + 1 < n) {
        memoryAccessed += sizeof(arr[offset + 1]);
        if (arr[offset + 1] == target) return offset + 1;
    }
    return -1;
}

// Utility to test and print result
void testSearch(const string& name, int (*searchFunc)(const vector<int>&, int, size_t&), const vector<int>& data, int target) {
    size_t memoryAccessed = 0;
    auto start = high_resolution_clock::now();
    int result = searchFunc(data, target, memoryAccessed);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start).count();

    cout << "=== " << name << " ===\n";
    cout << (result != -1 ? "Found at index: " : "Not found. Closest index: ") << result << "\n";
    cout << "Execution Time: " << duration << " ns\n";
    cout << "Memory Accessed: " << memoryAccessed << " bytes\n\n";
}

int main() {
    srand(time(0));
    const int SIZE = 100;
    vector<int> data(SIZE);

    for (int i = 0; i < SIZE; ++i)
        data[i] = rand() % 1000000;

    sort(data.begin(), data.end());

    int target = data[rand() % SIZE]; // Random target from the data

    cout << "Sorted Array (first 10 elements): ";
    for (int i = 0; i < min(10, SIZE); ++i)
        cout << data[i] << " ";
    cout << "...\n\nTarget to Find: " << target << "\n\n";

    testSearch("BINARY SEARCH", binarySearch, data, target);
    testSearch("JUMP SEARCH", jumpSearch, data, target);
    testSearch("INTERPOLATION SEARCH", interpolationSearch, data, target);
    testSearch("FIBONACCI SEARCH", fibonacciSearch, data, target);

    return 0;
}