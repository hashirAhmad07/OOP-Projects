#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
    public:
        Book();
        Book(std::string, std::string, int);
//        void displayInfo() const;     remove due to refactoring
        void borrowBook();
        void returnBook();
        void displayBasicInfo() const;
        int getId() const;
        void displayAvailability() const;
        virtual ~Book();

            std::string getTitle() const;
        std::string getAuthor() const;

    protected:

    private:
    std::string title;
    std::string author;
    int id;
    bool available;
};

#endif // BOOK_H
