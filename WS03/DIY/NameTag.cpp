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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "NameTag.h"
namespace sdds {
    void NameTag::set(const char* name) {
        strcpy(NameTag::name, name);
    }

    char* NameTag::readName() {
        return name;
    }
}