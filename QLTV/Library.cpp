#include "library.h"

string getCurrentDate() {
	auto now = chrono::system_clock::now();
	auto in_time_t = chrono::system_clock::to_time_t(now);

	tm timeinfo;
	localtime_s(&timeinfo, &in_time_t);

	stringstream ss;
	ss << std::put_time(&timeinfo, "%d/%m/%Y");
	return ss.str();
}

// Getter functions
string Library::getReaderID() {
	string str_id = to_string(ReaderID);
	str_id.insert(str_id.begin(), 4 - str_id.length(), '0');
	return str_id;
}

string Library::getReaderName() {
	return ReaderName;
}

string Library::getBookName() {
	return BookName;
}

string Library::getBookBorrowingDay() {
	return BookBorrowingDay;
}

// Setter functions
void Library::setReaderID(const unsigned int id) {
	ReaderID = id;
}

void Library::setReaderName(const string& name) {
	ReaderName = name;
}

void Library::setBookName(const string& bookName) {
	BookName = bookName;
}

void Library::setBookBorrowingDay(const string& borrowingDay) {
	BookBorrowingDay = borrowingDay;
}

// other function
void Library::borrowBook(vector<Library>& borrowedInfo, vector<reader>& allReaders, vector<book>& allBooks) {
	string ReaderID;
	string BookName;
	cin.ignore();
	cout << "\nID Reader: ";
	getline(cin, ReaderID);
	cout << "\nBook Name: ";
	getline(cin, BookName);

	// Tìm reader và book 
	for (int i = 0; i < allReaders.size(); i++) {
		if (allReaders[i].getID() == ReaderID) {
			for (int j = 0; j < allBooks.size(); j++) {
				if (allBooks[j].getTitle() == BookName && allBooks[j].getQuantity() > 0) {
					// Trừ số lượng sách và thêm thông tin mượn sách vào danh sách
					allBooks[j].setQuantity(allBooks[j].getQuantity() - 1);
					// Thêm thông tin mượn sách vào danh sách
					Library newInfo;
					newInfo.setReaderID(stoi(ReaderID));
					newInfo.setReaderName(allReaders[i].getName());
					newInfo.setBookName(BookName);
					newInfo.setBookBorrowingDay(getCurrentDate()); // Hàm này bạn có thể triển khai để lấy ngày hiện tại

					borrowedInfo.push_back(newInfo);

					cout << "Book borrowed successfully.\n";
					return;
				}
			}
		}
	}

	cout << "\nNot found Reader or Book." << endl;
}


void Library::returnBook(vector<Library>& borrowedInfo, vector<book>& allBooks) {
	string ReaderID;
	string BookName;
	cin.ignore();
	cout << "\nID Reader: ";
	getline(cin, ReaderID);
	cout << "\nBook Name: ";
	getline(cin, BookName);

	// Tìm reader và book
	for (int i = 0; i < borrowedInfo.size(); i++) {
		if (borrowedInfo[i].getReaderID() == ReaderID && borrowedInfo[i].getBookName() == BookName) {
			for (int j = 0; j < allBooks.size(); j++) {
				if (borrowedInfo[i].getBookName() == allBooks[j].getTitle()) {
					// Cộng số lượng sách
					allBooks[j].setQuantity(allBooks[j].getQuantity() + 1);
					// Xóa thông tin mượn sách khỏi danh sách
					borrowedInfo.erase(borrowedInfo.begin() + i);
					cout << "Book returned successfully.\n";
					return;
				}
			}
		}
	}
	
	cout << "\nNot found Reader or Book." << endl;
}


void Library::displayAllBooksBorrows(vector<Library>& borrowedInfo) {
	if (borrowedInfo.empty())
	{
		cout << "\nNo body borrowed book.";
	}
	else {
		cout << left << setw(20) << "Reader's ID" << setw(30) << "Reader's name" << setw(40) << "Book's Name" << setw(20) << "BBD" << endl;
		string line(140, '-');
		cout << line << endl;
		for (int i = 0; i < borrowedInfo.size(); i++)
		{
			cout << left << setw(20) << borrowedInfo[i].getReaderID();
			cout << left << setw(30) << borrowedInfo[i].getReaderName();
			cout << left << setw(40) << borrowedInfo[i].getBookName();
			cout << left << setw(20) << borrowedInfo[i].getBookBorrowingDay() << endl;
		}
	}
}

void Library::menuManagerLibrary(vector<Library>& borrowedInfo, vector<reader>& allReaders, vector<book>& allBooks) {
	Library newInfo;
	newInfo.readers = allReaders;
	newInfo.books = allBooks;

	bool isNotOut = true;
	while (isNotOut) {
		system("cls");
		cout << "\n=== MANAGER BORROWED BOOK ===";
		cout << "\n1. Borrow Book";
		cout << "\n2. Return Book";
		cout << "\n3. Display All Books Borrowed";
		cout << "\n0. Back to main menu";

		int choice;
		cout << "\nEnter your choice: ";
		if (cin >> choice)
		{
			switch (choice) {
			case 1:
				system("cls");
				newInfo.borrowBook(borrowedInfo, allReaders, allBooks);
				system("pause");
				break;
			case 2:
				system("cls");
				Library::returnBook(borrowedInfo, allBooks);
				system("pause");
				break;
			case 3:
				system("cls");
				Library::displayAllBooksBorrows(borrowedInfo);
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