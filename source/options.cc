#include "options.h"

EuropeanOption::EuropeanOption(const Underlying &underlying, option_type type)
 : underlying(underlying), type(type) {
    int j = underlying.idx;

    if (options.size() <= static_cast<std::size_t>(j)) {
        options.resize(j + 1);
    }

    int i = options[j].size();
    options[j].emplace_back(i);
    idx = std::make_tuple(i, j);
}
