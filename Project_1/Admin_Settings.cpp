#define NUMBER_OF_ATTEMPTS 5
char password[6] = "Pesho";
#include <iostream>
#include <cstring>
#include "Admin_Settings.h"
bool isAdmin() {
	char attempt[100] = " ";
	char choice = 'Y';
	int counter = NUMBER_OF_ATTEMPTS - 1;
	while (counter >= 0 && (strcmp(attempt, password) != 0) && (choice == 'Y' || choice == 'y')) {
		std::cout << "Enter password for administrator privileges or \"USER\" for user: "; std::cin >> attempt;
		if ((strcmp(attempt, "USER") == 0) || (strcmp(attempt, "user") == 0)) {
			std::cout << "Granting user privileges.";
			return false;
		}
		else if (strcmp(attempt, password) != 0 && counter != 0) {
			std::cout << "Incorrect password! You have " << counter-- << " attempt(s) left. Try again? (Y/N): ";
			std::cin >> choice;
		}
		else if (counter == 0) counter--;
	}
	if (counter < 0) {
		std::cout << "You have run out of attempts. Granting user privileges.";
		return false;
	}
	else if (choice == 'N' || choice == 'n') {
		std::cout << "Granting user privileges.";
		return false;
	}
	else {
		std::cout << "Congratulations! Granting administrator privileges!";
		return true;
	}
}