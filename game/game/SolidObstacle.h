#ifndef SOLIDOBSTACLE_H
#define SOLIDOBSTACLE_H

#include "Obstacle.h"

// Клас для непрохідної перешкоди, що успадковується від Obstacle
class SolidObstacle : public Obstacle {
public:
    SolidObstacle(int x, int y); // Конструктор для ініціалізації непрохідної перешкоди
    void render() override;      // Перевизначений метод для відображення непрохідної перешкоди
};

#endif
