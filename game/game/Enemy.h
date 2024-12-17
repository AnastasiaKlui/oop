#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

// Клас для ворогів, що успадковується від GameObject
class Enemy : public GameObject {
protected:
    int x, y; // Координати ворога на ігровому полі

public:
    Enemy();                // Конструктор для ініціалізації ворога у випадкових координатах
    virtual void update() override; // Метод для оновлення позиції ворога
    virtual void render() override; // Метод для відображення ворога
    int getX() const;       // Отримання координати X
    int getY() const;       // Отримання координати Y
};

#endif
