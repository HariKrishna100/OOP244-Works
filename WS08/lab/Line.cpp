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
#include <iostream>
#include <cstring>
#include "Line.h"
using namespace std;
namespace sdds {
   Line::Line() {
      m_length = 0;
   }

   Line::~Line() {

   }

   Line::Line(const char* cstr, int lineLength): LblShape(cstr) {
      if (lineLength > 0) m_length = lineLength;
   }

   void Line::getSpecs(std::istream& istr) {
      LblShape::getSpecs(istr);
      istr >> m_length;
      istr.ignore(1000, '\n');
   }

   void Line::draw(std::ostream& ostr) const {
      if (m_length > 0 && label()) {
         ostr << label();
         for (int i = 0; i < m_length - int (strlen(label())); i++)
         {
            ostr << "=";
         }
      }
   }
}