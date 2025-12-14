/*
 * Practical 2: Generate Prime Numbers <= n
 * Subject: Design and Analysis of Algorithms
 * BCA Semester 4
 *
 * Multiple algorithms implemented with complexity analysis
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

/*
 * ALGORITHM 1: Naive/Brute Force Approach
 * ----------------------------------------
 * For each number from 2 to n, check if it's prime by
 * testing divisibility with all numbers from 2 to num-1.
 *
 * Algorithm GeneratePrimes_Naive(n):
 *   1. For num = 2 to n:
 *      a. Set isPrime = true
 *      b. For i = 2 to num-1:
 *         - If num mod i == 0, set isPrime = false, break
 *      c. If isPrime, print num
 *
 * Time Complexity: O(n^2) - For each number, check all previous numbers
 * Space Complexity: O(1) - No extra space used
 */
void generatePrimes_Naive(int n) {
    cout << "Primes using Naive Method: ";

    for (int num = 2; num <= n; num++) {
        bool isPrime = true;

        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
}

/*
 * ALGORITHM 2: Optimized Trial Division (Square Root Method)
 * -----------------------------------------------------------
 * Check divisibility only up to sqrt(num) since if num = a * b,
 * one of a or b must be <= sqrt(num).
 *
 * Algorithm GeneratePrimes_Optimized(n):
 *   1. For num = 2 to n:
 *      a. Set isPrime = true
 *      b. For i = 2 to sqrt(num):
 *         - If num mod i == 0, set isPrime = false, break
 *      c. If isPrime, print num
 *
 * Time Complexity: O(n * sqrt(n)) - For each number, check up to sqrt
 * Space Complexity: O(1)
 */
void generatePrimes_Optimized(int n) {
    cout << "Primes using Optimized Trial Division: ";

    for (int num = 2; num <= n; num++) {
        bool isPrime = true;

        // Only check up to square root
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
}

/*
 * ALGORITHM 3: Further Optimized (Check 2, then odd numbers only)
 * ----------------------------------------------------------------
 * After checking 2, only check odd divisors.
 *
 * Algorithm GeneratePrimes_SkipEven(n):
 *   1. If n >= 2, print 2
 *   2. For num = 3 to n, step 2 (odd numbers only):
 *      a. Set isPrime = true
 *      b. For i = 3 to sqrt(num), step 2:
 *         - If num mod i == 0, set isPrime = false, break
 *      c. If isPrime, print num
 *
 * Time Complexity: O(n * sqrt(n) / 4) = O(n * sqrt(n))
 * Space Complexity: O(1)
 */
void generatePrimes_SkipEven(int n) {
    cout << "Primes using Skip Even Method: ";

    if (n >= 2) {
        cout << "2 ";
    }

    // Check only odd numbers
    for (int num = 3; num <= n; num += 2) {
        bool isPrime = true;

        // Check only odd divisors
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
}

/*
 * ALGORITHM 4: Sieve of Eratosthenes (MOST EFFICIENT)
 * ----------------------------------------------------
 * Ancient algorithm that eliminates multiples of each prime.
 *
 * Algorithm SieveOfEratosthenes(n):
 *   1. Create boolean array isPrime[0..n], initialize all to true
 *   2. Set isPrime[0] = isPrime[1] = false
 *   3. For i = 2 to sqrt(n):
 *      a. If isPrime[i] is true:
 *         - For j = i*i to n, step i:
 *           - Set isPrime[j] = false (mark multiples)
 *   4. Print all i where isPrime[i] is true
 *
 * Time Complexity: O(n log log n) - Nearly linear!
 * Space Complexity: O(n) - Boolean array of size n
 *
 * WHY IT'S FAST:
 * - Each composite number is crossed out only by its smallest prime factor
 * - Starting from i*i because smaller multiples already marked
 */
void sieveOfEratosthenes(int n) {
    cout << "Primes using Sieve of Eratosthenes: ";

    if (n < 2) {
        cout << "No primes" << endl;
        return;
    }

    // Create a boolean array and initialize all entries as true
    vector<bool> isPrime(n + 1, true);

    // 0 and 1 are not prime
    isPrime[0] = isPrime[1] = false;

    // Sieve algorithm
    for (int i = 2; i * i <= n; i++) {
        // If i is still prime
        if (isPrime[i]) {
            // Mark all multiples of i as not prime
            // Start from i*i because smaller multiples are already marked
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Print all prime numbers
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

/*
 * ALGORITHM 5: Sieve of Eratosthenes (Optimized - Even numbers skipped)
 * ----------------------------------------------------------------------
 * Store only odd numbers to reduce memory by half.
 *
 * Time Complexity: O(n log log n)
 * Space Complexity: O(n/2) = O(n) but uses half the memory
 */
void sieveOptimized(int n) {
    cout << "Primes using Optimized Sieve: ";

    if (n < 2) {
        cout << "No primes" << endl;
        return;
    }

    if (n >= 2) {
        cout << "2 ";
    }

    if (n < 3) {
        cout << endl;
        return;
    }

    // Only store odd numbers: index i represents number (2*i + 3)
    // So index 0 = 3, index 1 = 5, index 2 = 7, etc.
    int size = (n - 1) / 2;
    vector<bool> isPrime(size, true);

    for (int i = 0; i * 2 + 3 <= sqrt(n); i++) {
        if (isPrime[i]) {
            int prime = i * 2 + 3;
            // Start marking from prime^2, skip even multiples
            for (int j = (prime * prime - 3) / 2; j < size; j += prime) {
                isPrime[j] = false;
            }
        }
    }

    // Print primes
    for (int i = 0; i < size; i++) {
        if (isPrime[i]) {
            cout << (i * 2 + 3) << " ";
        }
    }
    cout << endl;
}

/*
 * Helper function to count primes (for comparison)
 */
int countPrimes_Sieve(int n) {
    if (n < 2) return 0;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) count++;
    }
    return count;
}

// Main function
int main() {
    int n;

    cout << "========================================" << endl;
    cout << "  GENERATE PRIME NUMBERS <= N" << endl;
    cout << "  Practical 2 - DAA Lab" << endl;
    cout << "========================================" << endl;

    cout << "\nEnter value of n: ";
    cin >> n;

    if (n < 2) {
        cout << "No prime numbers less than or equal to " << n << endl;
        return 0;
    }

    cout << "\n--- Results for n = " << n << " ---\n" << endl;

    // Run all algorithms
    generatePrimes_Naive(n);
    cout << endl;

    generatePrimes_Optimized(n);
    cout << endl;

    generatePrimes_SkipEven(n);
    cout << endl;

    sieveOfEratosthenes(n);
    cout << endl;

    sieveOptimized(n);

    // Statistics
    cout << "\n--- Statistics ---" << endl;
    cout << "Total primes found: " << countPrimes_Sieve(n) << endl;

    // Demonstrate with a standard example
    cout << "\n--- Quick Reference: Primes up to 50 ---" << endl;
    sieveOfEratosthenes(50);

    return 0;
}

/*
 * COMPLEXITY COMPARISON TABLE
 * ============================
 *
 * Algorithm                  | Time Complexity    | Space Complexity
 * ---------------------------|--------------------|-----------------
 * Naive (Brute Force)        | O(n^2)             | O(1)
 * Optimized Trial Division   | O(n * sqrt(n))     | O(1)
 * Skip Even Numbers          | O(n * sqrt(n))     | O(1)
 * Sieve of Eratosthenes      | O(n log log n)     | O(n)
 * Optimized Sieve            | O(n log log n)     | O(n/2)
 *
 * PERFORMANCE COMPARISON (approximate iterations for n = 1,000,000):
 * ------------------------------------------------------------------
 * Naive:          ~500,000,000,000 (500 billion!) - Very slow
 * Trial Division: ~1,000,000,000 (1 billion)
 * Sieve:          ~20,000,000 (20 million) - Much faster!
 *
 * RECOMMENDATION:
 * ---------------
 * - For small n (< 1000): Any method works
 * - For medium n (1000 - 100000): Use Optimized Trial Division
 * - For large n (> 100000): Use Sieve of Eratosthenes
 *
 * SAMPLE OUTPUT:
 * --------------
 * Enter value of n: 30
 *
 * Primes using Sieve of Eratosthenes: 2 3 5 7 11 13 17 19 23 29
 * Total primes found: 10
 *
 * VISUAL: HOW SIEVE WORKS (for n=30)
 * -----------------------------------
 * Initial:  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
 * After 2:  2  3  X  5  X  7  X  9  X 11  X 13  X 15  X 17  X 19  X 21  X 23  X 25  X 27  X 29  X
 * After 3:  2  3  X  5  X  7  X  X  X 11  X 13  X  X  X 17  X 19  X  X  X 23  X 25  X  X  X 29  X
 * After 5:  2  3  X  5  X  7  X  X  X 11  X 13  X  X  X 17  X 19  X  X  X 23  X  X  X  X  X 29  X
 * Final:    2  3     5     7        11    13          17    19          23                29
 */
