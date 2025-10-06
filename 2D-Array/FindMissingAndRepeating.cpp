#include<iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> se;
        int a = -1, b = -1;
        long long actSum = 0;  // use long long to avoid overflow
        int n = grid.size();
        int maxVal = n * n;    // correct max value
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actSum += val;
                if (se.find(val) != se.end()) {
                    a = val;
                }
                se.insert(val);
            }
        }
        long long expSum = 1LL * maxVal * (maxVal + 1) / 2;
        b = expSum - actSum + a;
        return {a, b};
    }
};

int main() {
    Solution solution;
    // Example: 2x2 grid, missing 3, repeated 2
    vector<vector<int>> grid = {
        {1, 2},
        {2, 4}
    };
    vector<int> result = solution.findMissingAndRepeatedValues(grid);
    cout << "Repeated value: " << result[0] << endl;
    cout << "Missing value: " << result[1] << endl;
    return 0;
}
