/*
*****************************************************************************
                          Diy - #3
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 3/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_TagList_H_
#define SDDS_TagList_H_
#include "NameTag.h"
namespace sdds {
    class TagList {
    private:
        NameTag* tags;
        unsigned int frame;
        unsigned int size;
    public:
        void set();
        void set(int num);
        void add(const NameTag& nt);
        void print();
        void cleanup();
    };
}
#endif // !SDDS_TagList_H_
