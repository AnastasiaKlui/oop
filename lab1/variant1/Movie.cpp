#include <stdio.h>
#include <iostream>
#include "Movie.hpp"


void Movie::setTitle(const std::string&title) {
    this->title = title;
}
void Movie::setDirector(const std::string&director) {
    this->director = director;
}
void Movie::setYear(int year) {
    this->year = year;
}
void Movie::setDuration(int duration) {
    this->duration = duration;
}



std::string Movie::getTitle() const {
    return title;
}
std::string Movie::getDirector() const {
    return director;
}
int Movie::getYear() const {
    return year;
}
int Movie::getDuration() const {
    return duration;
}

