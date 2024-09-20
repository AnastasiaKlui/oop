#include "Movie.hpp"
#include <iostream>

int main(){
    Movie* myMovie = new Movie();
    
    myMovie->setTitle("Bad Boys");
    myMovie->setDirector("Майкл Бей");
    myMovie->setYear(1995);
    myMovie->setDuration(118);
    
    std::cout << "Назва фільму: " << myMovie->getTitle() << std::endl;
    std::cout << "Автор фільму: " << myMovie->getDirector() << std::endl;
    std::cout << "Рік фільму: " << myMovie->getYear() << std::endl;
    std::cout << "Тривалість фільму: " << myMovie->getDuration() << std::endl;
    
    return 0;
}
