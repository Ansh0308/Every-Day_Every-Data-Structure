#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        // horizontal check
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') return false;
        }
        // vertical check
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // diagonal left
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // diagonal right
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
    void nQueensRows(vector<string>& board, int row, vector<vector<string>>& ans) {
        if (row >= board.size()) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (isSafe(board, row, j)) {
                board[row][j] = 'Q';
                nQueensRows(board, row + 1, ans);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueensRows(board, 0, ans);
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter n: ";
    cin >> n;
    auto results = s.solveNQueens(n);

    cout << "Number of solutions: " << results.size() << endl;
    for (const auto& board : results) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
