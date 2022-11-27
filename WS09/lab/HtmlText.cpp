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
#include "HtmlText.h"
#include "Utils.h"
using namespace std;
namespace sdds {
   // one argument constructor to set title
	HtmlText::HtmlText(const char* titleCstr) : m_title{} {
		if (titleCstr) {
			m_title = ut.alcpy(titleCstr);
		}
	}

   // copy constructor
	HtmlText::HtmlText(const HtmlText& toCopy) : Text(toCopy), m_title{} {
		delete[] m_title;
		m_title = nullptr;
		operator=(toCopy);
	}

   // assignment operator
	HtmlText& HtmlText::operator=(const HtmlText& toCopy) {
		if (this && &toCopy) {
			delete[] m_title;
			m_title = nullptr;
			(Text&)(*this) = toCopy;
			m_title = ut.alcpy(toCopy.m_title);
		}
		return *this;
	}

   // destructor
	HtmlText::~HtmlText() {
		delete[] m_title;
	}

   // display data content
	ostream& HtmlText::write(ostream& ostr) const {
      bool MS = false;
      char text = '\0';

      ostr << "<html><head><title>";
      if (m_title) {
         ostr << m_title;
      }
      else {
         ostr << "No Title";
      }
      ostr << "</title></head>\n<body>\n";

      if (m_title) {
         ostr << "<h1>" << m_title << "</h1>\n";
      }
     
      for (int i = 0; operator[](i); i++) {
         text = Text::operator[](i);
         if (text == '<') {
            ostr << "&lt;";
            MS = false;
         }
         else if (text == '>') {
            ostr << "&gt;";
            MS = false;
         }
         else if (text == '\n') {
            ostr << "<br />\n";
            MS = false;
         }
         else if (text == ' ') {
            if (MS) {
               ostr << "&nbsp;";
            }
            else {
               MS = true;
               ostr << " ";
            }
         }
         else {
            MS = false;
            ostr << text;
         }
      }
      ostr << "</body>\n</html>";
      return ostr;
	}
}