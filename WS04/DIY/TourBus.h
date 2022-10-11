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
#ifndef SDDS_TOURBUS_H_
#define SDDS_TOURBUS_H_
#include "TourTicket.h"
namespace sdds {
    const int privateBus = 4;
    const int miniBus = 16;
    const int fullBus = 22;

    class TourBus {
    private:
        TourTicket* tt;
        char m_passengerName[41];
        int m_numPassengers;
        int m_board;
    public:
        bool validTour()const;
        TourBus();
        TourBus(int noofpassengers);
        ~TourBus();
        TourBus& board();
        std::ostream& startTheTour(std::ostream& coutRef = std::cout)const;
    };
}
#endif // !SDDS_TOURBUS_H_
