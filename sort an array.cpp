#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;        // root
        int left = 2 * i + 1;   // left child
        int right = 2 * i + 2;  // right child

        // Find the largest among root, left child, and right child
        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;

        // If root is not largest, swap and continue heapifying
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // Step 2: Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);  // Move current root to end
            heapify(nums, i, 0);     // Heapify reduced heap
        }

        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> sorted = sol.sortArray(nums);

    for (int num : sorted) cout << num << " ";
    // Output: 1 2 3 5
    return 0;
}
