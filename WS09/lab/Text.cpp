/*
*****************************************************************************
                          Lab - #9
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 25/11/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Text.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   // provide read only access to the content
   const char& Text::operator[](int index) const {
      return m_content[index];
   }

   // sets Text class to empty
   Text::Text() {
      m_content = nullptr;
   }

   // copy constructor
   Text::Text(const Text& toCopy) {
      delete[] m_content;
      m_content = nullptr;
      operator=(toCopy);
   }

   // assignment operator
   Text& Text::operator=(const Text& toCopy) {
      if (this != &toCopy) {
         delete[] m_content;
         m_content = nullptr;
         m_content = ut.alcpy(toCopy.m_content);
      }
      return *this;
   }

   // destructor
   Text::~Text() {
      delete[] m_content;
   }

   unsigned Text::getFileLength(istream& is) {
      unsigned len{};
      if (is) {
         // save the current read position
         std::streampos cur = is.tellg();
         // go to the end
         is.seekg(0, ios::end);
         // tell what is the positions (end position = size)
         len = unsigned(is.tellg());
         // now go back to where you were.
         is.seekg(cur);
      }
      return len;
   }

   // reads data from file
   istream& Text::read(istream& istr) {
      delete[] m_content;
      int len = getFileLength(istr);
      m_content = new char[len + 1];
      istr.get(m_content, len + 1, EOF);
      m_content[len] = '\0';
      istr.seekg(0, ios::end);
      return istr;
   }

   // dispays content read
   ostream& Text::write(ostream& ostr)const {
      ostr << m_content;
      return ostr;
   }

   // insertion extraction healper operators
   ostream& operator<<(ostream& os, const Text& T) {
      T.write(os);
      return os;
   }

   istream& operator>>(istream& is, Text& T) {
      T.read(is);
      return is;
   }
}