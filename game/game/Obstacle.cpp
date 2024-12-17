#include "Obstacle.h"
#include <iostream>

// Конструктор для ініціалізації координат перешкоди
Obstacle::Obstacle(int x, int y) : x(x), y(y) {}

// Оновлення перешкоди (перешкода залишається на місці)
void Obstacle::update() {}

// Відображення перешкоди на екрані
void Obstacle::render() {
    std::cout << "Obstacle is at (" << x << ", " << y << ")\n";
}

// Гетери для отримання координат перешкоди
int Obstacle::getX() const { return x; }
int Obstacle::getY() const { return y; }
