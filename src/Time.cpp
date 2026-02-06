#include "Time.h"
#include <iostream>

Time::Time() {
    // base = second
    multipliers["s"] = 1.0;
    multipliers["min"] = 60.0;
    multipliers["hr"] = 3600.0;
    multipliers["ms"] = 0.001;
    multipliers["ns"] = 0.000000001;
}

double Time::toBase(double value, std::string unit){
    if (multipliers.count(unit)) {
        return value * multipliers[unit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0; 
}

double Time::fromBase(double baseValue, std::string targetUnit) {
    if (multipliers.count(targetUnit)) {
        return baseValue / multipliers[targetUnit];
    }
    std::cerr << "Error: Unit not found\n";
    return 0.0; // Error
}