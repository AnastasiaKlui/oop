#include <iostream>
#include <string>
#include <stdexcept> // Для обробки винятків

// Базовий абстрактний клас Boat
class Boat {
protected:
    std::string name;            // Назва човна
    double maxSpeed;             // Максимальна швидкість човна
    double capacity;             // Вантажопідйомність човна

public:
    // Конструктор для ініціалізації загальних характеристик човна
    Boat(const std::string& name, double maxSpeed, double capacity)
        : name(name), maxSpeed(maxSpeed), capacity(capacity) {
        if (maxSpeed <= 0) {
            throw std::invalid_argument("Max speed must be a positive value.");
        }
        if (capacity <= 0) {
            throw std::invalid_argument("Capacity must be a positive value.");
        }
    }

    // Віртуальний деструктор
    virtual ~Boat() {}

    // Віртуальна функція для виведення інформації про човен
    virtual void displayInfo() const = 0;

    // Сетери для загальних характеристик
    void setName(const std::string& n) {
        if (n.empty()) {
            throw std::invalid_argument("Name cannot be empty.");
        }
        name = n;
    }

    void setMaxSpeed(double speed) {
        if (speed <= 0) {
            throw std::invalid_argument("Max speed must be a positive value.");
        }
        maxSpeed = speed;
    }

    void setCapacity(double cap) {
        if (cap <= 0) {
            throw std::invalid_argument("Capacity must be a positive value.");
        }
        capacity = cap;
    }

    // Гетери для загальних характеристик
    std::string getName() const { return name; }
    double getMaxSpeed() const { return maxSpeed; }
    double getCapacity() const { return capacity; }
};

// Клас Rowboat (Весловий човен), який успадковується від Boat
class Rowboat : public Boat {
private:
    int numOars;           // Кількість весел
    std::string material;  // Тип матеріалу

public:
    // Конструктор для ініціалізації характеристик веслового човна
    Rowboat(const std::string& name, double maxSpeed, double capacity, int numOars, const std::string& material)
        : Boat(name, maxSpeed, capacity), numOars(numOars), material(material) {
        if (numOars <= 0) {
            throw std::invalid_argument("Number of oars must be a positive integer.");
        }
        if (material.empty()) {
            throw std::invalid_argument("Material cannot be empty.");
        }
    }

    // Перевизначення віртуальної функції для виведення інформації
    void displayInfo() const override {
        std::cout << "Rowboat Info:\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Max Speed: " << maxSpeed << " knots\n";
        std::cout << "Capacity: " << capacity << " kg\n";
        std::cout << "Number of Oars: " << numOars << "\n";
        std::cout << "Material: " << material << "\n\n";
    }
};

// Клас Motorboat (Моторний човен), який успадковується від Boat
class Motorboat : public Boat {
private:
    int enginePower;       // Потужність двигуна (у кінських силах)
    std::string fuelType;  // Тип палива

public:
    // Конструктор для ініціалізації характеристик моторного човна
    Motorboat(const std::string& name, double maxSpeed, double capacity, int enginePower, const std::string& fuelType)
        : Boat(name, maxSpeed, capacity), enginePower(enginePower), fuelType(fuelType) {
        if (enginePower <= 0) {
            throw std::invalid_argument("Engine power must be a positive integer.");
        }
        if (fuelType.empty()) {
            throw std::invalid_argument("Fuel type cannot be empty.");
        }
    }

    // Перевизначення віртуальної функції для виведення інформації
    void displayInfo() const override {
        std::cout << "Motorboat Info:\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Max Speed: " << maxSpeed << " knots\n";
        std::cout << "Capacity: " << capacity << " kg\n";
        std::cout << "Engine Power: " << enginePower << " HP\n";
        std::cout << "Fuel Type: " << fuelType << "\n\n";
    }
};

// Головна функція для тестування програми
int main() {
    try {
        // Створення об'єкта Rowboat
        Rowboat rowboat("Classic Rowboat", 10, 200, 2, "Wood");
        rowboat.displayInfo();

        // Створення об'єкта Motorboat
        Motorboat motorboat("Speedy Motorboat", 50, 500, 150, "Gasoline");
        motorboat.displayInfo();

        // Спроба створити об'єкт із некоректними даними (викличе виняток)
        Motorboat faultyBoat("Faulty Boat", -30, -100, -200, "");
        faultyBoat.displayInfo();
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    catch (...) {
        std::cerr << "An unexpected error occurred.\n";
    }

    return 0;
}
