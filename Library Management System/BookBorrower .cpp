#include "BookBorrower .h"
#include "Book.h"
#include <iostream>

using namespace std;

BookBorrower ::BookBorrower(std::vector<Book>& books) : books(books) {}

//Replace with method object
void BookBorrower::borrowBook(int bookId) {
        int foundBookIndex = findBookIndex(bookId);
        if (foundBookIndex != -1) {
            books[foundBookIndex].borrowBook();
        } else {
            cout << "Book with ID " << bookId << " not found in the library." << endl;
        }
}

// need this function for above function execution
int BookBorrower::findBookIndex(int bookId) const {
        for (int i = 0; i < books.size(); ++i) {
            if (bookId == books[i].getId()) {
                return i;
            }
        }
        return -1;
    }

BookBorrower ::~BookBorrower ()
{
    //dtor
}
