#indef OPTIONS_H
#define OPTIONS_H


#include <memory>
#include <tuple>
#include <vector>


// local.
#include "underlying.h"
#include "types.h"



// -- ignore.
enum class trade_side {
    buy,
    sell,
    no_aggressor 
};


enum class option_type {
    put,
    call
};


class EuropeanOption final {
    // (Vanilla) European option class.

    public:
        explicit EuropeanOption(const Underlying &underlying, option_type type);
        
        static void set_strikes(ndarray_ptr<float> strikes) {
            EuropeanOption::strikes = strikes;
        }

        static void set_tenors(ndarray_ptr<float> tau) {
            EuropeanOption::tau = tau;
        }
        
        static std::vector<std::vector<int>> get_options(void) {
            return options;
        }
        
        float get_strike(void) const {
            auto [i, j] = idx;
            return (*strikes)(i, j);
        }

        float get_tenor(void) const {
            auto [i, j] = idx;
            return (*tau)(i, j);
        }

        std::tuple<int, int> get_index(void) const {
            return idx;
        }
    
        option_type get_option_type(void) const {
            return type;
        }
        
        Underlying underlying;
        friend class BlackScholes;


    private:
        option_type type;
        std::tuple<int, int> idx;
        inline static ndarray_ptr<float> strikes = nullptr;
        inline static ndarray_ptr<float> tau = nullptr;
        inline static ndarray_ptr<float> prices = nullptr;
        inline static std::vector<std::vector<int>> options = { {} };
};



#endif
