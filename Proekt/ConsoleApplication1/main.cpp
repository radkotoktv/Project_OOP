#include <fstream>
#include <iostream>
#include "Book.h"
#include "Admin.h"
#include "Library.h"
#include "Menu.h"
int main() {
	Menu menu;
	menu.printMenu();
	return 0;
	//Book kniga;
 //   std::ifstream database("database.txt", std::ios::app);
 //   if (!database.is_open()) {
 //       std::cout << "Problem while opening the file" << std::endl;
 //       return 1;
 //   }
 //   database >> kniga;
 //   database.close();
 //   kniga.print();
}