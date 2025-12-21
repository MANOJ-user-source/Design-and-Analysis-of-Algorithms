/*
 * Practical 6: Implement Recursive Binary search and Linear search 
 * and determine the time taken to search an element.
 * Subject: Design and Analysis of Algorithms
 *
 * Comparison of Linear vs Binary Search approaches
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

/*
 * ALGORITHM 1: Linear Search
 * --------------------------
 * Sequentially checks each element of the list until a match is found 
 * or the whole list has been searched.
 *
 * Time Complexity: O(n) - Worst case (element at end or not present)
 * Space Complexity: O(1) - No extra space required
 */
int linearSearch(const vector<int>& arr, int key) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

/*
 * ALGORITHM 2: Recursive Binary Search (Divide and Conquer)
 * ---------------------------------------------------------
 * Search a sorted array by repeatedly dividing the search interval in half.
 * 
 * Algorithm BinarySearch(arr, left, right, key):
 *   1. If right >= left:
 *      mid = left + (right - left) / 2
 *      If arr[mid] == key, return mid
 *      If arr[mid] > key, return BinarySearch(arr, left, mid-1, key)
 *      Else return BinarySearch(arr, mid+1, right, key)
 *   2. Return -1 (Element not found)
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) - Due to recursive stack
 * Recurrence Relation: T(n) = T(n/2) + c
 */
int binarySearchRecursive(const vector<int>& arr, int left, int right, int key) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearchRecursive(arr, left, mid - 1, key);

        return binarySearchRecursive(arr, mid + 1, right, key);
    }
    return -1;
}

// Function to display complexity analysis
void showComplexityAnalysis(int n) {
    cout << "\n--- Complexity Analysis for n=" << n << " ---" << endl;
    cout << "Linear Search (Worst Case): O(n)     = " << n << " comparisons" << endl;
    
    double logN = (n > 0) ? log2(n) : 0;
    cout << "Binary Search (Worst Case): O(log n) = " << (int)logN + 1 << " comparisons" << endl;
    
    cout << "\nNote: Binary Search is significantly faster for large n," << endl;
    cout << "but requires the array to be sorted." << endl;
}

int main() {
    int n, key;
    
    cout << "========================================" << endl;
    cout << "  BINARY SEARCH & LINEAR SEARCH" << endl;
    cout << "  Practical 6 - DAA Lab" << endl;
    cout << "========================================" << endl;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Sort the array to ensure Binary Search works correctly
    sort(arr.begin(), arr.end());
    cout << "\nArray has been sorted for Binary Search: [ ";
    for (int x : arr) cout << x << " ";
    cout << "]" << endl;
    
    cout << "\nEnter the element to search: ";
    cin >> key;
    
    cout << "\n--- Execution Results ---" << endl;
    
    // Measure Linear Search Time
    auto start = high_resolution_clock::now();
    int lsIndex = linearSearch(arr, key);
    auto stop = high_resolution_clock::now();
    auto durationLS = duration_cast<nanoseconds>(stop - start);
    
    if (lsIndex != -1) cout << "1. Linear Search: Found at index " << lsIndex;
    else cout << "1. Linear Search: Not found";
    cout << "\n   Time taken: " << durationLS.count() << " ns" << endl;
    
    // Measure Recursive Binary Search Time
    start = high_resolution_clock::now();
    int bsIndex = binarySearchRecursive(arr, 0, n - 1, key);
    stop = high_resolution_clock::now();
    auto durationBS = duration_cast<nanoseconds>(stop - start);
    
    if (bsIndex != -1) cout << "2. Binary Search: Found at index " << bsIndex;
    else cout << "2. Binary Search: Not found";
    cout << "\n   Time taken: " << durationBS.count() << " ns" << endl;
    
    // Show complexity analysis
    showComplexityAnalysis(n);
    
    return 0;
}

/*
 * ANALYSIS OF SEARCH ALGORITHMS
 * =============================
 *
 * 1. LINEAR SEARCH
 *    - Approach: Brute force. Check every element.
 *    - Best Case: O(1) (Element is at the first position)
 *    - Worst Case: O(n) (Element is at the last position or not present)
 *    - Average Case: O(n)
 *    - Prerequisite: None (Array can be unsorted)
 *
 * 2. BINARY SEARCH (Recursive)
 *    - Approach: Divide and Conquer.
 *    - Logic:
 *      Compare key with middle element.
 *      If key matches, return index.
 *      If key < mid, search left half.
 *      If key > mid, search right half.
 *    - Recurrence Relation:
 *      T(n) = T(n/2) + 1
 *      T(1) = 1
 *      Solution: T(n) = O(log n)
 *    - Best Case: O(1) (Element is at the middle)
 *    - Worst Case: O(log n)
 *    - Prerequisite: Array MUST be sorted.
 *
 * COMPARISON
 * ----------
 * For small n, Linear Search is sufficient and sometimes faster due to overhead.
 * For large n, Binary Search is exponentially faster.
 * Example: n = 1,000,000
 *   Linear Search: ~1,000,000 comparisons
 *   Binary Search: ~20 comparisons (log2(10^6) ≈ 19.9)
 */