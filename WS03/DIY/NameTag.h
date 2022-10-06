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
#ifndef SDDS_NameTag_H_
#define SDDS_NameTag_H_
namespace sdds {
    class NameTag {
    private:
        char name[51];
    public:
        void set(const char* name);
        char* readName();
    };
}
#endif // !SDDS_NameTag_H_