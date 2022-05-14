#include <fstream>
#include <iostream>
#include "Book.h"
#include "Admin.h"
#include "Library.h"
#include "Menu.h"
int main() {
 //   Book book;
	Menu menu;
	menu.printMenu();
	return 0;
 //   std::ifstream database("database.txt", std::ios::app);
 //   if (database.peek() == std::ifstream::traits_type::eof()) {
 //       std::cout << "The library is empty.";
 //   }
 //   else {
 //       if (!database.is_open()) {
 //           std::cout << "Problem while opening the file" << std::endl;
 //           return 1;
 //       }
 //       char tempLine[100];
 //       while (!database.eof()) {
 //           database.getline(tempLine, 100);
 //           database >> book;
 //       }
 //   }
 //   database.close();
 //   book.print();
 //   return 0;
}