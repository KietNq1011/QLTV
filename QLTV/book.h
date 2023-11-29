#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class book
{
private:
	string ISBN;
	string Title;
	string Author;
	string Publisher;
	unsigned int Quantity;
	string Category;
	float Price;
public:
	book();
	~book();

	// getter
	string getISBN();
	string getTitle();
	string getAuthor();
	string getPublisher();
	unsigned int getQuantity();
	string getCategory();
	float getPrice();

	// setter
	void setISBN(const string isbn);
	void setTitle(const string& title);
	void setAuthor(const string& author);
	void setPublisher(const string& publisher);
	void setQuantity(unsigned int quantity);
	void setCategory(const string& category);
	void setPrice(float price);

	static void displayAllBooks(vector<book>& allBooks);

	static void searchBookByTitle(vector<book>& allBooks);

	static void searchBookByAuthor(vector<book>& allBooks);

	void addBook();

	static void deleteBook(vector<book>& allBooks);

	static void updateQuantity(vector<book>& allBooks);

	static void menuBook(vector<book>& allBooks);
};

