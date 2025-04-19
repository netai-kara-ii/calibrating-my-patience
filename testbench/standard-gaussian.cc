
// local.
#include "normal-distribution.h"
#include "types.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <vector>


// from google test.
#include <gtest/gtest.h>


class GaussianDistributionTest: public ::testing::Test {
    protected:
        void SetUp(void) override {
            tol = 1e-4;
            standard_gaussian = new StandardGaussian<double>();
        };

        void TearDown() override {
            delete standard_gaussian;
        };
        double tol;
        StandardGaussian<double> *standard_gaussian;
};
            

TEST_F(GaussianDistributionTest, CriticalPoints) {
    ndarray<double> real_vector(5, 1);
    real_vector << -std::numeric_limits<double>::infinity(), -3.0, 0.0,
        3.0, std::numeric_limits<double>::infinity();
    
    ndarray<double> cumulative_probabilities = standard_gaussian->cdf(real_vector);
    
    std::cout << cumulative_probabilities;
    //for (auto &e : cumulative_probabilities) {
     //   EXPECT_NEAR(e, , tol);
    //}
};
