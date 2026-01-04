# Knuth–Morris–Pratt (KMP) String Matching Algorithm

## Aim
To implement the **Knuth–Morris–Pratt (KMP) algorithm** for searching a pattern
string within a given text efficiently.

## Description
This program searches for occurrences of a pattern in a text using the
KMP string matching technique.

The algorithm preprocesses the pattern to create an **LPS (Longest Prefix Suffix)**
array. The LPS array helps skip unnecessary comparisons when a mismatch occurs,
making the algorithm more efficient than naive string matching.

## Algorithm Used
- Knuth–Morris–Pratt (KMP)
- LPS (Longest Prefix Suffix) computation

## Input
- A text string
- A pattern string

## Output
- Index/indices where the pattern is found in the text

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- LPS array computation: **O(m)**
- Pattern searching: **O(n)**
- Overall complexity: **O(n + m)**  
where `n` is the length of the text and `m` is the length of the pattern.

## Applications
- Text searching
- Pattern matching in editors
- Bioinformatics (DNA sequence matching)
- Information retrieval

## Conclusion
The KMP algorithm efficiently searches for a pattern in a text by avoiding
repeated comparisons, making it faster than traditional string matching methods.

