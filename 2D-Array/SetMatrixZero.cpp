#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        unordered_set<int> rows, cols;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(int index : rows) {
            for(int i = 0; i < n; i++) {
                arr[index][i] = 0;
            }
        }
        for(int index : cols) {
            for(int i = 0; i < m; i++) {
                arr[i][index] = 0;
            }
        }
    }
};

void printMatrix(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(arr);

    Solution sol;
    sol.setZeroes(arr);

    cout << "Matrix After setZeroes:" << endl;
    printMatrix(arr);

    return 0;
}
