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
#include "Rectangle.h"
using namespace std;
namespace sdds {
   Rectangle::Rectangle(): LblShape() {
      m_height = 0;
      m_width = 0;
   }

   Rectangle::Rectangle(const char* cstr, int rWidth, int rHeight): LblShape(cstr) {
      m_height = rHeight;
      m_width = rWidth;
      int len = (strlen(LblShape::label()) + 2);

      if (m_height < 3 || m_width < len) {
         m_width = 0;
         m_height = 0;
      }
   }

   Rectangle::~Rectangle() {

   }

   void Rectangle::getSpecs(std::istream& istr) {
      char delim;
      bool success = false;
      int width, height;

      do {
         LblShape::getSpecs(istr);
         istr >> width >> delim >> height;

         if (!istr) {
            istr.clear();
            istr.ignore(1000, '\n');
         }
         else {
            istr.ignore(1000, '\n');
            m_width = width;
            m_height = height;
            success = true;
         }
      } while (!success);
   }

   void Rectangle::draw(std::ostream& ostr) const {
      if (m_width > 0 && m_height > 0) {
         ostr << '+';
         ostr.width(m_width - 2);
         ostr.fill('-');
         ostr << '-' << '+' << endl;

         ostr << '|';
         ostr.width(m_width - 2);
         ostr.fill(' ');
         ostr.setf(ios::left);
         ostr << LblShape::label() << '|' << endl;

         for (int i = 0; i < (m_height - 3); i++) {
            ostr << '|';
            ostr.width(m_width - 2);
            ostr.fill(' ');
            ostr << ' ' << '|' << endl;
         }

         ostr << '+';
         ostr.width(m_width - 2);
         ostr.fill('-');
         ostr << '-' << '+';
      }
   }
}
