#include <iostream>
#include <cstring>

class Set {
private:
    char* characters;
    int size;
    
public:
    
    Set(){
        characters = nullptr;
        size = 0;
    }
    
    Set(const char* input) {
            if (input) {
                size = strlen(input);
                characters = new char[size + 1];
                strcpy(characters, input);
            } else {
                characters = nullptr;
                size = 0;
            }
        }
    
    bool box(char c) const {
           if (characters) {
               for (int i = 0; i < size; ++i) {
                   if (characters[i] == c) {
                       return true;
                   }
               }
           }
           return false;
       }

    
   /* void tm(const Set& other) {
        // створюємо новий буфер розмір якого дорівнює сумі розмірів 2х обєктів
        auto newSize = size + other.size + 1;
        char* buffer = new char[newSize];
        
        // заповнюємо новий буфер нулями (ініціализація)
        std::memset(buffer, 0, newSize);
        
        // спочатку копіюємо буфер першого (this) обєкта в новий буфер
        std::memcpy(buffer, characters, size);
        
        // потім копіюємо в "хвіст" буфер другого обєкта
        std::memcpy(buffer + size, other.characters, other.size);
        
        // не забуваємо підчищати за собою: тобно видаляти буфери які створили коли вони вже  не треба
        delete buffer;
    }*/
    
    Set add(const Set& other) {
        // створюємо новий буфер розмір якого дорівнює сумі розмірів 2х обєктів
        auto newSize = size + other.size + 1;
        char* buffer = new char[newSize];
        
        // заповнюємо новий буфер нулями (ініціализація)
        std::memset(buffer, 0, newSize);
        
        // спочатку копіюємо буфер першого (this) обєкта в новий буфер
        std::memcpy(buffer, characters, size);
        
        // потім копіюємо в "хвіст" буфер другого обєкта
        std::memcpy(buffer + size, other.characters, other.size);
        
        Set result(buffer);
        
        // не забуваємо підчищати за собою: тобно видаляти буфери які створили коли вони вже  не треба
        delete[] buffer;
            
        return result;
    }
    
    
    Set f1(const Set& other){
        
        
        return Set();
    }
    
    
    
};



// реалізуйти метод, який приймає інший об'єкт класу Set і повертає нову множину, що містить всі елементи з обох множин без дублювання



// реалізуйти метод, що повертає нову множину, яка містить елементи, що є у першій множині, але відсутні у другій

malloc();
memcpy();
free();
