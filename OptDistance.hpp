// Copyright Andrew Jacobson 2023
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class OptDistance {
 public:
    // constructor
    OptDistance(std::string str1, std::string str2);
    static int min(int a, int b, int c);
    static int penalty(char a, char b);
    int optDistance();
    std::string alignment();

 private:
    // strings for DNA string
    std::string str1;
    std::string str2;

    // vector of vectors
    std::vector<std::vector<int>> matrix;

    // dimensions of matrix from length of strings
    int N;
    int M;
};
