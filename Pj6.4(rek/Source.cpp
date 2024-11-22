#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Функція для виведення масиву рекурсивно
void COUT(double mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(6) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

// Функція для обчислення кількості елементів, більших за C
int CountGreaterThanC(double mas[], int size, double C, int i = 0, int count = 0) {
    if (i == size) return count;
    if (mas[i] > C) count++;
    return CountGreaterThanC(mas, size, C, i + 1, count);
}

// Функція для знаходження індексу максимального за модулем елемента
int MaxAbsIndex(double mas[], int size, int i = 0, int maxIndex = 0) {
    if (i == size) return maxIndex;
    if (fabs(mas[i]) > fabs(mas[maxIndex])) maxIndex = i;
    return MaxAbsIndex(mas, size, i + 1, maxIndex);
}

// Функція для обчислення добутку елементів після максимального за модулем елемента
double ProductAfterMaxAbs(double mas[], int size, int maxIndex, int i = 0, double product = 1) {
    if (i <= maxIndex) return product;
    product *= mas[i];
    return ProductAfterMaxAbs(mas, size, maxIndex, i + 1, product);
}

// Функція для перетворення масиву
void RearrangeArray(double mas[], int size) {
    double* temp = new double[size];
    int negIndex = 0, posIndex = 0;

    // Збираємо від'ємні елементи
    for (int i = 0; i < size; i++) {
        if (mas[i] < 0) temp[negIndex++] = mas[i];
    }

    // Збираємо додатні та нульові елементи
    for (int i = 0; i < size; i++) {
        if (mas[i] >= 0) temp[negIndex + posIndex++] = mas[i];
    }

    // Копіюємо назад у початковий масив
    for (int i = 0; i < size; i++) {
        mas[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    double C;

    // Введення розміру масиву та параметра C
    cout << "Введiть кiлькiсть елементiв масиву n: ";
    cin >> n;
    cout << "Введiть значення параметра C: ";
    cin >> C;

    double* mas = new double[n];

    // Введення елементів масиву
    cout << "Введiть елементи масиву: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "Початковий масив: " << endl;
    COUT(mas, n);

    // 1.1. Кількість елементів масиву, більших за C
    int count = CountGreaterThanC(mas, n, C);
    cout << "Кiлькiсть елементiв масиву, бiльших за " << C << ": " << count << endl;

    // 1.2. Добуток елементів після максимального за модулем елемента
    int maxIndex = MaxAbsIndex(mas, n);
    double product = ProductAfterMaxAbs(mas, n, maxIndex, maxIndex + 1);
    cout << "Добуток елементiв масиву, розташованих пiсля максимального за модулем елемента: " << product << endl;

    // 2. Перетворення масиву
    RearrangeArray(mas, n);
    cout << "Перетворений масив (вiд'ємнi -> додатнi): " << endl;
    COUT(mas, n);

    delete[] mas;

    return 0;
}
