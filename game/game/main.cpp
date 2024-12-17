#include "Game.h"
#include <iostream>

int main() {
    srand(static_cast<unsigned>(time(0))); // Ініціалізація генератора випадкових чисел
    Game game;                             // Створення об'єкта гри
    game.showMainMenu();                   // Показ головного меню та запуск гри
    return 0;                              // Завершення програми
}
