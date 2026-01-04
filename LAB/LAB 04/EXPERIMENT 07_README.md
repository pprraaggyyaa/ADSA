# Huffman Coding Algorithm

## Aim
To implement the **Huffman Coding algorithm** to generate optimal prefix codes
for a given input string based on the frequency of characters.

## Description
This program reads a string from the user and calculates the frequency of each
character present in the string. Using these frequencies, a **Huffman Tree** is
constructed with the help of a **min-heap**.

Each character is assigned a binary code such that:
- Frequently occurring characters get shorter codes
- Less frequent characters get longer codes

This ensures efficient data compression without ambiguity.

## Algorithm Used
- Huffman Coding
- Min-Heap

## Input
- A string of characters

## Output
- Huffman codes (binary codes) for each character in the input string

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Applications
- Data compression
- File encoding and decoding
- Multimedia compression (text, images, audio)

## Conclusion
Huffman Coding is an efficient lossless compression technique that minimizes
the average code length by assigning shorter codes to frequently occurring
characters.

