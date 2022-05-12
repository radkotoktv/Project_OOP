#pragma once
#include <fstream>
class Book {
private:
	char* author;
	char* title;
	char* text;
	char* description;
	int rating;
	int ISBN;

public:
	void copyString(char*& destination, const char* source);
	void deallocate();
	void copy(const Book& other);
	Book();
	Book(const char* author, const char* title, const char* text, const char* description, const int rating, const int ISBN);
	Book(const Book& other);

	Book& operator = (const Book& other);

	void setAuthor(const char* author);
	void setTitle(const char* title);
	void setText(const char* text);
	void setDescription(const char* description);
	void setRating(const int rating);
	void setISBN(const int ISBN);
	const char* getAuthor() const;
	const char* getTitle() const;
	const char* getText() const;
	const char* getDescription() const;
	const int getRating() const;
	const int getISBN() const;

	void print() const;

	~Book();
};
