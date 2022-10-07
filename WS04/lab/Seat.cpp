#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Seat.h"
namespace sdds {
    bool Seat::validate(int row, char letter) const {
        if ((row >= 1 && row <= 4) && (letter == 'A' || letter == 'B' ||
            letter == 'E' || letter == 'F') || ((row >= 7 && row <= 15)  ||
            (row >= 20 && row <= 38)) && (letter == 'A' || letter == 'B' ||
             letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')) {
            return true;
        }
    }
    Seat& Seat::alAndCp(const char* str) {
        // TODO: set passengername to null and allocate memory
        // copy str to passengername 
        m_passengerName = nullptr;
        if (str != NULL && str != 0)
        {
            m_passengerName = new char[strlen(str) + 1];
            strcpy(m_passengerName, str);
        }
        return *this;
    }
    Seat& Seat::reset() {
        // TODO: insert return statement here
        delete[] m_passengerName;
        m_passengerName = nullptr;
        m_seatRowNo = 0;
        m_seatLetter = 0;
        return *this;
    }
    bool Seat::isEmpty() const {
        if (m_passengerName == nullptr)
        {
            return true;
        }
    }
    bool Seat::assigned() const {
        return validate(m_seatRowNo, m_seatLetter);
    }
    Seat::Seat() {
        m_passengerName = nullptr;
        reset();
    }
    Seat::Seat(const char* passengerName) {
        alAndCp(m_passengerName);
        m_seatRowNo = 0;
        m_seatLetter = 0;
    }
    Seat::Seat(const char* passengerName, int row, char letter){

    }
    Seat::~Seat() {

    }
    int Seat::row() const {
        return 0;
    }
    const char* Seat::passenger() const {
        return nullptr;
    }
    std::ostream& Seat::display(std::ostream& coutRef) const {
        // TODO: insert return statement here
    }
    std::istream& Seat::read(std::istream& cinRef) {
        // TODO: insert return statement here
    }
}