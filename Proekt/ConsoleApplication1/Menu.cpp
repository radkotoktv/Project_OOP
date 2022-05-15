#include "Menu.h"
#include "Admin.h"
#include "Book.h"
#include "Library.h"
#include <iostream>
Menu::Menu() {
	this->choice = 0;
	this->library.getBooksFromFile();
}
Menu::Menu(const int choice) {
	this->choice = choice;
}
void Menu::printMenu() {
	Admin user;
	if (user.isAdmin()) {
		while (true) {
			std::cout << "\n\n\t MENU" << std::endl;
			std::cout << "_____________________________" << std::endl;
			std::cout << "1\t Sorted List" << std::endl;
			std::cout << "2\t Find a book" << std::endl;
			std::cout << "3\t Add a book" << std::endl;
			std::cout << "4\t Remove a book" << std::endl;
			std::cout << "5\t Read a book" << std::endl;
			std::cout << "6\t Exit the program" << std::endl;
			std::cout << "_____________________________" << std::endl;
			std::cout << "Enter 1-6: "; std::cin >> this->choice;
			if (choice > 0 && choice < 7) {
				switch (choice) {
				case 1: sortList(); break;
				case 2: findBook(); break;
				case 3: addBookToLibrary(); break;
				case 4: removeBookFromLibrary(); break;
				case 5: printBook(); break;
				case 6:
					std::cout << "Logging out...";
					return;
					break;
				}
			}
			else std::cout << "Please enter 1-6!";
		}
	}
	else {
		while (true) {
				std::cout << "\n\n\t MENU" << std::endl;
				std::cout << "_____________________________" << std::endl;
				std::cout << "1\t Sorted List" << std::endl;
				std::cout << "2\t Find a book" << std::endl;
				std::cout << "3\t Read a book" << std::endl;
				std::cout << "4\t Exit the program" << std::endl;
				std::cout << "_____________________________" << std::endl;
				std::cout << "Enter 1-4: ";  std::cin >> this->choice;
			if (choice > 0 && choice < 5) {
				switch (choice) {
				case 1: sortList(); break;
				case 2: findBook(); break;
				case 3: printBook(); break;
				case 4:
					std::cout << "Logging out...";
					return;
					break;
				}
			}
			else std::cout << "Please enter 1-4!";
		}
	}
}
void Menu::sortList() {
	this->library.printLibraryInfo();
}
void Menu::findBook() {
	std::cout << "findBook" << std::endl;
}
void Menu::addBookToLibrary() {
	std::cin >> this->book;
	this->library.addBook(this->book);
}
void Menu::removeBookFromLibrary() {
	std::cout << "removeBookFromLibrary" << std::endl;
}
void Menu::printBook() {
	std::cout << "printBook" << std::endl;
}