#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H


#include <Eigen/Dense>
#include <cstdint>


template <typename T>
class BlackScholes {

        /*
         * Implements foreign exchange (fx) Black Scholes option pricing
         * (Garman & Kolhagen (1983)). Uses fx market conventions.
        */   
   
    public: 
        using ndarray = Eigen::Array<T, Eigen::Dynamic, Eigen::Dynamic>;
        
        /*
         * Defining type alias within the class for locality of behaviour.
         * Further, being public exposes it as a valid data type specifier
         * beyond the class scope. Must be defined before use, so that it 
         * remains visible during compiler name look-up (parsing).
        */

    private:
        static_assert(std::is_floating_point_v<T>);

    public: 
        BlackScholes(T spot) : spot(spot) {}

        

#endif
