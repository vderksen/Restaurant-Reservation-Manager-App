#pragma once
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

//#include <iostream>
#include <string>
//#include <iomanip>
//using namespace std;

namespace sdds {
	class Reservation {
		std::string reservationID; // reservation id: an array of characters
		std::string name; // the name on the reservation
		std::string email; // the email that can be used to send the confirmation that the reservation can be honored or not
		size_t numOfPeople; // the number of people in the party
		int day; // the day when the party is expected to come (an integer between 1 and 31)
		int hour; // the hour when the party is expected to come (an integer between 1 and 24)

	public:
		// Default constructor
		Reservation();
		// Constructor that receives the reservation as a string
		Reservation(const std::string& m_res);
		// Friend Helpers
		friend std::ostream& operator<<(std::ostream& out, const Reservation& ppReservations);
	};


}
#endif // !SDDS_RESERVATION_H


