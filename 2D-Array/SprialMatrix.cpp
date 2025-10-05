#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& arr) {
    vector<int> ans;
    int top=0, right=arr[0].size()-1, left=0, bottom=arr.size()-1;
    while(top<=bottom && left<=right){
        if(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(arr[top][i]);
            }
            top++;
        }
        if(top<=bottom && left<=right){
            for(int i=top;i<=bottom;i++){
                ans.push_back(arr[i][right]);
            }
            right--;
        }
        if(top<=bottom && left<=right){
            for(int i=right;i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }
        if(top<=bottom && left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    vector<int> result = spiralOrder(matrix);
    cout << "Spiral order: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
