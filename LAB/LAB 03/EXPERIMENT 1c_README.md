# Quick Sort Using Median as Pivot

## Aim
To implement the **Quick Sort algorithm** using the **median (middle element)**
as the pivot element.

## Description
This program sorts a given array using the Quick Sort technique.
Instead of choosing the first or last element as the pivot, the **middle element**
of the array is selected as the pivot.

The pivot is temporarily moved to the end of the array during partitioning,
and elements smaller than or equal to the pivot are placed on the left side,
while larger elements are placed on the right side.

Using a median pivot helps in reducing the chances of worst-case performance
for partially sorted arrays.

## Algorithm Used
- Quick Sort (Median as Pivot)

## Input
- Number of elements `n`
- `n` array elements

## Output
- Sorted array in ascending order

## Language Used
- C Programming

## How to Execute
1. Compile the program:
2. Run the program:

## Time Complexity
- Best Case: **O(n log n)**
- Average Case: **O(n log n)**
- Worst Case: **O(n²)**

## Applications
- Efficient sorting of large datasets
- Divide and conquer based sorting
- Performance optimization in sorting

## Conclusion
Quick Sort using the median element as the pivot improves the balance of
partitions in many cases, resulting in better performance compared to
choosing a fixed pivot.

