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
#include <iostream>
#include <string.h>
#include "TagList.h"
using namespace std;
namespace sdds {
    // initialize values to safe empty state
    void TagList::set() {
        tags = nullptr;
        frame = 0;
        size = 0;
    }

    // cleanup memory and dynamically allocate memory to size of num
    void TagList::set(int num) {
        cleanup();
        tags = new NameTag[num];
    }

    // add upto num of NameTags to TagList
    void TagList::add(const NameTag& nt) {
        size++;
        tags[size - 1] = nt;
        int nameLength = strlen(tags[size - 1].readName());
        if ((unsigned)nameLength > frame)
        {
            frame = nameLength;
        }
    }

    // Display TagList names encapsulated in frame set
    void TagList::print() {
        for (int i = 0; (unsigned)i < size; i++)
        {
            frame = 30;

            // print 30 '*' 1st column
            cout.fill('*');
            cout.width(frame);
            cout.setf(ios::left);
            cout << "*" << endl;
            cout.unsetf(ios::left);

            // print '*' name '*' 2nd column
            cout << "* ";
            cout.fill(' ');
            cout.width(frame - 3);
            cout.setf(ios::left);
            cout << tags[i].readName() << "*" << endl;
            cout.unsetf(ios::left);

            // print 30 '*' 3rd column
            cout.fill('*');
            cout.width(frame);
            cout << "*" << endl;
        }
    }

    // deallocate memory
    void TagList::cleanup() {
        delete[] tags;
        tags = nullptr;
    }
}