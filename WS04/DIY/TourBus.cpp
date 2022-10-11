/*
*****************************************************************************
                          Diy - #4
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 09/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "TourBus.h"
using namespace std;
namespace sdds {
    bool TourBus::validTour()const {
        int success = false;
        if (m_numPassengers == privateBus || m_numPassengers == miniBus || m_numPassengers == fullBus) {
            success = true;
        }
        return success;
    }

    TourBus::TourBus() {
        tt = nullptr;
        m_passengerName[0] = {};
        m_numPassengers = 0;
        m_board = 0;
    }

    TourBus::TourBus(int num) {
        tt = nullptr;
        m_passengerName[0] = {};
        m_numPassengers = num;
        m_board = 0;
    }

    TourBus::~TourBus() {
        delete[] tt;
        tt = nullptr;
    }

    TourBus& TourBus::board() {
        tt = new TourTicket[m_numPassengers];

        if (validTour()) {
            cout << "Boarding " << m_numPassengers << " Passengers:" << endl;

            for (int i = 0; i < m_numPassengers; i++) {
                cout << i + 1 << "/" << m_numPassengers << "- Passenger Name: ";
                cin.getline(m_passengerName, 41, '\n');
                if (!cin.fail()) {
                    tt[i].issue(m_passengerName);
                    m_board++;
                }
            }
        }
        return *this;
    }

    std::ostream& TourBus::startTheTour(std::ostream& coutRef) const {

        if (validTour()) {
            if (m_board == m_numPassengers) {
                coutRef << "Starting the tour...." << endl;
                coutRef << "Passenger List:" << endl;
                coutRef << "|Row | Passenger Name                           | Num |" << endl;
                coutRef << "+----+------------------------------------------+-----+" << endl;

                for (int i = 0; i < m_numPassengers; i++) {
                    coutRef << "|";
                    coutRef.width(3);
                    cout << i + 1 << " ";
                    tt[i].display();
                    coutRef << endl;
                }

                coutRef << "+----+------------------------------------------+-----+" << endl;
            }
            else {
                coutRef << "Cannot start the tour, the bus is not fully boarded!" << endl;
            }
        }

        return coutRef;
    }
}