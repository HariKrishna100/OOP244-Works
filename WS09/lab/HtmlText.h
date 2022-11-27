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
#ifndef SDDS_HTMLTEXT_H_
#define SDDS_HTMLTEXT_H_
#include <iostream>
#include "Text.h"
namespace sdds {
   class HtmlText: public Text {
      char* m_title{};
   public:
      HtmlText(const char* titleCstr = nullptr);
      HtmlText(const HtmlText& toCopy);
      HtmlText& operator=(const HtmlText& toCopy);
      virtual ~HtmlText();
      virtual std::ostream& write(std::ostream& ostr)const;
   };
}
#endif // !SDDS_HTMLTEXT_H_
