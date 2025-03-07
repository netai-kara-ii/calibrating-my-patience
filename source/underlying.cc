#include "underlying.h"

Underlying::Underlying(float spot, asset_type type) 
 : spot(spot), type(type) {
    idx = underlyings.size();
    underlyings.emplace_back(idx);
}
