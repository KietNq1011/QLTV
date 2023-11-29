#include <string>
#include <iostream>
#include <vector>
#include "reader.h"
#include "book.h"
#include "Library.h"

using namespace std;

int main()
{
    vector<book> allBook;
    vector<reader> allReaders;
    vector<Library> allBookBorrowed;


    // Create a new reader instance with the provided details
    reader newReader;
    newReader.setID(1);  // Assuming you want to assign ID 1
    newReader.setName("Kiet Nguyen");
    newReader.setAddress("Kien Giang");
    newReader.setPhone("0326609063");
    newReader.setEmail("tuankiet9063@gmail.com");

    // Add the new reader to the vector
    allReaders.push_back(newReader);

    // Book 1
    book book1;
    book1.setISBN("978-3-16-148410-0");
    book1.setTitle("The Art of Programming");
    book1.setAuthor("John Codingto");
    book1.setPublisher("TechPublish Co.");
    book1.setQuantity(50);
    book1.setCategory("Programming");
    book1.setPrice(29.99);

    // Book 2
    book book2;
    book2.setISBN("978-0-330-25864-0");
    book2.setTitle("1984");
    book2.setAuthor("George Orwell");
    book2.setPublisher("Penguin Books");
    book2.setQuantity(100);
    book2.setCategory("Fiction, Dystopian");
    book2.setPrice(10.99);

    // Add books to the vector
    allBook.push_back(book1);
    allBook.push_back(book2);


    bool isNotExit = true;
    while (isNotExit) {
        system("cls");
        cout << "\n=== MENU ===";
        cout << "\n1. Manage reader";
        cout << "\n2. Manage book";
        cout << "\n3. Manage library";
        cout << "\n0. Exit";

        int choice;
        cout << "\nEnter your choice: ";
        if (cin >> choice)
        {
            switch (choice) {
            case 1:
                system("cls");
                reader::menuReader(allReaders);
                break;
            case 2:
                system("cls");
                book::menuBook(allBook);
                break;
            case 3:
                system("cls");
                Library::menuManagerLibrary(allBookBorrowed, allReaders, allBook);
                break;
            case 0:
                cout << "Exiting...\n";
                isNotExit = false;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
            }
        }
        else {
            // Clear the fail state and ignore the invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid option.\n";
            system("pause");
        }
    }

    return 0;
}
