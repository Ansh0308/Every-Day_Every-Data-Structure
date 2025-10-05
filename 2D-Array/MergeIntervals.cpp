#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        
        for(vector<int> range : arr) {
            if(ans.size() == 0) {
                ans.push_back(range);
                continue;
            }
            if(range[0] <= ans.back()[1] && range[1] <= ans.back()[1]) {
                continue;
            }
            else if(range[0] <= ans.back()[1]) {
                ans.back()[1] = range[1];
            }
            else {
                ans.push_back(range);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> mergedIntervals = solution.merge(intervals);
    
    cout << "Merged intervals: ";
    for(auto &interval : mergedIntervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
