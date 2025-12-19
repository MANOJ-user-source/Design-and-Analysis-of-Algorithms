# Practical 4: Find Factorial of n

## Problem
Compute the factorial of a non-negative integer n.

**Example:** For n = 5, result = 5! = 5 × 4 × 3 × 2 × 1 = 120

---

## Algorithms

### 1. Iterative - O(n)
```
result = 1
for i = 2 to n:
    result = result * i
return result
```

### 2. Recursive - O(n)
```
Factorial(n):
    if n == 0 or n == 1: return 1
    return n * Factorial(n-1)
```

### 3. Tail Recursive - O(n)
```
Factorial(n, acc=1):
    if n == 0 or n == 1: return acc
    return Factorial(n-1, n * acc)
```

---

## Mathematical Definition

```
n! = n × (n-1) × (n-2) × ... × 2 × 1
0! = 1 (by definition)

Recursive:
n! = | 1              if n = 0 or n = 1
     | n × (n-1)!     if n > 1
```

---

## Complexity

| Algorithm | Time | Space |
|-----------|------|-------|
| Iterative | O(n) | O(1) |
| Recursive | O(n) | O(n) |
| Tail Recursive | O(n) | O(n)* |

*Can be O(1) with tail call optimization

---

## Recurrence Relation

```
T(n) = T(n-1) + O(1)
T(1) = O(1)

Solution: T(n) = O(n)
```

---

## Factorial Table

| n | n! |
|---|-----|
| 0 | 1 |
| 1 | 1 |
| 2 | 2 |
| 3 | 6 |
| 4 | 24 |
| 5 | 120 |
| 6 | 720 |
| 7 | 5040 |
| 8 | 40320 |
| 9 | 362880 |
| 10 | 3628800 |

---

## Run

```bash
g++ factorial.cpp -o factorial.exe
./factorial.exe
```

## Output

```
Enter a non-negative integer n: 5

Results for 5!:
1. Iterative:      120
2. Recursive:      120
3. Tail Recursive: 120
```
