/*
 * Practical 5: Find Maximum and Minimum using Divide and Conquer
 * Subject: Design and Analysis of Algorithms
 * BCA Semester 4
 *
 * Comparison of Linear vs Divide and Conquer approaches
 */

#include <iostream>
#include <climits>
using namespace std;

// Structure to hold both max and min
struct Pair {
    int max;
    int min;
};

/*
 * ALGORITHM 1: Linear/Naive Approach
 * -----------------------------------
 * Compare each element with current max and min.
 *
 * Algorithm FindMaxMin_Linear(arr, n):
 *   1. Set max = min = arr[0]
 *   2. For i = 1 to n-1:
 *      a. If arr[i] > max, set max = arr[i]
 *      b. If arr[i] < min, set min = arr[i]
 *   3. Return (max, min)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * Number of Comparisons: 2(n-1) = 2n - 2
 */
Pair findMaxMin_Linear(int arr[], int n) {
    Pair result;
    result.max = arr[0];
    result.min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > result.max) {
            result.max = arr[i];
        }
        if (arr[i] < result.min) {
            result.min = arr[i];
        }
    }

    return result;
}

/*
 * ALGORITHM 2: Linear Optimized (Pairwise Comparison)
 * ----------------------------------------------------
 * Compare elements in pairs first, then with max/min.
 *
 * Number of Comparisons: 3n/2 - 2 (Better than 2n-2)
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
Pair findMaxMin_Pairwise(int arr[], int n) {
    Pair result;
    int i;

    // If odd number of elements, initialize with first element
    if (n % 2 == 1) {
        result.max = result.min = arr[0];
        i = 1;
    }
    // If even, compare first two elements
    else {
        if (arr[0] > arr[1]) {
            result.max = arr[0];
            result.min = arr[1];
        } else {
            result.max = arr[1];
            result.min = arr[0];
        }
        i = 2;
    }

    // Compare in pairs
    while (i < n - 1) {
        if (arr[i] > arr[i + 1]) {
            if (arr[i] > result.max) result.max = arr[i];
            if (arr[i + 1] < result.min) result.min = arr[i + 1];
        } else {
            if (arr[i + 1] > result.max) result.max = arr[i + 1];
            if (arr[i] < result.min) result.min = arr[i];
        }
        i += 2;
    }

    return result;
}

/*
 * ALGORITHM 3: Divide and Conquer Approach
 * -----------------------------------------
 * Divide array into two halves, find max-min in each half,
 * then combine results.
 *
 * Algorithm FindMaxMin_DAC(arr, low, high):
 *   1. If low == high:                    // Single element
 *      - Return (arr[low], arr[low])
 *
 *   2. If high == low + 1:                // Two elements
 *      - If arr[low] > arr[high]:
 *          Return (arr[low], arr[high])
 *      - Else:
 *          Return (arr[high], arr[low])
 *
 *   3. Else:                              // More than two elements
 *      - mid = (low + high) / 2
 *      - (max1, min1) = FindMaxMin_DAC(arr, low, mid)
 *      - (max2, min2) = FindMaxMin_DAC(arr, mid+1, high)
 *      - Return (max(max1, max2), min(min1, min2))
 *
 * Time Complexity: O(n)
 * Space Complexity: O(log n) - recursion stack
 * Number of Comparisons: 3n/2 - 2
 *
 * Recurrence Relation:
 *   T(n) = 2T(n/2) + 2    (two recursive calls + 2 comparisons)
 *   T(2) = 1              (base case: 1 comparison)
 *   T(1) = 0              (base case: no comparison)
 *
 *   Solution: T(n) = 3n/2 - 2
 */
Pair findMaxMin_DAC(int arr[], int low, int high) {
    Pair result, left, right;

    // Case 1: Only one element
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    // Case 2: Two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }

    // Case 3: More than two elements - Divide and Conquer
    int mid = (low + high) / 2;

    // Divide: Solve for left and right halves
    left = findMaxMin_DAC(arr, low, mid);
    right = findMaxMin_DAC(arr, mid + 1, high);

    // Conquer: Combine results
    result.max = (left.max > right.max) ? left.max : right.max;
    result.min = (left.min < right.min) ? left.min : right.min;

    return result;
}

// Wrapper function for Divide and Conquer
Pair findMaxMin_DivideConquer(int arr[], int n) {
    return findMaxMin_DAC(arr, 0, n - 1);
}

// Function to display the divide and conquer process
void showDAC_Steps(int arr[], int low, int high, int depth = 0) {
    string indent(depth * 4, ' ');

    if (low == high) {
        cout << indent << "Single element [" << low << "]: " << arr[low];
        cout << " -> max=" << arr[low] << ", min=" << arr[low] << endl;
        return;
    }

    if (high == low + 1) {
        cout << indent << "Two elements [" << low << "," << high << "]: ";
        cout << arr[low] << ", " << arr[high];
        if (arr[low] > arr[high])
            cout << " -> max=" << arr[low] << ", min=" << arr[high] << endl;
        else
            cout << " -> max=" << arr[high] << ", min=" << arr[low] << endl;
        return;
    }

    int mid = (low + high) / 2;

    cout << indent << "Divide [" << low << "," << high << "] at mid=" << mid << endl;

    // Left half
    cout << indent << "Left half [" << low << "," << mid << "]:" << endl;
    showDAC_Steps(arr, low, mid, depth + 1);

    // Right half
    cout << indent << "Right half [" << mid + 1 << "," << high << "]:" << endl;
    showDAC_Steps(arr, mid + 1, high, depth + 1);

    // Combine
    Pair left = findMaxMin_DAC(arr, low, mid);
    Pair right = findMaxMin_DAC(arr, mid + 1, high);
    cout << indent << "Combine: max(" << left.max << "," << right.max << ")=";
    cout << max(left.max, right.max);
    cout << ", min(" << left.min << "," << right.min << ")=";
    cout << min(left.min, right.min) << endl;
}

// Calculate number of comparisons for each method
void showComparisons(int n) {
    cout << "\n--- Number of Comparisons for n=" << n << " ---" << endl;
    cout << "Linear (Naive):        2(n-1) = " << 2 * (n - 1) << " comparisons" << endl;
    cout << "Pairwise Optimized:    3n/2-2 = " << (3 * n / 2 - 2) << " comparisons" << endl;
    cout << "Divide and Conquer:    3n/2-2 = " << (3 * n / 2 - 2) << " comparisons" << endl;
    cout << "\nSavings with D&C: " << (2 * (n - 1)) - (3 * n / 2 - 2) << " fewer comparisons" << endl;
}

// Main function
int main() {
    int n;
    int choice;

    cout << "========================================" << endl;
    cout << "  FIND MAX AND MIN (Divide & Conquer)" << endl;
    cout << "  Practical 5 - DAA Lab" << endl;
    cout << "========================================" << endl;

    cout << "\nEnter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Error: Array size must be positive." << endl;
        return 1;
    }

    int* arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Display input array
    cout << "\nArray: [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "\n--- Results ---\n" << endl;

    // Run all algorithms
    Pair result1 = findMaxMin_Linear(arr, n);
    cout << "1. Linear Method:          Max = " << result1.max << ", Min = " << result1.min << endl;

    Pair result2 = findMaxMin_Pairwise(arr, n);
    cout << "2. Pairwise Method:        Max = " << result2.max << ", Min = " << result2.min << endl;

    Pair result3 = findMaxMin_DivideConquer(arr, n);
    cout << "3. Divide and Conquer:     Max = " << result3.max << ", Min = " << result3.min << endl;

    // Show comparison counts
    showComparisons(n);

    // Show detailed steps
    cout << "\nWould you like to see Divide and Conquer steps?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Enter choice (1/2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "\n--- Divide and Conquer Trace ---" << endl;
        showDAC_Steps(arr, 0, n - 1);
    }

    // Quick example
    cout << "\n--- Quick Example ---" << endl;
    int example[] = {3, 5, 1, 8, 2, 9, 4, 7};
    int exSize = 8;
    cout << "Array: [3, 5, 1, 8, 2, 9, 4, 7]" << endl;
    Pair exResult = findMaxMin_DivideConquer(example, exSize);
    cout << "Max = " << exResult.max << ", Min = " << exResult.min << endl;

    delete[] arr;
    return 0;
}

/*
 * DIVIDE AND CONQUER PARADIGM
 * ===========================
 *
 * Three Steps:
 * 1. DIVIDE:   Split problem into smaller subproblems
 * 2. CONQUER:  Solve subproblems recursively
 * 3. COMBINE:  Merge solutions of subproblems
 *
 * For Max-Min Problem:
 * - DIVIDE:  Split array into two halves
 * - CONQUER: Find max-min in each half recursively
 * - COMBINE: max = max(left_max, right_max)
 *            min = min(left_min, right_min)
 *
 * COMPLEXITY ANALYSIS
 * ===================
 *
 * Recurrence Relation:
 *   T(n) = 2T(n/2) + 2
 *   T(2) = 1
 *   T(1) = 0
 *
 * Solving (Substitution):
 *   T(n) = 2T(n/2) + 2
 *        = 2[2T(n/4) + 2] + 2
 *        = 4T(n/4) + 4 + 2
 *        = 4[2T(n/8) + 2] + 6
 *        = 8T(n/8) + 8 + 6
 *        ...
 *        = 2^k * T(n/2^k) + Σ(2^i) for i=1 to k
 *
 *   When n/2^k = 2, k = log(n) - 1
 *   T(n) = n/2 * T(2) + 2(n/2 - 1)
 *        = n/2 * 1 + n - 2
 *        = n/2 + n - 2
 *        = 3n/2 - 2
 *
 * COMPARISON COUNT TABLE
 * ======================
 *
 * Method              | Comparisons | For n=8 | For n=100
 * --------------------|-------------|---------|----------
 * Linear (Naive)      | 2n - 2      | 14      | 198
 * Divide and Conquer  | 3n/2 - 2    | 10      | 148
 * Savings             | n/2         | 4       | 50
 *
 * WHY D&C IS BETTER (for comparisons):
 * ------------------------------------
 * - Linear: Each element compared twice (with max AND min)
 * - D&C: Elements compared only once at leaf level,
 *        then only max vs max and min vs min at higher levels
 *
 * VISUAL EXAMPLE (n=8)
 * ====================
 *
 * Array: [3, 5, 1, 8, 2, 9, 4, 7]
 *
 *                    [3,5,1,8,2,9,4,7]
 *                    max=9, min=1
 *                   /              \
 *           [3,5,1,8]              [2,9,4,7]
 *           max=8,min=1            max=9,min=2
 *          /        \              /        \
 *       [3,5]      [1,8]        [2,9]      [4,7]
 *       m=5,n=3    m=8,n=1      m=9,n=2    m=7,n=4
 *
 * Comparisons: 4 (at leaves) + 4 (at level 1) + 2 (at root) = 10
 * Linear would need: 2(8-1) = 14 comparisons
 *
 * SAMPLE OUTPUT
 * =============
 *
 * Enter number of elements: 6
 * Enter 6 elements: 12 5 8 3 15 7
 *
 * Array: [12, 5, 8, 3, 15, 7]
 *
 * Results:
 * 1. Linear Method:       Max = 15, Min = 3
 * 2. Divide and Conquer:  Max = 15, Min = 3
 *
 * Comparisons for n=6:
 * Linear:   2(n-1) = 10
 * D&C:      3n/2-2 = 7
 */