#include "Item.h"
#include <iostream>

// Конструктор для ініціалізації координат предмета
Item::Item(int x, int y) : x(x), y(y) {}

// Оновлення предмета (немає логіки для оновлення)
void Item::update() {}

// Відображення предмета на екрані
void Item::render() {
    std::cout << "Item is at (" << x << ", " << y << ")\n";
}

// Гетери для отримання координат предмета
int Item::getX() const { return x; }
int Item::getY() const { return y; }
