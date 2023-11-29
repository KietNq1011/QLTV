#include "reader.h"

reader::reader() {};

reader::~reader() {};

// getter
string reader::getID() {
	string str_id = to_string(IdReader);
	str_id.insert(str_id.begin(), 4 - str_id.length(), '0');
	return str_id;
}

string reader::getName() {
	return name;
}

string reader::getAddress() {
	return address;
}

string reader::getPhone() {
	return phone;
}

string reader::getEmail() {
	return email;
}

//setter
void reader::setID(unsigned int id) {
	IdReader = id;
}

void reader::setName(const string& newName) {
	name = newName;
}

void reader::setAddress(const string& newAddress) {
	address = newAddress;
}

void reader::setPhone(const string& newPhone) {
	phone = newPhone;
}

void reader::setEmail(const string& newEmail) {
	email = newEmail;
}

// other function
void reader::addReader() {
	cout << "\n\t\t=== ADD READER ===";

	cout << "\nID: "; cin >> IdReader;

	cout << "\nName: ";
	cin.ignore();
	getline(cin, name);

	cout << "\nAddress: ";
	//cin.ignore();
	getline(cin, address);

	cout << "\nPhone: ";
	//cin.ignore();
	getline(cin, phone);

	cout << "\nEmail: ";
	//cin.ignore();
	getline(cin, email);
}

void reader::deleteReader(vector<reader>& allReaders) {
	string targetID;
	cout << "\nDELETE READER";
	cout << "\nReader's ID you want to delete: "; 
	cin.ignore();
	getline(cin, targetID);

	for (int i = 0; i < allReaders.size(); i++)
	{
		if (allReaders[i].getID() == targetID)
		{
			allReaders.erase(allReaders.begin() + i);
			cout << "Reader with ID " << targetID << " deleted.\n";
			return;
		}
	}
	// If the loop completes without finding the reader
	cout << "Reader with ID " << targetID << " not found.\n";
}

void reader::updateInfo(vector<reader>& allReaders) {
	string targetID;
	cout << "\nUPDATE READER";
	cout << "\nReader's ID you want to update: ";
	cin.ignore();
	getline(cin, targetID);

	for (int i = 0; i < allReaders.size(); i++)
	{
		if (allReaders[i].getID() == targetID)
		{
			string newName, newAddress, newPhone, newEmail;

			cout << "\nName: ";
			getline(cin, newName);

			cout << "\nAddress: ";
			//cin.ignore();
			getline(cin, newAddress);

			cout << "\nPhone: ";
			//cin.ignore();
			getline(cin, newPhone);

			cout << "\nEmail: ";
			//cin.ignore();
			getline(cin, newEmail);

			// Use setter functions to update reader attributes
			allReaders[i].setName(newName);
			allReaders[i].setAddress(newAddress);
			allReaders[i].setPhone(newPhone);
			allReaders[i].setEmail(newEmail);

			cout << "Reader with ID " << targetID << " updated.\n";
			return;
		}
	}
	// If the loop completes without finding the reader
	cout << "Reader with ID " << targetID << " not found.\n";
}

void reader::displayAllReaders(vector<reader>& allReaders) {
	if (allReaders.size() == 0) {
		cout << "\nNo readers found.";
	}
	else {
		cout << "\n=== READER LIST ===\n\n";
		cout << left << setw(15) << "ID" << setw(25) << "Name" << setw(25) << "Address" << setw(15) << "Phone" << setw(30) << "Email" << endl;
		string line(140, '-');
		cout << line << endl;
		for (int i = 0; i < allReaders.size(); i++) {
			cout << left << setw(15) << allReaders[i].getID();
			cout << left << setw(25) << allReaders[i].getName();
			cout << left << setw(25) << allReaders[i].getAddress();
			cout << left << setw(15) << allReaders[i].getPhone();
			cout << left << setw(30) << allReaders[i].getEmail() << endl;
		}
	}
}

void reader::searchReaderByID(vector<reader>& allReaders) {
	string targetID;
	cout << "\nReader's ID you want to search: ";
	cin.ignore();
	getline(cin, targetID);

	for (int i = 0; i < allReaders.size(); i++)
	{
		if (targetID == allReaders[i].getID())
		{
			cout << left << setw(15) << "ID" << setw(25) << "Name" << setw(25) << "Address" << setw(15) << "Phone" << setw(30) << "Email" << endl;
			string line(180, '-');
			cout << line << endl;
			cout << left << setw(15) << allReaders[i].getID();
			cout << left << setw(25) << allReaders[i].getName();
			cout << left << setw(25) << allReaders[i].getAddress();
			cout << left << setw(15) << allReaders[i].getPhone();
			cout << left << setw(30) << allReaders[i].getEmail() << endl;
			return;
		}
	}

	// If the loop completes without finding the reader
	cout << "Reader with ID " << targetID << " not found.\n";
}

void reader::menuReader(vector<reader>& allReaders)
{
	reader newReader;
	bool isNotOut = true;
	while (isNotOut) {
		system("cls");
		cout << "\n=== MENU ===";
		cout << "\n1. Add Reader";
		cout << "\n2. Delete Reader";
		cout << "\n3. Update Reader Info";
		cout << "\n4. Display All Readers";
		cout << "\n5. Search Reader by ID";
		cout << "\n0. Back to main menu";

		int choice;
		cout << "\nEnter your choice: ";
		if (cin >> choice)
		{
			switch (choice) {
			case 1:
			{
				system("cls");
				newReader.addReader();
				allReaders.push_back(newReader);
				break;
			}
			case 2:
				system("cls");
				reader::deleteReader(allReaders);
				system("pause");
				break;
			case 3:
				system("cls");
				reader::updateInfo(allReaders);
				system("pause");
				break;
			case 4:
				system("cls");
				reader::displayAllReaders(allReaders);
				system("pause");
				break;
			case 5:
				system("cls");
				reader::searchReaderByID(allReaders);
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
		else
		{
			// Clear the fail state and ignore the invalid input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a valid option.\n";
			system("pause");
		}
	}
};