#ifndef LIBRARY_H
#define LIBRARY_H

#include<string>
#include<vector>
#include "Book.h"

class Library
{
    public:
        Library();
        void addBook(std::string , std::string);
        void displayAllBooks() const;
        void borrowBook(int);
        void returnBook(int);
        void addStudentMembership(std::string ,std::string);
        void viewMembers() const;
        int findBookIndex(int) const;
        virtual ~Library();



    protected:

    private:
    std::vector<Book> books;
    int nextBookId = 0;
    std::vector<std::string> studentMemberships;
};

#endif // LIBRARY_H
