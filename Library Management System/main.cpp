#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

// Extract Method for Switch Statement
void displayMenu() {
    cout << "\nLibrary Management System Menu:\n";
    cout << "1. Add a Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Borrow a Book\n";
    cout << "4. Return a Book\n";
    cout << "5. Add Student Membership\n";
    cout << "6. View Students Membership\n";
    cout << "7. Exit\n";
    cout << "Enter your choice (1-7): ";
}

// Extract Method for Switch Statement
void processUserChoice(Library& library, int choice) {
    switch (choice) {
        case 1: {
            string title, author;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(title, author);
            break;
        }
        case 2:
            library.displayAllBooks();
            break;
        case 3: {
            int bookId;
            cout << "Enter book ID to borrow: ";
            cin >> bookId;
            library.borrowBook(bookId);
            break;
        }
        case 4: {
            int bookId;
            cout << "Enter book ID to return: ";
            cin >> bookId;
            library.returnBook(bookId);
            break;
        }
        case 5: {
            string studentName, studentId;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, studentName);
            cout << "Enter student ID: ";
            getline(cin, studentId);
            library.addStudentMembership(studentName, studentId);
            break;
        }
        case 6:
            library.viewMembers();
            break;
        case 7:
            cout << "Exiting the Library Management System. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7.\n";
    }
}

int main() {
    Library library;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        processUserChoice(library, choice);
    } while (choice != 7);

    return 0;
}
