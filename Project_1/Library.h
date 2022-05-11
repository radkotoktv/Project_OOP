#pragma once
#include "Book.h"
class Library {
private:
	Book* books;
	std::size_t size;
	std::size_t capacity;
	std::size_t startCapacity;
	std::size_t step;

	void deallocate();
	void resize();

public:
	Library();
	Library(const Library& other);
	~Library();

	int getBookIndex(const char* bookName);
	void addBook(Book& bookToAdd);
	void print();
};