# Practical 2: Generate Prime Numbers <= n

## Problem Statement
For a given value of n, generate all prime numbers less than or equal to n.

## What is a Prime Number?
A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

**Examples:** 2, 3, 5, 7, 11, 13, 17, 19, 23, 29...

## Algorithms Implemented

### 1. Naive/Brute Force - O(n^2)
```
Algorithm GeneratePrimes_Naive(n):
    For num = 2 to n:
        isPrime = true
        For i = 2 to num-1:
            If num mod i == 0:
                isPrime = false
                break
        If isPrime: print num
```

### 2. Optimized Trial Division - O(n * sqrt(n))
```
Algorithm GeneratePrimes_Optimized(n):
    For num = 2 to n:
        isPrime = true
        For i = 2 to sqrt(num):
            If num mod i == 0:
                isPrime = false
                break
        If isPrime: print num
```

### 3. Skip Even Numbers - O(n * sqrt(n))
```
Algorithm GeneratePrimes_SkipEven(n):
    If n >= 2: print 2
    For num = 3 to n, step 2:
        isPrime = true
        For i = 3 to sqrt(num), step 2:
            If num mod i == 0:
                isPrime = false
                break
        If isPrime: print num
```

### 4. Sieve of Eratosthenes - O(n log log n) [BEST]
```
Algorithm SieveOfEratosthenes(n):
    Create boolean array isPrime[0..n] = all true
    isPrime[0] = isPrime[1] = false

    For i = 2 to sqrt(n):
        If isPrime[i]:
            For j = i*i to n, step i:
                isPrime[j] = false

    Print all i where isPrime[i] = true
```

## Complexity Comparison

| Algorithm | Time Complexity | Space Complexity | Best For |
|-----------|-----------------|------------------|----------|
| Naive | O(n^2) | O(1) | Learning only |
| Trial Division | O(n * sqrt(n)) | O(1) | Small n |
| Skip Even | O(n * sqrt(n)) | O(1) | Small n |
| **Sieve** | **O(n log log n)** | O(n) | **Large n** |

## How Sieve Works (Visual)
```
n = 30

Initial: 2 3 4 5 6 7 8 9 10 11 12 13 14 15 ... 29 30

Step 1 - Cross out multiples of 2:
         2 3 X 5 X 7 X 9 X  11 X  13 X  X  ... 29 X

Step 2 - Cross out multiples of 3:
         2 3 X 5 X 7 X X X  11 X  13 X  X  ... 29 X

Step 3 - Cross out multiples of 5:
         2 3   5   7       11    13        ... 29

Result: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
```

## How to Compile and Run
```bash
g++ prime_numbers.cpp -o prime_numbers
./prime_numbers
```

## Sample Output
```
Enter value of n: 50

Primes using Sieve of Eratosthenes: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

Total primes found: 15
```

## Key Learning Points
1. **Sieve of Eratosthenes** is the most efficient algorithm for generating primes
2. Starting from i*i in sieve because smaller multiples are already marked
3. Trade-off: Sieve uses more memory but is much faster
