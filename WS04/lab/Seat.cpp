/*
*****************************************************************************
                          Lab - #4
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 07/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Seat.h"
namespace sdds {
    // check if seat numbers and letters range are valid
    bool Seat::validate(int row, char letter) const {
        bool success = false;

        if ((row >= 1 && row <= 4) && (letter == 'A' || letter == 'B' ||
            letter == 'E' || letter == 'F')) {
            success = true;
        }
        else if ((row >= 7 && row <= 15) &&
                (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' ||
                letter == 'E' || letter == 'F')) {
             success = true;
        }
        else if ((row >= 20 && row <= 38) && (letter == 'A' || letter == 'B' ||
                letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F')) {
             success = true;
        }
        return success;
    }

    // set passengername to null and allocate memory
    // copy str to passengername
    Seat& Seat::alAndCp(const char* str) {
         
        delete[] m_passengerName;
        m_passengerName = nullptr;

        if (str != nullptr && str[0] != '\0')
        {
            m_passengerName = new char[strlen(str) + 1];
            strcpy(m_passengerName, str);
        }
        return *this;
    }

    // deallocate memory and initialize object to safe empty
    Seat& Seat::reset() {
        delete[] m_passengerName;
        m_passengerName = nullptr;
        m_seatRowNo = 0;
        m_seatLetter = 0;
        return *this;
    }

    // check if object is empty
    bool Seat::isEmpty() const {
        return m_passengerName == nullptr;
    }

    // check if seat assigned falls in valid range
    bool Seat::assigned() const {
        return validate(m_seatRowNo, m_seatLetter);
    }

    // set object to safe empty
    Seat::Seat() {
        m_passengerName = nullptr;
        reset();
    }

    // allocate memory to dynamic passengerName
    Seat::Seat(const char* passengerName) {
        m_passengerName = nullptr;
        reset();

        if (passengerName != nullptr && passengerName[0] != '\0')
        {
            alAndCp(passengerName);
            m_seatRowNo = 0;
            m_seatLetter = 0;
        }
    }

    // set row and letter with corresponding values
    Seat::Seat(const char* passengerName, int row, char letter){
        m_passengerName = nullptr;
        reset();

        if (passengerName != nullptr && passengerName[0] != '\0')
        {
            alAndCp(passengerName);
            m_seatRowNo = row;
            m_seatLetter = letter;
        }
    }

    // deallocate memory of dynamic passengerName
    Seat::~Seat() {
        delete[] m_passengerName;
        m_passengerName = nullptr;
    }

    // validate then set row and letter 
    Seat& Seat::set(int row, char letter) {
        if (validate(row, letter)) {
            m_seatRowNo = row;
            m_seatLetter = letter;
        }
        else
        {
            m_seatRowNo = 0;
            m_seatLetter = 0;
        }
        return *this;
    }

    // return row attribute
    int Seat::row() const {
        return m_seatRowNo;
    }

    // return letter attribute
    char Seat::letter()const {
        return m_seatLetter;
    }

    // return passengerName attribute
    const char* Seat::passenger() const {
        return m_passengerName;
    }

    // print passenger and seat info
    std::ostream& Seat::display(std::ostream& coutRef) const {
        int nameLen;
        char* name;

        // when object !empty
        if (!isEmpty()) {    

            nameLen = strlen(m_passengerName);

            // when passengerName > 40 chars
            if (nameLen > 40) {
                name = new char[71];

                // copy upto 40 chars
                strcpy(name, m_passengerName);

                for (int i = 40; i < nameLen; i++) {
                    name[i] = 0;
                }  

                coutRef.fill('.');
                coutRef.width(40);
                coutRef.setf(std::ios::left);
                coutRef << name;
                coutRef.unsetf(std::ios::left);
                coutRef.fill(' ');

                // dealocate temporary memory created copy name
                delete[] name;
                name = nullptr;
            }
            else {
                coutRef.fill('.');
                coutRef.width(40);
                coutRef.setf(std::ios::left);
                coutRef << m_passengerName;
                coutRef.unsetf(std::ios::left);
                coutRef.fill(' ');
            }
            // when seat number is invalid " " <-blank
            if (m_seatRowNo != 0) {
                coutRef << " " << m_seatRowNo << m_seatLetter;
            }
            // when object is empty
            else
            {
                coutRef << " " << "___";
            }
  
        }
        else {
            coutRef << "Invalid Seat!";
        }
        return coutRef;
    }

    // get values from input console
    std::istream& Seat::read(std::istream& cinRef) {
        char letter, name[71];
        int row;

        reset();

        cinRef.getline(name, 70, ',');
        cinRef >> row >> letter;
        cinRef.ignore();

        // when cin !fail allocate memory
        if (cinRef) {
            alAndCp(name);
            if (!isEmpty()) {
                set(row, letter);
            }
        }
        // when allocation !fail set seatrow and seatletter
        if (m_passengerName != nullptr)
        {
            set(row, letter);
        }

        return cinRef;
    }
}