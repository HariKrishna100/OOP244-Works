/*
*****************************************************************************
                          Lab - #10
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 1/12/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
namespace sdds {
   template<typename T>
   bool search(T arr[], int size, const char* keyValue, Collection<T>& obj) {
      bool success = false;
      for (int i = 0; i < size; i++) {
         if (arr[i] == keyValue) {
            obj.add(arr[i]);
            success = true;
         }
      }
      return success;
   }
}
#endif // !SDDS_SEARCH_H_