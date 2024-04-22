#include <iostream>
using namespace std;

class Movie {
protected:
    string name;
    string genre;
    string director;
    float duration;
    float shootingTime;
    float postProductionTime;

public:
    Movie() {
        name = " ";
        genre = " ";
        director = "";
        duration = 0.0;
        shootingTime = 0.0;
        postProductionTime = 0.0;
    }

    Movie(string name, string genre, string director, float duration, float shootingTime, float postProductionTime) {
        this->name = name;
        this->genre = genre;
        this->director = director;
        this->duration = duration;
        this->shootingTime = shootingTime;
        this->postProductionTime = postProductionTime;
    }

    virtual float estimatedCost() = 0;

    void printMovieInfo() {
        cout << "Name: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Shooting Time: " << shootingTime << " hours" << endl;
        cout << "Post Production Time: " << postProductionTime << " hours" << endl;
    }

    virtual void printMostImportantInfo() {
        cout << "Name: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Director: " << director << endl;
        cout << "Shooting Time: " << shootingTime << " hours" << endl;
    }

    void addMovie() {
        cout << "Enter movie name: ";
        cin >> name;
        cout << "Enter genre: ";
        cin >> genre;
        cout << "Enter director: ";
        cin >> director;
        cout << "Enter duration (in hours): ";
        cin >> duration;
        cout << "Enter shooting time (in hours): ";
        cin >> shootingTime;
        cout << "Enter post production time (in hours): ";
        cin >> postProductionTime;
    }
};

class AnimatedMovie : public Movie {
public:
    AnimatedMovie() : Movie("", "", "", 0, 0, 0) {}
    AnimatedMovie(string name, string genre, string director, float duration, float shootingTime, float postProductionTime)
        : Movie(name, genre, director, duration, shootingTime, postProductionTime) {}

    float estimatedCost() {
        return postProductionTime * 1000;
    }

    void printMostImportantInfo() {
        cout << "Name: " << name << endl;
        cout << "Director: " << director << endl;
        cout << "Estimated Cost: $" << estimatedCost() << endl;
        cout << "Post Production Time: " << postProductionTime << " hours" << endl;
    }
};


class ActionMovie : public Movie {
public:
    ActionMovie() : Movie("", "", "", 0, 0, 0) {}

    ActionMovie(string name, string genre, string director, float duration, float shootingTime, float postProductionTime)
        : Movie(name, genre, director, duration, shootingTime, postProductionTime) {}

    float estimatedCost() {
        return shootingTime * 800;
    }
};

int main() {
    char choice;
    AnimatedMovie animated;
    ActionMovie action;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add a new Animated Movie" << endl;
        cout << "2. Add a new Action Movie" << endl;
        cout << "3. Show Animated Movie Information" << endl;
        cout << "4. Show Action Movie Information" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "\nAdding a new Animated Movie:" << endl;
            animated.addMovie();
            break;
        case '2':
            cout << "\nAdding a new Action Movie:" << endl;
            action.addMovie();
            break;
        case '3':
            cout << "\nAnimated Movie Information:" << endl;
            animated.printMovieInfo();
            cout << "Estimated Cost: $" << animated.estimatedCost() << endl;
            cout << "Most Important Information:" << endl;
            animated.printMostImportantInfo();
            break;
        case '4':
            cout << "\nAction Movie Information:" << endl;
            action.printMovieInfo();
            cout << "Estimated Cost: $" << action.estimatedCost() << endl;
            cout << "Most Important Information:" << endl;
            action.printMostImportantInfo();
            break;
        case '5':
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != '5');

    return 0;
}
