/*
 * Practical 3: Find X^n (Power of a Number)
 * Subject: Design and Analysis of Algorithms
 * BCA Semester 4
 *
 * Iterative and Recursive algorithms with complexity analysis
 */

#include <iostream>
using namespace std;

/*
 * ALGORITHM 1: Iterative Approach (Naive)
 * ----------------------------------------
 * Multiply x by itself n times.
 *
 * Algorithm Power_Iterative(x, n):
 *   1. Set result = 1
 *   2. For i = 1 to n:
 *      a. result = result * x
 *   3. Return result
 *
 * Time Complexity: O(n) - Loop runs n times
 * Space Complexity: O(1) - Only constant space used
 */
long long power_iterative(int x, int n) {
    long long result = 1;

    for (int i = 0; i < n; i++) {
        result *= x;
    }

    return result;
}

/*
 * ALGORITHM 2: Recursive Approach (Naive)
 * ----------------------------------------
 * Use recursion: x^n = x * x^(n-1)
 *
 * Algorithm Power_Recursive(x, n):
 *   1. If n == 0, return 1 (Base case)
 *   2. Return x * Power_Recursive(x, n-1)
 *
 * Time Complexity: O(n) - n recursive calls
 * Space Complexity: O(n) - Recursion stack depth is n
 *
 * Recurrence Relation: T(n) = T(n-1) + O(1)
 *                      T(n) = O(n)
 */
long long power_recursive(int x, int n) {
    // Base case
    if (n == 0) {
        return 1;
    }

    // Recursive case
    return x * power_recursive(x, n - 1);
}

/*
 * ALGORITHM 3: Optimized Iterative (Exponentiation by Squaring)
 * --------------------------------------------------------------
 * Use binary representation of n to reduce multiplications.
 *
 * Key Insight:
 * - x^10 = x^(1010 in binary) = x^8 * x^2
 * - If n is even: x^n = (x^2)^(n/2)
 * - If n is odd:  x^n = x * x^(n-1)
 *
 * Algorithm Power_Optimized_Iterative(x, n):
 *   1. Set result = 1
 *   2. While n > 0:
 *      a. If n is odd (n & 1 == 1):
 *         - result = result * x
 *      b. x = x * x (square x)
 *      c. n = n / 2 (right shift)
 *   3. Return result
 *
 * Time Complexity: O(log n) - Loop runs log(n) times
 * Space Complexity: O(1) - Only constant space used
 */
long long power_optimized_iterative(long long x, int n) {
    long long result = 1;

    while (n > 0) {
        // If n is odd, multiply result by x
        if (n & 1) {  // Same as (n % 2 == 1)
            result *= x;
        }

        // Square x
        x *= x;

        // Divide n by 2
        n >>= 1;  // Same as n = n / 2
    }

    return result;
}

/*
 * ALGORITHM 4: Optimized Recursive (Exponentiation by Squaring)
 * --------------------------------------------------------------
 * Recursive version of the optimized algorithm.
 *
 * Algorithm Power_Optimized_Recursive(x, n):
 *   1. If n == 0, return 1 (Base case)
 *   2. If n is even:
 *      a. half = Power_Optimized_Recursive(x, n/2)
 *      b. return half * half
 *   3. If n is odd:
 *      a. return x * Power_Optimized_Recursive(x, n-1)
 *
 * Time Complexity: O(log n) - Problem size halves each time
 * Space Complexity: O(log n) - Recursion stack depth is log(n)
 *
 * Recurrence Relation: T(n) = T(n/2) + O(1)
 *                      T(n) = O(log n)
 */
long long power_optimized_recursive(long long x, int n) {
    // Base case
    if (n == 0) {
        return 1;
    }

    // If n is even: x^n = (x^(n/2))^2
    if (n % 2 == 0) {
        long long half = power_optimized_recursive(x, n / 2);
        return half * half;
    }
    // If n is odd: x^n = x * x^(n-1)
    else {
        return x * power_optimized_recursive(x, n - 1);
    }
}

/*
 * ALGORITHM 5: Optimized Recursive (Alternative - Cleaner)
 * ---------------------------------------------------------
 * Slightly different formulation that always halves.
 *
 * Algorithm Power_Recursive_V2(x, n):
 *   1. If n == 0, return 1
 *   2. half = Power_Recursive_V2(x, n/2)
 *   3. If n is even: return half * half
 *   4. If n is odd: return half * half * x
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n)
 */
long long power_recursive_v2(long long x, int n) {
    // Base case
    if (n == 0) {
        return 1;
    }

    // Compute x^(n/2)
    long long half = power_recursive_v2(x, n / 2);

    // If n is even: x^n = half * half
    if (n % 2 == 0) {
        return half * half;
    }
    // If n is odd: x^n = half * half * x
    else {
        return half * half * x;
    }
}

// Display function to show step-by-step working
void showIterativeSteps(int x, int n) {
    cout << "\n--- Step-by-step (Iterative) ---" << endl;
    cout << "Computing " << x << "^" << n << endl;

    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= x;
        cout << "Step " << i << ": result = " << result;
        cout << " (multiplied by " << x << ")" << endl;
    }
    cout << "Final result: " << result << endl;
}

void showOptimizedSteps(int x, int n) {
    cout << "\n--- Step-by-step (Optimized - Binary Exponentiation) ---" << endl;
    cout << "Computing " << x << "^" << n << endl;
    cout << n << " in binary: ";

    // Print binary representation
    int temp = n;
    int bits[32];
    int bitCount = 0;
    while (temp > 0) {
        bits[bitCount++] = temp & 1;
        temp >>= 1;
    }
    for (int i = bitCount - 1; i >= 0; i--) {
        cout << bits[i];
    }
    cout << endl << endl;

    long long base = x;
    long long result = 1;
    int step = 1;
    int exp = n;

    while (exp > 0) {
        cout << "Step " << step++ << ": n = " << exp << ", base = " << base;
        if (exp & 1) {
            result *= base;
            cout << " (odd, multiply result by " << base << ") -> result = " << result;
        } else {
            cout << " (even, skip)";
        }
        base *= base;
        exp >>= 1;
        cout << endl;
    }
    cout << "Final result: " << result << endl;
}

// Main function
int main() {
    int x, n;
    int choice;

    cout << "========================================" << endl;
    cout << "  FIND X^n (Power of a Number)" << endl;
    cout << "  Practical 3 - DAA Lab" << endl;
    cout << "========================================" << endl;

    cout << "\nEnter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    if (n < 0) {
        cout << "Error: This program handles non-negative exponents only." << endl;
        cout << "For negative exponents, result would be 1/x^|n| (fraction)." << endl;
        return 1;
    }

    cout << "\n--- Results for " << x << "^" << n << " ---\n" << endl;

    // Run all algorithms and display results
    cout << "1. Iterative (Naive) O(n):           " << power_iterative(x, n) << endl;
    cout << "2. Recursive (Naive) O(n):           " << power_recursive(x, n) << endl;
    cout << "3. Optimized Iterative O(log n):     " << power_optimized_iterative(x, n) << endl;
    cout << "4. Optimized Recursive O(log n):     " << power_optimized_recursive(x, n) << endl;
    cout << "5. Optimized Recursive V2 O(log n):  " << power_recursive_v2(x, n) << endl;

    // Show detailed steps
    cout << "\nWould you like to see step-by-step working?" << endl;
    cout << "1. Yes - Iterative steps" << endl;
    cout << "2. Yes - Optimized (Binary) steps" << endl;
    cout << "3. No" << endl;
    cout << "Enter choice (1/2/3): ";
    cin >> choice;

    if (choice == 1) {
        showIterativeSteps(x, n);
    } else if (choice == 2) {
        showOptimizedSteps(x, n);
    }

    // Quick reference examples
    cout << "\n--- Quick Reference Examples ---" << endl;
    cout << "2^10 = " << power_optimized_recursive(2, 10) << endl;
    cout << "3^5  = " << power_optimized_recursive(3, 5) << endl;
    cout << "5^3  = " << power_optimized_recursive(5, 3) << endl;
    cout << "7^0  = " << power_optimized_recursive(7, 0) << endl;

    return 0;
}

/*
 * COMPLEXITY COMPARISON TABLE
 * ============================
 *
 * Algorithm                  | Time Complexity | Space Complexity
 * ---------------------------|-----------------|------------------
 * Iterative (Naive)          | O(n)            | O(1)
 * Recursive (Naive)          | O(n)            | O(n) - stack
 * Optimized Iterative        | O(log n)        | O(1)
 * Optimized Recursive        | O(log n)        | O(log n) - stack
 *
 * PERFORMANCE EXAMPLE (for n = 1000):
 * -----------------------------------
 * Naive:     1000 multiplications
 * Optimized: ~10 multiplications (log2(1000) ≈ 10)
 *
 * HOW BINARY EXPONENTIATION WORKS:
 * --------------------------------
 * Example: 2^13 where 13 = 1101 in binary
 *
 * 2^13 = 2^8 * 2^4 * 2^1
 *      = 256 * 16 * 2
 *      = 8192
 *
 * Binary: 1  1  0  1
 *         |  |     |
 *         |  |     +-- 2^1 = 2 (include)
 *         |  |
 *         |  +-------- 2^4 = 16 (include)
 *         |
 *         +----------- 2^8 = 256 (include)
 *
 * RECURRENCE RELATIONS:
 * ---------------------
 * Naive Recursive: T(n) = T(n-1) + c
 *                  T(n) = cn = O(n)
 *
 * Optimized:       T(n) = T(n/2) + c
 *                  By Master Theorem: T(n) = O(log n)
 *
 * SAMPLE OUTPUT:
 * --------------
 * Enter base (x): 2
 * Enter exponent (n): 10
 *
 * Results for 2^10:
 * 1. Iterative (Naive): 1024
 * 2. Recursive (Naive): 1024
 * 3. Optimized Iterative: 1024
 * 4. Optimized Recursive: 1024
 *
 * Step-by-step (Optimized):
 * 10 in binary: 1010
 * Step 1: n=10, base=2 (even, skip)
 * Step 2: n=5, base=4 (odd, result=4)
 * Step 3: n=2, base=16 (even, skip)
 * Step 4: n=1, base=256 (odd, result=1024)
 * Final: 1024
 */
