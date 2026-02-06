#include "JSONHandler.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

bool JsonHandler::load(std::string filename) {
    
    table.clear();
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return false;
    }

    json data;
    file >> data; 

    table.push_back(data["header"].get<std::vector<std::string>>());

    for (const auto& row : data["data"]) {
        table.push_back(row.get<std::vector<std::string>>());
    }

    return true;
}

std::vector<std::string> JsonHandler::getColumn(std::string selector) {
    std::vector<std::string> results;
    int index = std::stoi(selector); 
    
    // Start at i=1 to skip header
    for (size_t i = 1; i < table.size(); i++) {
        if (index < table[i].size()) {
            results.push_back(table[i][index]);
        } else {
            results.push_back(""); 
        }
    }
    return results;
}

void JsonHandler::appendColumn(std::string newHeader, const std::vector<std::string>& values)  {
    table[0].push_back(newHeader);

    for (size_t i = 1; i <= values.size(); i++) {
        table[i].push_back(values[i-1]);
    }
}

void JsonHandler::save(std::string filename) {
    json j;
    j["header"] = json::array();
    j["data"] = json::array();
    
    for (const auto& row : table[0]) {
        j["header"].push_back(row);
    }
    for (size_t i = 1; i < table.size(); i++) {
        json rowJson = json::array();
        for (size_t k = 0; k < table[i].size(); k++) {
            rowJson.push_back(table[i][k]);
        }
        j["data"].push_back(rowJson);
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not write " << filename << "\n";
        return;
    }
    file << j.dump(2);
    file << "\n"; // New line at end of row
}
