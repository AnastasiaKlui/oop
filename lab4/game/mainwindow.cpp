#include "mainwindow.h"
#include <QMouseEvent>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setFixedSize(800, 600); // Встановлюємо фіксований розмір вікна
    setMouseTracking(true); // Увімкнення відслідковування руху миші без натискання кнопок

    // Створюємо мітку для мухи
    flyLabel = new QLabel(this);
    flyLabel->setText("🪰"); // Встановлюємо текст як іконку мухи
    flyLabel->setGeometry(100, 100, 30, 30); // Встановлюємо початкову позицію мухи

    // Створюємо мітку для пастки
    trapLabel = new QLabel(this);
    trapLabel->setText("🪤"); // Встановлюємо текст як іконку пастки
    trapLabel->setGeometry(400, 300, 30, 30); // Встановлюємо позицію пастки
}

MainWindow::~MainWindow() {
    delete flyLabel; // Видаляємо мітку мухи при знищенні вікна
    delete trapLabel; // Видаляємо мітку пастки при знищенні вікна
}

bool MainWindow::event(QEvent* e) {
    if (e->type() == QEvent::MouseMove) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(e); // Приведення події до типу QMouseEvent
        QPoint cursorPos = mouseEvent->pos(); // Отримуємо позицію курсора

        // Якщо муха близько до курсора (відстань менша за 100 пікселів), вона тікає
        if ((flyLabel->x() - cursorPos.x()) * (flyLabel->x() - cursorPos.x()) +
                (flyLabel->y() - cursorPos.y()) * (flyLabel->y() - cursorPos.y()) < 10000) {
            moveFlyAway(); // Переміщаємо муху
        }
    }

    // Передаємо подію для стандартної обробки (відправляємо її базовому класу)
    return QMainWindow::event(e);
}

void MainWindow::moveFly() {
    // Випадкове переміщення мухи в межах вікна
    int newX = QRandomGenerator::global()->bounded(width() - flyLabel->width());
    int newY = QRandomGenerator::global()->bounded(height() - flyLabel->height());
    flyLabel->move(newX, newY);

    // Перевірка, чи муха потрапила в пастку (якщо геометрія мухи перетинає геометрію пастки)
    if (flyLabel->geometry().intersects(trapLabel->geometry())) {
        flyLabel->setText("😵"); // Муха "спіймана" (зміна іконки)
    }
}

void MainWindow::moveFlyAway() {
    // Випадкове переміщення мухи в межах вікна (коли муха тікає від курсора)
    int newX = QRandomGenerator::global()->bounded(width() - flyLabel->width());
    int newY = QRandomGenerator::global()->bounded(height() - flyLabel->height());
    flyLabel->move(newX, newY);
}
