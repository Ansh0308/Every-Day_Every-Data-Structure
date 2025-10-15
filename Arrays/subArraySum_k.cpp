#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Edge case: if single element equals k
        if (nums.size() == 1 && nums[0] == k) return 1;

        int n = nums.size();
        int count = 0;

        // Prefix Sum array
        vector<int> PS(n);
        PS[0] = nums[0];
        for (int i = 1; i < n; i++) {
            PS[i] = PS[i - 1] + nums[i];
        }

        // Hash map to store frequency of prefix sums
        unordered_map<int, int> PS_freq;

        for (int j = 0; j < n; j++) {
            // Case 1: subarray starts from index 0
            if (PS[j] == k) count++;

            // Case 2: subarray between two indices (i, j)
            int val = PS[j] - k;
            if (PS_freq.find(val) != PS_freq.end()) {
                count += PS_freq[val];
            }

            // Store prefix sum frequency
            PS_freq[PS[j]]++;
        }

        return count;
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    Solution sol;

    // Example input
    vector<int> nums = {1, 2, 3};
    int k = 3;

    // Compute result
    int result = sol.subarraySum(nums, k);

    // Output the result
    cout << "Number of subarrays with sum = " << k << " is: " << result << endl;

    return 0;
}

/*
------------------ EXPLANATION ------------------
This program finds the number of subarrays whose sum equals k.
It uses prefix sums and an unordered_map to store frequencies
of prefix sums seen so far.

------------------ TIME COMPLEXITY ------------------
O(n)
- We traverse the array once.
- Each map operation (insert, find) is O(1) on average.

------------------ SPACE COMPLEXITY ------------------
O(n)
- The prefix sum array (PS) takes O(n) space.
- The unordered_map can also store up to O(n) prefix sums.
*/
