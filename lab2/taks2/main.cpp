#include <iostream>
#include <set>
#include <algorithm>

// Клас "Множина"
class Set {
private:
    std::set<char> elements;

public:
    // Конструктор за замовчуванням
    Set() {}

    // Конструктор із масивом символів
    Set(const std::initializer_list<char>& initList) {
        for (char el : initList) {
            elements.insert(el);
        }
    }

    // Додавання елемента
    void add(char element) {
        elements.insert(element);
    }

    // Перевірка, чи є елемент у множині
    bool contains(char element) const {
        return elements.find(element) != elements.end();
    }

    // Перетин множин
    Set intersection(const Set& other) const {
        Set result;
        for (char el : elements) {
            if (other.contains(el)) {
                result.add(el);
            }
        }
        return result;
    }

    // Об'єднання множин
    Set unite(const Set& other) const {
        Set result = *this;
        for (char el : other.elements) {
            result.add(el);
        }
        return result;
    }

    // Різниця множин
    Set difference(const Set& other) const {
        Set result;
        for (char el : elements) {
            if (!other.contains(el)) {
                result.add(el);
            }
        }
        return result;
    }

    // Виведення множини
    void print() const {
        std::cout << "{ ";
        for (char el : elements) {
            std::cout << el << " ";
        }
        std::cout << "}" << std::endl;
    }
};

// Функція для побудови множини унікальних елементів
Set findUniqueElements(const Set& set1, const Set& set2) {
    Set unionSet = set1.unite(set2);
    Set intersectionSet = set1.intersection(set2);
    return unionSet.difference(intersectionSet);
}

int main() {
    // Створення множин
    Set setA({'a', 'b', 'c'});
    Set setB({'b', 'c', 'd', 'e'});

    // Перевірка належності елемента до множини
    char element = 'a';
    std::cout << "Чи належить елемент '" << element << "' множині A? "
              << (setA.contains(element) ? "Так" : "Ні") << std::endl;

    // Перетин множин
    Set intersectionSet = setA.intersection(setB);
    std::cout << "Перетин множин A і B: ";
    intersectionSet.print();

    // Об'єднання множин
    Set unionSet = setA.unite(setB);
    std::cout << "Об'єднання множин A і B: ";
    unionSet.print();

    // Різниця множин
    Set differenceSet = setA.difference(setB);
    std::cout << "Різниця множин A і B: ";
    differenceSet.print();

    // Унікальні елементи
    Set uniqueSet = findUniqueElements(setA, setB);
    std::cout << "Елементи, які входять тільки в одну з множин A або B: ";
    uniqueSet.print();

    return 0;
}
