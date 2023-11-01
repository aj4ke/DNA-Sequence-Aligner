// Copyright Andrew Jacobson 2023
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <SFML/System.hpp>
#include "OptDistance.hpp"

int main(int argc, char *argv[]) {
    // reads from command line
    std::ifstream infile(argv[1]);
    if (!infile.is_open()) {
        std::cout << "failed to open " << argv[1] << std::endl;
        return 1;
    }
    // reads strings from file
    std::string str1, str2;
    infile >> str1 >> str2;
    infile.close();

    sf::Clock clock;
    sf::Time t;

    std::ofstream outFile("OptAlignment.txt");

    OptDistance OptDistance(str1, str2);
    int dist = OptDistance.optDistance();
    // Edit distance
    outFile << "Edit distance = " << dist << std::endl;

    // Strings after alignment
    outFile << OptDistance.alignment() << std::endl;

    // elasped time
    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds \n";
    outFile << "Execution time is " << t.asSeconds() << " seconds";

    outFile.close();
    return 0;
}
