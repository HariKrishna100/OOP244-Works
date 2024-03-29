/*
*****************************************************************************
                          Lab - #6
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 26/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
   class Numbers {
      double* m_numbers{};
      char* m_filename{};
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void deallocate();
      void setFilename(const char* filename);
      Numbers& sort(bool ascending);
   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      ~Numbers();
      Numbers(const Numbers& toCopy);
      Numbers& operator=(const Numbers& toCopy);
      Numbers operator-()const;
      Numbers operator+()const;
      int numberCount()const;
      bool load();
      void save();
      Numbers& operator+=(double value);
      std::ostream& display(std::ostream& ostr) const;
   };
   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_

