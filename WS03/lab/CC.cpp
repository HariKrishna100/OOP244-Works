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
		cout << m_cardNumber / 1000000000000 << endl;

		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << (m_cardNumber % 1000000000000) / 100000000 << endl;

		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << ((m_cardNumber % 1000000000000) % 100000000) / 10000 << endl;

		cout.width(4);
		cout.fill('0');
		cout.setf(ios::right);
		cout << ((((m_cardNumber % 1000000000000) % 1000000000) % 1000000) % 10000) << endl;

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
		
		bool success = false;

		cleanUp();

		if (success)
		{
			m_Cardholdername = new char [strlen(cc_name) + 1];
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
		bool success = false;

		cleanUp();

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
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
		}
		if (!cin.fail())
		{
			set(name, cardNo, cvv, expiryMonth, expiryYear);
		}
		cin.ignore(1000, '\n');
		return !isEmpty();
	}

	void CC::display(int row = 0) const {
		bool empty = isEmpty();
		char name[1000];
		if (!empty)
		{
			if (row > 0)
			{
				cout << "| " << right;
				cout.setf(3);
				cout << row << " ";

				if (strlen(m_Cardholdername) > 30)
				{
					strcpy(name, m_Cardholdername);
					for (int i = 30; i < strlen(m_Cardholdername); i++)
					{
						name[i] = '\0';
					}
					strcpy(m_Cardholdername, name);
				}
				cout << "| " << left;
				cout.setf(30);
				cout << m_Cardholdername << " ";
				cout.setf(ios::left);
				cout << "| ";

				prnNumber();

				cout << " ";

				cout << "| " << m_CVV << " ";
				cout << "| " << right;
				cout.setf(2);
				cout << m_expMon << "/" << M_expYear << " |" << endl;

			}
			else if (row <= 0)
			{
				cout << "Name: " << m_Cardholdername << endl;
				cout << "Creditcard No: ";

				prnNumber();

				cout << endl << "Card Verification Value: " << m_CVV << endl;
				cout << "Expiry Date: " << m_expMon << "/" << M_expYear << endl;
			}
		}
		else
		{
			cout << "Invalid Credit Card Record" << endl;
		}
	}
}