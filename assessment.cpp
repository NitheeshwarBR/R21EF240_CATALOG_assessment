#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <vector>
#include "json.hpp"  // Ensure this includes the correct JSON library

using json = nlohmann::json;

// Function to convert a number from a given base to decimal
int convertToDecimal(const std::string &number, int base) {
    int decimal = 0;
    int power = 0;
    for (int i = number.size() - 1; i >= 0; --i) {
        char digit = number[i];
        int value = (digit >= '0' && digit <= '9') ? digit - '0' : digit - 'A' + 10; // Support for bases > 10
        decimal += value * std::pow(base, power++);
    }
    return decimal;
}

// Function to find the constant term (c) of the polynomial using Lagrange interpolation
double findConstantTerm(const std::map<int, std::pair<int, int>> &points) {
    double c = 0.0;
    std::vector<std::pair<int, int>> decimalPoints;

    // Convert points to decimal values and store in vector
    for (const auto &point : points) {
        int x = point.first;
        int y = point.second.second; // Already decoded
        decimalPoints.emplace_back(x, y);
    }

    // Applying Lagrange interpolation at x = 0 to find the constant term c
    for (size_t i = 0; i < decimalPoints.size(); ++i) {
        double term = decimalPoints[i].second; // Corresponds to y_i
        for (size_t j = 0; j < decimalPoints.size(); ++j) {
            if (i != j) {
                term *= static_cast<double>(-decimalPoints[j].first) / (decimalPoints[i].first - decimalPoints[j].first);
            }
        }
        c += term;
    }

    return c;
}

int main() {
    // Open and parse the JSON file
    std::ifstream inputFile("input.json");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the JSON file." << std::endl;
        return 1;
    }

    json inputData;
    inputFile >> inputData;

    // Read points from the JSON data
    std::map<int, std::pair<int, int>> points; // Change to int for y value
    for (auto it = inputData.begin(); it != inputData.end(); ++it) {
        // Skip the "keys" object in JSON
        if (it.key() == "keys") continue;

        int x = std::stoi(it.key());
        int base = std::stoi(it.value().at("base").get<std::string>());
        std::string value = it.value().at("value").get<std::string>();
        
        // Decode y value and store in the points map
        int y = convertToDecimal(value, base);
        points[x] = {base, y};

        // Print the decoded y value
        std::cout << "Decoded y value for x = " << x << ": " << y << " (base " << base << ")" << std::endl;
    }

    // Finding the constant term c of the polynomial
    double constantTerm = findConstantTerm(points);

    // Output the result
    std::cout << "Constant term (c) of the polynomial: " << constantTerm << std::endl;

    return 0;
}
