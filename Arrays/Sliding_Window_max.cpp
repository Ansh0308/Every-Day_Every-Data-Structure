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
// 🔹 Main Logic Example
// -------------------------------
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> window;
        int Max=INT_MIN;
        for(int i=0;i<0+k;i++){
            window.push_back(nums[i]);
            Max=max(Max,nums[i]);


        }
        ans.push_back(Max);
        for(int i=k;i<n;i++){
            window.pop_front();
            window.push_back(nums[i]);
            auto ele = max_element(window.begin(), window.end());
            ans.push_back(*ele);
           

        }
        return ans;
        
    }

void solve() {
    // // Example 1: Using typedefs and input helpers
    cout << "Enter number of elements: "<<endl;
    int n; cin >> n;
    vi arr = input_vi(n);
    cout<<"Enter the size of window"<<endl;
    int k;
    cin>>k;
    vi result = maxSlidingWindow(arr, k);
    cout << "Sliding window maximums: ";
    print_vec(result);


    // // Example 2: Using macros and algorithms
    // sort(all(arr)); // uses all()
    // reverse(rall(arr)); // uses rall()

    // // Example 3: Output helper
    // cout << "Reversed sorted array: ";
    // print_vec(arr);

    // // Example 4: Using constants
    // cout << "Modulo constant: " << MOD << endl;

    // // Example 5: Using pairs and vectors of pairs
    // vpii vp;
    // forn(i, n) vp.pb({arr[i], i + 1}); // (value, position)
    
    // cout << "Vector of pairs (value, index):" << endl;
    // for (auto &p : vp)
    //     cout << "(" << p.ff << ", " << p.ss << ") ";
    // cout << endl;

    // // Example 6: Using long long vector and arithmetic
    // cout << "Enter " << n << " long long values: ";
    // vll nums = input_vll(n);
    // ll sum = accumulate(all(nums), 0LL);
    // cout << "Sum = " << sum << endl;

    // // Example 7: Using reverse for loop
    // cout << "Printing nums in reverse: ";
    // forr(i, n) cout << nums[i] << " ";
    // cout << endl;

    // // Example 8: Debug macro (only works if compiled with -DLOCAL)
    // dbg(sum);

    // // Example 9: Using strings and vector<string>
    // cout << "Enter 3 strings: ";
    // vs names(3);
    // forn(i, 3) cin >> names[i];
    // sort(all(names));
    // cout << "Sorted names: ";
    // print_vec(names);

}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
