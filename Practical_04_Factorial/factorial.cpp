/*
 * Practical 4: Find Factorial of n
 * Subject: Design and Analysis of Algorithms
 * BCA Semester 4
 *
 * Iterative and Recursive algorithms with complexity analysis
 */

#include <iostream>
using namespace std;

/*
 * ALGORITHM 1: Iterative Approach
 * --------------------------------
 * Multiply all numbers from 1 to n.
 *
 * Algorithm Factorial_Iterative(n):
 *   1. Set result = 1
 *   2. For i = 2 to n:
 *      a. result = result * i
 *   3. Return result
 *
 * Time Complexity: O(n) - Loop runs n-1 times
 * Space Complexity: O(1) - Only constant space used
 */
unsigned long long factorial_iterative(int n) {
    unsigned long long result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

/*
 * ALGORITHM 2: Recursive Approach
 * --------------------------------
 * Use recursion: n! = n * (n-1)!
 *
 * Algorithm Factorial_Recursive(n):
 *   1. If n == 0 or n == 1, return 1 (Base case)
 *   2. Return n * Factorial_Recursive(n-1)
 *
 * Time Complexity: O(n) - n recursive calls
 * Space Complexity: O(n) - Recursion stack depth is n
 *
 * Recurrence Relation: T(n) = T(n-1) + O(1)
 *                      T(n) = O(n)
 */
unsigned long long factorial_recursive(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive case: n! = n * (n-1)!
    return n * factorial_recursive(n - 1);
}

/*
 * ALGORITHM 3: Tail Recursive Approach
 * -------------------------------------
 * Optimized recursion where recursive call is the last operation.
 * Some compilers can optimize this to avoid stack buildup.
 *
 * Algorithm Factorial_TailRecursive(n, accumulator):
 *   1. If n == 0 or n == 1, return accumulator
 *   2. Return Factorial_TailRecursive(n-1, n * accumulator)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) - but can be O(1) with tail call optimization
 */
unsigned long long factorial_tail_recursive(int n, unsigned long long accumulator = 1) {
    // Base case
    if (n == 0 || n == 1) {
        return accumulator;
    }

    // Tail recursive call - result is passed as accumulator
    return factorial_tail_recursive(n - 1, n * accumulator);
}

// Display function to show step-by-step working (Iterative)
void showIterativeSteps(int n) {
    cout << "\n--- Step-by-step (Iterative) ---" << endl;
    cout << "Computing " << n << "!" << endl;
    cout << n << "! = ";

    // Print the multiplication sequence
    for (int i = n; i >= 1; i--) {
        cout << i;
        if (i > 1) cout << " x ";
    }
    cout << endl;

    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
        cout << "Step " << (i - 1) << ": " << (i - 1) << "! x " << i << " = " << result << endl;
    }
    cout << "Final result: " << n << "! = " << result << endl;
}

// Display function to show step-by-step working (Recursive)
void showRecursiveSteps(int n, int depth = 0) {
    string indent(depth * 2, ' ');

    if (n == 0 || n == 1) {
        cout << indent << "factorial(" << n << ") = 1 (base case)" << endl;
        return;
    }

    cout << indent << "factorial(" << n << ") = " << n << " * factorial(" << n - 1 << ")" << endl;
    showRecursiveSteps(n - 1, depth + 1);
    cout << indent << "factorial(" << n << ") = " << n << " * " << factorial_recursive(n - 1) << " = " << factorial_recursive(n) << endl;
}

// Main function
int main() {
    int n;
    int choice;

    cout << "========================================" << endl;
    cout << "  FIND FACTORIAL OF N" << endl;
    cout << "  Practical 4 - DAA Lab" << endl;
    cout << "========================================" << endl;

    cout << "\nEnter a non-negative integer n: ";
    cin >> n;

    if (n < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1;
    }

    if (n > 20) {
        cout << "Warning: For n > 20, result may overflow (max ~18 quintillion for 64-bit)." << endl;
    }

    cout << "\n--- Results for " << n << "! ---\n" << endl;

    // Run all algorithms and display results
    cout << "1. Iterative O(n):       " << factorial_iterative(n) << endl;
    cout << "2. Recursive O(n):       " << factorial_recursive(n) << endl;
    cout << "3. Tail Recursive O(n):  " << factorial_tail_recursive(n) << endl;

    // Show detailed steps
    cout << "\nWould you like to see step-by-step working?" << endl;
    cout << "1. Yes - Iterative steps" << endl;
    cout << "2. Yes - Recursive call trace" << endl;
    cout << "3. No" << endl;
    cout << "Enter choice (1/2/3): ";
    cin >> choice;

    if (choice == 1) {
        showIterativeSteps(n);
    } else if (choice == 2) {
        cout << "\n--- Recursive Call Trace ---" << endl;
        showRecursiveSteps(n);
    }

    // Quick reference - Factorial table
    cout << "\n--- Factorial Table (0! to 10!) ---" << endl;
    cout << "n\tn!" << endl;
    cout << "---\t---" << endl;
    for (int i = 0; i <= 10; i++) {
        cout << i << "\t" << factorial_iterative(i) << endl;
    }

    return 0;
}

/*
 * COMPLEXITY COMPARISON TABLE
 * ============================
 *
 * Algorithm            | Time Complexity | Space Complexity
 * ---------------------|-----------------|------------------
 * Iterative            | O(n)            | O(1)
 * Recursive            | O(n)            | O(n) - stack
 * Tail Recursive       | O(n)            | O(n) or O(1)*
 *
 * *With tail call optimization by compiler
 *
 * RECURRENCE RELATION:
 * --------------------
 * T(n) = T(n-1) + c    (one recursive call + constant work)
 * T(1) = c             (base case)
 *
 * Solving:
 * T(n) = T(n-1) + c
 *      = T(n-2) + c + c
 *      = T(n-3) + c + c + c
 *      ...
 *      = T(1) + (n-1)c
 *      = c + (n-1)c
 *      = nc
 *      = O(n)
 *
 * MATHEMATICAL DEFINITION:
 * ------------------------
 * n! = n × (n-1) × (n-2) × ... × 2 × 1
 * 0! = 1 (by definition)
 * 1! = 1
 *
 * RECURSIVE DEFINITION:
 * ---------------------
 * n! = | 1              if n = 0 or n = 1
 *      | n × (n-1)!     if n > 1
 *
 * FACTORIAL VALUES:
 * -----------------
 * 0! = 1
 * 1! = 1
 * 2! = 2
 * 3! = 6
 * 4! = 24
 * 5! = 120
 * 6! = 720
 * 7! = 5040
 * 8! = 40320
 * 9! = 362880
 * 10! = 3628800
 * 20! = 2432902008176640000
 *
 * ITERATIVE vs RECURSIVE:
 * -----------------------
 * Iterative:
 *   + Uses O(1) space
 *   + No risk of stack overflow
 *   + Slightly faster (no function call overhead)
 *
 * Recursive:
 *   + More intuitive, matches mathematical definition
 *   + Easier to understand
 *   - Uses O(n) stack space
 *   - Risk of stack overflow for large n
 *
 * SAMPLE OUTPUT:
 * --------------
 * Enter a non-negative integer n: 5
 *
 * Results for 5!:
 * 1. Iterative: 120
 * 2. Recursive: 120
 * 3. Tail Recursive: 120
 *
 * Step-by-step (Iterative):
 * 5! = 5 x 4 x 3 x 2 x 1
 * Step 1: 1! x 2 = 2
 * Step 2: 2! x 3 = 6
 * Step 3: 3! x 4 = 24
 * Step 4: 4! x 5 = 120
 * Final result: 5! = 120
 */