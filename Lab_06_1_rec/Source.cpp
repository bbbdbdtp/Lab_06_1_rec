#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int a[], int index) {
    if (index == 25) {
        return;
    }

    a[index] = rand() % 51 - 20;
    fillArray(a, index + 1);
}

void printArray(const int a[], int index) {
    if (index == 25) {
        cout << endl;
        return;
    }

    cout << a[index] << " ";
    printArray(a, index + 1);
}

void processAndCount(int a[], int& count, int& sum, int index) {
    if (index == 25) {
        return;
    }

    if (a[index] > 0 && a[index] % 2 == 0) {
        count++;
        sum += a[index];
        a[index] = 0;
    }

    processAndCount(a, count, sum, index + 1);
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int myArray[25];
    int count = 0, sum = 0;

    fillArray(myArray, 0);

    cout << "Original Array: ";
    printArray(myArray, 0);

    processAndCount(myArray, count, sum, 0);

    cout << "Count of elements satisfying the criteria: " << count << endl;
    cout << "Sum of elements satisfying the criteria: " << sum << endl;

    cout << "Modified Array : ";
    printArray(myArray, 0);

    return 0;
}