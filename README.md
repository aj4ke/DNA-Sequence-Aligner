# DNA Sequence Aligner

## Overview

This project computes the optimal alignment between two DNA sequences using dynamic programming. It calculates the **edit distance** by aligning characters (matches/mismatches) or inserting gaps with predefined penalties, then reconstructs the alignment using a backtrace similar to the **Needleman-Wunsch** algorithm.

**Edit costs:**

- Match: `0`
- Mismatch: `1`
- Gap: `2`

The final output includes:

- The minimum edit distance
- A line-by-line alignment of both sequences with associated costs

## Features

- Command-line interface for input file specification
- Dynamic memory allocation for alignment matrix
- Backtrace reconstruction of optimal alignment
- Output written to `OptAlignment.txt`
- Runtime performance measurement

## Example Usage

$ ./OptDistance  
Enter path to file: input.txt  
Execution time is 0.00123 seconds

Where `input.txt` contains two whitespace-separated DNA sequences:

AGTACG  
ACATAG

Output (`OptAlignment.txt`) might look like:

Edit distance = 4  
A A 0  
G C 1  
T A 1  
A T 1  
C A 1  
G G 0

## Building

This project is written in modern C++17. To build it:

make

Makefile assumes `g++` is installed and available on your `PATH`.

## File Structure

- `main.cpp` - Handles input/output, execution timing  
- `OptDistance.hpp / OptDistance.cpp` - Core alignment logic and matrix processing  
- `README.md` - Documentation  
- `Makefile` - Build instructions
