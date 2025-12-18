# Practical 3: Find X^n (Power of a Number)

## Problem
Compute X raised to the power n using iterative and recursive approaches.

**Example:** For x = 2, n = 10, result = 2^10 = 1024

---

## Algorithms

### 1. Iterative (Naive) - O(n)
```
result = 1
for i = 1 to n:
    result = result * x
return result
```

### 2. Recursive (Naive) - O(n)
```
Power(x, n):
    if n == 0: return 1
    return x * Power(x, n-1)
```

### 3. Optimized - Binary Exponentiation - O(log n) [BEST]
```
Power(x, n):
    if n == 0: return 1
    half = Power(x, n/2)
    if n is even: return half * half
    else: return half * half * x
```

---

## How Binary Exponentiation Works

```
Example: 2^13 where 13 = 1101 (binary)

2^13 = 2^8 * 2^4 * 2^1
     = 256 * 16 * 2
     = 8192

Binary positions:
1    1    0    1
|    |         |
2^8  2^4      2^1
```

---

## Complexity

| Algorithm | Time | Space |
|-----------|------|-------|
| Iterative (Naive) | O(n) | O(1) |
| Recursive (Naive) | O(n) | O(n) |
| **Optimized** | **O(log n)** | O(1) or O(log n) |

---

## Recurrence Relations

**Naive Recursive:**
```
T(n) = T(n-1) + O(1)
T(n) = O(n)
```

**Optimized Recursive:**
```
T(n) = T(n/2) + O(1)
T(n) = O(log n)
```

---

## Run

```bash
g++ power_xn.cpp -o power_xn.exe
./power_xn.exe
```

## Output

```
Enter base (x): 2
Enter exponent (n): 10

Results for 2^10:
1. Iterative (Naive):     1024
2. Recursive (Naive):     1024
3. Optimized Iterative:   1024
4. Optimized Recursive:   1024
```
