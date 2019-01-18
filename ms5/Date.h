// Milestone 1
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Date.h

// Milestone 1
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Date.h

#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace aid {
  const int min_year = 2018;
  const int max_year = 2038;
  const int min_month = 1;
  const int max_month = 12;
  const int min_date = 751098;
  
  const int NO_ERROR = 0;
  const int CIN_FAILED = 1;
  const int DAY_ERROR = 2;
  const int MON_ERROR = 3;
  const int YEAR_ERROR = 4;
  const int PAST_ERROR = 5;
  
  class Date {
    int dYear, dMonth, dDay, dComparator, dErrorState;
    
    int mdays(int, int)const;
    int comparator(int, int, int) const;
    int value() const;
    void errCode(int);
    
  public:
    Date();
    Date(int, int, int);
    bool valid(int, int, int);
    
    //Relational Operators
    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
    
    //Queries and modifier
    int errCode() const;
    bool bad() const;
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr) const;
  };
    //Helper functions
    std::ostream &operator<<(std::ostream&, const Date&);
    std::istream &operator>>(std::istream&, Date&);
}
#endif