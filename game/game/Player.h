#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

// Клас для гравця, що успадковується від GameObject
class Player : public GameObject {
private:
    int x, y;        // Координати гравця на ігровому полі
    int health;      // Здоров'я гравця
    int score;       // Очки гравця

public:
    Player();        // Конструктор для ініціалізації гравця
    void move(char direction); // Метод для руху гравця
    void takeDamage(int amount); // Метод для отримання пошкоджень
    void addScore(int points);   // Метод для додавання очок
    void update() override;      // Оновлення стану гравця
    void render() override;      // Відображення гравця
    int getX() const;            // Отримання координати X
    int getY() const;            // Отримання координати Y
    int getHealth() const;       // Отримання здоров'я
    int getScore() const;        // Отримання очок
};

#endif
