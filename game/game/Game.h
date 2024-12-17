#ifndef GAME_H
#define GAME_H

#include "Level.h"
#include <memory>

class Game {
private:
    bool isRunning;               // Статус гри (запущена чи завершена)
    bool isPaused;                // Статус паузи (гра на паузі чи ні)
    int currentLevelNumber;       // Поточний номер рівня
    std::unique_ptr<Level> currentLevel;  // Унікальний покажчик на поточний рівень

public:
    Game();                       // Конструктор для ініціалізації гри
    void showMainMenu();          // Метод для відображення головного меню
    void loadLevel(int levelNumber); // Метод для завантаження рівня
    void run();                   // Головний цикл гри
    void handleInput();           // Обробка вводу користувача
    void togglePause();           // Перемикання стану паузи
    void update();                // Оновлення стану гри
    void render();                // Відображення стану гри
    void checkLevelCompletion();  // Перевірка завершення рівня
};

#endif
