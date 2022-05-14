#include "Library.h"
#include <cassert>
void Library::copy(const Library& other) {
    this->books = new (std::nothrow) Book[other.capacity];
    if (!this->books) {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for (std::size_t i = 0; i < other.size; ++i) {
        this->books[i] = other.books[i];
    }
    this->capacity = other.capacity;
    this->size = other.size;
}
void Library::deallocate() {
    delete[] this->books;
}
void Library::resize() {
    Book* newBooks = new (std::nothrow) Book[this->capacity * INCREASE_STEP];
    if (!newBooks) {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < this->size; ++i) {
        newBooks[i] = this->books[i];
    }

    this->deallocate();
    this->books = newBooks;
    this->capacity *= INCREASE_STEP;
}
int Library::getBookIndex(const char* bookName) {
    assert(bookName != nullptr);

    for (std::size_t i = 0; i < this->size; ++i) {
        if (strcmp(bookName, this->books[i].getTitle()) == 0) return i;
    }
    return -1;
}
Library::Library() {
    INCREASE_STEP = 2;
    INITIAL_CAPACITY = 2;
    this->books = new (std::nothrow) Book[INITIAL_CAPACITY];
    if (!this->books) {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
}
Library::Library(const Library& other) {
    this->copy(other);
}
Library& Library::operator = (const Library& other) {
    if (this != &other) {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}
Library::~Library() {
    this->deallocate();
}
void Library::addBook(const Book& bookToAdd) {
    if (this->getBookIndex(bookToAdd.getTitle()) == -1) {
        if (this->size == this->capacity) {
            this->resize();
        }
        this->books[this->size++] = bookToAdd;
        std::ofstream database("database.txt", std::ios::app);
        if (!database.is_open()) {
            std::cout << "Problem while opening the file!" << std::endl;
            return;
        }
        database << bookToAdd.getAuthor() << std::endl;
        database << bookToAdd.getTitle() << std::endl;
        database << bookToAdd.getText() << ".txt" << std::endl;
        database << bookToAdd.getDescription() << std::endl;
        database << bookToAdd.getRating() << "/10" << std::endl;
        database << bookToAdd.getISBN() << std::endl;
        database.close();
    }
}
void Library::printLibraryInfo() {
    for (std::size_t i = 0; i < this->size; ++i) {
        this->books[i].print();
        std::cout << std::endl;
    }
}
void Library::printFileInfo() {
    std::ifstream database("database.txt", std::ios::app);
    if (database.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "The library is empty.";
    }
    else {
        if (!database.is_open()) {
            std::cout << "Problem while opening the file" << std::endl;
            return;
        }
        char tempLine[100];
        while (!database.eof()) {
            database.getline(tempLine, 100);
            std::cout << tempLine << std::endl;
        }
    }
    database.close();
}
void Library::addFileToLibrary() {
    std::ifstream database("database.txt", std::ios::app);
    if (!database.is_open()) {
        std::cout << "Problem while opening the file" << std::endl;
        return;
    }
    char tempLine[100];
    int counter;
    for (std::size_t i = 0; i < this->size; ++i) {
        counter = 0;
        while (counter <= 6) {
            database.getline(tempLine, 100);
            database >> this->books[i];
            counter++;
        }
    }
    database.close();
}