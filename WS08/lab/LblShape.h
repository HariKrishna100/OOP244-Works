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
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"
namespace sdds {
   class LblShape : public Shape {
   private:
      char* m_label{};
   protected:
      const char* label() const;
   public:
      LblShape();
      LblShape(const char* copyCstr);
      ~LblShape();
      LblShape(const LblShape& toCopy) = delete;
      LblShape& operator=(const LblShape& toCopy) = delete;
      void getSpecs(std::istream& istr);
   };
}
#endif // !SDDS_LBLSHAPE_H_