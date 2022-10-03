/*
*****************************************************************************
						  Lab - #3
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 30/09/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "CC.h"
using namespace std;
namespace sdds {
	// verify credit card information
	bool CC::validate(const char* name,
		unsigned long long cardNo,
		short cvv,
		short expMon,
		short expYear) const {

		int success = false;

		if (name != NULL && strlen(name) > 2)
		{
			if (cardNo >= 4000000000000000 && cardNo <= 4099999999999999)
			{
				if (cvv > 99 && cvv < 1000)
				{
					if (expMon >= 1 && expMon <= 12)
					{
						if (expYear >= 22 && expYear <= 32)
						{
							success = true;
						}
					}
				}
			}
		}
		return success;
	}

	// Prints a 16-digit number in a set of 4-digit numbers separated by spaces
	void CC::prnNumber()const {
		// Setting first 4 digits
		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << m_cardNumber / 1000000000000 << " ";
		cout.fill(' ');
		cout.unsetf(ios::right);

		// Setting second 4 digits
		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << (m_cardNumber % 1000000000000) / 100000000 << " ";
		cout.fill(' ');
		cout.unsetf(ios::right);

		// Setting third 4 digits
		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << ((m_cardNumber % 1000000000000) % 100000000) / 10000 << " ";
		cout.fill(' ');
		cout.unsetf(ios::right);

		// Setting fourth 4 digits
		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << ((((m_cardNumber % 1000000000000) % 1000000000) % 1000000) % 10000);
		cout.fill(' ');
		cout.unsetf(ios::right);
	}

	// Sets the object to a safe empty state
	void CC::set() {
		m_Cardholdername = nullptr;
		m_CVV = 0;
		m_expMon = 0;
		M_expYear = 0;
		m_cardNumber = 0;
	}

	// deallocate memory and call set
	void CC::cleanUp() {
		delete[] m_Cardholdername;
		set();
	}

	// check if the CC object is in a safe empty state or not
	bool CC::isEmpty() const {
		return m_Cardholdername == nullptr;
	}

	// copies values to the class
	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short cvv,
		short expMon,
		short expYear) {
		
		cleanUp();

		bool success = validate(cc_name, cc_no, cvv, expMon, expYear);

		// when details match range provided initialize values to class CC
		if (success)
		{
			m_Cardholdername = new char [strlen(cc_name) + 1];
			strcpy(m_Cardholdername, cc_name);
			m_CVV = cvv;
			m_expMon = expMon;
			M_expYear = expYear;
			m_cardNumber = cc_no;
		}
	}

	// read values from console input device
	bool CC::read() {
		char name[71];
		short cvv = 0, expiryMonth = 0, expiryYear = 0;
		long long cardNo = 0;

		cleanUp();

		// when cin fails
		// clear cin and flush keyboard
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}

		// when cin has not failed
		// get user inputs
		if (cin) {
			cout << "Card holder name: ";
			cin.getline(name, 71);
		}
		if (cin) {
			cout << "Credit card number: ";
			cin >> cardNo;
		}
		if (cin) {
			cout << "Card Verification Value (CVV): ";
			cin >> cvv;
		}
		if (cin) {
			cout << "Expiry month and year (MM/YY): ";
			cin >> expiryMonth;
			cin.ignore(1, '/');
			cin >> expiryYear;
		}
		if (!cin.fail()) {
			set(name, cardNo, cvv, expiryMonth, expiryYear);
		}

		cin.ignore(1000, '\n');

		return !isEmpty();
	}

	// Display CC class information
	void CC::display(int row) const {
		bool null = isEmpty();
		char name[1000];
		int nameLength;
		if (!null) {
			if (row > 0) {
				// setting fill to row number column size
				cout << "| ";
				cout.width(3);
				cout.setf(ios::right);
				cout << row << " |";
				cout.unsetf(ios::right);

				nameLength = strlen(m_Cardholdername);

				// printing char array name
				if (nameLength > 30) {
					strcpy(name, m_Cardholdername);
					for (int i = 30; i < nameLength; i++) {
						name[i] = '\0';
					}
					strcpy(m_Cardholdername, name);
				}

				// setting fill column to size of cardholder name
				cout << " ";
				cout.width(30);
				cout.setf(ios::left);
				cout << m_Cardholdername << " ";
				cout.unsetf(ios::left);

				// Displaying Card number
				cout << "| ";
				prnNumber();  
				cout << " ";

				// Displaying CVV number
				cout << "| " << m_CVV << " |";

				// setting fill to size of expiry month and year column
				cout << " ";
				cout.width(2);
				cout.fill(' ');
				cout.setf(ios::right);
				cout << m_expMon << "/" << M_expYear << " |" << endl;
				cout.fill(' ');
				cout.unsetf(ios::right);
			}
			else if (row <= 0) {
				cout << "Name: " << m_Cardholdername << endl;
				cout << "Creditcard No: ";
				prnNumber();
				cout << endl << "Card Verification Value: " << m_CVV << endl;
				cout << "Expiry Date: " << m_expMon << "/" << M_expYear << endl;
			}
		}
		else {
			cout << "Invalid Credit Card Record" << endl;
		}
	}
}