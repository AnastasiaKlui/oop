#ifndef LEVEL_H
#define LEVEL_H

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "FastEnemy.h"
#include "Obstacle.h"
#include "SolidObstacle.h"
#include "Item.h"
#include <vector>
#include <memory>

class Level {
private:
    int levelNumber;  // Номер поточного рівня
    std::unique_ptr<Player> player;  // Унікальний покажчик на гравця
    std::vector<std::unique_ptr<GameObject>> objects;  // Список об'єктів рівня

public:
    Level(int number);       // Конструктор для ініціалізації рівня
    void generate();         // Метод для генерації об'єктів на рівні
    void update();           // Оновлення всіх об'єктів на рівні
    void render();           // Відображення всіх об'єктів рівня
    Player* getPlayer();     // Отримання покажчика на гравця
    bool checkCollisions();  // Перевірка колізій
};

#endif
