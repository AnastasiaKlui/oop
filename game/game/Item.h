#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

// Клас для предметів, які можна збирати
class Item : public GameObject {
private:
    int x, y; // Координати предмета

public:
    Item(int x, int y); // Конструктор для ініціалізації предмета
    void update() override; // Метод для оновлення (порожній, оскільки предмети не рухаються)
    void render() override; // Метод для відображення предмета
    int getX() const;       // Отримання координати X
    int getY() const;       // Отримання координати Y
};

#endif
