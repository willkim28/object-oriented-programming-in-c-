// Milestone 3
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Good.cpp

#include "Good.h"

using namespace std;

namespace aid {
    void Good::name(const char* g_goodName) {
        if (g_goodName != nullptr) {
            int nameLen = strlen(g_goodName);
            goodName = nullptr;
            goodName = new char[nameLen];
            for (int i = 0; i < nameLen; ++i) {
                goodName[i] = g_goodName[i];
            }
            goodName[nameLen] = '\0';
        } else {
            goodName = nullptr;
        }
    }
    
    const char* Good::name() const {
        if (goodName != nullptr) {
            return goodName;
        } else {
            return nullptr;
        }
    }
    
    const char* Good::sku() const {
        return goodSku;
    }
    
    const char* Good::unit() const {
        return goodUnit;
    }
    
    bool Good::taxed() const {
        return goodTaxable;
    }
    
    double Good::itemPrice() const {
        return goodPrice;
    }
    
    double Good::itemCost() const {
        if (goodTaxable) {
            return (itemPrice() * (1 + currentTax));
        } else {
            return itemPrice();
        }
    }
    
    void Good::message(const char* c_errMsg) {
        err.message(c_errMsg);
    }
    
    bool Good::isClear() const {
        return err.isClear();
    }
    
    Good::Good(char c_type) {
        goodType = c_type;
        goodSku[0] = '\0';
        goodUnit[0] = '\0';
        goodName = nullptr;
        goodInven = 0;
        goodNeeded = 0;
        goodPrice = 0;
        goodTaxable = false;
    }
    
    Good::Good(const char* c_sku, const char* c_name, const char* c_unit, int c_noOfGoods, bool c_taxable, double c_price, int c_noNeeded) {
        name(c_name);
        strncpy(goodSku, c_sku, MAX_SKU_LENGTH + 1);
        goodSku[MAX_SKU_LENGTH] = '\0';
        strncpy(goodUnit, c_unit, MAX_UNIT_LENGTH + 1);
        goodUnit[MAX_UNIT_LENGTH] = '\0';
        goodInven = c_noOfGoods;
        goodNeeded = c_noNeeded;
        goodTaxable = c_taxable;
        goodPrice = c_price;
    }
    
    Good::Good(const Good& r) {
        name(r.goodName);
        goodType = r.goodType;
        strncpy(goodSku, r.goodSku, MAX_SKU_LENGTH + 1);
        goodSku[MAX_SKU_LENGTH] = '\0';
        strncpy(goodUnit, r.goodUnit, MAX_UNIT_LENGTH + 1);
        goodUnit[MAX_UNIT_LENGTH] = '\0';
        goodInven = r.goodInven;
        goodNeeded = r.goodNeeded;
        goodPrice = r.goodPrice;
        goodTaxable = r.goodTaxable;
    }
    
    Good &Good::operator=(const Good& rhs) {
        if (this != &rhs) {
            goodType = rhs.goodType;
            strncpy(goodSku, rhs.goodSku, MAX_SKU_LENGTH + 1);
            goodSku[MAX_SKU_LENGTH] = '\0';
            strncpy(goodUnit, rhs.goodUnit, MAX_UNIT_LENGTH + 1);
            goodUnit[MAX_UNIT_LENGTH] = '\0';
            goodInven = rhs.goodInven;
            goodNeeded = rhs.goodNeeded;
            goodPrice = rhs.goodPrice;
            goodTaxable = rhs.goodTaxable;
            delete[] goodName;
            name(rhs.goodName);
        }
        return *this;
    }
    
    Good::~Good() {
        delete[] goodName;
    }
    
    fstream& Good::store(fstream& file, bool newLine) const {
        file << goodType << ',' << goodSku << ',' << goodUnit << ',' << goodName << ',' << ',' << goodInven << ',' << goodTaxable << ',' << goodPrice << ',' << goodNeeded;
        if (newLine) {
            file << endl;
        }
        file.clear();
        file.close();
        return file;
    }
    
    fstream& Good::load(fstream& file) {
        Good temp;
        temp.goodName = new char[MAX_NAME_LENGTH + 1];
        if (file.is_open()) {
            file >> goodType >> goodSku >> goodUnit >> goodName >> goodInven >> goodTaxable >> goodNeeded;
            *this = temp;
        }
        delete[] temp.goodName;
        temp.goodName = nullptr;
        
        return file;
    }
    
    ostream& Good::write(ostream& os, bool linear) const {
        if (linear) {
            os << setw(MAX_SKU_LENGTH) << left << goodSku << "|" 
            << setw(W_MAX_NAME) << left << goodName << "|"
            << setw(MAX_SKU_LENGTH) << right << fixed << setprecision(2) << itemCost() << "|"
            << setw(W_MAX_QUANT) << right << goodInven << "|"
            << setw(MAX_UNIT_LENGTH) << left << goodUnit << "|"
            << setw(W_MAX_QUANT) << right << goodNeeded << "|";
        } else {
            os << "Sku: " << goodSku << endl
            << "Name: " << goodName << endl
            << "Price: " << goodPrice << endl;
            if (taxed()) {
                os << "Price after tax: " << itemCost() << endl;
            } else {
                os << "N/A" << endl;
            }
        os << "Quantity on hand: " << goodInven << endl;
        os << "Quantity needed: " << goodNeeded << endl;
        }
        return os;
    }
    
    istream& Good::read(istream& is) {
        char sku_r[MAX_SKU_LENGTH + 1];
        char unit_r[MAX_UNIT_LENGTH + 1];
        char* goodName_r = new char[MAX_NAME_LENGTH + 1];
        int goodInven_r;
        double goodPrice_r;
        bool goodTaxable_r;
        int goodNeeded_r;
        char taxC_r;
        
        cout << " Sku: ";
        is >> sku_r;
        
        cout << " Name (no spaces): ";
        is >> goodName_r;
        
        cout << " Unit: ";
        is >> unit_r;
        
        cout << " Taxed? (y/n): ";
        //of course you can't just try w goodTaxable_r... this took me 2 hours to figure out
        is >> taxC_r;
        if (taxC_r == 'Y' || taxC_r == 'y') {
            goodTaxable_r = true;
        } else if (taxC_r == 'N' || taxC_r == 'n') {
            goodTaxable_r = false;
        } else {
            is.setstate(ios::failbit);
            err.message("Only (Y)es or (N)o are acceptable");
        }
        
        if (!is.fail()) {
            cout << " Price: ";
            is >> goodPrice_r;
            if (is.fail()) {
                err.message("Invalid Price Entry");
            }
        }
        
        if (!is.fail()) {
            cout << " Quantity on hand: ";
            is >> goodInven_r;
            if (is.fail()) {
                err.message("Invalid Quantity Entry");
            }
        }
        
        if (!is.fail()) {
            cout << " Quantity needed: ";
            is >> goodNeeded_r;
            if (is.fail()) {
                err.message("Invalid Quantity Needed Entry");
            }
        }
        
        if (!is.fail()) {
            Good temp = Good(sku_r, goodName_r, unit_r, goodInven_r, goodTaxable_r, goodPrice_r, goodNeeded_r);
            *this = temp;
        }
        
        //clear up memory
        delete[] goodName_r;
        goodName_r = nullptr;
        
        //return result of function
        return is;
    }
    
    bool Good::operator==(const char* string) const {
        //strcmp for differences
        return (strcmp(string, this->goodSku) == 0);
    }
    
    double Good::total_cost() const {
        //return product of functions
        return quantity() * itemCost();
    }
    
    void Good::quantity(int units) {
        //set goodInven by input
        goodInven = units;
    }
    
    bool Good::isEmpty() const {
        //check for bool comparison on goodName
        return (goodName == nullptr);
    }
    
    int Good::qtyNeeded() const {
        return goodNeeded;
    }
    
    int Good::quantity() const {
        return goodInven;
    }
    
    bool Good::operator>(const char* comp_sku) const {
        return (strcmp(goodSku, comp_sku) > 0);
    }
    
    bool Good::operator>(const Good& comp) const {
        return (strcmp(goodName, comp.goodName) > 0);
    }
    
    int Good::operator+=(int add_unit) {
        if (add_unit > 0) {
            goodInven += add_unit;
        }
        return goodInven;
    }
    
    ostream& operator<<(ostream& os, const Good& other) {
        return other.write(os, true);
    }
    
    istream& operator>>(istream& is, Good& other) {
        other.read(is);
        return is;
    }
    
    double operator+=(double& total, const Good& other) {
        total += other.total_cost();
        return total;
    }
}