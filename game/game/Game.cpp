#include "Game.h"
#include <iostream>

// Конструктор для ініціалізації стану гри
Game::Game() : isRunning(true), isPaused(false), currentLevelNumber(1), currentLevel(nullptr) {}

// Метод для відображення головного меню
void Game::showMainMenu() {
    char choice;
    while (true) {
        std::cout << "===== Main Menu =====\n";
        std::cout << "1. Start Game\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            loadLevel(currentLevelNumber);
            run();
            break;
        } else if (choice == '2') {
            std::cout << "Exiting the game. Goodbye!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Метод для завантаження рівня за номером
void Game::loadLevel(int levelNumber) {
    currentLevel = std::make_unique<Level>(levelNumber);
    currentLevel->generate();
}

// Головний цикл гри
void Game::run() {
    while (isRunning) {
        handleInput();
        if (!isPaused) {
            update();
            render();
            if (currentLevel->checkCollisions()) {
                isRunning = false;
                std::cout << "Game Over!\n";
            }
            checkLevelCompletion();
        }
    }
}

// Обробка вводу користувача
void Game::handleInput() {
    char input;
    std::cout << "Enter direction (w/a/s/d), 'p' to pause, or 'q' to quit: ";
    std::cin >> input;

    if (input == 'q') {
        isRunning = false;
    } else if (input == 'p') {
        togglePause();
    } else {
        currentLevel->getPlayer()->move(input);
    }
}

// Перемикання стану паузи
void Game::togglePause() {
    isPaused = !isPaused;
    if (isPaused) {
        std::cout << "Game Paused\n";
    } else {
        std::cout << "Game Resumed\n";
    }
}

// Оновлення стану гри
void Game::update() {
    currentLevel->update();
}

// Відображення стану гри
void Game::render() {
    currentLevel->render();
}

// Перевірка завершення рівня
void Game::checkLevelCompletion() {
    Player* player = currentLevel->getPlayer();
    if (player->getX() == 9 && player->getY() == 9) {
        std::cout << "Level " << currentLevelNumber << " completed!\n";
        currentLevelNumber++;
        loadLevel(currentLevelNumber);
    }
}
