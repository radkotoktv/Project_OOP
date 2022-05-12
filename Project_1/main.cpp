#include <fstream>
#include <iostream>
#include "Book.h"
#include "Admin.h"
#include "Library.h"
#include "Menu.h"
int main() {
	Book kniga1("Ivan Vazov", "Pod Igoto", "Texta_na_Pod_Igoto.txt", "Stranno", 5, 1234);
	Book kniga2("Hristo Botev", "Na Proshtavane", "Texta_na_na_Proshtavane.txt", "Gotino", 10, 4321);
	Book kniga3("Aleko Konstantinov", "Bai Ganio", "Texta_na_Bai_Ganio.txt", "Bulgarsko", 9, 666);
	Book kniga4("Kireto99", "Kak da oceleesh v Lulin", "Texta_na_Kireto.txt", "Lulindjiisko", 1, 2);
	//Book _kniga;
	//Admin user;
	//user.isAdmin();
	//Menu menu;
	Library biblioteka;
	biblioteka.addBook(kniga1);
	biblioteka.addBook(kniga2);
	biblioteka.addBook(kniga3);
	biblioteka.addBook(kniga4);
	biblioteka.printLibraryInfo();
}