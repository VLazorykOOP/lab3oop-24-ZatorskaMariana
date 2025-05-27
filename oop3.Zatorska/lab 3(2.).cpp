#include <iostream>
#include <cmath>

using namespace std;

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
        cout << "Знищення об'єкта Vector. Стан: " << state << endl;
        objectCount--;
    }

    // --- Сетери координат ---
    void set(char coord = 'x', float value = 0.0f) {
        switch (coord) {
            case 'x': x = value; break;
            case 'y': y = value; break;
            case 'z': z = value; break;
            default: cerr << "Невірна координата\n";
        }
    }

    // --- Гетери координат ---
    float get(char coord = 'x') const {
        switch (coord) {
            case 'x': return x;
            case 'y': return y;
            case 'z': return z;
            default: cerr << "Невірна координата\n"; return 0;
        }
    }

    // --- Функція друку ---
    void print() const {
        cout << "Vector(" << x << ", " << y << ", " << z << "), Стан: " << state << endl;
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
            cerr << "Помилка: ділення на 0!" << endl;
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
        return sqrt(x * x + y * y + z * z);
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
    cout << "Введення даних для вектора:\n";

    float x, y, z;
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;

    // Створюємо вектор з введеними значеннями
    float arr[3] = {x, y, z};
    Vector userVector(arr);

    cout << "Ваш вектор:\n";
    userVector.print();

    cout << "\nСтворимо ще один вектор (1.0, 2.0, 3.0) для операцій:\n";
    float refData[3] = {1.0f, 2.0f, 3.0f};
    Vector refVector(refData);
    refVector.print();

    cout << "\nСума векторів:\n";
    Vector sum = userVector.add(refVector);
    sum.print();

    cout << "Різниця векторів:\n";
    Vector diff = userVector.subtract(refVector);
    diff.print();

    cout << "Векторний добуток:\n";
    Vector cross = userVector.cross(refVector);
    cross.print();

    cout << "Введіть ціле число для ділення: ";
    short divisor;
    cin >> divisor;

    userVector.divide(divisor);
    cout << "Вектор після ділення:\n";
    userVector.print();

    cout << "\nПорівняння довжин:\n";
    cout << "Ваш вектор > опорного: " << (userVector.isGreater(refVector) ? "Так" : "Ні") << endl;
    cout << "Ваш вектор <= опорного: " << (userVector.isLessOrEqual(refVector) ? "Так" : "Ні") << endl;

    cout << "\nКількість об'єктів: " << Vector::getObjectCount() << endl;

    return 0;
}
