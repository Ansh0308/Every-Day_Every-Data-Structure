#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int m=arr.size(), n=arr[0].size();
        if(m==1 && n==1){
            return (arr[0][0]==target)?true:false;
        }

        int row=0, col=n-1;
        while(row<=m-1 && col>=0){
            if(arr[row][col]==target) return true;
            if(arr[row][col]>target){
                col--;
            }
            else if(arr[row][col]<target){
                row++;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> arr = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    Solution sol;
    bool found = sol.searchMatrix(arr, target);

    if(found) {
        cout << "Target " << target << " found in matrix." << endl;
    } else {
        cout << "Target " << target << " not found in matrix." << endl;
    }

    return 0;
}
