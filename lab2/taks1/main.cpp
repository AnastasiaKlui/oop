#include <iostream>
#include "Movie.hpp"

int main() {
    // Створення об'єкта за допомогою конструктора за замовчуванням
    Movie defaultMovie;
    // Виведення значень полів об'єкта
    std::cout << "Title: " << defaultMovie.getTitle() << std::endl;
    std::cout << "Director: " << defaultMovie.getDirector() << std::endl;
    std::cout << "Year: " << defaultMovie.getYear() << std::endl;
    std::cout << "Duration: " << defaultMovie.getDuration() << " minutes" << std::endl;
    
    // Створення об'єкта за допомогою конструктора з параметрами
    Movie myMovie("Bad boys", "Adil El Arbi Bilall Fallah", 2024, 169);
    // Виведення значень полів об'єкта
    std::cout << "Title: " << myMovie.getTitle() << std::endl;
    std::cout << "Director: " << myMovie.getDirector() << std::endl;
    std::cout << "Year: " << myMovie.getYear() << std::endl;
    std::cout << "Duration: " << myMovie.getDuration() << " minutes" << std::endl;
    
    //Створіть ще один об'єкт, скопіюйте значення з першого об'єкта за допомогою копіюючого конструктора
    Movie copiedMovie(myMovie);
    // Виведення значень полів copiedMovie
    std::cout << "Copied Movie:" << std::endl;
    std::cout << "Title: " << copiedMovie.getTitle() << std::endl;
    std::cout << "Director: " << copiedMovie.getDirector() << std::endl;
    std::cout << "Year: " << copiedMovie.getYear() << std::endl;
    std::cout << "Duration: " << copiedMovie.getDuration() << " minutes" << std::endl;
    
    return 0;
}
