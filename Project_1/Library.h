#pragma once
#include "Book.h"
class Library
{
private:
    Book* books;
    std::size_t size;
    std::size_t capacity;
    std::size_t start;
    std::size_t multiple;

    void copy(const Library& other);
    void deallocate();
    void resize();
    int getBookIndex(const char* bookName);

public:
    Library();
    Library(const Library& other);
    ~Library();
    void addBook(Book& bookToAdd);
    void printLibraryInfo();
};