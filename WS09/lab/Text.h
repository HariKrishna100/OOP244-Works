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
#ifndef SDDS_TEXT_H_
#define SDDS_TEXT_H_
#include <iostream>
namespace sdds {
   class Text {
      char* m_content{};
   protected:
      const char& operator[](int index)const;
   public:
      Text();
      Text(const Text& toCopy);
      Text& operator=(const Text& toCopy);
      virtual ~Text();
      virtual unsigned getFileLength(std::istream& is);
      virtual std::istream& read(std::istream& istr);
      virtual std::ostream& write(std::ostream& ostr)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text& T);
   std::istream& operator>>(std::istream& is, Text& T);
}
#endif // !SDDS_TEXT_H_
