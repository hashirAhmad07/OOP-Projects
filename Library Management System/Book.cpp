#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(){}
Book::Book(string title, string author, int id)
    : title(title), author(author), id(id), available(true)
{}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

// commenting to show Inline Method Extraction

//void Book::displayInfo() const
//{
//    displayBasicInfo();       // Extract Method
//    displayAvailability();
//    cout << "Book ID: " << id << ", Title: " << title << ", Author: " << author;
//    displayAvailability();
//}

// Extract Method Applying
void Book::displayAvailability() const {
    if (available) {
        cout << " (Available)" << endl;
    } else {
        cout << " (Not Available)" << endl;
    }
}

void Book::displayBasicInfo() const {
    cout << "Book ID: " << id << ", Title: " << title << ", Author: " << author;
    displayAvailability();
}

int Book::getId() const {
    return id;
}

void Book::borrowBook()
{
    if (available)
    {
        available = false;
        cout << "Book successfully borrowed." <<  endl;
    }
    else
    {
        cout << "Sorry, the book is not available for borrowing." <<  endl;
    }
}

void Book::returnBook()
{
    if (!available)
    {
        available = true;
        cout << "Book successfully returned." <<  endl;
    }
    else
    {
        cout << "This book is already available in the library." <<  endl;
    }
}

Book::~Book()
{
    //dtor
}
