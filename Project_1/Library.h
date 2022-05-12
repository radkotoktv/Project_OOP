#pragma once
#include "Book.h"
#include <iostream>
class Library {
private:
    Book* books;
    std::size_t size;
    std::size_t capacity;
    std::size_t INCREASE_STEP;
    std::size_t INITIAL_CAPACITY;

    void copy(const Library& other);
    void deallocate();
    void resize();
    int getBookIndex(const char* bookName);

public:
    Library();
    Library(const Library& other);
    Library& operator = (const Library& other);
    ~Library();
    void addBook(const Book& bookToAdd);
    void printLibraryInfo();
};