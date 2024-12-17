#include "SolidObstacle.h"
#include <iostream>

// Конструктор для встановлення координат непрохідної перешкоди
SolidObstacle::SolidObstacle(int x, int y) : Obstacle(x, y) {}

// Відображення непрохідної перешкоди на екрані
void SolidObstacle::render() {
    std::cout << "Solid Obstacle is at (" << x << ", " << y << ") - Unbreakable\n";
}
