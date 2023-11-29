#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

class reader
{
private:
	unsigned int IdReader;
	string name;
	string address;
	string phone;
	string email;
public:
	reader();
	~reader();

	//getter
	string getID();
	string getName();
	string getAddress();
	string getPhone();
	string getEmail();

	//setter
	void setID(unsigned int id);
	void setName(const string& newName);
	void setAddress(const string& newAddress);
	void setPhone(const string& newPhone);
	void setEmail(const string& newEmail);

	//other functions
	void addReader();

	static void deleteReader(vector<reader>& allReaders);

	static void updateInfo(vector<reader>& allReaders);

	static void displayAllReaders(vector<reader>& allReaders);

	static void searchReaderByID(vector<reader>& allReaders);

	static void menuReader(vector<reader>& allReaders);
};

