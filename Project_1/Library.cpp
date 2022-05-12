#include "Library.h"
#include "Book.h"
#include <iostream>
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
	Book* newBooks = new (std::nothrow) Book[this->capacity * this->multiple];
	if (!newBooks) {
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	for (std::size_t i = 0; i < this->size; ++i) {
		newBooks[i] = this->books[i];
	}
	deallocate();
	this->books = newBooks;
	this->capacity *= multiple;
}
int Library::getBookIndex(const char* bookName) {
	assert(bookName != nullptr);
	for (std::size_t i = 0; i < this->size; ++i) {
		if (strcmp(bookName, this->books[i].getTitle()) == 0) return i;
	}
	return -1;
}
Library::Library() {
	this->start = 2;
	this->multiple = 2;
	this->books = new (std::nothrow) Book[this->start];
	if (!this->books) {
		std::cout << "Memory problem" << std::endl;
		return;
	}
	this->capacity = this->start;
	this->size = 0;
}
Library::Library(const Library& other) {
	this->copy(other);
}
Library::~Library() {
	this->deallocate();
}
void Library::addBook(Book& bookToAdd) {
	if (this->getBookIndex(bookToAdd.getTitle()) == -1) {
		if (this->size == this->capacity) {
			this->resize();
		}
		this->books[this->size++] = bookToAdd;
	}
}
void Library::printLibraryInfo() {
	for (std::size_t i = 0; i < this->size; ++i) {
		std::cout << "BOOK #" << i + 1 << std::endl;
		this->books[i].print();
	}
}