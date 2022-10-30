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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
#include "Numbers.h"
using namespace std;
namespace sdds {


   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   } 

   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         deallocate();
         setEmpty();
         m_isOriginal = false; 
      }
   }

   Numbers::~Numbers() {
      save();
      deallocate();
   }

   // copy constructor create original instance
   Numbers::Numbers(const Numbers& toCopy) {
       setEmpty();
       operator=(toCopy);
   }

   // copy assignment operator
   Numbers& Numbers::operator=(const Numbers& toCopy) {
       if (this != &toCopy) {
           delete[] m_numbers;
           delete[] m_filename;
           setEmpty();
           m_numbers = nullptr;
           m_isOriginal = false;
           m_numbers = new double[toCopy.m_numCount + 1];
           m_numCount = toCopy.m_numCount;
           for (int i = 0; i < toCopy.m_numCount; i++) {
               m_numbers[i] = toCopy.m_numbers[i];
           }
       }
       return *this;
   }
   
   // display numbers in descending order
   Numbers Numbers::operator-() const {
       int i, j = 0;
       Numbers num(*this);
       Numbers temp(*this);

       for (i = num.m_numCount - 1; i > 0; i--) {
           for (j = 0; j < i; j++) {
               if (num.m_numbers[j + 1] > num.m_numbers[j]) {
                   temp.m_numbers[i] = num.m_numbers[j + 1];
                   num.m_numbers[j + 1] = num.m_numbers[j];
                   num.m_numbers[j] = temp.m_numbers[i];
               }
           }
       }
       return num;
   }

   // display numbers in ascending order
   Numbers Numbers::operator+() const {
       int i, j;
       Numbers num(*this);
       Numbers temp(*this);
       for (i = num.m_numCount - 1; i > 0; i--) {
           for (j = 0; j < i; j++) {
               if (num.m_numbers[j] > num.m_numbers[j + 1]) {
                   temp.m_numbers[i] = num.m_numbers[j];
                   num.m_numbers[j] = num.m_numbers[j + 1];
                   num.m_numbers[j + 1] = temp.m_numbers[i];
               }
           }
       }
       return num;
   }

   // display number of lines in file
   int Numbers::numberCount() const {
       int count = 0;
       string line;
       ifstream file;

       file.open(m_filename);
       if (file.is_open()) {
           while (getline(file, line, '\n')) {
               count++;
           }
       }
       file.close();
       return count;
   }

   // check if all numbers are read from file
   bool Numbers::load() {
       int numreads = 0;
       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           ifstream file;
           file.open(m_filename);
           if (file.is_open()) {
               for (int i = 0; i < m_numCount; i++) {
                   file >> m_numbers[i];
                   numreads++;
               }
           }
           file.close();
       }
       return numreads == m_numCount;
   }

   // overwrite data
   void Numbers::save() {
       if (m_isOriginal && !isEmpty()) {
           ofstream file;
           file.open(m_filename);
           for (int i = 0; i < m_numCount; i++) {
               file << setprecision(2) << fixed << m_numbers[i] << endl;
           }
           file.close();
       }
   }

   // add single double value to array list
   Numbers& Numbers::operator+=(double value) {
       double* temp = new double[m_numCount + 1];
       for (int i = 0; i < m_numCount; i++) {
           temp[i] = m_numbers[i];
       }
       m_numCount++;
       temp[m_numCount - 1] = value;
       delete[] m_numbers;
       m_numbers = temp;
       return *this;
   }

   // display
   std::ostream& Numbers::display(ostream& ostr) const {
       ostr << setprecision(2) << fixed;

       if (isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           if (m_isOriginal) {
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }
           for (int i = 0; i < m_numCount; i++) {
               if (i != m_numCount - 1) {
                   ostr << m_numbers[i] << ", ";
               }
               else {
                   ostr << m_numbers[i] << endl;
               }
           }
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average:         " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }

   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }

   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr; 
      m_numCount = 0;
   }

   void Numbers::deallocate() {
      delete[] m_filename;
      delete[] m_numbers;
   }

   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }

   // sort according to bool parameter
   Numbers& Numbers::sort(bool ascending) {
       int i, j;
       Numbers temp(*this);
       if (ascending) {
           for (i = m_numCount - 1; i > 0; i--)
           {
               for (j = 0; j < i; j++)
               {
                   if (m_numbers[j] > m_numbers[j + 1])
                   {
                       temp.m_numbers[i] = m_numbers[j];
                       m_numbers[j] = m_numbers[j + 1];
                       m_numbers[j + 1] = temp.m_numbers[i];
                   }
               }
           }
       }
       else {
           for (i = m_numCount - 1; i > 0; i--)
           {
               for (j = 0; j < i; j++)
               {
                   if (m_numbers[j+1] < m_numbers[j])
                   {
                       temp.m_numbers[i] = m_numbers[j+1];
                       m_numbers[j+1] = m_numbers[j];
                       m_numbers[j] = temp.m_numbers[i];
                   }
               }
           }
       }
       return *this;
   }

   double Numbers::average() const {
      double average = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            average += m_numbers[i];
         average = average / m_numCount;
      }
      return average;
   }

   double Numbers::min() const {
      double minValue = 0.0;
      if (!isEmpty()) {
         minValue = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minValue > m_numbers[i]) minValue = m_numbers[i];
      }
      return minValue;
   }

   double Numbers::max() const {
      double maxValue = 0.0;
      if(!isEmpty()) {
         maxValue = m_numbers[0];
         for(int i = 1; i < m_numCount; i++)
            if(maxValue < m_numbers[i]) maxValue = m_numbers[i];
      }
      return maxValue;
   }

   // helper functions
   std::ostream& operator<<(std::ostream& os, const Numbers& N) {
       return N.display(os);
   }

   std::istream& operator>>(std::istream& istr, Numbers& N) {
       double num;
       if (istr >> num) {
           N += num;
       }
       return istr;
   }
}
