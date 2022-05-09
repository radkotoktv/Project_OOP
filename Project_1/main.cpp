#include <fstream>
#include <iostream>
#include "Book.h"
int main() {
	Book kniga("Ivan Vazov", "Pod Igoto", "Texta na Pod Igoto", "Stranno", 5, 1234);
	std::cout << kniga;
}