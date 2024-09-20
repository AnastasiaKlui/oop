#ifndef Movie_h
#define Movie_h

typedef struct Movie{
    char* title;
    char* director;
    int year;
    int duration;
} Movie;

void setMovieTitle(Movie *movie, const char* title);
void setMovieDirector(Movie *movie, const char* director);
void setMovieYear(Movie *movie, int year);
void setMovieDuration(Movie *movie, int duration);

#endif
