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
#include "CC.h"
using namespace std;
namespace sdds {
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

	void CC::prnNumber()const {
		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << m_cardNumber / 1000000000000 << " ";
		cout.fill(' ');
		cout.unsetf(ios::right);

		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << (m_cardNumber % 1000000000000) / 100000000 << " ";
		cout.fill(' ');
		cout.unsetf(ios::right);

		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << ((m_cardNumber % 1000000000000) % 100000000) / 10000 << " ";
		cout.fill(' ');
		cout.unsetf(ios::right);

		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << ((((m_cardNumber % 1000000000000) % 1000000000) % 1000000) % 10000);
		cout.fill(' ');
		cout.unsetf(ios::right);
	}

	void CC::set() {
		m_Cardholdername = nullptr;
		m_CVV = 0;
		m_expMon = 0;
		M_expYear = 0;
		m_cardNumber = 0;
	}

	void CC::cleanUp() {
		delete[] m_Cardholdername;
		set();
	}

	bool CC::isEmpty() const {
		return m_Cardholdername == nullptr;
	}

	void CC::set(const char* cc_name,
		unsigned long long cc_no,
		short cvv,
		short expMon,
		short expYear) {
		
		cleanUp();

		bool success = validate(cc_name, cc_no, cvv, expMon, expYear);
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

	bool CC::read() {
		char name[71];
		short cvv = 0, expiryMonth = 0, expiryYear = 0;
		long long cardNo = 0;

		cleanUp();

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
		if (cin) cout << "Card holder name: ";
		cin.getline(name, 71);
		if (cin) cout << "Credit card number: ";
		cin >> cardNo;
		if (cin) cout << "Card Verification Value (CVV): ";
		cin >> cvv;
		if (cin) cout << "Expiry month and year (MM/YY): ";
		cin >> expiryMonth;
		cin.ignore(1, '/');
		cin >> expiryYear;
		if (!cin.fail()) {
			set(name, cardNo, cvv, expiryMonth, expiryYear);
		}
		cin.ignore(1000, '\n');
		return !isEmpty();
	}

	void CC::display(int row) const {
		bool null = isEmpty();
		char name[1000];
		if (!null) {
			if (row > 0) {
				cout << "| ";
				cout.width(3);
				cout.setf(ios::right);
				cout << row << " |";
				cout.unsetf(ios::right);

				if (strlen(m_Cardholdername) > 30) {
					strcpy(name, m_Cardholdername);
					for (int i = 30; i < strlen(m_Cardholdername); i++) {
						name[i] = '\0';
					}
					strcpy(m_Cardholdername, name);
				}

				cout << " ";
				cout.width(30);
				cout.setf(ios::left);
				cout << m_Cardholdername << " ";
				cout.unsetf(ios::left);

				cout << "| ";
				prnNumber();  
				cout << " ";

				cout << "| " << m_CVV << " |";

				cout << " ";
				cout.width(2);
				cout.fill('| ');
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