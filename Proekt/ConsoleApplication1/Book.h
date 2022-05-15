#pragma once
#include <fstream>
class Book {
private:
	char* author;
	char* title;
	char* text;
	char* description;
	char* rating;
	char* ISBN;

public:
	void copyString(char*& destination, const char* source);
	void deallocate();
	void copy(const Book& other);
	Book();
	Book(const char* author, const char* title, const char* text, const char* description, const char* rating, const char* ISBN);
	Book(const Book& other);

	Book& operator = (const Book& other);

	void setAuthor(const char* author);
	void setTitle(const char* title);
	void setText(const char* text);
	void setDescription(const char* description);
	void setRating(const char* rating);
	void setISBN(const char* ISBN);
	const char* getAuthor() const;
	const char* getTitle() const;
	const char* getText() const;
	const char* getDescription() const;
	const char* getRating() const;
	const char* getISBN() const;

	void print() const;

	friend std::istream& operator >> (std::istream& in, Book& other);

	~Book();
};
