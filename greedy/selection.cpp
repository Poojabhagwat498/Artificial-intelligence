#include <iostream>
#include <vector>

using namespace std;

// Function to print the current state of the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Selection Sort Function with Step-by-Step Output
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    cout << "Original Array: ";
    printArray(arr);
    cout << "---------------------------------------" << endl;

    // One by one move the boundary of the unsorted subarray
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i; // Assume the first unsorted element is the minimum

        // Greedy choice: Find the minimum element in the remaining unsorted array
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Update index of the true minimum
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }

        // Print the array status after this step
        cout << "Step " << i + 1 << " (Swapped " << arr[i] << " to position " << i << "): ";
        printArray(arr);
    }
    
    cout << "---------------------------------------" << endl;
    cout << "Sorted Array: ";
    printArray(arr);
}

int main() {
    // Example array
    vector<int> arr = {64, 25, 12, 22, 11};
    
    selectionSort(arr);

    return 0;
} 
 /*How the "Greedy" Mechanism Works Behind the Scenes:
Step 1: The algorithm looks at the entire array [64, 25, 12, 22, 11]. The greedy choice searches for the absolute minimum value, which is 11. It swaps 11 with the first element 64.

Step 2: The unsorted part is now [25, 12, 22, 64]. The greedy choice finds 12 as the minimum and swaps it with 25.

Step 3: The unsorted part is [25, 22, 64]. The minimum is 22. It swaps with 25.

Step 4: The unsorted part is [25, 64]. The minimum is 25. Since it's already in the correct spot, no physical swap changes its position, but the sorted boundary moves forward.

Final: The last element 64 is naturally left in the correct position.*/