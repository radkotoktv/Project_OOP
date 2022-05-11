#pragma once
#include <fstream>
class Book {
private:
	char* author;
	char* title;
	char* text;
	char* description;
	int rating;
	long long int ISBN;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Book();
	Book(const Book& other);
	Book(const char* author, const char* title, const char* text, const char* description, int rating, long long int ISBN);
	~Book();
	void setAuthor(const char* author);
	const char* getAuthor();
	void setTitle(const char* title);
	const char* getTitle();
	void setText(const char* text);
	const char* getText();
	void setDescription(const char* description);
	const char* getDescription();
	void setRating(int rating);
	int getRating();
	void setISBN(long long int ISBN);
	long long int getISBN();

	friend std::istream& operator >> (std::istream& in, Book& other);
	friend std::ostream& operator << (std::ostream& out, const Book& other);
};