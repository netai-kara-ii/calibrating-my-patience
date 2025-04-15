#ifndef _NORMAL_DISTRIBUTION_H
#define _NORMAL_DISTRIBUTION_H


#include <cmath>
#include <numbers>


#include "types.h"

#include <boost/math/special_functions/erf.hpp>
#include <unsupported/Eigen/SpecialFunctions>

template <typename T>
class StandardGaussian final {

        /*
         * Vectorised cdf and icdf for the standard Gaussian (zero mean,
         * unit variance) distribution. 
        */

        static_assert(std::is_floating_point_v<T>);

    private:
        static constexpr T INV_SQRT_TWO = static_cast<T>(1. / 1.4142135623730951);
        static constexpr T SQRT_TWO = static_cast<T>(1.4142135623730951);

    public:
        ndarray<T> cdf(ndarray<T> x) { 

            /*
             * Args: n-space vector of points x, of any real type.
             *
             * Performs element-wise cumulative distribution function in terms
             * of the erf. Uses built-in eigen function.
            */

               return (T)0.5 * ((T)1 + erf(x * INV_SQRT_TWO)); 
        }

        ndarray<T> icdf(ndarray<T> p) {

            /*
             * Args: n-space vector of probabilities p, therefore verifying 
             * 0 <= p_i <= 1 for every i = 1, ..., n, of any real type.
             * 
             * Performs element-wise inverse cummulative distribution function
             * (i.e., quantile), in terms of the inverse erf. Passes a capture
             * -less lambda that shifts and scales arguments to fit the target
             * Gaussian distribution. The initial idea was to use a function 
             * pointer but eigen does not like it.
            */

            return p.unaryExpr([](T e) { return SQRT_TWO * boost::math::erf_inv((T)2 * e - (T)1); }); 
        }
};



#endif
