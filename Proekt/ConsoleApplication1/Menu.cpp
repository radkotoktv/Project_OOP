#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "Admin.h"
#include "Book.h"
#include "Library.h"
#include <iostream>
void Menu::deallocate() {
	delete[] this->search;
}
void Menu::copyString(char*& destination, const char* source) {
	destination = new (std::nothrow) char[strlen(source) + 1];
	if (!destination) {
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(destination, source);
}
Menu::Menu() {
	this->choice = 0;
	this->search = nullptr;
}
Menu::Menu(const int choice, const char* search) {
	this->choice = choice;
	copyString(this->search, search);
}
Menu::Menu(const Menu& other) {
	this->choice = other.choice;
	copyString(this->search, other.search);
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
			default: std::cout << "Please enter a number between 1-6!";
				break;
			}
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
			switch (choice) {
			case 1: sortList(); break;
			case 2: findBook(); break;
			case 3: printBook(); break;
			case 4:
				std::cout << "Logging out...";
				return;
				break;
			default: std::cout << "Please enter a number between 1-4!";
				break;
			}
		}
	}
}
void Menu::sortList() {
	this->library.printLibraryInfo();
}
void Menu::findBook() {
	delete[] this->search;
	char searchBuffer[100];
	std::cout << "Please enter author: "; std::cin >> searchBuffer;
	this->search = new char[strlen(searchBuffer) + 1];
	strcpy(this->search, searchBuffer);
	std::ifstream database("database.txt", std::ios::app);
	if (database.peek() != std::ifstream::traits_type::eof()) {
		if (!database.is_open()) {
			std::cout << "Problem while opening the file" << std::endl;
			return;
		}
		char tempLine[100];
		int rowNumber = 0;
		while (!database.eof()) {
			database.getline(tempLine, 100);
			if ((strcmp(tempLine, this->search) == 0) && (rowNumber % 6 == 0)) {
				Book book;
				int counter = 0;
				while (counter < 6) {
					switch (counter)
					{
					case 0:
						book.setAuthor(tempLine);
						break;
					case 1:
						book.setTitle(tempLine);
						break;
					case 2:
						book.setText(tempLine);
						break;
					case 3:
						book.setDescription(tempLine);
						break;
					case 4:
						book.setRating(tempLine);
						break;
					case 5:
						book.setISBN(tempLine);
						break;
					}
					database.getline(tempLine, 100);
					counter++;
				}
				book.print();
				return;
			}
			rowNumber++;
		}
		std::cout << "No book with that author found." << std::endl;
		return;
	}
}
void Menu::addBookToLibrary() {
	std::cin >> this->book;
	this->library.addBook(this->book);
	this->library.saveBook(this->book);
}
void Menu::removeBookFromLibrary() {
	delete[] this->search;
	char searchBuffer[100];
	std::cout << "Please enter book name: "; std::cin >> searchBuffer;
	this->search = new char[strlen(searchBuffer) + 1];
	strcpy(this->search, searchBuffer);

	this->library.removeBookFromLibrary(this->search);
	this->library.removeBookFromFile(this->search);
}
void Menu::printBook() {
	//std::ifstream bookText("bookText.txt", std::ios::app); 
	//if (!bookText.is_open()) {
	//	std::cout << "Problem while opening the file!" << std::endl;
	//	return;
	//}
	//char ch;
	//while (!bookText.eof()) {
	//	bookText.get(ch);
	//	std::cout << ch;
	//}
	//bookText.close();
	std::cout << "printBook" << std::endl;
}
Menu::~Menu() {
	this->deallocate();
}