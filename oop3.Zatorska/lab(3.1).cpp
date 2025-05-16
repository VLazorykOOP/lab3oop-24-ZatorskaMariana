#include <iostream>
#include <cmath>
#include <string>

class Rhombus {
private:
    double side;
    double diagonal;
    std::string color;

public:
    Rhombus() : side(1.0), diagonal(1.0), color("white") {}

    Rhombus(double s, double d, const std::string& c) {
        setSide(s);
        setDiagonal(d);
        setColor(c);
    }

    void setSide(double s) {
        if (s > 0)
            side = s;
        else
            std::cerr << "Сторона повинна бути більшою за 0.\n";
    }

    void setDiagonal(double d) {
        if (d > 0)
            diagonal = d;
        else
            std::cerr << "Діагональ повинна бути більшою за 0.\n";
    }

    void setColor(const std::string& c) {
        if (!c.empty())
            color = c;
        else
            std::cerr << "Колір не може бути порожнім.\n";
    }

    double getSide() const {
        return side;
    }

    double getDiagonal() const {
        return diagonal;
    }

    std::string getColor() const {
        return color;
    }

    double area() const {
        double halfDiagonal = diagonal / 2.0;
        double otherHalf = std::sqrt(side * side - halfDiagonal * halfDiagonal);
        double d2 = otherHalf * 2.0;
        return (diagonal * d2) / 2.0;
    }

    double perimeter() const {
        return 4 * side;
    }

    void print() const {
        std::cout << "\n--- Інформація про ромб ---\n"
                  << "Сторона: " << side << "\n"
                  << "Діагональ: " << diagonal << "\n"
                  << "Колір: " << color << "\n"
                  << "Площа: " << area() << "\n"
                  << "Периметр: " << perimeter() << "\n";
    }
};

int main() {
    double sideInput, diagonalInput;
    std::string colorInput;

    std::cout << "Введіть сторону ромба: ";
    std::cin >> sideInput;

    while (sideInput <= 0) {
        std::cout << "Помилка! Сторона повинна бути > 0. Спробуйте ще раз: ";
        std::cin >> sideInput;
    }

    std::cout << "Введіть діагональ ромба: ";
    std::cin >> diagonalInput;

    while (diagonalInput <= 0) {
        std::cout << "Помилка! Діагональ повинна бути > 0. Спробуйте ще раз: ";
        std::cin >> diagonalInput;
    }

    std::cout << "Введіть колір ромба: ";
    std::cin.ignore(); // очищає вхідний буфер після cin >>
    std::getline(std::cin, colorInput);

    while (colorInput.empty()) {
        std::cout << "Помилка! Колір не може бути порожнім. Спробуйте ще раз: ";
        std::getline(std::cin, colorInput);
    }

    Rhombus userRhombus(sideInput, diagonalInput, colorInput);
    userRhombus.print();

    return 0;
}
