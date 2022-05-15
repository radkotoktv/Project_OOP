#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cassert>
#include "Book.h"
void Book::copyString(char*& destination, const char* source) {
    destination = new (std::nothrow) char[strlen(source) + 1];
    if (!destination)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(destination, source);
}
void Book::deallocate() {
    delete[] this->author;
    delete[] this->title;
    delete[] this->text;
    delete[] this->description;
    delete[] this->rating;
    delete[] this->ISBN;
}
void Book::copy(const Book& other) {
    assert(other.author != nullptr);
    assert(other.title != nullptr);
    assert(other.text != nullptr);
    assert(other.description != nullptr);
    this->copyString(this->author, other.author);
    this->copyString(this->title, other.title);
    this->copyString(this->text, other.text);
    this->copyString(this->description, other.description);
    this->copyString(this->rating, other.rating);
    this->copyString(this->ISBN, other.ISBN);
}
Book::Book() {
    this->author = nullptr;
    this->title = nullptr;;
    this->text = nullptr;;
    this->description = nullptr;;
    this->rating = nullptr;
    this->ISBN = nullptr;
}
Book::Book(const char* author, const char* title, const char* text, const char* description, const char* rating, const char* ISBN) {
    this->setAuthor(author);
    this->setTitle(title);
    this->setText(text);
    this->setDescription(description);
    this->setRating(rating);
    this->setISBN(ISBN);
}
Book::Book(const Book& other) {
    this->copy(other);
}

Book& Book::operator = (const Book& other) {
    if (this != &other) {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}

void Book::setAuthor(const char* author) {
    assert(author != nullptr);
    delete[] this->author;
    this->copyString(this->author, author);
}
void Book::setTitle(const char* title) {
    assert(title != nullptr);
    delete[] this->title;
    this->copyString(this->title, title);
}
void Book::setText(const char* text) {
    assert(text != nullptr);
    delete[] this->text;
    this->copyString(this->text, text);
}
void Book::setDescription(const char* description) {
    assert(description != nullptr);
    delete[] this->description;
    this->copyString(this->description, description);
}
void Book::setRating(const char* rating) {
    assert(rating != nullptr);
    delete[] this->rating;
    this->copyString(this->rating, rating);
}
void Book::setISBN(const char* ISBN) {
    assert(ISBN != nullptr);
    delete[] this->ISBN;
    this->copyString(this->ISBN, ISBN);
}
const char* Book::getAuthor() const {
    return this->author;
}
const char* Book::getTitle() const {
    return this->title;
}
const char* Book::getText() const {
    return this->text;
}
const char* Book::getDescription() const {
    return this->description;
}
const char* Book::getRating() const {
    return this->rating;
}
const char* Book::getISBN() const {
    return this->ISBN;
}

void Book::print() const {
    std::cout << "________________________" << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Text file: " << this->text << ".txt" << std::endl;
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Rating: " << this->rating << "/10" << std::endl;
    std::cout << "ISBN: " << this->ISBN << std::endl;
    std::cout << "________________________" << std::endl;
}
std::istream& operator >> (std::istream& in, Book& other) {

    delete[] other.author;
    char authorBuffer[100];
    std::cout << "Enter author: "; in >> authorBuffer;
    other.author = new char[strlen(authorBuffer) + 1];
    strcpy(other.author, authorBuffer);

    delete[] other.title;
    char titleBuffer[100];
    std::cout << "Enter title: "; in >> titleBuffer;
    other.title = new char[strlen(titleBuffer) + 1];
    strcpy(other.title, titleBuffer);

    delete[] other.text;
    char textBuffer[100];
    std::cout << "Enter text: "; in >> textBuffer;
    other.text = new char[strlen(textBuffer) + 1];
    strcpy(other.text, textBuffer);

    delete[] other.description;
    char descriptionBuffer[100];
    std::cout << "Enter description: "; in >> descriptionBuffer;
    other.description = new char[strlen(descriptionBuffer) + 1];
    strcpy(other.description, descriptionBuffer);

    delete[] other.rating;
    char ratingBuffer[100];
    std::cout << "Enter rating: "; in >> ratingBuffer;
    other.rating = new char[strlen(ratingBuffer) + 1];
    strcpy(other.rating, ratingBuffer);

    delete[] other.ISBN;
    char ISBNBuffer[100];
    std::cout << "Enter ISBN: "; in >> ISBNBuffer;
    other.ISBN = new char[strlen(ISBNBuffer) + 1];
    strcpy(other.ISBN, ISBNBuffer);

    return in;
}
Book::~Book() {
    this->deallocate();
}