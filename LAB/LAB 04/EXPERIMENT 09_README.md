# Knuth–Morris–Pratt (KMP) String Matching Algorithm

## Aim
To implement the **Knuth–Morris–Pratt (KMP) algorithm** for efficient pattern
searching in a given text.

## Description
This program searches for a pattern string within a given text using the
KMP string matching algorithm.

The algorithm avoids unnecessary comparisons by preprocessing the pattern
and creating an **LPS (Longest Prefix Suffix) array**.  
The LPS array helps determine how much the pattern should be shifted when
a mismatch occurs.

## Algorithm Used
- Knuth–Morris–Pratt (KMP)
- LPS (Longest Prefix Suffix) preprocessing

## Input
- A text string
- A pattern string to be searched

## Output
- Index/indices at which the pattern is found in the text

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Preprocessing (LPS array): **O(M)**
- Pattern searching: **O(N)**
- Overall: **O(N + M)**  
where `N` is the length of the text and `M` is the length of the pattern.

## Applications
- Text editors
- Search engines
- DNA sequence matching
- Plagiarism detection

## Conclusion
The KMP algorithm efficiently performs pattern matching by eliminating
redundant comparisons, making it faster than naive string matching techniques.

