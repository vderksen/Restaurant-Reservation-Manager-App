// Workshop 4 - Containers
//
// Name: Valentina Derksen
// Seneca Student ID: 153803184
// Seneca email: vderksen@myseneca.ca
// Date of completion: 2019-10-11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "ConfirmationSender.h"

namespace sdds
{
	// Default constructor
	ConfirmationSender::ConfirmationSender() {};

	// Copy constuctor
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) : ConfirmationSender(){
		*this = src;
	}

	// Copy assigment operator
	ConfirmationSender& ConfirmationSender::operator = (const ConfirmationSender& src){
		// check for self-assigment
		if (this != &src)	{
			// copy the value for str_Count from the source object
			this->m_cnt = src.m_cnt;
			// deallocate previously allocated dynamic memory
			delete[] m_reservation;
			// allocate memory for the pointer;
			m_reservation = new const Reservation*[m_cnt];
			for (size_t i = 0; i < m_cnt; i++)
				this->m_reservation[i] = src.m_reservation[i];
		} return *this;
	}

	// Move constuctor
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src){
		*this = std::move(src);
	}

	// Move assigment operator
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src){
		// check for self-assigment
		if (this != &src) {
			this->m_cnt = src.m_cnt;
			this->m_reservation = src.m_reservation;
			src.m_reservation = nullptr;
		} return *this;
	}

	// Destructor
	ConfirmationSender::~ConfirmationSender() {
		delete[] m_reservation;
		m_reservation = nullptr;
	};

	// add the parameter to the array
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
		for (size_t i = 0; i < m_cnt; i++)	{
			if (this->m_reservation[i] == &res){
				return *this;
			}
		}
		Reservation** temp = new Reservation*[m_cnt + 1];
		for (size_t i = 0; i < m_cnt; i++){
			temp[i] = const_cast<Reservation*>(m_reservation[i]);
		} delete[] m_reservation;
		m_reservation = new const Reservation*[m_cnt + 1];
		for (size_t i = 0; i < m_cnt; i++) {
			m_reservation[i] = temp[i];
		} delete[] temp;
		m_reservation[m_cnt] = const_cast<Reservation*>(&res);
		m_cnt++;

		return *this;
	}

	// remove the parameter from the array
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
		bool is_found = true;
		for (size_t i = 0; i < this->m_cnt; i++)	{
			if (this->m_reservation[i] != &res) is_found = false;
			else is_found = true;
		} if (!is_found) return *this;

		for (size_t i = 0; i < this->m_cnt; i++)	{
			if (this->m_reservation[i] == const_cast<Reservation*>(&res))	{
				Reservation* *temp = new Reservation*[m_cnt - 1];
				for (size_t i = 0; i < m_cnt - 1; i++){
					temp[i] = const_cast<Reservation*>(m_reservation[i]);
				}	delete[] m_reservation;
				m_reservation = new const Reservation*[m_cnt - 1];
				for (size_t i = 0; i < m_cnt - 1; i++)	{
					m_reservation[i] = temp[i];
				} delete[] temp;
				m_reservation[m_cnt] = const_cast<Reservation*>(&res);
				m_cnt--;
			}
		} return *this;
	}

	// Friend Helpers
	std::ostream& operator << (std::ostream& os, const ConfirmationSender& src)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";

		if (src.m_reservation == nullptr)
			os << "The object is empty!\n";
		else {
			for (size_t i = 0; i < src.m_cnt; i++)
			{
				os << *src.m_reservation[i];
			}
		} os << "--------------------------\n";
		return os;
	}
}