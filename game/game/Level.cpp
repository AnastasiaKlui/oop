#include "Level.h"
#include <iostream>
#include <cstdlib>

// Конструктор для створення рівня з переданим номером
Level::Level(int number) : levelNumber(number), player(std::make_unique<Player>()) {}

// Генерація об'єктів на рівні
void Level::generate() {
    std::cout << "Generating Level " << levelNumber << "...\n";
    objects.push_back(std::move(player));

    // Додаємо ворогів
    int enemyCount = levelNumber * 2;
    for (int i = 0; i < enemyCount; ++i) {
        if (rand() % 2 == 0)
            objects.push_back(std::make_unique<Enemy>());
        else
            objects.push_back(std::make_unique<FastEnemy>());
    }

    // Додаємо перешкоди
    int obstacleCount = levelNumber + 1;
    for (int i = 0; i < obstacleCount; ++i) {
        if (rand() % 2 == 0)
            objects.push_back(std::make_unique<Obstacle>(rand() % 10, rand() % 10));
        else
            objects.push_back(std::make_unique<SolidObstacle>(rand() % 10, rand() % 10));
    }

    // Додаємо предмет
    objects.push_back(std::make_unique<Item>(rand() % 10, rand() % 10));
}

// Оновлення об'єктів рівня
void Level::update() {
    for (auto& obj : objects) {
        obj->update();
    }
}

// Відображення об'єктів рівня
void Level::render() {
    std::cout << "Rendering Level " << levelNumber << "...\n";
    for (auto& obj : objects) {
        obj->render();
    }
}

// Отримання покажчика на гравця
Player* Level::getPlayer() {
    return dynamic_cast<Player*>(objects[0].get());
}

// Перевірка колізій
bool Level::checkCollisions() {
    Player* player = getPlayer();
    for (size_t i = 1; i < objects.size(); ++i) {
        GameObject* obj = objects[i].get();
        if (Enemy* enemy = dynamic_cast<Enemy*>(obj)) {
            if (player->getX() == enemy->getX() && player->getY() == enemy->getY()) {
                std::cout << "Collision with an Enemy! Game Over.\n";
                return true;
            }
        }
    }
    return false;
}//
//  Level.cpp
//  game
//
//  Created by Anastasia Klui on 15.12.2024.
//

