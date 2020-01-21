#pragma once
// Workshop 4 - Containers
//
// Name: Valentina Derksen
// Seneca Student ID: 153803184
// Seneca email: vderksen@myseneca.ca
// Date of completion: 2019-10-11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H 
#define SDDS_RESTAURANT_H

#include <iostream>
#include <string>
#include <iomanip>
#include"Reservation.h"
using namespace std;

namespace sdds {
	class Restaurant {
		Reservation* m_reservation {nullptr}; // dynamically allocated array of objects of type Reservation
		size_t m_cnt = 0u; // number reservations are in the system
	public:
		// Default constructor
		Restaurant();
		// Constructor which stores copies of all reservations
		Restaurant(Reservation* reservation[], size_t cnt);
		// Copy constuctor
		Restaurant(const Restaurant&);
		// Copy assigment operator
		Restaurant& operator=(const Restaurant&);
		// Move constuctor
		Restaurant(Restaurant&&); 
		// Move assigment operator
		Restaurant& operator=(Restaurant&&); 
		// Destructor
		~Restaurant(); 
		// query that return how many reservations are in the system
		size_t size() const; 
		// Friend Helpers
		friend std::ostream& operator<<(std::ostream& out, const Restaurant&);
	};

}

#endif // !SDDS_RESTAURANT_H