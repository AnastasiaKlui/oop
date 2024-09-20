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
};


#endif /* Movie_hpp */
