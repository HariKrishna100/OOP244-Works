#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds {
    Mark::Mark() {
        m_Score = 0;
        m_Grade = '\0';
        m_GPA = 0;
    }

    Mark::Mark(int number) {
        m_Score = number;
        m_Grade = '\0';
        m_GPA = 0;
        if (number >= 0 && number <= 100) {
            if (number >= 0 && number < 50) {
                m_Grade = 'F';
                m_GPA = 0;
            }
            else if (number >= 50 && number < 60) {
                m_Grade = 'D';
                m_GPA = 1;
            }
            else if (number >= 60 && number < 70) {
                m_Grade = 'C';
                m_GPA = 2;
            }
            else if (number >= 70 && number < 80) {
                m_Grade = 'B';
                m_GPA = 3;
            }
            else if (number >= 80 && number <= 100) {
                m_Grade = 'A';
                m_GPA = 4;
            }
        }
        else {
            m_Score = -1;
        }
    }

    Mark::operator int() const {
        return m_Score;
    }

    Mark::operator double()const {
        return m_GPA;
    }

    Mark::operator char() {
        if (*this) {
            return m_Grade;
        }
        else {
            return 'X';
        }
    }

    Mark::operator bool() const {
        return (m_Score >= 0 && m_Score <= 100);
    }

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

    Mark::~Mark() {
        m_Score = 0;
        m_Grade = '\0';
        m_GPA = 0.0;
    }
}