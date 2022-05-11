#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
#include <cstring>
#include <fstream>
#include "Book.h"
void Book::copyString(char*& destination, const char* source) {
    destination = new char[strlen(source) + 1];
    if (!destination) {
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
}
Book::Book() {
    this->author = nullptr;
    this->title = nullptr;
    this->text = nullptr;
    this->description = nullptr;
    this->rating = 0;
    this->ISBN = 0;
}
Book::Book(const Book& other) {
    assert(other.author != nullptr);
    assert(other.title != nullptr);
    assert(other.text != nullptr);
    assert(other.description != nullptr);
    assert(other.rating != 0);
    assert(other.ISBN != 0);
    this->author = other.author;
    this->title = other.title;
    this->text = other.text;
    this->description = other.description;
    this->rating = other.rating;
    this->ISBN = other.ISBN;
}
Book::Book(const char* author, const char* title, const char* text, const char* description, int rating, long long int ISBN) {
    copyString(this->author, author);
    copyString(this->title, title);
    copyString(this->text, text);
    copyString(this->description, description);
    this->rating = rating;
    this->ISBN = ISBN;
}
Book::~Book() {
    this->deallocate();
}
void Book::setAuthor(const char* author) {
    copyString(this->author, author);
}
const char* Book::getAuthor() {
    return this->author;
}
void Book::setTitle(const char* title) {
    copyString(this->title, title);
}
const char* Book::getTitle() {
    return this->title;
}
void Book::setText(const char* text) {
    copyString(this->text, text);
}
const char* Book::getText() {
    return this->text;
}
void Book::setDescription(const char* description) {
    copyString(this->description, description);
}
const char* Book::getDescription() {
    return this->description;
}
void Book::setRating(int rating) {
    this->rating = rating;
}
int Book::getRating() {
    return this->rating;
}
void Book::setISBN(long long int ISBN) {
    this->ISBN = ISBN;
}
long long int Book::getISBN() {
    return this->ISBN;
}
std::istream& operator >> (std::istream& in, Book& other) {
    return in;
}
std::ostream& operator << (std::ostream& out, const Book& other) {
    std::cout << "Author: " << other.author << std::endl;
    std::cout << "Title: " << other.title << std::endl;
    std::cout << "Text: " << other.text << std::endl;
    std::cout << "Description: " << other.description << std::endl;
    std::cout << "Rating: " << other.rating << "/10" << std::endl;
    std::cout << "ISBN: " << other.ISBN << std::endl;
    return out;
}