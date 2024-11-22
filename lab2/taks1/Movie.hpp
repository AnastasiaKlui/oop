#ifndef Movie_hpp
#define Movie_hpp

#include <string>

class Movie{
private:
    std::string title;
    std::string director;
    int year;
    int duration;
    
public:
    //задання та отримання назви фільму
    void setTitle(const std::string&title);
    std::string getTitle() const;
    
    //задання та отримання автора фільму
    void setDirector(const std::string&director);
    std::string getDirector() const;
    
    //задання та отримання рік фільму
    void setYear(int year);
    int getYear() const;
    
    //задання та отримання часу фільму
    void setDuration(int duration);
    int getDuration() const;
    
    // Конструктор за замовчуванням
    Movie() {
        title = "Unknown";
        director = "Unknown";
        year = 0;
        duration = 0;
    }
    
    // Конструктор з параметрами
    Movie(const std::string &title, const std::string &director, int year, int duration) {
        this->title = title;
        this->director = director;
        this->year = year;
        this->duration = duration;
    }
    
    // Копіюючий конструктор
    Movie(const Movie& other) {
        title = other.title;
        director = other.director;
        year = other.year;
        duration = other.duration;
    }
    
    // Деструктор
    ~Movie() {
        std::cout << "Деструктор викликаний для фільму: " << title << std::endl;
    }
};


#endif /* Movie_hpp */
