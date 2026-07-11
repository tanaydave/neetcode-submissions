class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

private:
    // Sift arr[i] down so the subtree rooted at i becomes a valid max-heap.
    // n = number of elements still part of the heap (anything at index >= n is already sorted).
    void heapify(vector<int>& arr, int n, int i) {
        int left  = i * 2 + 1;   // left child of node i
        int right = i * 2 + 2;   // right child of node i
        int largestNode = i;     // assume the parent is the largest for now

        // If the left child exists and is bigger, it becomes the new candidate.
        if (left < n && arr[left] > arr[largestNode]) {
            largestNode = left;
        }
        // Same check for the right child.
        if (right < n && arr[right] > arr[largestNode]) {
            largestNode = right;
        }

        // If a child was larger, swap it up and keep fixing the subtree it came from.
        if (largestNode != i) {
            swap(arr[i], arr[largestNode]);
            heapify(arr, n, largestNode);
        }
        // If largestNode == i, the parent was already the biggest: heap property holds, stop.
    }

    void heapSort(vector<int>& arr) {
        int n = arr.size();

        // Phase 1: build a max-heap.
        // Start at the last non-leaf node (n/2 - 1) and heapify every node up to the root.
        // Leaves (the back half) are already valid one-element heaps, so we skip them.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Phase 2: extract the max repeatedly.
        // The largest element is always at index 0, so swap it to the end,
        // then shrink the heap by one and re-heapify the root to restore order.
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);   // park the current max at the end
            heapify(arr, i, 0);     // heap is now size i, fix the root
        }
    }
};