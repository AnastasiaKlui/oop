#include <iostream>
#include <string>

// Клас Movie (з лабораторної роботи №1)
class Movie {
private:
    std::string title;
    std::string director;
    int year;
    int duration;

public:
    Movie(const std::string& t, const std::string& d, int y, int dur)
        : title(t), director(d), year(y), duration(dur) {}

    void setTitle(const std::string& t) { title = t; }
    std::string getTitle() const { return title; }

    void setDirector(const std::string& d) { director = d; }
    std::string getDirector() const { return director; }

    void setYear(int y) { year = y; }
    int getYear() const { return year; }

    void setDuration(int dur) { duration = dur; }
    int getDuration() const { return duration; }

    void printInfo() const {
        std::cout << "Title: " << title << ", Director: " << director
                  << ", Year: " << year << ", Duration: " << duration << " mins\n";
    }
};

// Клас Actor
class Actor {
private:
    std::string name;
    int age;

public:
    Actor(const std::string& n, int a) : name(n), age(a) {}

    void setName(const std::string& n) { name = n; }
    std::string getName() const { return name; }

    void setAge(int a) { age = a; }
    int getAge() const { return age; }

    void printInfo() const {
        std::cout << "Actor: " << name << ", Age: " << age << "\n";
    }
};

// Клас MovieWithActor (включення)
class MovieWithActor {
private:
    Movie movie;  // Композиція: включає об'єкти Movie і Actor
    Actor actor;

public:
    MovieWithActor(const std::string& title, const std::string& director, int year, int duration,
                   const std::string& actorName, int actorAge)
        : movie(title, director, year, duration), actor(actorName, actorAge) {}

    void printMovieInfo() const {
        movie.printInfo();
        actor.printInfo();
    }
};

// Клас MovieWithActorReference (посилання)
class MovieWithActorReference {
private:
    Movie* movie;   // Посилання на об'єкт Movie
    Actor* actor;   // Посилання на об'єкт Actor

public:
    MovieWithActorReference(Movie* m, Actor* a) : movie(m), actor(a) {}

    void printMovieInfo() const {
        movie->printInfo();
        actor->printInfo();
    }
};

// Клас SpecialMovie (наслідування)
class SpecialMovie : public Movie {
private:
    std::string genre;

public:
    SpecialMovie(const std::string& t, const std::string& d, int y, int dur, const std::string& g)
        : Movie(t, d, y, dur), genre(g) {}

    void printSpecialInfo() const {
        printInfo();
        std::cout << "Genre: " << genre << "\n";
    }
};

int main() {
    // Створення об'єкта класу Movie
    Movie movie1("Inception", "Christopher Nolan", 2010, 148);
    Actor actor1("Leonardo DiCaprio", 49);
    
    // Використання композиції: MovieWithActor
    MovieWithActor movieWithActor("Inception", "Christopher Nolan", 2010, 148, "Leonardo DiCaprio", 49);
    movieWithActor.printMovieInfo();
    
    // Використання посилання: MovieWithActorReference
    MovieWithActorReference movieWithActorRef(&movie1, &actor1);
    movieWithActorRef.printMovieInfo();

    // Використання наслідування: SpecialMovie
    SpecialMovie specialMovie("Inception", "Christopher Nolan", 2010, 148, "Sci-Fi");
    specialMovie.printSpecialInfo();

    return 0;
}
