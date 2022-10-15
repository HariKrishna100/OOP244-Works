/*
*****************************************************************************
                          Lab - #5
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 14/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Apartment.h"

using namespace std;
namespace sdds
{
   Apartment::Apartment(int number, double balance)
   {

      if (number >= 1000 && number <= 9999
         && balance >= 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Apartment::display() const
   {
      if (*this)
      {
         cout.width(4);
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else
      {
         cout << "Invld|  Apartment   ";
      }
      return cout;
   }
   
   // check if the object is not empty
   Apartment::operator bool() const {
       return ((m_number >= 1000 && m_number <= 9999) && (m_balance >= 0.0));
   }
    
   // return appartmentNo
   Apartment::operator int() const {
       return m_number;
   }

   // return rentBalance
   Apartment::operator double() const {
       return m_balance;
   }

   // check if apartmentbalance = 0
   bool Apartment::operator~() const {
       return m_balance == 0;
   }

   // assign apartment to int
   Apartment& Apartment::operator=(int appNum)
   {
       if (appNum >= 1000 && appNum <= 9999) {
           m_number = appNum;
       }
       else {
           m_number = -1;
           m_balance = 0;
       }
       return *this;
   }

   // swap values to another AP Object 
   Apartment& Apartment::operator=(Apartment& RO) {
       int num = 0;
       double bal = 0.0;
       if (this != &RO) {
           num = m_number;
           bal = m_balance;
           m_number = RO.m_number;
           m_balance = RO.m_balance;
           RO.m_number = num;
           RO.m_balance = bal;
       }
       return *this;
   }

   // add double value to rent
   Apartment& Apartment::operator+=(double value) {
       if (*this && (m_balance > 0.0) && (value > 0.0)) {
           m_balance += value;
       }
       return *this;
   }

   // reduce rent by double value
   Apartment& Apartment::operator-=(double value) {
       if (*this && (m_balance > 0.0) && (value > 0.0) && (value < m_balance)) {
           m_balance -= value;
       }
       return *this;
   }

   // Pour balance from Right to Left
   Apartment& Apartment::operator<<(Apartment& RO) {
       double bal = 0.0;
       if (*this && RO && (this != &RO)) {
           bal = RO.m_balance;
           RO.m_balance = 0.0;
           m_balance += bal;
       }
       return *this;
   }

   // Pour balance from Left to Right
   Apartment& Apartment::operator>>(Apartment& RO) {
       double bal = 0.0;
       if (*this && RO && (this != &RO)) {
           bal = m_balance;
           m_balance = 0.0;
           RO.m_balance += bal;
       }
       return *this;
   }

   // sum balance of apartments
   double operator+(const Apartment& LO, const Apartment& RO) {
       double bal = 0.0, loValue = LO, roValue = RO;
       if (LO && RO) {
           bal = loValue + roValue;
       }
       return bal;
   }

   // sum left + right
   double operator+=(double& LO, const Apartment& RO) {
       double bal = 0.0, roValue = 0.0;
       if (RO) {
           roValue = RO;
           bal = LO += roValue;
       }
       return bal;
   }
}