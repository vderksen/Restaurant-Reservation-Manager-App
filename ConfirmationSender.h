// Workshop 4 - Containers
//
// Name: Valentina Derksen
// Seneca Student ID: 153803184
// Seneca email: vderksen@myseneca.ca
// Date of completion: 2019-10-11
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef CONFIRMATION_SENDER_H
#define CONFIRMATION_SENDER_H

#include <iostream>
#include "Reservation.h"
#include "Restaurant.h"


namespace sdds {
	class ConfirmationSender{
		const Reservation** m_reservation{ nullptr }; ;
		size_t m_cnt = 0u;
	public:
		// Default constructor
		ConfirmationSender();
		// Copy constuctor
		ConfirmationSender(const ConfirmationSender&);
		// Copy assigment operator
		ConfirmationSender& operator = (const ConfirmationSender&);
		// Move constuctor
		ConfirmationSender(ConfirmationSender&&);
		// Move assigment operator
		ConfirmationSender& operator=(ConfirmationSender&&);
		// Destructor
		~ConfirmationSender();
		// add the parameter to the array
		ConfirmationSender& operator+=(const Reservation& res);
		// remove the parameter from the array
		ConfirmationSender& operator-=(const Reservation& res);
		// Friend Helpers
		friend std::ostream& operator << (std::ostream&, const ConfirmationSender&);
	};

}

#endif
