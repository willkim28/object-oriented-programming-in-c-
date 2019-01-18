// Milestone 3
// Name: Woohyun Kim
// Student #: 122733157
// Course: OOP244 Fall 2018
// File: Good.h

#ifndef AMA_GOOD_H
#define AMA_GOOD_H
#include "Error.h"

namespace aid {
    const int MAX_SKU_LENGTH = 7;
    const int MAX_UNIT_LENGTH = 10;
    const int MAX_NAME_LENGTH = 75;
    const double currentTax = 0.13;
    const int W_MAX_NAME = 20;
    const int W_MAX_QUANT = 4;
    
    const int max_sku_length = MAX_SKU_LENGTH;
    const int max_unit_length = MAX_UNIT_LENGTH;
    const int max_name_length = MAX_NAME_LENGTH;
    
    class Good {
        char goodType;
        char goodSku[MAX_SKU_LENGTH + 1];
        char goodUnit[MAX_UNIT_LENGTH + 1];
        char* goodName;
        int goodInven;
        double goodPrice;
        bool goodTaxable;
        int goodNeeded;
        Error err;
        
    protected:
        void name(const char*);
        const char* name() const;
        const char* sku() const;
        const char* unit() const;
        bool taxed() const;
        double itemPrice() const;
        double itemCost() const;
        void message(const char*);
        bool isClear() const;
        
    public:
        Good(char goodType = 'N');
        Good(const char* c_sku, const char* c_name, const char* c_unit, int goodInven = 0, bool goodTaxable = true, double goodPrice = 0.0, int goodNeeded = 0);
        Good(const Good&);
        Good& operator=(const Good&);
        ~Good();
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator==(const char*) const;
        double total_cost() const;
        void quantity(int);
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char*) const;
        bool operator>(const Good&) const;
        int operator+=(int);
    };
        std::ostream& operator<<(std::ostream&, const Good&);
        std::istream& operator>>(std::istream&, Good&);
        double operator+=(double&, const Good&);
}

#endif