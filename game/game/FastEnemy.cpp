#include "FastEnemy.h"
#include <iostream>

// Швидкий ворог рухається двічі за один цикл оновлення
void FastEnemy::update() {
    Enemy::update();
    Enemy::update();
}

// Відображення швидкого ворога на екрані
void FastEnemy::render() {
    std::cout << "Fast Enemy is at (" << x << ", " << y << ")\n";
}
