// Workshop 2
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

    class CRA_Account {
        char famName_t[max_name_length];
        char givenName_t[max_name_length];
        int sin_t;
    public:
        void set(const char* familyName, const char* givenName, int sin);
        bool isEmpty() const;
        void display() const;
    };
}

#endif