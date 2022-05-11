#include "Library.h"
#include <iostream>
#include <cassert>
void Library::deallocate() {
	delete[] this->books;
}
void Library::resize() {
	Book* newBooks = new (std::nothrow) Book[this->capacity * this->step];
	if (!newBooks) {
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	for (std::size_t i = 0; i < this->size; ++i) {
		newBooks[i] = this->books[i];
	}
	this->deallocate();
	this->books = newBooks;
	this->capacity *= this->step;
}
Library::Library() {
	this->startCapacity = 2;
	this->step = 2;
	this->books = new (std::nothrow) Book[startCapacity];
	if (!this->books) {
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	this->capacity = startCapacity;
	this->size = 0;
}
Library::Library(const Library& other) {
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
Library::~Library() {
	this->deallocate();
}
int Library::getBookIndex(const char* bookTitle) {
	assert(bookTitle != nullptr);
	for (std::size_t i = 0; i < this->size; ++i) {
		if (strcmp(bookTitle, this->books[i].getTitle()) == 0) {
			return i;
		}
	}
	return -1;
}
void Library::addBook(Book& bookToAdd) {
	if (this->getBookIndex(bookToAdd.getTitle()) == -1) {
		if (this->size == this->capacity) {
			this->resize();
		}
		this->books[this->size++] = bookToAdd;
	}
}
void Library::print() {
	for (std::size_t i = 0; i < this->size; ++i) {
		std::cout << "BOOK#" << i + 1 << std::endl;
		this->books[i].print();
	}
}