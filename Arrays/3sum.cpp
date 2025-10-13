#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Skip duplicates for i
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (sum < 0) j++;
            else if (sum > 0) k--;
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                // Skip duplicates for j
                while (j < k && nums[j] == nums[j - 1]) j++;
                // Skip duplicates for k
                while (j < k && nums[k] == nums[k + 1]) k--;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to zero:\n";
    for (auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
