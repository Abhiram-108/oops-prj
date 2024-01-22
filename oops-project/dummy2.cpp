#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
    int year;
    string dueDate; // New field for due date
    Book* left;
    Book* right;

    Book(int _id, const string& _title, const string& _author, int _year)
        : id(_id), title(_title), author(_author), year(_year), dueDate(""), left(nullptr), right(nullptr) {}
};

// Student structure
struct Student {
    string name;
    unordered_map<int, string> borrowedBooks; // Map book ID to due date

    Student(const string& _name) : name(_name) {}
};

// Binary Search Tree class
class Library {
private:
    Book* root;

    // Helper function to insert a book into the BST
    Book* insertBook(Book* node, int id, const string& title, const string& author, int year) {
        if (node == nullptr) {
            return new Book(id, title, author, year);
        }

        if (id < node->id) {
            node->left = insertBook(node->left, id, title, author, year);
        } else if (id > node->id) {
            node->right = insertBook(node->right, id, title, author, year);
        }

        return node;
    }

    // Helper function to search for a book in the BST
    Book* searchBook(Book* node, int id) {
        if (node == nullptr || node->id == id) {
            return node;
        }

        if (id < node->id) {
            return searchBook(node->left, id);
        } else {
            return searchBook(node->right, id);
        }
    }

    // Helper function to display books in sorted order
    void displayBooks(Book* node) {
        if (node != nullptr) {
            displayBooks(node->left);
            cout << setw(5) << node->id << setw(30) << node->title << setw(20) << node->author << setw(10) << node->year << endl;
            displayBooks(node->right);
        }
    }

public:
    Library() : root(nullptr) {}

    // Public function to add a book to the library
    void addBook(int id, const string& title, const string& author, int year) {
        root = insertBook(root, id, title, author, year);
    }

    // Public function to search for a book by ID
    Book* findBook(int id) {
        return searchBook(root, id);
    }

    // Public function to display all books in sorted order
    void displayAllBooks() {
        cout << setw(5) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(10) << "Year" << endl;
        cout << "------------------------------------------------------------" << endl;
        displayBooks(root);
        cout << "------------------------------------------------------------" << endl;
    }

    // Public function to borrow a book by a student
    void borrowBook(Student& student, int bookId, const string& dueDate) {
        Book* book = findBook(bookId);
        if (book != nullptr) {
            // Book found, add to student's borrowed books with due date
            student.borrowedBooks[bookId] = dueDate;
            cout << "Book \"" << book->title << "\" borrowed by " << student.name << " due on " << dueDate << endl;
        } else {
            cout << "Book with ID " << bookId << " not found in the library." << endl;
        }
    }
};

int main() {
    Library library;

    // Adding books to the library
    library.addBook(101, "The Catcher in the Rye", "J.D. Salinger", 1951);
    library.addBook(204, "To Kill a Mockingbird", "Harper Lee", 1960);
    library.addBook(305, "1984", "George Orwell", 1949);
    library.addBook(402, "The Great Gatsby", "F. Scott Fitzgerald", 1925);
    library.addBook(511, "Moby-Dick", "Herman Melville", 1851);

    // Displaying all books
    cout << "All Books in the Library:" << endl;
    library.displayAllBooks();

    // Creating a student
    Student student("John Doe");

    // Borrowing a book
    library.borrowBook(student, 305, "2023-12-01");

    return 0;
}
