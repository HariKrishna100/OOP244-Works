/* Citation and Sources...
Final Project Milestone 3
Module: Utils
Filename: Utils.h
Version 1.0
Author	Harikrishna Paresh Patel
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
// using namespace std; not allowed in a header file
namespace sdds {
   class Utils {
   public:
      char* alcpy(const char* cstr);
      char tolower(char ch)const;
      void toUpper(char* ch);
      char* strcat(char* des, const char* src)const;
      int strcmp(const char* s1, const char* s2)const;
      int strcmp(const char* s1, const char* s2, int len)const;
      char* strcpy(char* des, const char* src)const;
      char* strcpy(char* des, const char* src, int len)const;
      char* strncpy(char* des, const char* src, int len)const;
      int strlen(const char* str)const;
      const char* strstr(const char* str, const char* find)const;
      int isalpha(char ch)const;
      int isspace(char ch)const;
      void trim(char word[])const;
      char* lowerstrcpy(char des[], const char source[])const;
      void read(char* cString, unsigned int maxSize, char delimiter = '\n')const;
      int getint(const char* prompt = nullptr, std::istream& istr = std::cin)const;
      std::istream& getint(int& num, const char* prompt = nullptr, std::istream& istr = std::cin)const;
      char* getDynCstr(std::istream& istr);
      char* getDynCstr(const char* prompt = nullptr);
   };
   extern Utils ut;
   extern bool sdds_debug;
}

#endif // !SDDS_UTILS_H