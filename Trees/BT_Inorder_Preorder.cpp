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
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=nullptr;
    }

};

Node* BuildTree(vi& preorder,int &idx){
    idx++;
    if(preorder[idx]==-1 || idx>=preorder.size())return nullptr;
    Node* root=new Node(preorder[idx]);
    root->left=BuildTree(preorder,idx);
    root->right=BuildTree(preorder,idx);
    return root;
}
void Preorder(Node* root){
    if(root==nullptr)return;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root){
    if(root==nullptr)return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Postorder(Node* root){
    if(root==nullptr)return;
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
void LevelOrder(Node* root){
    if(root==nullptr)return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<" ";
        if(q.front()->left!=nullptr)q.push(q.front()->left);
        if(q.front()->right!=nullptr)q.push(q.front()->right);
        q.pop();
    }
}
Node* BuildTreeInorderPreorder(vi& preorder,vi& inorder,int &preidx,int inStart,int inEnd){
    if(inStart>inEnd)return nullptr;
    int curr=preorder[preidx];
    preidx++;
    Node* node=new Node(curr);
    int pos=-1;
    for(int i=inStart;i<=inEnd;i++){
        if(inorder[i]==curr){
            pos=i;
            break;
        }
    }
    node->left=BuildTreeInorderPreorder(preorder,inorder,preidx,inStart,pos-1);
    node->right=BuildTreeInorderPreorder(preorder,inorder,preidx,pos+1,inEnd);
    return node;
}
void solve() {
    vi preorder={3,9,20,15,7};
    
    vi inorder={9,3,15,20,7};
    int preidx=0;
    Node* root=BuildTreeInorderPreorder(preorder,inorder,preidx,0,inorder.size()-1);
    cout<<"Tree built from preorder and inorder traversal: "<<endl;
    
    Preorder(root);
    }

// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
