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
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include "LblShape.h"
namespace sdds {
   class Line: public LblShape {
      int m_length;
   public:
      Line();
      Line(const char* cstr, int lineLength);
      virtual ~Line();
      void getSpecs(std::istream& istr);
      void draw(std::ostream& ostr) const;
   };
}
#endif // !SDDS_LINE_H_