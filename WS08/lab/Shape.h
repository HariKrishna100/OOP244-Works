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
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds {
   class Shape {
   public:
      virtual ~Shape() {};
      virtual void draw(std::ostream& ostr)const = 0;
      virtual void getSpecs(std::istream& istr) = 0;
   };
   std::ostream& operator<<(std::ostream& os, const Shape& S);
   std::istream& operator>>(std::istream& is, Shape& S);
}
#endif // !SDDS_SHAPE_H_