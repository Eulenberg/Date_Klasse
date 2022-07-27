/* date.cpp
   osk-2010, osk-2013
   Grundzuege einer einfache Klasse für Datumsangaben.
 */
#include "date.h"
#include <iostream>
#include <iomanip>
#include <string>


Date::Date() // delegierender Standardkonstruktor
	: Date{ 1876, Date::Jan, 1 }
{ }


Date::Date(int yy, Month mm, int dd) // ein Konstruktor
	: y{ yy }, m{ mm }, d{ dd }
{ if (!check()) throw Invalid{}; }


int Date::year() const { 
	return y; 
}

Date::Month Date::month() const {
	return m; 
}

int Date::day() const { 
	return d; 
}

std::string Date::month_string() const {
	switch (m)
	{
	case Date::Jan:
		return "Jan";
		break;
	case Date::Feb:
		return "Feb";
		break;
	case Date::Mrz:
		return "Mrz";
		break;
	case Date::Apr:
		return "Apr";
		break;
	case Date::Mai:
		return "Mai";
		break;
	case Date::Jun:
		return "Jun";
		break;
	case Date::Jul:
		return "Jul";
		break;
	case Date::Aug:
		return "Aug";
		break;
	case Date::Sep:
		return "Sep";
		break;
	case Date::Okt:
		return "Okt";
		break;
	case Date::Nov:
		return "Nov";
		break;
	case Date::Dez:
		return "Dez";
		break;

	}
}


bool Date::check() const // Invarianten pruefen
{
	if (y < 1800 || 2200 < y) return false; // Jahresbereich

	if (m < Jan || Dez < m) return false;   // falscher Monat, kann passieren z.B. durch Date::Month(13)

	if (d < 1) return false; // Tag kann minimal der 1. sein

	switch (m)
	{ // Tag kann maximal pro Monat 28./29. oder 30. oder 31. sein
	case Feb: // ohne Schaltjahre
		if (isSchaltjahr(y) && 29 < d) return false;
		if (!isSchaltjahr(y) && 28 < d) return false;
	case Apr: case Jun: case Sep: case Nov:
		if (d > 30) return false;
	default:
		if (d > 31) return false;
	}
	return true;
}


int Date::compare_to(const Date& other) const
{
	if (year() == other.year() && month() == other.month() && day() == other.day()) {
		return 0;
	}

	else if (year() > other.year()) {
		return 1;

	}
	else if (month() > other.month() && year() >= other.year()) {
		return 1;

	}

	else if (month() >= other.month() && year() >= other.year() && day() > other.day()) {
		return 1;

	}

	else { return -1; };
}


void Date::change_days(const int& n)
{
	if (n == 0) return;
	if (n > 0) {
		for (int i{}; i < n; i++) {

			incDay();

		}
	}
	if (n < 0) {
		for (int i{}; i > n; i-- ) {

			decDay();

		}
	}

	if (!check()) throw Invalid(); // 31.Mrz + 1 Monat = 31.Apr : Fehler
	return;
}


// Stream Insertion Operator << ueberladen (nicht Klassenmember): 
ostream& operator<<(std::ostream& os, const Date& d)
{
	return os << d.year() << '-' << d.month_string() << '-' << std::setfill('0') << std::setw(2) << d.day();
}


// Praefix Inkrement Operator ++ ueberladen (nicht Klassenmember)
Date::Month& operator++(Date::Month& mon)
{
	mon = (mon == Date::Dez) ? Date::Jan : Date::Month(mon + 1);
	return mon;
}

Date::Month& operator--(Date::Month& mon)
{
	mon = (mon == Date::Jan) ? Date::Dez : Date::Month(mon - 1);
	return mon;
}

Date& operator++(Date& dDate) {
	dDate.change_days(1);
	return dDate;
}

Date& operator--(Date& dDate) {
	dDate.change_days(-1);
	return dDate;
}



bool isSchaltjahr(int iYear) {
	if (iYear % 400 == 0) {
		return true;
	}
	if (iYear % 4 == 0 && (iYear % 100 != 0)) {
		return true;
	}
	return false;

}


void Date::incDay() {
	if (m == 12 && d == 31) {
		d = 1;
		m = Jan;
		y++;
		if (!check()) throw Invalid();
		return;
	}
	if ((d == 28 && m == 2) && isSchaltjahr(y) == false) {
		d = 1;
		++m;
		if (!check()) throw Invalid();
		return;
	}
	if ((d == 29 && m == 2) && isSchaltjahr(y) == true) {
		d = 1;
		++m;
		if (!check()) throw Invalid();
		return;
	}

	if (d == 30 && ((m == 4) || m == 6 || m == 9 || m == 11)) {
		d = 1;
		++m;
		if (!check()) throw Invalid();
		return;
	}

	if (d == 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)) {
		d = 1;
		++m;
		if (!check()) throw Invalid();
		return;
	}
	else {
		d++;
			
	}

	if (!check()) throw Invalid();

}

void Date::decDay() {
	if (m == 1 && d == 1) {
		d = 31;
		--m;
		--y;
		if (!check()) throw Invalid();
		return;
	}
	if ((d == 1 && m == 3) && isSchaltjahr(y) == false) {
		d = 28;
		--m;
		if (!check()) throw Invalid();
		return;
	}
	if ((d == 1 && m == 3) && isSchaltjahr(y) == true) {
		d = 29;
		--m;
		if (!check()) throw Invalid();
		return;
	}
	if (d == 1 && (m == 5 || m == 7 || m == 10 || m == 12)) {
		--m;
		d = 30;
		if (!check()) throw Invalid();
		return;

	}

	if (d == 1 && (m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11)) {
		--m;
		d = 31;
		if (!check()) throw Invalid();
		return;

	}
	d--;
	if (!check()) throw Invalid();

}
