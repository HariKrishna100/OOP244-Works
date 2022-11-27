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
#include "Shape.h"
using namespace std;
namespace sdds {
   std::ostream& operator<<(std::ostream& os, const Shape& S) {
      S.draw(os);
      return os;
   }

   std::istream& operator>>(std::istream& is, Shape& S) {
      S.getSpecs(is);
      return is;
   }
}