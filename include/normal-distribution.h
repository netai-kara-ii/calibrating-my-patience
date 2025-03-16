#ifndef _NORMAL_DISTRIBUTION_H
#define _NORMAL_DISTRIBUTION_H

#include <cmath>
#include <numbers>


#include "types.h"


template <typename T>
class StandardGaussian final {
    public:
        ndarray<T> cdf(ndarray<T> x) {
            return (T)0.5 * ((T)1 + erf(x * INV_SQRT_TWO));
        }

        ndarray<T> icdf(ndarray<T> p) {
            ndarray<T> t = (T)2 * p - (T)1;
            t = t.unaryExpr(
                [&](T e) { return std::erf_inv(e); }, Eigen::Vectorized()
            ); 

            return SQRT_TWO * t;
        }
         
       
    private:
        static constexpr T INV_SQRT_TWO;
        static constexpr T SQRT_TWO; 

};

template <typename T>
constexpr T StandardGaussian<T>::INV_SQRT_TWO = static_cast<T>(std::numbers::inv_sqrt2);

template <typename T>
constexpr T StandardGaussian<T>::SQRT_TWO = static_cast<T>(std::numbers::sqrt2);


#endif
