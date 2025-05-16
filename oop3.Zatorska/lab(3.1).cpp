#include <iostream>
#include <cmath>
#include <string>

using namespace std;
class Rhombus {
private:
    double side;
    double diagonal;
    string color;

public:
    Rhombus() : side(1.0), diagonal(1.0), color("white") {}

    Rhombus(double s, double d, const string& c) {
        setSide(s);
        setDiagonal(d);
        setColor(c);
    }

    void setSide(double s) {
        if (s > 0)
            side = s;
        else
            cerr << "Сторона повинна бути більшою за 0.\n";
    }

    void setDiagonal(double d) {
        if (d > 0)
            diagonal = d;
        else
            cerr << "Діагональ повинна бути більшою за 0.\n";
    }

    void setColor(const std::string& c) {
        if (!c.empty())
            color = c;
        else
            cerr << "Колір не може бути порожнім.\n";
    }

    double getSide() const {
        return side;
    }

    double getDiagonal() const {
        return diagonal;
    }

    string getColor() const {
        return color;
    }

    double area() const {
        double halfDiagonal = diagonal / 2.0;
        double otherHalf = sqrt(side * side - halfDiagonal * halfDiagonal);
        double d2 = otherHalf * 2.0;
        return (diagonal * d2) / 2.0;
    }

    double perimeter() const {
        return 4 * side;
    }

    void print() const {
        cout << "\n--- Інформація про ромб ---\n"
                  << "Сторона: " << side << "\n"
                  << "Діагональ: " << diagonal << "\n"
                  << "Колір: " << color << "\n"
                  << "Площа: " << area() << "\n"
                  << "Периметр: " << perimeter() << "\n";
    }
};

int main() {
    double sideInput, diagonalInput;
    string colorInput;

    cout << "Введіть сторону ромба: ";
    cin >> sideInput;

    while (sideInput <= 0) {
        cout << "Помилка! Сторона повинна бути > 0. Спробуйте ще раз: ";
        cin >> sideInput;
    }

    cout << "Введіть діагональ ромба: ";
    cin >> diagonalInput;

    while (diagonalInput <= 0) {
        cout << "Помилка! Діагональ повинна бути > 0. Спробуйте ще раз: ";
        cin >> diagonalInput;
    }

    cout << "Введіть колір ромба: ";
    cin.ignore(); // очищає вхідний буфер після cin >>
    getline(cin, colorInput);

    while (colorInput.empty()) {
        cout << "Помилка! Колір не може бути порожнім. Спробуйте ще раз: ";
        getline(cin, colorInput);
    }

    Rhombus userRhombus(sideInput, diagonalInput, colorInput);
    userRhombus.print();

    return 0;
}
