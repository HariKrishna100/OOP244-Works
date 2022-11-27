/*
*****************************************************************************
                          Lab - #8
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 19/11/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"
using namespace std;
namespace sdds {
   const char* LblShape::label() const {
      return m_label;
   }

   LblShape::LblShape() {
      m_label = nullptr;
   }

   LblShape::LblShape(const char* copyCstr) {
      m_label = nullptr;
      m_label = new char[strlen(copyCstr) + 1];
      strcpy(m_label, copyCstr);
   }

   LblShape::~LblShape() {
      delete[] m_label;
   }

   void LblShape::getSpecs(std::istream& istr) {
      char temp[21];
      istr.get(temp, 21, ',');
      delete[] m_label;
      m_label = new char[21];
      strcpy(m_label, temp);
      istr.ignore(100, ',');
   }
}