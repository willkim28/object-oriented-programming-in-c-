// Workshop 3
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: CRA_Account.h

#ifndef sict_CRA_Account_h
#define sict_CRA_Account_h


namespace sict {
  const int max_name_length = 40;
  const int min_sin = 100000000;
  const int max_sin = 999999999;
  const int max_yrs = 4;

    class CRA_Account {
        char famName_t[max_name_length];
        char givenName_t[max_name_length];
        int sin_t;
        int year_t[max_yrs];
        double balance_t[max_yrs];
        int years_t;
    public:
        void set(const char* familyName, const char* givenName, int sin);
        void set(int, double);
        bool isEmpty() const;
        void display() const;
    };
}

#endif