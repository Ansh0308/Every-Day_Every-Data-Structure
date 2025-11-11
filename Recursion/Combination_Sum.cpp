#include <bits/stdc++.h>
using namespace std;

// -------------------------------
// 🔹 Shortcuts & Typedefs
// -------------------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<string> vs;

// -------------------------------
// 🔹 Macros
// -------------------------------
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define sz(x) (int)(x).size()

#define forn(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i <= (n); i++)
#define forr(i, n) for (int i = (n)-1; i >= 0; i--)

// -------------------------------
// 🔹 Input / Output Helpers
// -------------------------------
vi input_vi(int n = -1) {
    if (n == -1) cin >> n;
    vi v(n);
    forn(i, n) cin >> v[i];
    return v;
}

vll input_vll(int n = -1) {
    if (n == -1) cin >> n;
    vll v(n);
    forn(i, n) cin >> v[i];
    return v;
}

template<typename T>
void print_vec(const vector<T>& v, string sep = " ") {
    for (auto &x : v) cout << x << sep;
    cout << endl;
}

// -------------------------------
// 🔹 Debug Utility
// -------------------------------
#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif

// -------------------------------
// 🔹 Constants
// -------------------------------
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

// -------------------------------
// 🔹 Combination Sum Logic
// -------------------------------
struct Solution {
    void helper(const vector<int>& nums, int target,
                vector<vector<int>>& ans, int index, int sum,
                vector<int>& temp) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (index == (int)nums.size() || sum > target) return;

        // pick current (stay at same index for unlimited use)
        temp.push_back(nums[index]);
        helper(nums, target, ans, index, sum + nums[index], temp);
        temp.pop_back();

        // skip current (move to next index)
        helper(nums, target, ans, index + 1, sum, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // keeps output deterministic
        nums.erase(unique(nums.begin(), nums.end()), nums.end()); // safety if input isn't strictly distinct
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, target, ans, 0, 0, temp);
        return ans;
    }
};

// -------------------------------
// 🔹 Main Logic (I/O)
// -------------------------------
void solve() {
    fast_io;
    // Input format (simple):
    // n
    // n integers (candidates)
    // target
    int n; 
    if (!(cin >> n)) return;
    vi candidates = input_vi(n);
    int target; cin >> target;

    Solution sol;
    auto res = sol.combinationSum(candidates, target);

    // Print results
    // Each combination on a new line, numbers space-separated
    // If no combinations, print nothing (or you can print 0)
    for (auto &comb : res) {
        for (int i = 0; i < (int)comb.size(); ++i) {
            if (i) cout << ' ';
            cout << comb[i];
        }
        cout << '\n';
    }
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
