#include <iostream>

class Vector {
public:
    float x, y, z;
    int state;  // Стан вектора
    static int count;  // Лічильник об'єктів класу

    // Конструктор без параметрів
    Vector() : x(0), y(0), z(0), state(0) {
        count++;
    }

    // Конструктор, що ініціалізує поля значеннями x, y, z
    Vector(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val), state(0) {
        count++;
    }

    // Конструктор, що приймає вказівник на масив
    Vector(float* arr) {
        if (arr != nullptr) {
            x = arr[0];
            y = arr[1];
            z = arr[2];
            state = 0;
        } else {
            state = -1;  // Код помилки при передачі nullptr
            x = y = z = 0;
        }
        count++;
    }

    // Деструктор з виведенням інформації про стан вектора
    ~Vector() {
        std::cout << "Вектор знищений. Стан: " << state << std::endl;
        count--;
    }

    // Функція, яка присвоює значення полям x, y, z
    void setValues(float newX = 0, float newY = 0, float newZ = 0) {
        x = newX;
        y = newY;
        z = newZ;
    }

    // Функція, яка повертає значення певного елемента: 1 - x, 2 - y, 3 - z
    float getValue(int index) const {
        if (index == 1) return x;
        if (index == 2) return y;
        if (index == 3) return z;
        return 0;
    }

    // Оператор копіювання
    Vector(const Vector& v) : x(v.x), y(v.y), z(v.z), state(v.state) {
        count++;
    }

    // Оператор присвоєння
    Vector& operator=(const Vector& v) {
        if (this != &v) {
            x = v.x;
            y = v.y;
            z = v.z;
            state = v.state;
        }
        return *this;
    }

    // Оператор + для додавання векторів
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y, z + v.z);
    }

    // Оператор - для віднімання векторів
    Vector operator-(const Vector& v) const {
        return Vector(x - v.x, y - v.y, z - v.z);
    }

    // Оператор / для ділення на число (тип short)
    Vector operator/(short int divisor) {
        if (divisor == 0) {
            state = -2;  // Код помилки при діленні на 0
            return *this;  // Не виконуємо ділення
        }
        return Vector(x / divisor, y / divisor, z / divisor);
    }

    // Векторний добуток
    Vector crossProduct(const Vector& v) const {
        float cx = y * v.z - z * v.y;
        float cy = z * v.x - x * v.z;
        float cz = x * v.y - y * v.x;
        return Vector(cx, cy, cz);
    }

    // Оператор порівняння <
    bool operator<(const Vector& v) const {
        return (x < v.x && y < v.y && z < v.z);
    }

    // Оператор порівняння ==
    bool operator==(const Vector& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    // Функція для виведення вектора
    void display() const {
        std::cout << "Вектор(" << x << ", " << y << ", " << z << ", " << state << ")" << std::endl;
    }

    // Функція, яка повертає кількість об'єктів цього класу
    static int getCount() {
        return count;
    }
};

// Ініціалізація статичної змінної
int Vector::count = 0;

int main() {
    // Тестування всіх можливостей класу

    // Створення векторів
    Vector v1(1.0f, 2.0f, 3.0f);
    Vector v2(4.0f, 5.0f, 6.0f);
    Vector v3 = v1 + v2;
    v3.display();

    // Векторний добуток
    Vector v4 = v1.crossProduct(v2);
    v4.display();

    // Порівняння
    std::cout << "v1 < v2: " << (v1 < v2) << std::endl;
    std::cout << "v1 == v2: " << (v1 == v2) << std::endl;

    // Ділення на число
    Vector v5 = v1 / 2;
    v5.display();
    v5 = v1 / 0;  // Ділення на 0, має встановити код помилки
    v5.display();

    // Робота з масивом
    float arr[] = {7.0f, 8.0f, 9.0f};
    Vector v6(arr);
    v6.display();
    Vector v7(nullptr);  // Передача nullptr, має встановити код помилки
    v7.display();

    // Виведення кількості об'єктів класу
    std::cout << "Кількість об'єктів класу Vector: " << Vector::getCount() << std::endl;

    return 0;
}
