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
#pragma once
#ifndef SDDS_APARTMENT_H_
#define SDDS_APARTMENT_H_
#include <iostream>

namespace sdds
{
   class Apartment
   {
      int m_number = -1;
      double m_balance = 0.0;

   public:
      Apartment(int number, double balance);
      std::ostream& display()const;
      operator bool()const;
      operator int()const;
      operator double()const;
      bool operator ~()const;
      Apartment& operator=(int appNum);
      Apartment& operator=(Apartment& RO);
      Apartment& operator+=(double RO);
      Apartment& operator-=(double RO);
      Apartment& operator<<(Apartment& RO);
      Apartment& operator>>(Apartment& RO);
   };
   // binary helper Operators
   double operator+(const Apartment& LO, const Apartment& RO);
   double operator+=(double& LO, const Apartment& RO);
}

#endif // SDDS_APARTMENT_H_