#include <bits/stdc++.h>
using namespace std;

// -------------------------------
// 🔹 Shortcuts & Typedefs
// -------------------------------
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
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
vi NextGreaterElement(vi &arr){
    int n=sz(arr);
    vi nge(n,-1);
    stack<int> st; // {value, index}
    forr(i,n){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            nge[i]=st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}
vi NextGreaterElement_I(vi &nums1,vi &nums2){
    int n=sz(nums2);
    unordered_map<int,int> mp; // {value, next greater element}
    stack<int> st; // {value, index}
    forr(i,n){
        while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
        }
        if(!st.empty()){
            mp[nums2[i]]=st.top();
        }
        else{
            mp[nums2[i]]=-1;
        }
        st.push(nums2[i]);
    }
    vi res;
    for(int num:nums1){
        res.pb(mp[num]);
    }
    return res;
}
vi previousSmallerElement(vi &arr){
    int n=sz(arr);
    vi pse(n,-1);
    stack<int> st; // {value, index}
    forn(i,n){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        if(!st.empty()){
            pse[i]=st.top();
        }
        st.push(arr[i]);
    }
    return pse;
}
int largestRectangleArea(vi &heights){
    int n=sz(heights);
    vi rightSmaller(n,-1);
    vi leftSmaller(n,-1);
    stack<int> st;
    forn(i,n){
        while(!st.empty()){
            if(heights[st.top()]<heights[i]){
                leftSmaller[i]=st.top();
                break;
                
            }
            st.pop();
            
        }
        if(st.empty()){
                leftSmaller[i]=-1;
                
            }
        st.push(i);
    }
    while(!st.empty())st.pop();
    forr(i,n){
        while(!st.empty()){
            if(heights[st.top()]<heights[i]){
                rightSmaller[i]=st.top();
                break;
                
            }
            st.pop();
            
        }
        if(st.empty()){
                rightSmaller[i]=n;
                
            }
        st.push(i);
    }
    int maxArea=0;
    forn(i,n){
        int height=heights[i];
        int width=rightSmaller[i]-leftSmaller[i]-1;
        maxArea=max(maxArea,height*width);
    }
    return maxArea;
}
int FindCelebrity(vvi &nums){
    int n=nums.size();
    stack<int> st;
    forn(i,n)st.push(i);
    while(st.size()>1){
        int a=st.top();st.pop();
        int b=st.top();st.pop();
        if(nums[a][b]==1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    int candidate=st.top();
    forn(i,n){
        if(i!=candidate && (nums[candidate][i]==1 || nums[i][candidate]==0)){
            return -1;
        }
    }
    return candidate;
}
class QueueUsingStack{
    public:
    stack<int> s1;
    stack<int> s2;

    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        
    }
    
    int pop() {
        int temp=s1.top();
        s1.pop();
        return temp;
        
    }
    
    int peek() {
        return s1.top();
        
    }
    
    bool empty() {
        return s1.empty();
    }
    };
void solve() {
    QueueUsingStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.peek()<<endl;
        q.pop();
    }
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
