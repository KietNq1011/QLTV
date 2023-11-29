#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "book.h"
#include "reader.h"

#include <chrono>
#include <sstream>

using namespace std;

class Library
{
private:
	unsigned int ReaderID;
	string ReaderName;
	string BookName;
	string BookBorrowingDay;
	vector<reader> readers;
	vector<book> books;
public:
	// Getter functions
	string getReaderID();
	string getReaderName();
	string getBookName();
	string getBookBorrowingDay();

	// Setter functions
	void setReaderID(const unsigned int id);
	void setReaderName(const string& name);
	void setBookName(const string& bookName);
	void setBookBorrowingDay(const string& borrowingDay);

	// other function
	static void menuManagerLibrary(vector<Library>& borrowedInfo, vector<reader>& allReaders, vector<book>& allBooks);
	void borrowBook(vector<Library>& borrowedInfo, vector<reader>& allReaders, vector<book>& allBooks);
	static void returnBook(vector<Library>& borrowedInfo, vector<book>& allBooks);
	static void displayAllBooksBorrows(vector<Library>& borrowedInfo);
};


