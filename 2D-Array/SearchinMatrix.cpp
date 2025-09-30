#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size(),n=matrix[0].size();
        if(m==1 && n==1){
            return (matrix[0][0]==target)?true:false;
        }
        int start=0,end=m-1,row=start;
        while(start<=end){
            int mid=end+(start-end)/2;
            if(matrix[mid][0]<=target && matrix[mid][n-1]>=target){
                row=mid;
                break;}
            if(matrix[mid][0]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        start=0,end=n-1;
        while(start<=end){
             int mid=end+(start-end)/2;
            if(matrix[row][mid]==target)return true;
            if(matrix[row][mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    bool found = sol.searchMatrix(matrix, target);
    if (found) {
        cout << "Target " << target << " found in matrix." << endl;
    } else {
        cout << "Target " << target << " not found in matrix." << endl;
    }
    return 0;
}
