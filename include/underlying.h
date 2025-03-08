#ifndef UNDERLYING_H
#define UNDERLYING_H

#include <vector>


enum class asset_type {
    stock,
    bond,
    currency,
    commodity
};

/* 
  think about better api design. exposed
  member attributes? or encapsulate? first
  is more convenient but can lead to errors.
*/


class Underlying final {
    public:
        Underlying(float spot, asset_type type);
        
        static std::vector<int> get_underlyings(void) {
            return underlyings;
        }

        friend class EuropeanOption;

        float spot;
        asset_type type;
        int idx;

    private:
        inline static std::vector<int> underlyings = {};
};



class EncapsulatedUnderlying final {
    public:
        Underlying(float spot, asset_type type);
        
        static std::vector<int> get_underlyings(void) {
            return underlyings;
        }

        int get_index(void) const {
            return idx;
        }

        float get_spot_price(void) const {
            return spot;
        }
        
        asset_type get_asset_type(void) const {
            return type;
        }
        
        friend class EuropeanOption;


    private:
        inline static std::vector<int> underlyings = {};
        float spot;
        asset_type type;
        int idx;
};


#endif 
