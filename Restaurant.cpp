// Workshop 4 - Containers
//
// Name: Valentina Derksen
// Seneca Student ID: 153803184
// Seneca email: vderksen@myseneca.ca
// Date of completion: 2019-10-11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
//#include <iomanip>
//#include <algorithm>
#include "Reservation.h"
#include "Restaurant.h"


namespace sdds {
	// Default constructor
	Restaurant::Restaurant() {};
	
	// Constructor which stores copies of all reservations
	Restaurant::Restaurant(Reservation* reservation[], size_t cnt) {
		if (cnt > 0) {
			m_reservation = new Reservation[cnt];
			for (size_t i = 0; i < cnt; i++) {
				if (reservation[i] != nullptr) {
					m_reservation[m_cnt++] = *reservation[i];
				}
			}
		}
	};
	
	// Copy constuctor
	Restaurant::Restaurant(const Restaurant& src) {
		*this = src;
	};
	
	// Copy assigment operator
	Restaurant& Restaurant::operator=(const Restaurant&src) {
		// check for self-assigment
		if (this != &src) {
			// copy the value for str_Count from the source object
			m_cnt= src.m_cnt;
			// deallocate previously allocated dynamic memory
			delete[] m_reservation;
			// allocate memory for the pointer;
			m_reservation = new Reservation[m_cnt];
			// copy the value for array of strings
			for (size_t i = 0; i < (size_t)m_cnt; i++)
				m_reservation[i] = src.m_reservation[i];
		} return *this;
	};

	// Move constuctor
	Restaurant::Restaurant(Restaurant&& src) {
		*this = std::move(src);
	};
	
	// Move assigment operator
	Restaurant& Restaurant::operator=(Restaurant&& src) {
		// check for self-assigment
		if (this != &src) {
			// deallocate previously allocated dynamic memory
			delete[] m_reservation;
			// copy the data from the source object
			m_reservation = src.m_reservation;
			m_cnt = src.m_cnt;
			// set the sourse object into empty safe state
			src.m_reservation = nullptr;
			src.m_cnt = 0;
		} return *this;
	};
	
	// Destructor
	Restaurant::~Restaurant() {
		delete[] m_reservation;
		m_reservation = nullptr;
	};
	
	// query that return how many reservations are in the system
	size_t Restaurant::size() const {
		return m_cnt;
	};
	
	// Friend Helpers
	std::ostream& operator<<(std::ostream& out, const Restaurant& src) {
		out << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;
		if (src.m_cnt==0) {
			out << "The object is empty!" << std::endl;
		} else {
			for (size_t i = 0; i < src.size(); i++) {
				out << src.m_reservation[i];
			}
		} out << "--------------------------" << std::endl;
		return out;
	};
}
