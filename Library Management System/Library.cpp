#include "Library.h"
#include <iostream>
using namespace std;

Library::Library()
{
    //ctor
}


void Library::addBook(string title, string author)
{
    Book newBook(title, author, nextBookId++);
    books.push_back(newBook);
    cout << "Book added to the library." <<  endl;
}

void Library::displayAllBooks() const
{
    cout << "Library Catalog:" << endl;
    for (const Book& book : books) {
        cout << "Book ID: " << book.getId() << ", Title: " << book.getTitle()
             << ", Author: " << book.getAuthor();
        book.displayAvailability();
    }
}

//Replace with method object
void Library::borrowBook(int bookId)
{
     int foundBookIndex = findBookIndex(bookId);
    if (foundBookIndex != -1) {
        books[foundBookIndex].borrowBook();
    } else {
        cout << "Book with ID " << bookId << " not found in the library." << endl;
    }
}

// Appling Technique Removing Assignment to parameter
int Library::findBookIndex(int bookId) const {
    for (int i = 0; i < books.size(); ++i) {
        if (bookId == books[i].getId()) {
            return i;
        }
    }
    return -1;
}

void Library::returnBook(int bookId)
{
    for (Book& book : books)
    {
        if (bookId == bookId && bookId >= 0 && bookId < books.size())
        {
            book.returnBook();
            return;
        }
    }
    cout << "Book with ID " << bookId << " not found in the library." <<  endl;
}

void Library::addStudentMembership(string studentName, string studentId)
{
    if (studentName.empty() || studentId.empty())
    {
         cout << "Invalid student information. Membership not created." <<  endl;
        return;
    }

    for (const string& id : studentMemberships)
    {
        if (id == studentId)
        {
             cout << "Student with ID " << studentId << " is already a member." <<  endl;
            return;
        }
    }

    studentMemberships.push_back(studentId);
    cout << "Student membership added successfully. Welcome, " << studentName << "!" <<  endl;
}

void Library::viewMembers() const {
    if (studentMemberships.empty()) {
         cout << "No members added yet." <<  endl;
    } else {
         cout << "Members in the library:" <<  endl;
        for (const  string& memberId : studentMemberships) {
             cout << "Member ID: " << memberId <<  endl;
        }
    }
}


Library::~Library()
{
    //dtor
}
