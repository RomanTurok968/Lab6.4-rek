#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ������� ��� ��������� ������ ����������
void COUT(double mas[], int size, int i = 0) {
    if (i == size) {
        cout << endl;
        return;
    }
    cout << setw(6) << mas[i] << " ";
    COUT(mas, size, i + 1);
}

// ������� ��� ���������� ������� ��������, ������ �� C
int CountGreaterThanC(double mas[], int size, double C, int i = 0, int count = 0) {
    if (i == size) return count;
    if (mas[i] > C) count++;
    return CountGreaterThanC(mas, size, C, i + 1, count);
}

// ������� ��� ����������� ������� ������������� �� ������� ��������
int MaxAbsIndex(double mas[], int size, int i = 0, int maxIndex = 0) {
    if (i == size) return maxIndex;
    if (fabs(mas[i]) > fabs(mas[maxIndex])) maxIndex = i;
    return MaxAbsIndex(mas, size, i + 1, maxIndex);
}

// ������� ��� ���������� ������� �������� ���� ������������� �� ������� ��������
double ProductAfterMaxAbs(double mas[], int size, int maxIndex, int i = 0, double product = 1) {
    if (i <= maxIndex) return product;
    product *= mas[i];
    return ProductAfterMaxAbs(mas, size, maxIndex, i + 1, product);
}

// ������� ��� ������������ ������
void RearrangeArray(double mas[], int size) {
    double* temp = new double[size];
    int negIndex = 0, posIndex = 0;

    // ������� ��'��� ��������
    for (int i = 0; i < size; i++) {
        if (mas[i] < 0) temp[negIndex++] = mas[i];
    }

    // ������� ������ �� ������ ��������
    for (int i = 0; i < size; i++) {
        if (mas[i] >= 0) temp[negIndex + posIndex++] = mas[i];
    }

    // ������� ����� � ���������� �����
    for (int i = 0; i < size; i++) {
        mas[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    double C;

    // �������� ������ ������ �� ��������� C
    cout << "����i�� �i���i��� �������i� ������ n: ";
    cin >> n;
    cout << "����i�� �������� ��������� C: ";
    cin >> C;

    double* mas = new double[n];

    // �������� �������� ������
    cout << "����i�� �������� ������: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "���������� �����: " << endl;
    COUT(mas, n);

    // 1.1. ʳ������ �������� ������, ������ �� C
    int count = CountGreaterThanC(mas, n, C);
    cout << "�i���i��� �������i� ������, �i����� �� " << C << ": " << count << endl;

    // 1.2. ������� �������� ���� ������������� �� ������� ��������
    int maxIndex = MaxAbsIndex(mas, n);
    double product = ProductAfterMaxAbs(mas, n, maxIndex, maxIndex + 1);
    cout << "������� �������i� ������, ������������ �i��� ������������� �� ������� ��������: " << product << endl;

    // 2. ������������ ������
    RearrangeArray(mas, n);
    cout << "������������ ����� (�i�'���i -> ������i): " << endl;
    COUT(mas, n);

    delete[] mas;

    return 0;
}
