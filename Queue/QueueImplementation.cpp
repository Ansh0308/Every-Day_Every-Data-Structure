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
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
}
};
class Queue{
    public:
    Node* head;
    Node* tail;
    Queue(){
        head = NULL;
        tail = NULL;
    }
    void push(int val){
        if(!head){
            head=new Node(val);
            tail=head;
            return;
        }
        tail->next=new Node(val);
        tail=tail->next;

    }
    void pop(){
        if(!head)return;
        Node* temp=head;
        head=head->next;
        delete temp;

    }
    int front(){
        if(!head)return -1;
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }
};

void solve() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << endl; // Output: 10
    q.pop();
    cout << q.front() << endl; // Output: 20
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl; // Output: Queue is not empty
    q.pop();
    q.pop();
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << endl; // Output: Queue is empty
    
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
