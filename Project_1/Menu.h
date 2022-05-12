#pragma once
class Menu {
private:
	int choice;

public:
	Menu();
	Menu(const int choice);
	void sortList();
	void findBook();
	void addBookToLibrary();
	void removeBookFromLibrary();
	void printBook();
};