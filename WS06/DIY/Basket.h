/*
*****************************************************************************
                          Diy - #6
Full Name  : Harikrishna Paresh Patel
Student ID#: 150739217
Email      : Hpatel296@myseneca.ca
Section    : NAA
Date       : 29/10/2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*****************************************************************************
*/
#ifndef SDDS_BASKET_H_
#define SDDS_BASKET_H_
#include <iostream>
namespace sdds {
    struct Fruit
    {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
    private:
        Fruit* m_Fruit;
        int m_Size;
        double m_Price;
    public:
        Basket();
        Basket(Fruit* fruits, int arraySize, double basketPrice);
        Basket(const Basket& toCopy);
        Basket& operator=(const Basket& toCopy);
        ~Basket();
        void setEmpty();
        void setPrice(double price);
        operator bool()const;
        Basket& operator+=(Fruit fruits);
        std::ostream& display(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& os, const Basket& B);
}
#endif // !SDDS_BASKET_H_


