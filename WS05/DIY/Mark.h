/*
*****************************************************************************
                          Diy - #5
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 20/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H
#include <iostream>
namespace sdds {
    class Mark {
    private:
        int m_Score;
        char m_Grade;
        double m_GPA;
    public:
        // constructors / destructor
        Mark();
        Mark(int num);
        ~Mark();
        // type conversion operators
        operator int()const;
        operator double()const;
        operator char()const;
        operator bool()const;
        // comparison operators
        bool operator==(const Mark& M)const;
        bool operator!=(const Mark& M)const;
        bool operator<(const Mark& M)const;
        bool operator>(const Mark& M)const;
        bool operator<=(const Mark& M)const;
        bool operator>=(const Mark& M)const;
        // unary operators
        Mark operator++();
        Mark operator++(int);
        Mark operator--();
        Mark operator--(int);
        bool operator~()const;
        // binary operators
        Mark operator=(int num);
        Mark operator=(const Mark toCorrect);
        Mark operator+=(int add);
        Mark operator-=(int subtract);
        Mark& operator<<(Mark& leftShiftO);
        Mark& operator>>(Mark& rightShiftO);
    };
    // binary helper operators
    Mark operator+(const Mark& leftOperand, int rightOperand);
    Mark operator+(const Mark& leftOperand, const Mark& rightOperand);
    int operator+(int& leftOperand, const Mark rightOperand);
    int operator+=(int& leftOperand, const Mark rightOperand);
    int operator-=(int& leftOperand, const Mark rightOperand);
}
#endif // !SDDS_MARK_H_
