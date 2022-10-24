/*
*****************************************************************************
                          Lab - #5
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
#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds {
    // constructors / destructor
    Mark::Mark() {
        m_Score = 0;
        m_Grade = '\0';
        m_GPA = 0.0;
    }
 
    Mark::Mark(int num) {
        m_Score = 0;
        m_Grade = '\0';
        m_GPA = 0.0;

        if (num >= 0 && num <= 100) {
            m_Score = num;
            if (num >= 0 && num < 50) {
                m_Grade = 'F';
                m_GPA = 0;
            }
            else if (num >= 50 && num < 60) {
                m_Grade = 'D';
                m_GPA = 1;
            }
            else if (num >= 60 && num < 70) {
                m_Grade = 'C';
                m_GPA = 2;
            }
            else if (num >= 70 && num < 80) {
                m_Grade = 'B';
                m_GPA = 3;
            }
            else if (num >= 80 && num <= 100) {
                m_Grade = 'A';
                m_GPA = 4;
            }
        }
        else {
            m_Score = -1;
        }
    }

    Mark::~Mark() {
        m_Score = 0;
        m_Grade = '\0';
        m_GPA = 0.0;
    }

    // Type Conversion Operator
    Mark::operator int() const {
        return m_Score;
    }

    Mark::operator double() const {
        return m_GPA;
    }

    Mark::operator char() const {
        char grade;
        if (*this) {
            grade = m_Grade;
        }
        else {
            grade = 'X';
        }
        return grade;
    }

    Mark::operator bool() const {
        return (m_Score >= 0 && m_Score <= 100);
    }

    // Comparison Operators
    bool Mark::operator==(const Mark& M) const {
        return m_Score == M.m_Score;
    }

    bool Mark::operator!=(const Mark& M) const {
        return m_Score != M.m_Score;
    }

    bool Mark::operator<(const Mark& M) const {
        return m_Score < M.m_Score;
    }

    bool Mark::operator>(const Mark& M) const {
        return m_Score > M.m_Score;
    }

    bool Mark::operator<=(const Mark& M) const {
        return m_Score <= M.m_Score;
    }

    bool Mark::operator>=(const Mark& M) const {
        return m_Score >= M.m_Score;
    }

    // Unary Operators
    Mark Mark::operator++() {
        return *this ? ++m_Score : m_Score = - 1;
    }

    Mark Mark::operator++(int) {
        return *this ? m_Score++ : m_Score = - 1;
    }

    Mark Mark::operator--() {
        return *this ? --m_Score : m_Score = - 1;
    }

    Mark Mark::operator--(int) {
        return *this ? m_Score-- : m_Score = - 1;
    }

    bool Mark::operator~() const {
        return (m_Score >= 50 && m_Score <= 100);
    }

    // binary Operators
    Mark Mark::operator=(int num) {
        if (num >= 0 && num <= 100) {
            m_Score = num;
        }
        else {
            m_Score = -1;
        }
        return *this;
    }

    Mark Mark::operator=(const Mark toCorrect) {
        if (toCorrect.m_Score >= 0 && toCorrect.m_Score <= 100) {
            m_Score = toCorrect;
        }
        else {
            m_Score = -1;
        }
        return *this;
    }

    Mark Mark::operator+=(int add) {
        int update = 0;
        if (*this) {
            update = *this;
            update += add;
            if (update >= 0 && update <= 100) {
                m_Score += add;
            }
            else {
                m_Score = -1;
            }
        }
        return *this;
    }

    Mark Mark::operator-=(int subtract) {
        int update = 0;
        if (*this) {
            update = *this;
            update -= subtract;
            if (update >= 0 && update <= 100) {
                m_Score -= subtract;
            }
            else {
                m_Score = -1;
            }
        }
        return *this;
    }

    Mark& Mark::operator<<(Mark& leftShiftO) {
        int leftValue = 0;
        if (leftShiftO) {
            leftValue = leftShiftO;
            m_Score += leftValue;
            while (leftValue != 0) {
                leftShiftO--;
                leftValue = leftShiftO;
            }
        }
        return *this;
    }

    Mark& Mark::operator>>(Mark& rightShiftO) {
        int rightValue = 0;
        int ttlValue = 0;
        if (rightShiftO) {
            rightValue = rightShiftO;
            ttlValue = m_Score + rightValue;
            m_Score = 0;
            while (rightValue != ttlValue) {
                rightShiftO++;
                rightValue = rightShiftO;
            }
        }
        return *this;
    }

    // binary helper operators
    Mark operator+(const Mark& leftOperand, int rightOperand) {
        int leftValue = 0;
        Mark m;
        if (leftOperand) {
            leftValue = leftOperand;
            m = rightOperand + leftValue;
            if (int(m) < 0 || int(m) > 100) {
                m = -1;
            }
        }
        return m;
    }
    Mark operator+(const Mark& leftOperand, const Mark& rightOperand) {
        int rightValue = 0;
        int leftValue = 0;
        Mark m;
        if (leftOperand && rightOperand) {
            leftValue = leftOperand;
            rightValue = rightOperand;
            m = leftValue + rightValue;
            if (int(m) < 0 || int(m) > 100) {
                m = -1;
            }
        }
        return m;
    }
    int operator+(int& leftOperand, const Mark rightOperand) {
        int rightValue = 0;
        Mark m;
        if (rightOperand) {
            rightValue = rightOperand;
            m = leftOperand + rightValue;
            if (int(m) < 0 || int(m) > 100) {
                m = -1;
            }
        }
        return m;
    }
    int operator+=(int& leftOperand, const Mark rightOperand) {
        int rightValue = 0;
        if (rightOperand) {
            rightValue = rightOperand;
            leftOperand += rightValue;
        }
        return leftOperand;
    }
    int operator-=(int& leftOperand, const Mark rightOperand) {
        int rightValue = 0;
        if (rightOperand) {
            rightValue = rightOperand;
            leftOperand -= rightValue;
        }
        return leftOperand;
    }
}