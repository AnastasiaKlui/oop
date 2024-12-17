#include "Enemy.h"
#include <iostream>
#include <cstdlib>

// Конструктор випадково розміщує ворога на полі
Enemy::Enemy() : x(rand() % 10), y(rand() % 10) {}

// Метод для випадкового руху ворога
void Enemy::update() {
    int direction = rand() % 4;
    switch (direction) {
        case 0: if (y > 0) y--; break;  // Вгору
        case 1: if (y < 9) y++; break;  // Вниз
        case 2: if (x > 0) x--; break;  // Вліво
        case 3: if (x < 9) x++; break;  // Вправо
    }
}

// Відображення ворога на екрані
void Enemy::render() {
    std::cout << "Enemy is at (" << x << ", " << y << ")\n";
}

// Гетери для отримання координат ворога
int Enemy::getX() const { return x; }
int Enemy::getY() const { return y; }
