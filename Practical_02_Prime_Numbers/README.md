# Practical 2: Generate Prime Numbers <= n

## Problem
Generate all prime numbers less than or equal to `n`.

**Example:** For n = 20, primes = 2, 3, 5, 7, 11, 13, 17, 19

---

## Algorithms

### 1. Brute Force - O(n²)
```
for num = 2 to n:
    for i = 2 to num-1:
        if num % i == 0: not prime
```

### 2. Optimized - O(n√n)
```
for num = 2 to n:
    for i = 2 to √num:
        if num % i == 0: not prime
```

### 3. Sieve of Eratosthenes - O(n log log n) [BEST]
```
isPrime[0..n] = true
isPrime[0] = isPrime[1] = false

for i = 2 to √n:
    if isPrime[i]:
        for j = i*i to n, step i:
            isPrime[j] = false
```

---

## How Sieve Works

```
n = 20

Start:  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20
Cross 2s:  2  3  X  5  X  7  X  9  X  11 X  13 X  15 X  17 X  19 X
Cross 3s:  2  3  X  5  X  7  X  X  X  11 X  13 X  X  X  17 X  19 X

Result: 2, 3, 5, 7, 11, 13, 17, 19
```

---

## Complexity

| Algorithm | Time | Space |
|-----------|------|-------|
| Brute Force | O(n²) | O(1) |
| Optimized | O(n√n) | O(1) |
| **Sieve** | **O(n log log n)** | O(n) |

---

## Run

```bash
g++ prime_numbers.cpp -o prime_numbers.exe
./prime_numbers.exe
```

## Output

```
Enter value of n: 30
Primes: 2 3 5 7 11 13 17 19 23 29
Total: 10
```
