#include "movie.h"
#include <string.h>
#include <stdlib.h>

void setMovieTitle(Movie *movie, const char* title) {
  size_t size = strlen(title);
    movie->title = (char*)malloc(size + 1);
  strcpy(movie->title, title);
}

void setMovieDirector(Movie *movie, const char* director) {
    size_t size = strlen(director);
    movie->director = (char*)malloc(size + 1);
  strcpy(movie->director, director);
}

void setMovieYear(Movie *movie, int year) {
    movie->year = year;
}

void setMovieDuration(Movie *movie, int duration) {
    movie->duration = duration;
}
