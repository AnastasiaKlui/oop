#ifndef SET_HPP
#define SET_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Set {
private:
    std::vector<char> elements;

public:
    // Конструктор за замовчуванням
    Set() {}

    // Конструктор із заданим набором елементів
    Set(const std::vector<char>& elements) {
        this->elements = elements;
    }

    // Перевірка, чи міститься елемент у множині
    bool contains(char element) const {
        return std::find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Перетин множин
    Set intersection(const Set& other) const {
        std::vector<char> result;
        for (char el : elements) {
            if (other.contains(el)) {
                result.push_back(el);
            }
        }
        return Set(result);
    }

    // Об'єднання множин
    Set unite(const Set& other) const {
        std::vector<char> result = elements;
        for (char el : other.elements) {
            if (!contains(el)) {
                result.push_back(el);
            }
        }
        return Set(result);
    }

    // Різниця множин
    Set difference(const Set& other) const {
        std::vector<char> result;
        for (char el : elements) {
            if (!other.contains(el)) {
                result.push_back(el);
            }
        }
        return Set(result);
    }

    // Виведення множини
    void print() const {
        std::cout << "{ ";
        for (char el : elements) {
            std::cout << el << " ";
        }
        std::cout << "}" << std::endl;
    }

    // Отримати елементи (для функцій поза класом)
    std::vector<char> getElements() const {
        return elements;
    }
};

// Функція для побудови множини унікальних елементів
Set findUniqueElements(const Set& set1, const Set& set2) {
    Set unionSet = set1.unite(set2);
    Set intersectionSet = set1.intersection(set2);

    return unionSet.difference(intersectionSet);
}

#endif /* SET_HPP */
