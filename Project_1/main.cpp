#include <fstream>
#include <iostream>
#include "Book.h"
#include "Admin_Settings.h"
int main() {
	Book kniga("Ivan Vazov", "Pod Igoto", "Texta na Pod Igoto", "Stranno", 5, 1234);
	std::cout << isAdmin();
}