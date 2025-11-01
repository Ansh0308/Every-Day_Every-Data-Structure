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

template<typename T>
void print_vec(const vector<T>& v, string sep = " ") {
    for (auto &x : v) cout << x << sep;
    cout << endl;
}

// -------------------------------
// 🔹 Subsets With Duplicates Logic
// -------------------------------
void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int> c = {}, int index = 0) {
    if (index == nums.size()) {
        ans.push_back(c);
        return;
    }

    // include current element
    c.push_back(nums[index]);
    helper(nums, ans, c, index + 1);

    // exclude current element
    c.pop_back();

    // skip duplicates
    int i = index + 1;
    while (i < nums.size() && nums[i] == nums[i - 1]) i++;

    helper(nums, ans, c, i);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    helper(nums, ans);
    return ans;
}

// -------------------------------
// 🔹 Main Logic
// -------------------------------
void solve() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    vi nums = input_vi(n);

    vector<vector<int>> res = subsetsWithDup(nums);

    cout << "\nAll unique subsets are:\n";
    for (auto &subset : res) {
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}" << endl;
    }
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    fast_io;
    solve();
    return 0;
}
