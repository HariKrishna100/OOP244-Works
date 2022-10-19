#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
namespace sdds {
    class Mark {
    private:
        int m_Score;
        char m_Grade;
        double m_GPA;
    public:
        Mark();
        Mark(int number);
        operator int()const;
        operator double()const;
        operator char();
        operator bool()const;
        bool operator==(const Mark& M)const;
        bool operator!=(const Mark& M)const;
        bool operator<(const Mark& M)const;
        bool operator>(const Mark & M)const;
        bool operator<=(const Mark& M)const;
        bool operator>=(const Mark& M)const;
        ~Mark();
    };

}
#endif // !SDDS_MARK_H_