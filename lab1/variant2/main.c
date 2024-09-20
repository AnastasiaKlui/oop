#include "movie.h"
#include <stdio.h>\

int main(void) {
  Movie movie;

    setMovieTitle(&movie, "Bad Boys");
    setMovieDirector(&movie, "Майкл Бей");
    setMovieYear(&movie, 1995);
    setMovieDuration(&movie, 118);
    printf("title: %s\ndirector: %s\nyear: %d\nduration: %d\n", movie.title, movie.director, movie.year, movie.duration);
}
