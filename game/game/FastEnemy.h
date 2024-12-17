#ifndef FASTENEMY_H
#define FASTENEMY_H

#include "Enemy.h"

// Клас для швидкого ворога, що рухається швидше за звичайного
class FastEnemy : public Enemy {
public:
    void update() override; // Перевизначений метод для швидшого руху
    void render() override; // Перевизначений метод для відображення швидкого ворога
};

#endif
