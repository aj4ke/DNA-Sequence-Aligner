// Copyright Andrew Jacobson 2023
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <chrono>
#include "OptDistance.hpp"

int main() {
    std::string filePath;
    std::cout << "Enter path to file: ";
    std::cin >> filePath;

    std::ifstream infile(filePath);
    if (!infile.is_open()) {
        std::cerr << "Failed to open " << filePath << std::endl;
        return 1;
    }

    std::string str1, str2;
    infile >> str1 >> str2;
    infile.close();

    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream outFile("OptAlignment.txt");

    OptDistance aligner(str1, str2);
    int dist = aligner.optDistance();

    outFile << "Edit distance = " << dist << std::endl;
    outFile << aligner.alignment() << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time is " << elapsed.count() << " seconds\n";

    outFile.close();
    return 0;
}
