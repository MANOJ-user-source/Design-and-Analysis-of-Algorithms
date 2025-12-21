# Practical 6: Binary Search and Linear Search

## Problem
Implement Recursive Binary Search and Linear Search to find an element in an array and determine the time taken.

**Example:** Array = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91], Key = 23 → Found at index 5

---

## Algorithms

### 1. Linear Search
Sequentially checks each element of the list until a match is found or the whole list has been searched.

```cpp
LinearSearch(arr, key):
    for i = 0 to n-1:
        if arr[i] == key:
            return i
    return -1
```

### 2. Recursive Binary Search (Divide and Conquer)
Search a sorted array by repeatedly dividing the search interval in half.

```cpp
BinarySearch(arr, left, right, key):
    if right >= left:
        mid = left + (right - left) / 2
        if arr[mid] == key: return mid
        if arr[mid] > key: return BinarySearch(arr, left, mid-1, key)
        return BinarySearch(arr, mid+1, right, key)
    return -1
```

---

## Complexity Analysis

| Method | Time Complexity (Worst) | Space Complexity | Prerequisite |
|--------|-------------------------|------------------|--------------|
| Linear Search | O(n) | O(1) | None |
| **Binary Search** | **O(log n)** | O(log n) (Stack) | **Sorted Array** |

---

## Recurrence Relation (Binary Search)

```
T(n) = T(n/2) + c
T(1) = c

Solution: T(n) = O(log n)
```

---

## Comparison

For `n = 1,000,000`:
- **Linear Search:** ~1,000,000 comparisons
- **Binary Search:** ~20 comparisons ($log_2(10^6) \approx 19.9$)

Binary Search is exponentially faster for large datasets but requires sorting.

---

## Run

```bash
g++ binary_linear_search.cpp -o search_app
./search_app
```

## Output

```
Enter the number of elements: 10
Enter 10 elements: 12 45 7 23 9 56 89 34 11 2

Array has been sorted for Binary Search: [ 2 7 9 11 12 23 34 45 56 89 ]

Enter the element to search: 23

--- Execution Results ---
1. Linear Search: Found at index 5
   Time taken: 200 ns

2. Binary Search: Found at index 5
   Time taken: 100 ns

--- Complexity Analysis for n=10 ---
Linear Search (Worst Case): O(n)     = 10 comparisons
Binary Search (Worst Case): O(log n) = 4 comparisons
```