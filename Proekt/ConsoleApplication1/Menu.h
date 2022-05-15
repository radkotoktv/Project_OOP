#pragma once
#include "Book.h"
#include "Library.h"
class Menu {
private:
	int choice;
	char* search;
	Book book;
	Library library;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Menu();
	Menu(const int choice, const char* search);
	Menu(const Menu& other);
	void printMenu();
	void sortList();
	void findBook();
	void addBookToLibrary();
	void removeBookFromLibrary();
	void printBook();
	~Menu();
};