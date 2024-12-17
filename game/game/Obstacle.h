#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObject.h"

// Клас для звичайних перешкод
class Obstacle : public GameObject {
protected:
    int x, y; // Координати перешкоди

public:
    Obstacle(int x, int y); // Конструктор для встановлення координат перешкоди
    void update() override; // Метод для оновлення (перешкода не рухається)
    void render() override; // Метод для відображення перешкоди
    int getX() const;       // Отримання координати X
    int getY() const;       // Отримання координати Y
};

#endif
