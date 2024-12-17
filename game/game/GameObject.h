#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Базовий клас для всіх об'єктів гри
class GameObject {
public:
    virtual void update() = 0; // Метод для оновлення об'єкта (рух, зміна стану)
    virtual void render() = 0; // Метод для відображення об'єкта на екрані
    virtual ~GameObject() = default; // Віртуальний деструктор для коректного видалення об'єктів
};

#endif
