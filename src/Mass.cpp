#include "Mass.h"
#include <iostream>

Mass::Mass() {
    // base = gram
    multipliers["g"] = 1.0;
    multipliers["kg"] = 1000.0;
    multipliers["mg"] = 0.001;
    multipliers["ton"] = 1000000.0;
    multipliers["lb"] = 453.592;
    multipliers["oz"] = 28.3495;
}

double Mass::toBase(double value, std::string unit){
    if (multipliers.count(unit)) {
        return value * multipliers[unit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0; 
}

double Mass::fromBase(double baseValue, std::string targetUnit) {
    if (multipliers.count(targetUnit)) {
        return baseValue / multipliers[targetUnit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0; // Error
}