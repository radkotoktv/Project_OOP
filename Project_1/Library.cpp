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
    }
}
void Library::printLibraryInfo() {
    std::ofstream database("database.txt");
    for (std::size_t i = 0; i < this->size; ++i) {
        std::cout << "BOOK #" << i + 1 << std::endl;
        this->books[i].print();
        database << books[i].getAuthor() << std::endl;
        database << books[i].getTitle() << std::endl;
        database << books[i].getText() << std::endl;
        database << books[i].getDescription() << std::endl;
        database << books[i].getRating() << std::endl;
        database << books[i].getISBN() << std::endl;
        database << "______________________________" << std::endl;
    }
    database.close();
}