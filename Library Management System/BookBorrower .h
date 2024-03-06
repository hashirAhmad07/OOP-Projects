#ifndef BOOKBORROWER _H
#define BOOKBORROWER _H

#include <vector>
// Replace Method with Method Object
#include"Book.h"
class BookBorrower
{
    public:
        BookBorrower ();
        BookBorrower(std::vector<Book>& books);
        void borrowBook(int);
        int findBookIndex(int) const;
        virtual ~BookBorrower ();

    protected:

    private:
        std::vector<Book>& books;
};

#endif // BOOKBORROWER _H
