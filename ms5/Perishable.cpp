#include "Perishable.h"

using namespace std;

namespace aid {
    Perishable::Perishable() : Good('P'){
        expDate = Date();
    }
    
    std::fstream& Perishable::store(fstream& file, bool newLine) const {
        Good::store(file, false);
        file << ",";
        expDate.write(file);
        if (newLine == true) {
            file << endl;
        }
        return file;
    }
    
    fstream& Perishable::load(fstream& file) {
        Good::load(file);
        file.ignore();
        expDate.read(file);
        file.ignore();
        return file;
    }
    
    ostream& Perishable::write(ostream& os, bool linear) const {
        Good::write(os, linear);
        
        if (isClear() && !isEmpty()) {
            if (linear) {
                expDate.write(os);
            } else {
                os << '\n' << " Expiry date: ";
                expDate.write(os);
            }
        }
        return os;
    }
    
    istream& Perishable::read(istream& is) {
        Good::read(is);
        Date temp = Date();
        if (!is.fail()) {
            cout << " Expiry date (YYYY/MM/DD): ";
            is >> temp;
            if (temp.bad()) {
                    is.setstate(std::ios::failbit);
                    if (temp.errCode() == CIN_FAILED) {
                        Good::message("Invalid Date Entry");
                    }
                    else if (temp.errCode() == DAY_ERROR) {
                        Good::message("Invalid Day in Date Entry");
                    }
                    else if (temp.errCode() == MON_ERROR) {
                        Good::message("Invalid Month in Date Entry");
                    }
                    else if (temp.errCode() == YEAR_ERROR) {
                        Good::message("Invalid Year in Date Entry");
                    }
                    else if (temp.errCode() == PAST_ERROR) {
                        Good::message("Invalid Expiry in Date Entry");
                    }
                } else {
                  expDate = temp;
                }
        }
        return is;
    }
    
    const Date& Perishable::expiry() const {
        return expDate;
    }
}