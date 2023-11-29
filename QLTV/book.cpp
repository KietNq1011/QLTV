#include "book.h"


book::book() {}

book::~book() {}

// getter
string book::getISBN() {
	return	ISBN;
}

string book::getTitle() {
	return Title;
}

string book::getAuthor() {
	return Author;
}

string book::getPublisher() {
	return Publisher;
}

unsigned int book::getQuantity() {
	return Quantity;
}

string book::getCategory() {
	return Category;
}

float book::getPrice() {
	return Price;
}

// setter
void book::setISBN(const string isbn) {
	ISBN = isbn;
}

void book::setTitle(const string& title) {
	Title = title;
}

void book::setAuthor(const string& author) {
	Author = author;
}

void book::setPublisher(const string& publisher) {
	Publisher = publisher;
}

void book::setQuantity(unsigned int quantity) {
	Quantity = quantity;
}

void book::setCategory(const string& category) {
	Category = category;
}

void book::setPrice(float price) {
	Price = price;
}

// other function
void book::addBook() {
	cout << "\nInput ISBN: ";
	cin >> ISBN;

	cout << "\nInput Title: ";
	cin.ignore();
	getline(cin, Title);

	cout << "\nInput Author: ";
	getline(cin, Author);

	cout << "\nInput Publisher: ";
	getline(cin, Publisher);

	cout << "\nInput Quantity: ";
	cin >> Quantity;

	cout << "\nInput Category: ";
	cin.ignore();
	getline(cin, Category);

	cout << "\nInput Price: ";
	cin >> Price;
}

void book::displayAllBooks(vector<book>& allBooks) {
	if (allBooks.size() == 0) {
		cout << "\nNo book found.";
	}
	else {
		cout << "\n=== BOOK LIST ===\n\n";
		cout << left << setw(20) << "ISBN" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publisher"
			<< setw(20) << "Category" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
		string line(140, '-');
		cout << line << endl;

		for (int i = 0; i < allBooks.size(); i++) {
			cout << left << setw(20) << allBooks[i].getISBN();
			cout << left << setw(30) << allBooks[i].getTitle();
			cout << left << setw(20) << allBooks[i].getAuthor();
			cout << left << setw(20) << allBooks[i].getPublisher();
			cout << left << setw(20) << allBooks[i].getCategory();
			cout << left << setw(10) << allBooks[i].getQuantity();
			cout << fixed << setprecision(2) << setw(10) << allBooks[i].getPrice() << endl;
		}
	}
};

void book::searchBookByTitle(vector<book>& allBooks) {
	string targetTitle;
	cout << "\nBook's title you want to search: ";
	cin.ignore();
	getline(cin, targetTitle);

	for (int i = 0; i < allBooks.size(); i++)
	{
		if (targetTitle == allBooks[i].getTitle())
		{
			cout << left << setw(20) << "ISBN" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publisher" << setw(20) << "Category" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
			string line(140, '-');
			cout << line << endl;
			cout << left << setw(20) << allBooks[i].getISBN();
			cout << left << setw(30) << allBooks[i].getTitle();
			cout << left << setw(20) << allBooks[i].getAuthor();
			cout << left << setw(20) << allBooks[i].getPublisher();
			cout << left << setw(20) << allBooks[i].getCategory();
			cout << left << setw(10) << allBooks[i].getQuantity();
			cout << fixed << setprecision(2) << setw(10) << allBooks[i].getPrice() << endl;

			return;
		}
	}

	cout << "Book with titlte " << targetTitle << " not found.\n";
};

void book::searchBookByAuthor(vector<book>& allBooks) {
	string targetAuthor;
	cout << "\nBook's title you want to search: ";
	cin.ignore();
	getline(cin, targetAuthor);

	for (int i = 0; i < allBooks.size(); i++)
	{
		if (targetAuthor == allBooks[i].getAuthor())
		{
			cout << left << setw(20) << "ISBN" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publisher" << setw(20) << "Category" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
			string line(140, '-');
			cout << line << endl;

			for (int i = 0; i < allBooks.size(); i++) {
				cout << left << setw(20) << allBooks[i].getISBN();
				cout << left << setw(30) << allBooks[i].getTitle();
				cout << left << setw(20) << allBooks[i].getAuthor();
				cout << left << setw(20) << allBooks[i].getPublisher();
				cout << left << setw(20) << allBooks[i].getCategory();
				cout << left << setw(10) << allBooks[i].getQuantity();
				cout << fixed << setprecision(2) << setw(10) << allBooks[i].getPrice() << endl;
			}
		}
	}
	return;

	cout << "Book(s) with author " << targetAuthor << " not found.\n";
};

void book::deleteBook(vector<book>& allBooks) {
	string targetISBN;
	cout << "\nBook's ISBN you want to delete: ";
	cin.ignore();
	getline(cin, targetISBN);

	for (int i = 0; i < allBooks.size(); i++)
	{
		if (targetISBN == allBooks[i].getISBN())
		{
			allBooks.erase(allBooks.begin() + i);
			cout << "\nBook with ISBN " << targetISBN << " deleted.\n";
			return;
		}
	}

	cout << "Book with ISBN " << targetISBN << " not found.\n";
};

void book::updateQuantity(vector<book>& allBooks) {
	string targetISBN;
	cout << "\nBook's ISBN you want to update quantity: ";
	cin.ignore();
	getline(cin, targetISBN);

	for (int i = 0; i < allBooks.size(); i++)
	{
		if (targetISBN == allBooks[i].getISBN())
		{
			cout << left << setw(20) << "ISBN" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publisher" << setw(20) << "Category" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
			string line(140, '-');
			cout << line << endl;
			cout << left << setw(20) << allBooks[i].getISBN();
			cout << left << setw(30) << allBooks[i].getTitle();
			cout << left << setw(20) << allBooks[i].getAuthor();
			cout << left << setw(20) << allBooks[i].getPublisher();
			cout << left << setw(20) << allBooks[i].getCategory();
			cout << left << setw(10) << allBooks[i].getQuantity();
			cout << fixed << setprecision(2) << setw(10) << allBooks[i].getPrice() << endl;

			cout << "\n\nInput quantity: ";
			int newQuantity; cin >> newQuantity;
			allBooks[i].setQuantity(newQuantity);
			system("pause");
			system("cls");

			cout << left << setw(20) << "ISBN" << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publisher" << setw(20) << "Category" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
			cout << line << endl;
			cout << left << setw(20) << allBooks[i].getISBN();
			cout << left << setw(30) << allBooks[i].getTitle();
			cout << left << setw(20) << allBooks[i].getAuthor();
			cout << left << setw(20) << allBooks[i].getPublisher();
			cout << left << setw(20) << allBooks[i].getCategory();
			cout << left << setw(10) << allBooks[i].getQuantity();
			cout << fixed << setprecision(2) << setw(10) << allBooks[i].getPrice() << endl;
			return;
		}
	}
};

void book::menuBook(vector<book>& allBooks) {
	book newBook;
	bool isNotOut = true;
	while (isNotOut) {
		system("cls");
		cout << "\n=== BOOK MENU ===";
		cout << "\n1. Add Book";
		cout << "\n2. Delete Book";
		cout << "\n3. Display All Books";
		cout << "\n4. Search Book by Title";
		cout << "\n5. Search Book by Author";
		cout << "\n6. Update Quantity";
		cout << "\n0. Back to main menu";

		int choice;
		cout << "\nEnter your choice: ";
		if (cin >> choice)
		{
			switch (choice) {
			case 1:
				system("cls");
				newBook.addBook();
				allBooks.push_back(newBook);
				break;
			case 2:
				system("cls");
				book::deleteBook(allBooks);
				break;
			case 3:
				system("cls");
				book::displayAllBooks(allBooks);
				system("pause");
				break;
			case 4:
				system("cls");
				book::searchBookByTitle(allBooks);
				system("pause");
				break;
			case 5:
				system("cls");
				book::searchBookByAuthor(allBooks);
				system("pause");
				break;
			case 6:
				system("cls");
				book::updateQuantity(allBooks);
				system("pause");
				break;
			case 0:
				isNotOut = false;
				break;
			default:
				cout << "Invalid choice. Please enter a valid option.\n";
				system("pause");
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
}