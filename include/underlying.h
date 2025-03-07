#ifndef UNDERLYING_H
#define UNDERLYING_H

#include <vector>


enum class asset_type {
    stock,
    bond,
    currency,
    commodity
};


class Underlying final {
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
        float spot;
        asset_type type;
        int idx;
        inline static std::vector<int> underlyings = {};
};


#endif 
