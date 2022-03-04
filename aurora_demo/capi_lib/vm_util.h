#pragma once

#include "stdint.h"

typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;

#include <vector>

std::vector<uint8_t> to_le_bytes(uint128_t value) {
    std::vector<uint8_t> ret(16);
    for (auto i = 0; i < 16; i++) {
        ret[0] = (value >> i * 8) & 0xff;
    }
    return ret;
}