# Practical 5: Find Maximum and Minimum using Divide and Conquer

## Problem
Find the maximum and minimum elements in an array using Divide and Conquer approach.

**Example:** Array = [3, 5, 1, 8, 2, 9] → Max = 9, Min = 1

---

## Algorithms

### 1. Linear (Naive) - 2(n-1) comparisons
```
max = min = arr[0]
for i = 1 to n-1:
    if arr[i] > max: max = arr[i]
    if arr[i] < min: min = arr[i]
```

### 2. Divide and Conquer - 3n/2-2 comparisons
```
FindMaxMin(arr, low, high):
    if low == high:                    // Single element
        return (arr[low], arr[low])

    if high == low + 1:                // Two elements
        return (max, min) of arr[low], arr[high]

    mid = (low + high) / 2
    (max1, min1) = FindMaxMin(arr, low, mid)      // Left half
    (max2, min2) = FindMaxMin(arr, mid+1, high)   // Right half

    return (max(max1,max2), min(min1,min2))       // Combine
```

---

## Divide and Conquer Paradigm

```
1. DIVIDE:   Split array into two halves
2. CONQUER:  Recursively find max-min in each half
3. COMBINE:  max = max(left_max, right_max)
             min = min(left_min, right_min)
```

---

## Visual Example

```
Array: [3, 5, 1, 8, 2, 9, 4, 7]

                  [3,5,1,8,2,9,4,7]
                   max=9, min=1
                  /              \
          [3,5,1,8]              [2,9,4,7]
          max=8,min=1            max=9,min=2
         /        \              /        \
      [3,5]      [1,8]        [2,9]      [4,7]
      m=5,n=3    m=8,n=1      m=9,n=2    m=7,n=4
```

---

## Complexity

| Method | Comparisons | Time | Space |
|--------|-------------|------|-------|
| Linear | 2(n-1) | O(n) | O(1) |
| **D&C** | **3n/2-2** | O(n) | O(log n) |

**Savings:** n/2 fewer comparisons with D&C

---

## Recurrence Relation

```
T(n) = 2T(n/2) + 2
T(2) = 1
T(1) = 0

Solution: T(n) = 3n/2 - 2 comparisons
```

---

## Comparison Count Example

| n | Linear (2n-2) | D&C (3n/2-2) | Saved |
|---|---------------|--------------|-------|
| 8 | 14 | 10 | 4 |
| 16 | 30 | 22 | 8 |
| 100 | 198 | 148 | 50 |

---

## Run

```bash
g++ max_min.cpp -o max_min.exe
./max_min.exe
```

## Output

```
Enter number of elements: 6
Enter 6 elements: 12 5 8 3 15 7

Array: [12, 5, 8, 3, 15, 7]

Results:
1. Linear Method:       Max = 15, Min = 3
2. Divide and Conquer:  Max = 15, Min = 3

Comparisons for n=6:
Linear: 10, D&C: 7
```
