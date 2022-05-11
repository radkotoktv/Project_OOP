#pragma once
#include <iostream>
#include <fstream>
class Admin {
private:
	char* adminPassword;
	char* attempt;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Admin();
	Admin(const Admin& other);
	Admin(const char* attempt);
	~Admin();
	bool isAdmin();
};