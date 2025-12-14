/*
 * Practical 1: Determine Smallest Divisor of an Integer
 * Subject: Design and Analysis of Algorithms
 * BCA Semester 4
 */

#include <iostream>
#include <cmath>
using namespace std;

/*
 * ALGORITHM 1: Brute Force Approach
 * ----------------------------------
 * Algorithm SmallestDivisor_BruteForce(n):
 *   1. If n <= 1, return n (no valid divisor > 1)
 *   2. For i = 2 to n:
 *      a. If n mod i == 0, return i
 *   3. Return n (n is prime)
 *
 * Time Complexity: O(n) - Worst case checks all numbers up to n
 * Space Complexity: O(1) - Only uses constant extra space
 */
int smallestDivisor_BruteForce(int n) {
    if (n <= 1) {
        return n;
    }

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }

    return n; // This line is reached only if n is 1
}

/*
 * ALGORITHM 2: Optimized Approach (Using Square Root)
 * ----------------------------------------------------
 * Key Insight: If n has a divisor d, then n/d is also a divisor.
 *              One of them must be <= sqrt(n).
 *
 * Algorithm SmallestDivisor_Optimized(n):
 *   1. If n <= 1, return n
 *   2. For i = 2 to sqrt(n):
 *      a. If n mod i == 0, return i
 *   3. Return n (n is prime, smallest divisor is n itself)
 *
 * Time Complexity: O(sqrt(n)) - Only checks up to square root
 * Space Complexity: O(1) - Only uses constant extra space
 */
int smallestDivisor_Optimized(int n) {
    if (n <= 1) {
        return n;
    }

    // Check divisibility from 2 to sqrt(n)
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return i;
        }
    }

    // If no divisor found, n is prime
    return n;
}

/*
 * ALGORITHM 3: Further Optimized (Skip Even Numbers)
 * ---------------------------------------------------
 * Key Insight: After checking 2, we only need to check odd numbers.
 *
 * Algorithm SmallestDivisor_SkipEven(n):
 *   1. If n <= 1, return n
 *   2. If n mod 2 == 0, return 2
 *   3. For i = 3 to sqrt(n), step 2:
 *      a. If n mod i == 0, return i
 *   4. Return n (n is prime)
 *
 * Time Complexity: O(sqrt(n)/2) = O(sqrt(n)) - Half the iterations
 * Space Complexity: O(1)
 */
int smallestDivisor_SkipEven(int n) {
    if (n <= 1) {
        return n;
    }

    // Check for 2 first
    if (n % 2 == 0) {
        return 2;
    }

    // Check only odd numbers from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

// Main function to demonstrate all algorithms
int main() {
    int n;

    cout << "========================================" << endl;
    cout << "  SMALLEST DIVISOR OF AN INTEGER" << endl;
    cout << "  Practical 1 - DAA Lab" << endl;
    cout << "========================================" << endl;

    cout << "\nEnter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer!" << endl;
        return 1;
    }

    cout << "\n--- Results ---" << endl;
    cout << "Input number: " << n << endl;

    cout << "\nAlgorithm 1 (Brute Force - O(n)):" << endl;
    cout << "Smallest divisor = " << smallestDivisor_BruteForce(n) << endl;

    cout << "\nAlgorithm 2 (Optimized - O(sqrt(n))):" << endl;
    cout << "Smallest divisor = " << smallestDivisor_Optimized(n) << endl;

    cout << "\nAlgorithm 3 (Skip Even - O(sqrt(n))):" << endl;
    cout << "Smallest divisor = " << smallestDivisor_SkipEven(n) << endl;

    // Test with some example values
    cout << "\n--- Additional Test Cases ---" << endl;
    int testCases[] = {2, 7, 12, 15, 49, 97, 100};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    cout << "\nNumber\t|\tSmallest Divisor" << endl;
    cout << "--------|-------------------" << endl;

    for (int i = 0; i < numTests; i++) {
        cout << testCases[i] << "\t|\t" << smallestDivisor_Optimized(testCases[i]) << endl;
    }

    return 0;
}

/*
 * COMPLEXITY ANALYSIS SUMMARY
 * ===========================
 *
 * Algorithm          | Time Complexity | Space Complexity | Best For
 * -------------------|-----------------|------------------|------------------
 * Brute Force        | O(n)            | O(1)             | Small numbers
 * Optimized (sqrt)   | O(sqrt(n))      | O(1)             | General use
 * Skip Even          | O(sqrt(n))      | O(1)             | Large odd numbers
 *
 * WHY O(sqrt(n)) IS BETTER:
 * -------------------------
 * For n = 1,000,000:
 *   - Brute Force: Up to 1,000,000 iterations
 *   - Optimized: Up to 1,000 iterations (sqrt(1,000,000) = 1000)
 *
 * This is a significant improvement for large numbers!
 *
 * SAMPLE OUTPUT:
 * --------------
 * Enter a positive integer: 49
 *
 * --- Results ---
 * Input number: 49
 *
 * Algorithm 1 (Brute Force - O(n)):
 * Smallest divisor = 7
 *
 * Algorithm 2 (Optimized - O(sqrt(n))):
 * Smallest divisor = 7
 *
 * Algorithm 3 (Skip Even - O(sqrt(n))):
 * Smallest divisor = 7
 */
