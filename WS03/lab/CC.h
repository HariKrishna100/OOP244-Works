#ifndef SDDS_CC_H_
#define SDDS_CC_H_
namespace sdds {
	class CC {
	private:
		char* m_Cardholdername;
		short int m_CVV;
		short int m_expMon;
		short int M_expYear;
		unsigned long long int m_cardNumber;
		bool validate(const char* name,
			unsigned long long cardNo,
			short cvv,
			short expMon,
			short expYear)const;
		void prnNumber()const;
	public:
		void set();
		void cleanUp();
		bool isEmpty() const;
		void set(const char* cc_name,
			unsigned long long cc_no,
			short cvv,
			short expMon,
			short expYear);
		bool read();
		void display(int row = 0) const;
	};
}

#endif // !SDDS_CC_H_
