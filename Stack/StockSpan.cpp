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
bool vaildParentheses(string &s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['||c=='{'){
            st.push(c);
        }
        else{
            if(st.empty())return false;
            else if(c==')'&&st.top()=='('){
                st.pop();
            }
            else if(c==']'&&st.top()=='['){
                st.pop();
            }
            else if(c=='}'&&st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
vi stockSpan(vi &prices){
    int n=sz(prices);
    vi span(n);
    stack<int> st; // {price, index}
    forn(i,n){
        while(!st.empty() && prices[st.top()]<=prices[i]){
            st.pop();
        }
        if(st.empty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-st.top();
        }
        st.push(i);
    }
    return span;
}
void solve() {
    
    vi prices = {100, 80, 60, 70, 60, 75, 85};
    vi span = stockSpan(prices);
    print_vec(span);
    

}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
