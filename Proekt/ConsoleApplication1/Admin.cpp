#define _CRT_SECURE_NO_WARNINGS
#include "Admin.h"
#include <cstring>
#include <iostream>
#include <cassert>
void Admin::copyString(char*& destination, const char* source) {
	destination = new (std::nothrow) char[strlen(source) + 1];
	if (!destination) {
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(destination, source);
}
void Admin::deallocate() {
	delete[] this->adminPassword;
	delete[] this->attempt;
}
Admin::Admin() : attempt(nullptr) {
	copyString(this->adminPassword, "Pesho");
	copyString(this->attempt, "");
}
Admin::Admin(const Admin& other) {
	copyString(this->attempt, other.attempt);
}
Admin::Admin(const char* attempt) {
	copyString(this->attempt, attempt);
}
Admin::~Admin() {
	this->deallocate();
}
bool Admin::isAdmin() {
	while (strcmp(this->attempt, "USER") != 0) {
		std::cout << "Enter password for administrator privileges or \"USER\" for user privileges: ";
		delete[] this->attempt;
		char buffer[1024];
		std::cin >> buffer;
		this->attempt = new char[strlen(buffer) + 1];
		strcpy(this->attempt, buffer);
		if (strcmp(this->attempt, "USER") == 0) std::cout << "Granting user privileges." << std::endl;
		else if (strcmp(this->attempt, this->adminPassword) != 0) std::cout << "Incorrect password! ";
		else {
			std::cout << "Congratulations! Granting administrator access!" << std::endl;
			return true;
		}
	}
	return false;
}