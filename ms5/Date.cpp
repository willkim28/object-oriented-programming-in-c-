
#include <iostream>
#include "Date.h"
using namespace std;

namespace aid {

	// number of days in month mon and year
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
	
	//sets error code
	void Date::errCode(int errorCode) {
	    dErrorState = errorCode;
	}
	
	//put calculation here to cut down on repetition
	int Date::comparator(int y, int m, int d) const {
		return (y * 372 + m * 31 + d);
	}
	
	//valid tester
	bool Date::valid(int year, int month, int day) {
		return (year >= min_year || year <= max_year) && (month >= min_month && month <= max_month) && (day <= mdays(month, year && day >= 1)) && (comparator(year, month, day) >= min_date);
	}
	
	Date::Date() {
		//set to safe empty state
		//will be properly formatted in write
		dYear = 0;
		dMonth = 0;
		dDay = 0;
		dComparator = 0;
		dErrorState = NO_ERROR;
	}
	
	Date::Date(int year, int month, int day) {
		//check if input is valid
		if (valid(year, month, day)) {
			//then save them
			dYear = year;
			dMonth = month;
			dDay = day;
			//using comparator calc
			dComparator = comparator(year,month,day);
			dErrorState = NO_ERROR;
		} else {
			//set to safe empty state
			*this = Date();
		}
	}
	
	//used for comparing comparator values
	int Date::value() const {
    	return comparator(dYear, dMonth, dDay);
  }

	bool Date::operator==(const Date& rhs) const {
		return (this->value() == rhs.value());
	}
	
	bool Date::operator!=(const Date& rhs) const {
		return (this->value() != rhs.value());
	}
	
	bool Date::operator<(const Date& rhs) const {
		return (this->value() < rhs.value());
	}
	
	bool Date::operator>(const Date& rhs) const {
		return (this->value() > rhs.value());
	}
	
	bool Date::operator<=(const Date& rhs) const {
		return (this->value() <= rhs.value());
	}
	
	bool Date::operator>=(const Date& rhs) const {
		return (this->value() >= rhs.value());
	}
	
	//return error code
	int Date::errCode() const {
		return dErrorState;
	}
	
	//return whether error state is NO_ERROR or nto
	bool Date::bad() const {
		return dErrorState != NO_ERROR;
	}
	
	//read date from console
	std::istream& Date::read(std::istream& istr) {
    int year, month, day;
		//placeholder for divider
		char div;
    	//accept input in format
    	istr >> year >> div >> month >> div >> day; 

	    //for each condition, return the relevant error code
	    if (istr.fail()) {
	      *this = Date();
	      errCode(CIN_FAILED);
	    } else if (year < min_year || year > max_year) {
	      errCode(YEAR_ERROR);
	    } else if (month < min_month || month > max_month) {
	      errCode(MON_ERROR);
	    } else if (day > mdays(month, year)) {
	      errCode(DAY_ERROR);
	    } else if (comparator(year, month, day) < min_date) {
	      errCode(PAST_ERROR);
	    } else {
        *this = Date(year, month, day);
        istr.clear();
      }
	    //return istr regardless
	    return istr;
	}
	
	std::ostream& Date::write(std::ostream& ostr) const {
	//format YYYY/MM/DD
    	char sl = '/';
		ostr << dYear << sl;
		//width and fill to format single digit numbers
    ostr.fill('0');
		ostr.width(2);
		ostr << dMonth << sl;
		ostr.width(2);
		ostr << dDay;
		//retun ostr
		return ostr;
	}
	
	//read date from console
	std::istream& operator>>(std::istream& istr, Date& i) {
    i.read(istr);
		return istr;
	}
	
	//print date to console
	std::ostream& operator<<(std::ostream& ostr, const Date& o) {
		o.write(ostr);
    return ostr;
	}
}