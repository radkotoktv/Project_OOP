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
void Book::print() {
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Title: " << this->title << std::endl;
    std::cout << "Text file: " << this->text << std::endl;
    std::cout << "Description: " << this->description << std::endl;
    std::cout << "Rating: " << this->rating << "/10" << std::endl;
    std::cout << "ISBN: " << this->ISBN << std::endl;
    std::cout << "________________________" << std::endl;
}
std::istream& operator >> (std::istream& in, Book& other) {
    return in;
}
std::ostream& operator << (std::ostream& out, const Book& other) {
    std::ofstream importantFile("importantInfo.txt", std::ios::app);
    importantFile << other.author << std::endl;
    importantFile << other.title << std::endl;
    importantFile << other.text << std::endl;
    importantFile << other.description << std::endl;
    importantFile << other.rating << std::endl;
    importantFile << other.ISBN << std::endl;
    importantFile << "______________________________" << std::endl;
    importantFile.close();
    return out;
}