// Copyright Andrew Jacobson 2023
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "OptDistance.hpp"

/// @brief Constructor initializes the n and m variables and allocates memory for the matrix
/// @param a string1 entered from stdin
/// @param b string2 entered from stdin
OptDistance::OptDistance(std::string a, std::string b) {
    // initializes
    str1 = a;
    str2 = b;
    // length of strings
    M = str1.size();
    N = str2.size();

    // resize the matrix
    matrix.resize(M+1);

    // "initializes" matrix
    for (int i = 0; i <= M; i++) {
        matrix[i].resize(N+1);
        matrix[i][N] = 2*(M-i);
        for (int j = 0; j <= N; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = M; i >= 0; i--) {
        matrix[i][N] = (2 * (M - i));
    }
}

/// @brief returns the smaller of the three parameters
/// @param a num 1
/// @param b num 2
/// @param c num 3
/// @return returns the smallest number of the three
int OptDistance::min(int a, int b, int c) {
    if (a < b && a < c) {
        return a;
    } else if (b < a && b < c) {
        return b;
    } else {
        return c;
    }
    // return std::min(a, std::min(b, c));
}

/// @brief calculates the penalty for aligning the strings
/// @param a character to compare
/// @param b character to compare
/// @return returns 1 or 0
int OptDistance::penalty(char a, char b) {
    if (a == b) {
        return 0;
    } else {
        return 1;
    }
}

/// @brief calculates the optimal distance for the strings to be aligned
/// @return int of the optimal distance
int OptDistance::optDistance() {
    // traverses matrix for bottom right to top left
    for (int i = M - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            // puts min value into matrix at (i, j),
            // PDF equation:
            // opt[i][j] = min { opt[i+1][j+1] + 0/1, opt[i+1][j] + 2, opt[i][j+1] + 2 }
            matrix.at(i).at(j) = min(matrix.at(i + 1).at(j) + 2,
                matrix.at(i).at(j + 1) + 2, matrix.at(i + 1).at(j + 1) +
                penalty(str1.at(i), str2.at(j)));
        }
    }
    this->matrix = matrix;
    // distance is equal to top left corner of matrix (0,0)
    return matrix.at(0).at(0);
}

/// @brief aligns the strings based on the optimal distance
/// @return returns the fully aligned strings
std::string OptDistance::alignment() {
    // new empty strings for after alignment
    std::string alignStr1 = "";
    std::string alignStr2 = "";
    std::string finalStr = "";
    // iterator values
    int i = 0;
    int j = 0;
    while (i < M || j < N) {
        if (i < M && j < N && matrix.at(i).at(j) ==
                matrix.at(i+1).at(j+1) + penalty(str1.at(i), str2.at(j))) {
            alignStr1 += str1.at(i);
            alignStr2 += str2.at(j);
            i++;
            j++;
        } else if (i < M && matrix.at(i).at(j) == matrix.at(i + 1).at(j)+ 2) {
            alignStr1 += str1.at(i);
            alignStr2 += "-";
            i++;
        } else {
            alignStr1 += "-";
            alignStr2 += str2.at(j);
            j++;
        }
    }
    // max size of new strings after alignment
    int maxSize = alignStr1.size();

    // combine both alignStr1 and alignStr2 into one string
    for (int i = 0; i < maxSize; i++) {
        finalStr += alignStr1.at(i);
        finalStr += " ";
        finalStr +=alignStr2.at(i);
        // compares the two strings,
        // same letter ->adds 0 to final string, if there is a gap -> adds 2, if not equal -> adds 1
        if (alignStr1.at(i) == alignStr2.at(i)) {
            finalStr += " 0";
        } else if (alignStr1.at(i) == '-' || alignStr2.at(i) == '-') {
            finalStr += " 2";
        } else if (alignStr1.at(i) != alignStr2.at(i)) {
            finalStr += " 1";
        }
        finalStr += "\n";
    }
    return finalStr;
}
