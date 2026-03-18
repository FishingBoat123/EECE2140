#include <iostream>
using namespace std;

class Movie
{
    private:
    string title;
    int year;
    string director;

    public:
    Movie() : title("Unknown"), year(0), director("Unknown") {}

    void setTitle(string title) {this->title = title;}
    void setYear(int year) {this->year = year;}
    void setDirector(string director) {this->director = director;}

    string getTitle() {return title;}
    int getYear() {return year;}
    string getDirector() {return director;}

    void display()
    {
        cout << "\n======Movie Information======\n";
        cout << "Title: " << title;
        cout << "\nYear: " << year;
        cout << "\nDirector: " << director << endl;;
    }

};

int main()
{
    Movie MyFavoriteMovie;
    MyFavoriteMovie.setTitle("Inception");
    MyFavoriteMovie.setYear(2010);
    MyFavoriteMovie.setDirector("Christopher Nolan");
    MyFavoriteMovie.display();

    return 0;
}