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
bool isSameTree(Node* p, Node* q) {
    if(p==nullptr && q==nullptr)return true;
    if(p==nullptr || q==nullptr)return false;
    if(p->data!=q->data)return false;
    return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}
bool isSubtree(Node* root, Node* subRoot) {
        if(root==nullptr && subRoot==nullptr)return true;
        if(root==nullptr || subRoot==nullptr)return false;
        if(root->data==subRoot->data){
            bool temp=isSameTree(root,subRoot);
             if(temp)return true;
        }
       
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);

        
    }
    int height(Node* root){
        if(root==nullptr)return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(Node* root) {
        if(root==nullptr)return 0;
        int h1=height(root->left);
        int h2=height(root->right);
        int ans1=h1+h2;
        int ans2=(h1>h2)?diameterOfBinaryTree(root->left):diameterOfBinaryTree(root->right);
        return max(ans1,ans2);
        
    }
    void topView(Node* root){
        queue<pair<Node*,int>>q;
        map<int,int> m;
        vi result;

        q.push({root,0});
        while(!q.empty()){
            Node* temp=q.front().first;
            int currentDistance=q.front().second;
            q.pop();
            if(m.find(currentDistance)==m.end()){
                m[currentDistance]=temp->data;
                
            }
            if(temp->left!=nullptr)q.push({temp->left,currentDistance-1});
            if(temp->right!=nullptr)q.push({temp->right,currentDistance+1});
        }
        for(auto it:m){
            cout<<it.second<<" ";
        }
        
    }
    int KthLevel(Node* root,int k){
        if(root==nullptr)return -1;
        int sum=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(i==k-1)sum+=temp->data;
                if(temp->left!=nullptr)q.push(temp->left);
                if(temp->right!=nullptr)q.push(temp->right);
            }
            k--;
            if(k==0)break;
        }
        return sum;
    }
    Node* LCA(Node* root,int n1,int n2){
        if(root==nullptr)return nullptr;
        if(root->data==n1 || root->data==n2)return root;
        Node* left=LCA(root->left,n1,n2);
        Node* right=LCA(root->right,n1,n2);
        if(left!=nullptr && right!=nullptr)return root;
        return (left!=nullptr)?left:right;
    }
void solve() {
    vi preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int idx=-1;
    Node* root=BuildTree(preorder,idx);
    
    Node* ans=LCA(root,4,5);
    if(ans!=nullptr)cout<<ans->data<<endl;
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
