#include <bits/stdc++.h>
using namespace std;

// Function to find the largest Jumping Number <= n with same number of digits
long long largestJumpingNumber(long long n) {
    string s = to_string(n);
    int len = s.size();
    
    // Special case: if n is single digit
    if (len == 1) return n;

    long long ans = -1;
    queue<long long> q;

    // Start BFS with digits 1..9
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        long long num = q.front();
        q.pop();

        int digits = to_string(num).size();

        if (digits == len && num <= n) {
            ans = max(ans, num); // update answer
        }

        if (digits < len) {
            int last = num % 10;

            // Possible next digits
            if (last > 0) q.push(num * 10 + (last - 1));
            if (last < 9) q.push(num * 10 + (last + 1));
        }
    }

    return ans;
}

int main() {
    long long n;
    cin >> n;
    cout << largestJumpingNumber(n) << "\n";
    return 0;
}
