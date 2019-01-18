// Workshop 6
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Contact.cpp

#include <iostream>
#include <cstring>
#include "Contact.h"

using namespace std;

namespace sict {
    Contact::Contact() {
        cName[0] = '\0';
        cNumbers = nullptr;
        cNoOfNumbers = 0;
    }
    
    Contact::Contact(const char *name, const long long *phoneNumbers, const int noOfNumbers) {
        
        //Name and # of #s
        if (name != nullptr && name[0] != '\0') {
            //define a var to be length of name
            int nameLength = strlen(name);
            //take whichever is shorter between MAX_CHAR and input length
            int cNameLength = (nameLength < MAX_CHAR) ? nameLength : MAX_CHAR;
            for (int i = 0; i < cNameLength; ++i) {
                cName[i] = name[i];
            }
            cName[cNameLength] = '\0';
        } else {
          cName[0] = '\0';
          }
        
        //Phone Numbers
        if (phoneNumbers != nullptr && noOfNumbers > 0) {
            //allocate new dynamic array, size of noOfNumbers
            cNumbers = new long long[noOfNumbers];
            cNoOfNumbers = 0;
            //needed to make sure 0s aren't added
            //this method would add 0's inbetween as well
            for (int i = 0; i < noOfNumbers; ++i) {
                if (isValid(phoneNumbers[i])) {
                  cNumbers[cNoOfNumbers] = phoneNumbers[i];
                  ++cNoOfNumbers;
                }
            }
        } else {
          cNumbers = nullptr;
          cNoOfNumbers = 0;
        }
    }
    
    Contact::~Contact() {
        //deallocate cNumbers
        delete[] cNumbers;
        //set to safe empty state just in case?
        cNumbers = nullptr;
    }
    
    bool Contact::isEmpty() const {
        //instead of checking for everything else, just check if name is empty
        return (cName[0] == '\0');
    }

    //checks validity of number
    bool Contact::isValid(const long long number) const {
        //Use length instead of strlen
        string numberString = to_string(number);
        bool flag = 
        //if NOT
        //less than numSize -1 OR
        !(numberString.length() < numSize-1 ||
        //greater than numSize OR
        numberString.length() > numSize ||
        //equal or less than zero OR
        number <= 0 ||
        //country/area code/number starts with 0
        numberString[numberString.length() - 10] == 0 ||
        numberString[numberString.length() - 7] == 0) ||
        numberString[0] == 0;
        return flag;
    }
    void Contact::display() const {
        //set strings for conversion
        string numString;
        string numCountry, numArea, numPrefix, numLine;
        //if not empty
        if (!isEmpty()) {
            //print name first
            cout << cName << endl;
            //check if numbers are valid
            if (cNumbers != nullptr && cNumbers[0] != '\0') {
              for (int i = 0; i < cNoOfNumbers; ++i) {
                //flooring would work differently on different # of digits
                //convert to string
                numString = to_string(cNumbers[i]);
                //numLength takes the length of the string
                int numLength = numString.length();
                
                //incrementer
                int currLeng = 0;
                //could treat 11 and 12 length differently, but for simpler functionality
                
                //country string
                numCountry = numString.substr(currLeng, (numLength - (areaLength + numberLength)));
                currLeng += numCountry.length();
                
                //area string
                numArea = numString.substr(currLeng, areaLength);
                currLeng += numArea.length();
                
                //number's prefix string
                numPrefix = numString.substr(currLeng, (areaLength));
                currLeng += numPrefix.length();
                
                //number's line string
                numLine = numString.substr(currLeng, (numberLength - areaLength));
                
                //print in format
                cout << "(+" + numCountry + ") " + numArea + " " + numPrefix + "-" + numLine << endl;
              }
            }
        } else {
            cout << "Empty contact!" << endl;
        }
        }
        
    Contact::Contact(const Contact& src) {
    cNumbers = nullptr;
    *this = src;
    }
    
    Contact& Contact::operator=(const Contact& rhs) {
        //if object does not match
        if (this != &rhs) {
            //copy
            strncpy(cName, rhs.cName, MAX_CHAR);
            //set last char to null terminator
            cName[MAX_CHAR - 1] = '\0';
            //copy NoOfNumbers as well
            cNoOfNumbers = rhs.cNoOfNumbers;
            //delete old
            delete[] cNumbers;
            //and set to safe empty state
            cNumbers = nullptr;
            
            //if right hand side number is not in safe empty state
            if (rhs.cNumbers != nullptr) {
                //allocate new dynamic array and set its contents
                cNumbers = new long long[cNoOfNumbers];
                for (int i = 0; i < cNoOfNumbers; ++i) {
                    cNumbers[i] = rhs.cNumbers[i];
                }
            } else {
                //else set to safe empty state
                cNumbers = nullptr;
            }
        }
        //return reference to current object regardless
        return *this;
    }
    
    Contact& Contact::operator+=(long long source) {
        //validates number received
        if (isValid(source)) {
            //increment number of numbers
            ++cNoOfNumbers;
            //allocate temp dynamic array
            long long* cNumbers2 = nullptr;
            cNumbers2 = new long long[cNoOfNumbers];
            
            //copy old array to temp array
            for (int i = 0; i < cNoOfNumbers - 1; ++i) {
                cNumbers2[i] = cNumbers[i];
            }
            //delete old array
            delete[] cNumbers;
            cNumbers = nullptr;
            //copy temp array to old array
            cNumbers = cNumbers2;
            //add new number to array
            cNumbers[cNoOfNumbers - 1] = source;
        }
        //return reference to current object regardless
        return *this;
    }
}