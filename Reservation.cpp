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
#include <iomanip>
#include <algorithm>
#include "Reservation.h"


namespace sdds {
	// a default constructor
	Reservation::Reservation() {
		reservationID = "";
		name = "";
		email = "";
		numOfPeople = 0;
		day = 0;
		hour = 0;
	}

	//  A constructor that receives the reservation as a string
	Reservation::Reservation(const std::string& m_res) {
		// ID:NAME,EMAIL,PARTY SIZE,DAY,HOUR
		//std::string::substr() - Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
		//std::string::find() - Searches the string for the first occurrence of the sequence specified by its arguments.
		//std::string::erase() - Erases part of the string, reducing its length:
		//std::stoi()  - Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.

		// copy the string from the file in the local string
		std::string line = m_res;
		// define a delimeter between data
		std::string delimeter = ",";
		// remove white space from the string
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

		// Get Reservation ID from the string
		this->reservationID = line.substr(0, line.find(":"));
		line.erase(0, line.find(":") + 1);

		// Get Name from the string 
		this->name = line.substr(0, line.find(delimeter));
		line.erase(0, line.find(delimeter) + 1);

		// Get Email from the string 
		this->email = line.substr(0, line.find(delimeter));
		line.erase(0, line.find(delimeter) + 1);

		// Get Party Size from the string 
		std::string numOfPeople_str = line.substr(0, line.find(delimeter));
		this->numOfPeople = stoi(numOfPeople_str, nullptr, 10);
		line.erase(0, line.find(delimeter) + 1);

		// Get Day from the string 
		std::string day_str = line.substr(0, line.find(delimeter));
		this->day = stoi(day_str, nullptr, 10);
		line.erase(0, line.find(delimeter) + 1);

		// Get Hour from the string 
		std::string hour_str = line.substr(0, 5);
		this->hour = stoi(hour_str, nullptr, 10);
	}

	std::ostream& operator<<(std::ostream& out, const Reservation& ppReservations) {
		std::string event;
		if (ppReservations.hour >= 6 && ppReservations.hour <= 9) {
			event = "Breakfast";
		}
		else if (ppReservations.hour >= 11 && ppReservations.hour <= 15) {
			event = "Lunch";
		}
		else if (ppReservations.hour >= 17 && ppReservations.hour <= 21) {
			event = "Dinner";
		}
		else event = "Drinks";

		out << "Reservation " << ppReservations.reservationID << ": "
			<< std::setw(10) << std::right << ppReservations.name;
		out << std::left
			<< " <" << ppReservations.email << std::setw(3) << "> "
			<< event << " on day " << ppReservations.day << " @ " << ppReservations.hour
			<< ":00 for " << ppReservations.numOfPeople << " people." << '\n';
		return out;
	}

}
