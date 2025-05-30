#include <iostream>
#include <string>
#include <map>
#include <set>
#include <array>

class Book {
private:
    std::string title;       
    std::string author;      
    std::string genre;      
    std::string zone;       
    bool isAvailable; 

public:
    Book() : title(""), author(""), genre(""), zone(""), isAvailable(true) {}

    Book(std::string a, std::string b, std::string c, std::string d, bool e)
        : title(a), author(b), genre(c), zone(d), isAvailable(e) {}

    // Геттеры
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getGenre() const { return genre; }
    std::string getZone() const { return zone; }
    bool getAvailability() const { return isAvailable; }

    // Сеттеры
    void setTitle(std::string t) { title = t; }
    void setAuthor(std::string a) { author = a; }
    void setGenre(std::string g) { genre = g; }
    void setZone(std::string z) { zone = z; }
    void setAvailability(bool available) { isAvailable = available; }

    void printInfo() const {
        std::cout << "Title: " << title << "\nAuthor: " << author
                  << "\nGenre: " << genre << "\nZone: " << zone
                  << "\nAvailable: " << (isAvailable ? "Yes" : "No") << "\n";
    }
};


std::map<std::string, Book> books;
std::set<std::string> genres;
std::array<std::string, 3> zones = {"Zone A", "Zone B", "Zone C"};

bool isValidZone(const std::string& zone) {
    for (const std::string& z : zones)
        if (z == zone) return true;
    return false;
}

void addBooks() {
    Book b1("1", "FST AGE", "RAP", "Zone A", true);
    Book b2("2", "HERONWATER", "HYPERPOP", "Zone B", true);
    Book b3("3", "9MICE", "RAP", "Zone C", true);

    books[b1.getTitle()] = b1;
    books[b2.getTitle()] = b2;
    books[b3.getTitle()] = b3;

    genres.insert(b1.getGenre());
    genres.insert(b2.getGenre());
    genres.insert(b3.getGenre());
}

void AddNewBook(const std::string& title, const std::string& author,
                    const std::string& genre, const std::string& zone) {
    std::cout << "\nTrying to add book: " << title << "\n";
    if (!isValidZone(zone)) {
        std::cout << "Invalid zone!\n";
        return;
    }

    Book newBook(title, author, genre, zone, true);
    books[title] = newBook;
    genres.insert(genre);
    std::cout << "Book added successfully.\n";
}

// Поиск и аренда
void findBook(const std::string& title) {
    std::cout << "\nSearching for book: " << title << "\n";
    auto it = books.find(title);
    if (it == books.end()) {
        std::cout << "Book not found.\n";
        return;
    }

    Book& b = it->second;
    b.printInfo();
    if (b.getAvailability()) {
        b.setAvailability(false);
        std::cout << "Book rented.\n";
    } else {
        std::cout << "Book not available.\n";
    }
}

// Удаление книги
void removeBook(const std::string& title) {
    std::cout << "\nRemoving book: " << title << "\n";
    if (books.erase(title)) {
        std::cout << "Book removed.\n";
    } else {
        std::cout << "Book not found.\n";
    }
}

// Вывод по жанру
void listByGenre(const std::string& genre) {
    std::cout << "\nBooks in genre: " << genre << "\n";
    int flag = 0;  
    for (const auto& [title, book] : books) {
        if (book.getGenre() == genre) {
            book.printInfo();
            std::cout << "----------\n";
            flag = 1; 
        }
    }
    if (flag == 0) std::cout << "No books in this genre.\n";
}

int main() {
    // Добавляем заранее заданные книги
    addBooks();

    AddNewBook("4", "Obladaet", "RAP", "Zone A");     // корректно
    AddNewBook("5", "2ho", "Shittalking", "Zone Z");     // ошибка

    // Поиск и аренда книги
    findBook("1"); // доступна
    findBook("1"); // уже арендована

    // Удаление книги
    removeBook("2");
    removeBook("2"); // повторное удаление - выдаст ошибку

    // Список книг по жанру
    listByGenre("RAP");
    listByGenre("R"); // выдаст ошибку

    return 0;
}




// Напишите программу, для моделирования работы библиотеки, в которой хранятся книги. Каждая книга представляется
// объектом класса Book, включающий название книги (title), автора (author), жанр (genre), зону хранения (zone) - одна из
// заранее определённых, статус доступности (isAvailable).
// Список зон хранения книг хранить в контейнере std::array<std::string, int>, уникальные жанры книг в контейнере
// std::set<std::string>, книги в контейнере std::map<std::string, Book>, где ключ - название книги, а значение - объект Book.
// Необходимо реализовать следующий функционал:
// 1. Добавить заранее заданные книги в библиотеку. (Присвоить жанры и зоны хранения. Жанры добавить в std::set)
// 2. Добавить новую книгу, проверяя допустимость зоны:
// a. Если зона указана неверно - вывести сообщение об ошибке.
// b. Если всё корректно -- добавить книгу в map, а жанр - в set.
// 3. Найти книгу по названию (вывести информацию о ней):
// a. Если книга доступна - арендовать её (пометить как isAvailable = false).
// b. Если недоступна - вывести сообщение.
// 4. Удалить книгу из библиотеки по названию.
// 5. Вывести список всех книг заданного жанра.