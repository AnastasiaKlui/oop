#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel> // Для використання QLabel як візуальних елементів

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow; // Оголошення простору імен для інтерфейсу (якщо він буде використовуватися)
}
QT_END_NAMESPACE

// Головний клас для вікна додатка
class MainWindow : public QMainWindow
{
    Q_OBJECT // Макрос Qt для підтримки сигналів і слотів

public:
    MainWindow(QWidget *parent = nullptr); // Конструктор з параметром вказівника на батьківський об'єкт
    ~MainWindow(); // Деструктор для звільнення ресурсів

protected:
    // Перевизначення методу для обробки подій, таких як рух миші
    bool event(QEvent* e) override;

private:
    QLabel* flyLabel;         // Мітка для відображення мухи (ігровий об'єкт)
    QLabel* trapLabel;        // Мітка для відображення пастки (ігровий об'єкт)

    void moveFly();           // Метод для випадкового переміщення мухи
    void moveFlyAway();       // Метод для переміщення мухи подалі від курсора
};

#endif // MAINWINDOW_H
