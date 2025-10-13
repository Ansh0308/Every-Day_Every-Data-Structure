#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> temp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            int k = j + 1, l = n - 1;
            while (k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum < target) k++;
                else if (sum > target) l--;
                else {
                    temp.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (l > k && nums[l] == nums[l + 1]) l--;
                }
            }
        }
    }
    return temp;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << " are:\n";
    for (const auto& quad : result) {
        cout << "[ ";
        for (int num : quad) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
