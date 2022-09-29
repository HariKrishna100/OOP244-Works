/*
*****************************************************************************
                          Lab - #1 (P1)
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 16/09/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
    struct Population {
        char* m_code;
        int m_figure;
    };
    bool load(const char filename[]);
    bool load(Population& p);
    void display();
    void deallocateMemory();
    void sortPopulation();
}
#endif // SDDS_POPULATION_H_