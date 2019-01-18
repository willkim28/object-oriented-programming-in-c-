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
            int nameLength = strlen(name);
            int cNameLength = (nameLength < MAX_CHAR) ? nameLength : MAX_CHAR;
            for (int i = 0; i < cNameLength; i++) {
                cName[i] = name[i];
            }
            cName[cNameLength] = '\0';
        } else {
          cName[0] = '\0';
          }
        
        //Phone Numbers
        if (phoneNumbers != nullptr && noOfNumbers > 0) {
            cNumbers = new long long[noOfNumbers];
            cNoOfNumbers = 0;
            //needed to make sure 0s aren't added
            //this method would add 0's inbetween as well
            for (int i = 0; i < noOfNumbers; i++) {
                if (isValid(phoneNumbers[i])) {
                  cNumbers[cNoOfNumbers] = phoneNumbers[i];
                  cNoOfNumbers++;
                }
            }
        } else {
          cNumbers = nullptr;
          cNoOfNumbers = 0;
        }
    }
    
    Contact::~Contact() {
        delete[] cNumbers;
        cNumbers = nullptr;
    }
    
    bool Contact::isEmpty() const {
        return (cName[0] == '\0' && cNumbers == nullptr && cNoOfNumbers == 0);
    }

    bool Contact::isValid(const long long number) const {
        //Use length instead of strlen
        string numberString = to_string(number);
        bool flag = !(        numberString.length() < numSize-1 ||
        numberString.length() > numSize ||
        number <= 0 ||
        numberString[numberString.length() - 10] == 0 ||
        numberString[numberString.length() - 7] == 0);
        return flag;
    }
    void Contact::display() const {
      string numString;
      string numCountry, numArea, numPrefix, numLine;
      int numLength;
        if (!isEmpty()) {
            cout << cName << endl;
            if (cNumbers != nullptr && cNumbers[0] != '\0') {
              for (int i = 0; i < cNoOfNumbers; i++) {
                //flooring would work differently on different # of digits
                //convert to string
                numString = to_string(cNumbers[i]);
                numLength = numString.length();
                //increment for simplicity of code
                int currLeng = 0;
                //could treat 11 and 12 length differently, but for better functionality
                numCountry = numString.substr(currLeng, (numLength - (areaLength + numberLength)));
                currLeng += numCountry.length();

                numArea = numString.substr(currLeng, areaLength);
                currLeng += numArea.length();

                numPrefix = numString.substr(currLeng, (areaLength));
                currLeng += numPrefix.length();

                numLine = numString.substr(currLeng, (numberLength - areaLength));

                cout << "(+" + numCountry + ") " + numArea + " " + numPrefix + "-" + numLine << endl;
              }
            }
        } else {
            cout << "Empty contact!" << endl;
        }
    }
}