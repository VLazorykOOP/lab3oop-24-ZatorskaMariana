#include <iostream>
#include <cmath> // Для використання функцій математичних операцій

using namespace std;

class Rhombus {
private:
    double side;       // Сторона ромба
    double diagonal1;  // Перша діагональ
    double diagonal2;  // Друга діагональ
    string color;      // Колір ромба

public:
    // Конструктор за замовчуванням
    Rhombus() : side(0), diagonal1(0), diagonal2(0), color("undefined") {}

    // Конструктор з параметрами
    Rhombus(double s, double d1, double d2, string c) {
        setSide(s);
        setDiagonals(d1, d2);
        setColor(c);
    }

    // Функція для встановлення значення сторони
    void setSide(double s) {
        if (s > 0) {
            side = s;
        } else {
            cout << "Помилка: Сторона повинна бути додатною!" << endl;
            side = 0;
        }
    }

    // Функція для встановлення значень діагоналей
    void setDiagonals(double d1, double d2) {
        if (d1 > 0 && d2 > 0) {
            diagonal1 = d1;
            diagonal2 = d2;
        } else {
            cout << "Помилка: Діагоналі повинні бути додатними!" << endl;
            diagonal1 = 0;
            diagonal2 = 0;
        }
    }

    // Функція для встановлення кольору
    void setColor(string c) {
        color = c;
    }

    // Функція для отримання значення сторони
    double getSide() const {
        return side;
    }

    // Функція для отримання значень діагоналей
    void getDiagonals(double &d1, double &d2) const {
        d1 = diagonal1;
        d2 = diagonal2;
    }

    // Функція для отримання кольору
    string getColor() const {
        return color;
    }

    // Функція для обчислення площі ромба
    double calculateArea() const {
        return (diagonal1 * diagonal2) / 2;
    }

    // Функція для обчислення периметра ромба
    double calculatePerimeter() const {
        return 4 * side;
    }

    // Функція для виведення інформації про ромб
    void printDetails() const {
        cout << "Ромб:\n";
        cout << "Сторона: " << side << endl;
        cout << "Діагоналі: " << diagonal1 << " та " << diagonal2 << endl;
        cout << "Колір: " << color << endl;
        cout << "Площа: " << calculateArea() << endl;
        cout << "Периметр: " << calculatePerimeter() << endl;
    }
};

int main() {
    // Створення ромба за допомогою конструктора за замовчуванням
    Rhombus r1;
    r1.printDetails();

    // Створення ромба з заданими параметрами
    Rhombus r2(5, 6, 8, "червоний");
    r2.printDetails();

    // Тестування встановлення значень за допомогою функцій-членів
    double side, diag1, diag2;
    string color;
    cout << "Введіть сторону ромба: ";
    cin >> side;
    cout << "Введіть першу діагональ: ";
    cin >> diag1;
    cout << "Введіть другу діагональ: ";
    cin >> diag2;
    cout << "Введіть колір ромба: ";
    cin >> color;

    // Створення нового ромба з введеними параметрами
    Rhombus r3;
    r3.setSide(side);
    r3.setDiagonals(diag1, diag2);
    r3.setColor(color);
    r3.printDetails();

    return 0;
}
