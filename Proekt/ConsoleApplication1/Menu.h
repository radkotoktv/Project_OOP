#pragma once
#include "Book.h"
#include "Library.h"
class Menu {
private:
	int choice;
	Book book;
	Library library;

public:
	Menu();
	Menu(const int choice);
	void printMenu();
	void sortList();
	void findBook();
	void addBookToLibrary();
	void removeBookFromLibrary();
	void printBook();
};