
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовий клас для товару
// Містить основні властивості: назву та ціну товару
class Product {
public:
    string name;   // Назва товару
    double price;  // Ціна товару

    Product(string name, double price) : name(name), price(price) {}

    // Метод для виведення інформації про товар
    virtual void display() {
        cout << "Товар: " << name << ", Ціна: " << price << " грн" << endl;
    }
};

// Похідний клас для продукту харчування
// Додає властивість терміну придатності та метод для перевірки терміну
class FoodProduct : public Product {
public:
    string expiration_date;  // Термін придатності

    FoodProduct(string name, double price, string expiration_date)
        : Product(name, price), expiration_date(expiration_date) {}

    // Переозначення методу для виведення додаткової інформації
    void display() override {
        cout << "Продукт: " << name << ", Ціна: " << price
             << " грн, Термін придатності: " << expiration_date << endl;
    }

    // Метод для перевірки терміну придатності
    bool is_expired(const string& current_date) {
        return expiration_date < current_date; // Порівняння дат
    }
};

// Клас для магазину
// Містить список товарів, а також методи для додавання, пошуку та виведення інформації
class Store {
public:
    string store_name;    // Назва магазину
    string store_address; // Адреса магазину
    vector<Product*> products; // Список товарів

    Store(string name, string address) : store_name(name), store_address(address) {}

    // Метод для додавання товару до магазину
    void add_product(Product* product) {
        products.push_back(product);
    }

    // Метод для пошуку товару за назвою
    Product* find_product(const string& product_name) {
        for (auto product : products) {
            if (product->name == product_name) {
                return product;
            }
        }
        return nullptr;
    }

    // Метод для підрахунку кількості товарів у магазині
    int count_products() const {
        return products.size();
    }

    // Метод для виведення інформації про всі товари
    void show_products() {
        cout << "Товари в магазині \"" << store_name << "\" (" << store_address << "):" << endl;
        for (auto product : products) {
            product->display();
        }
    }
};

// Клас для кошика
// Зберігає товари, розраховує їх загальну вартість і дозволяє додавати/видаляти товари
class Cart {
public:
    vector<Product*> items;  // Товари в кошику
    double total_price = 0;  // Загальна вартість

    // Метод для додавання товарів до кошика
    // Перевіряє наявність дубліката перед додаванням
    void add_to_cart(Product* product) {
        for (auto& item : items) {
            if (item == product) {
                cout << "Товар \"" << product->name << "\" уже в кошику!" << endl;
                return;
            }
        }
        items.push_back(product);
        total_price += product->price;
    }

    // Метод для видалення товару з кошика
    void remove_from_cart(Product* product) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (*it == product) {
                items.erase(it);
                total_price -= product->price;
                break;
            }
        }
    }

    // Метод для підрахунку кількості товарів у кошику
    int count_items() const {
        return items.size();
    }

    // Метод для виведення інформації про товари в кошику
    void show_cart() {
        cout << "Товари у кошику:" << endl;
        for (auto& item : items) {
            item->display();
        }
        cout << "Загальна вартість: " << total_price << " грн" << endl;
    }
};

// Демонстрація роботи програми
int main() {
    // Створюємо об'єкти товарів
    Product product1("Ноутбук", 15000);
    Product product2("Телефон", 8000);
    FoodProduct product3("Молоко", 30, "2024-12-01");

    // Створюємо магазин і додаємо товари
    Store store("Електроніка", "вул. Технологічна, 10");
    store.add_product(&product1);
    store.add_product(&product2);
    store.add_product(&product3);

    // Виводимо інформацію про товари у магазині
    cout << "===== Товари у магазині =====" << endl;
    store.show_products();

    // Перевіряємо термін придатності продукту
    cout << "\n===== Перевірка терміну придатності =====" << endl;
    if (product3.is_expired("2024-11-28")) {
        cout << "Товар \"" << product3.name << "\" непридатний до використання!" << endl;
    } else {
        cout << "Товар \"" << product3.name << "\" придатний до використання!" << endl;
    }

    // Пошук товару в магазині
    cout << "\n===== Пошук товару =====" << endl;
    Product* found = store.find_product("Ноутбук");
    if (found) {
        cout << "Товар знайдено: ";
        found->display();
    } else {
        cout << "Товар не знайдено!" << endl;
    }

    // Створюємо кошик і додаємо товари
    Cart cart;
    cout << "\n===== Додаємо товари до кошика =====" << endl;
    cart.add_to_cart(&product1);
    cart.add_to_cart(&product2);
    cart.add_to_cart(&product3);

    // Виводимо інформацію про товари в кошику
    cout << "\n===== Товари у кошику =====" << endl;
    cart.show_cart();

    // Видаляємо товар із кошика
    cout << "\n===== Видаляємо товар із кошика =====" << endl;
    cart.remove_from_cart(&product2);
    cart.show_cart();

    return 0;
}

