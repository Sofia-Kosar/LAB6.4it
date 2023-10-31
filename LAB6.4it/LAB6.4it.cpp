#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int* create(int n, const int Low, const int High) {
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
    return a;
}

void print(int* a, int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << a[i];
    }
    cout << endl;
}
int Min(int* a, const int size)
{
    int min = a[0];
    for (int i = 1; i < size; i++)
        if (abs(a[i]) < abs(min))
            min = a[i];
    return min;
}
int sumOfModsAfterZero(int* arr, int size) {
    int sum = 0;
    bool foundZero = false;

    for (int i = 0; i < size; ++i) {
        if (!foundZero) {
            foundZero = (arr[i] == 0); // ѕерев≥рка на перший нуль
        }
        else {
            sum += abs(arr[i]); // якщо вже знайдено перший нуль, додаванн€ до суми
        }
    }

    return sum;
}

void rearrangeArray(int a[], int size) {
    int* rearrangedArray = new int[size];
    int index = 0;

    for (int i = 0; i < size; i += 2) {
        rearrangedArray[index] = a[i];
        index++;
    }

    for (int i = 1; i < size; i += 2) {
        rearrangedArray[index] = a[i];
        index++;
    }

    for (int i = 0; i < size; ++i) {
        a[i] = rearrangedArray[i];
    }

    delete[] rearrangedArray;
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    srand((unsigned)time(NULL));
    int Low = -100;
    int High = 100;

    int* a = create(n, Low, High);
    
    print(a, n);
    cout << "min = " << abs( Min(a, n)) << endl;
    if (Min(a, n) == 0) {
        cout << "Sum of absolute values after the first zero: " << sumOfModsAfterZero(a, n) << endl;
       
    }
    else {
        cout << "sumOfModsAfterZero is impossible to find because there are no 0 in this array" << endl;
    }
    rearrangeArray(a, n);
    cout << "Rearranged array: ";
    print(a, n);

    delete[] a;
    return 0;
}
