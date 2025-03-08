#include "options.h"


#include <iostream>


void test_simple_input(void) {
    int x = 4;  // number of spot assets.
    int y = 10; // number of contingent claims / derivatives.


    Underlying spot_assets[4] = {
        {1.0f, asset_type::stock},
        {1.0f, asset_type::bond},
        {1.0f, asset_type::currency},
        {1.0f, asset_type::commodity}
    };

    std::vector<EuropeanOption> stock_options;
    for (int i = 0; i < y; i++) {
         stock_options.emplace_back(
            EuropeanOption(spot_assets[0], option_type::call)
        );
    }
    
    for (auto &option : stock_options) {
        auto [i, j] = option.get_index();

        std::cout << i << ", " << j << "\n";
    }
}

int main(void) {

    test_simple_input();

    return 0;
}
