#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> ma;
    for(int i = 0; i < nums.size(); i++) {
        int first_ele = nums[i];
        int second_ele = target - first_ele;
        if(ma.find(second_ele) != ma.end()) {
            return {i, ma[second_ele]};
        }
        ma[first_ele] = i;
    }
    return {-1, -1};

    // Alternate approach (sorting + two pointers)
    /*
    vector<pair<int,int>> s;
    for(int i = 0; i < nums.size(); i++){
        s.push_back({nums[i], i});
    }
    sort(s.begin(), s.end());
    int start = 0, end = nums.size() - 1;
    while(start <= end){
        if(s[start].first + s[end].first == target)
            return {s[start].second, s[end].second};
        if(s[start].first + s[end].first > target)
            end--;
        else
            start++;
    }
    return {-1, -1};
    */
}

int main() {
    vector<int> nums = {2, 7, 11, 15};  // Example input
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if(result[0] != -1)
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    else
        cout << "No two numbers sum up to the target." << endl;

    return 0;
}
