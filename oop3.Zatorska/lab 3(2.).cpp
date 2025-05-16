#include <iostream>
#include <cmath>

class Vector {
private:
    float x, y, z;
    int state; // 0 - OK, 1 - NULL вказівник, 2 - ділення на 0
    static int objectCount;

public:
    // --- Конструктори ---
    Vector() : x(0), y(0), z(0), state(0) {
        objectCount++;
    }

    Vector(float value) : x(value), y(value), z(value), state(0) {
        objectCount++;
    }

    Vector(float* arr) {
        if (arr == nullptr) {
            x = y = z = 0;
            state = 1;
        } else {
            x = arr[0];
            y = arr[1];
            z = arr[2];
            state = 0;
        }
        objectCount++;
    }

    // --- Деструктор ---
    ~Vector() {
        std::cout << "Знищення об'єкта Vector. Стан: " << state << std::endl;
        objectCount--;
    }

    // --- Сетери координат ---
    void set(char coord = 'x', float value = 0.0f) {
        switch (coord) {
            case 'x': x = value; break;
            case 'y': y = value; break;
            case 'z': z = value; break;
            default: std::cerr << "Невірна координата\n";
        }
    }

    // --- Гетери координат ---
    float get(char coord = 'x') const {
        switch (coord) {
            case 'x': return x;
            case 'y': return y;
            case 'z': return z;
            default: std::cerr << "Невірна координата\n"; return 0;
        }
    }

    // --- Функція друку ---
    void print() const {
        std::cout << "Vector(" << x << ", " << y << ", " << z << "), Стан: " << state << std::endl;
    }

    // --- Додавання ---
    Vector add(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    // --- Віднімання ---
    Vector subtract(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    // --- Векторний добуток ---
    Vector cross(const Vector& other) const {
        return Vector(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // --- Ділення на short ---
    void divide(short value) {
        if (value == 0) {
            state = 2;
            std::cerr << "Помилка: ділення на 0!" << std::endl;
            return;
        }
        x /= value;
        y /= value;
        z /= value;
    }

    // --- Порівняння ---
    bool isGreater(const Vector& other) const {
        return magnitude() > other.magnitude();
    }

    bool isLessOrEqual(const Vector& other) const {
        return magnitude() <= other.magnitude();
    }

    // --- Довжина вектора ---
    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // --- Кількість об'єктів ---
    static int getObjectCount() {
        return objectCount;
    }

private:
    Vector(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal), state(0) {
        objectCount++;
    }
};

// Ініціалізація лічильника об'єктів
int Vector::objectCount = 0;

int main() {
    std::cout << "Введення даних для вектора:\n";

    float x, y, z;
    std::cout << "Введіть x: ";
    std::cin >> x;
    std::cout << "Введіть y: ";
    std::cin >> y;
    std::cout << "Введіть z: ";
    std::cin >> z;

    // Створюємо вектор з введеними значеннями
    float arr[3] = {x, y, z};
    Vector userVector(arr);

    std::cout << "Ваш вектор:\n";
    userVector.print();

    std::cout << "\nСтворимо ще один вектор (1.0, 2.0, 3.0) для операцій:\n";
    float refData[3] = {1.0f, 2.0f, 3.0f};
    Vector refVector(refData);
    refVector.print();

    std::cout << "\nСума векторів:\n";
    Vector sum = userVector.add(refVector);
    sum.print();

    std::cout << "Різниця векторів:\n";
    Vector diff = userVector.subtract(refVector);
    diff.print();

    std::cout << "Векторний добуток:\n";
    Vector cross = userVector.cross(refVector);
    cross.print();

    std::cout << "Введіть ціле число для ділення: ";
    short divisor;
    std::cin >> divisor;

    userVector.divide(divisor);
    std::cout << "Вектор після ділення:\n";
    userVector.print();

    std::cout << "\nПорівняння довжин:\n";
    std::cout << "Ваш вектор > опорного: " << (userVector.isGreater(refVector) ? "Так" : "Ні") << std::endl;
    std::cout << "Ваш вектор <= опорного: " << (userVector.isLessOrEqual(refVector) ? "Так" : "Ні") << std::endl;

    std::cout << "\nКількість об'єктів: " << Vector::getObjectCount() << std::endl;

    return 0;
}
