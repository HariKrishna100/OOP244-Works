/*
*****************************************************************************
                          Diy - #6
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 29/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include <iomanip>
#include "Basket.h"
using namespace std;
namespace sdds {
    // defualt constructor
    Basket::Basket() {
        setEmpty();
    }

    // three argument constructor
    Basket::Basket(Fruit* fruits, int arraySize, double basketPrice) {
        if (basketPrice > 0 && arraySize > 0 && fruits != nullptr) {
            m_Fruit = new Fruit[arraySize];
            for (int i = 0; i < arraySize; i++) {
                m_Fruit[i] = fruits[i];
            }
            m_Size = arraySize;
            m_Price = basketPrice;
        }
    }

    // Copy constructor
    Basket::Basket(const Basket& toCopy) {
        setEmpty();
        operator=(toCopy);
    }

    // copy assignment operator
    Basket& Basket::operator=(const Basket& toCopy) {
        delete[] m_Fruit;
        setEmpty();

        m_Fruit = new Fruit[toCopy.m_Size];
        m_Size = toCopy.m_Size;
        m_Price = toCopy.m_Price;

        for (int i = 0; i < toCopy.m_Size; i++) {
            m_Fruit[i] = toCopy.m_Fruit[i];
        }
        return *this;
    }

    // deallocate memory
    Basket::~Basket() {
        delete[] m_Fruit;
    }

    // set Basket to safe empty
    void Basket::setEmpty() {
        m_Fruit = nullptr;
        m_Size = 0;
        m_Price = 0;
    }

    // update price by argument received 
    void Basket::setPrice(double price) {
        m_Price = price;
    }

    // check if basket contanins fruits
    Basket::operator bool() const {
        return (m_Size != 0);
    }

    // add object Fruit by value to m_fruits
    Basket& Basket::operator+=(Fruit fruits) {
        Fruit* temp = new Fruit[m_Size + 1];

        for (int i = 0; i < m_Size; i++) {
            temp[i] = m_Fruit[i];
        }
        m_Size++;

        temp[m_Size - 1] = fruits;
        delete[] m_Fruit;

        m_Fruit = temp;

        return *this;
    }

    // display 
    std::ostream& Basket::display(std::ostream& ostr) const {
        ostr << setprecision(2) << fixed;

        if (m_Size > 0) {
            ostr << "Basket Content:" << endl;
            for (int i = 0; i < m_Size; i++) {
                ostr.width(10);
                ostr.setf(ios::right);
                ostr << m_Fruit[i].m_name << ": " << m_Fruit[i].m_qty << "kg" << endl;
            }
            ostr << "Price: " << m_Price << endl;
        }
        else {
            ostr << "The basket is empty!" << endl;
        }
        return ostr;
    }

    // friend helper 
    std::ostream& operator<<(std::ostream& os, const Basket& B) {
        return B.display(os);
    }
}