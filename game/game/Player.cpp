#include "Player.h"
#include <iostream>

// Конструктор ініціалізує гравця на позиції (0, 0) зі 100 здоров'я та 0 очками
Player::Player() : x(0), y(0), health(100), score(0) {}

// Метод для руху гравця по екрану
void Player::move(char direction) {
    switch (direction) {
        case 'w': if (y > 0) y--; break;  // Рух вгору
        case 's': if (y < 9) y++; break;  // Рух вниз
        case 'a': if (x > 0) x--; break;  // Рух вліво
        case 'd': if (x < 9) x++; break;  // Рух вправо
    }
}

// Метод для отримання пошкоджень
void Player::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

// Метод для додавання очок
void Player::addScore(int points) {
    score += points;
}

// Оновлення гравця (наразі без додаткової логіки)
void Player::update() {}

// Відображення позиції, здоров'я та очок гравця
void Player::render() {
    std::cout << "Player is at (" << x << ", " << y << ") | Health: " << health << " | Score: " << score << "\n";
}

// Гетери для отримання стану гравця
int Player::getX() const { return x; }
int Player::getY() const { return y; }
int Player::getHealth() const { return health; }
int Player::getScore() const { return score; }
