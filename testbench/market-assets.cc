
// local.
#include "underlying.h"
#include "options.h"

#include <iostream>
#include <cmath>

// from google test.
#include <gtest/gtest.h>


class MarketAssetsTest : public ::testing::Test {
    protected:
        void SetUp(void) override {
            stock = new Underlying(1.0, asset_type::stock);
            bond = new Underlying(1.0, asset_type::bond);
        };

        void TearDown() override {
            delete stock;
            delete bond;
        };

        Underlying *stock, *bond;
};
            

TEST_F(MarketAssetsTest, CorrectIndices) {
    unsigned int n_contracts = 1 << 5;
    unsigned int midpoint = (unsigned int) std::floor(n_contracts / 2);

    std::vector<EuropeanOption> options;
    options.reserve(n_contracts);

    for (unsigned int i = 0; i < n_contracts; i++) {
         if (i < midpoint) {
            options.emplace_back(EuropeanOption(*stock, option_type::put));
         } else {
            options.emplace_back(EuropeanOption(*stock, option_type::call));
         }
    }

    for (unsigned int i = 0; i < n_contracts; i++) {
        EXPECT_EQ(options[i].get_index(), std::make_tuple(i, 0));
    }
}
