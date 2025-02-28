#include <iostream>
#include "../include/MyString.h"
#include "../include/MyIdentifier.h"

using std::cout;
using std::cin;

void printMs(MyString *&a, int n) {
    cout << "Массив строк размером " << n << ":\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << a[i] << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    MyString *a = nullptr;
    MyString d;
    int n, t, num1, num2;
    char pt;
    while (true) {
        cout << "Введите действие:\n"
        << "1. Ввод массива строк\n"
        << "2. Вывод массива строк\n"
        << "3. Сравнить строки\n"
        << "4. Сложить строки\n"
        << "5. Вычесть строки\n"
        << "6. Вывести первое вхождение в строку\n"
        << "7. Изменить регистр строки\n"
        << "8. Количество вызовов конструктора копирования MyString\n"
        << "9. Количество вызовов конструктора копирования MyIdentifier\n"
        << "10. Выход\n";
        cin >> t;
        cout << "\033[2J\033[1;1H";
        if (t == 1) {
            cout << "Введите размер массива: ";
            cin >> n;
            while (getchar() != '\n');
            if (a != nullptr) delete[] a;
            a = new MyIdentifier[n];
            for (int i = 0; i < n; i++) {
                cout << "Введите идентификатор " << i + 1 << ": ";
                cin >> a[i];
                a[i].checkIdnt();
            }
        }
        else if (t == 2) printMs(a, n);
        else if (t == 3) {
            printMs(a, n);
            cout << "Введите номера строк, которые вы хотите сравнить: ";
            cin >> num1 >> num2;
            if (a[--num1] > a[--num2]) cout << a[num1] << " > " << a[num2] << '\n';
            else if (a[num1] < a[num2]) cout << a[num1] << " < " << a[num2] << '\n';
            else cout << a[num1] << " = " << a[num2] << '\n';
        }
        else if (t == 4) {
            printMs(a, n);
            cout << "Введите номера строк, которые вы хотите сложить: ";
            cin >> num1 >> num2;
            d = a[--num1] + a[--num2];
            cout << "Итоговая строка: " << d << '\n';
        }
        else if (t == 5) {
            printMs(a, n);
            cout << "Введите номера строк, которые вы хотите вычесть: ";
            cin >> num1 >> num2;
            d = a[--num1] - a[--num2];
            cout << "Итоговая строка: " << d << '\n';
        }
        else if (t == 6) {
            printMs(a, n);
            cout << "Выберите строку, в которой хотите найти последнее вхождение символа: ";
            cin >> num1;
            cout << "Введите символ: ";
            cin >> pt;
            MyIdentifier c(a[num1 - 1]);
            cout << "Последнее вхождение: " << c.searchSymb(pt) + 1 << '\n';
        }
        else if (t == 7) {
            printMs(a, n);
            cout << "Выберите строку, в которой хоитите изменить регистр: ";
            cin >> num1;
            cout << "1 - Верхний регистр\n2 - Нижний регистр\n";
            cin >> num2;
            MyIdentifier c(a[num1 - 1]);
            if (num2 == 1) c.upper();
            else c.lower();
            cout << "Полученная строка: " << c << '\n';
        }
        else if (t == 8) {
            cout << "Строка: ";
            cin >> num1;
            cout << a[num1 - 1].MyString::getCpyNum() << '\n';
        }
        else if (t == 9) {
            cout << "Строка: ";
            cin >> num1;
            cout << a[num1 - 1].MyIdentifier::getCpyNum() << '\n';
        }
        else return 0;
    }
    return 0;
}