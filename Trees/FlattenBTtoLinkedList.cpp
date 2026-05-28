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
    vs binaryTreePaths(Node* root) {
        vs ans;
        if(root==nullptr)return ans;
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(to_string(root->data));
            return ans;
        }
        vs left=binaryTreePaths(root->left);
        vs right=binaryTreePaths(root->right);
        for(auto &x:left){
            ans.push_back(to_string(root->data)+"->"+x);
        }
        for(auto &x:right){
            ans.push_back(to_string(root->data)+"->"+x);
        }
        return ans;
    }
    int MaxWidth(Node* root){
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans=max(ans,q.back().second-q.front().second+1);
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                if(temp.first->left!=nullptr)q.push({temp.first->left,temp.second*2+1});
                if(temp.first->right!=nullptr)q.push({temp.first->right,temp.second*2+2});
            }
        }
        return ans;
    }
    Node* FindIP(Node* curr){
        Node* temp=curr->left;
        while(temp->right!=nullptr && temp->right!=curr){
            temp=temp->right;
        }
        return temp;
    }
    void MorrisInorder(Node* root){
        Node* curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                cout<<curr->data<<" ";
                curr=curr->right;
            }
            else{
                Node* IP=FindIP(curr);
                if(IP->right==nullptr){
                    IP->right=curr;
                    curr=curr->left;
                }
                else{
                    IP->right=nullptr;
                    cout<<curr->data<<" ";
                    curr=curr->right;
                }
                
            }
        }
    }
    Node* LastVisited=nullptr;
    void FlattenBT(Node* root){
        if(!root)return;
        FlattenBT(root->left);
        FlattenBT(root->right);
        root->left=nullptr;
        root->right=LastVisited;
        LastVisited=root;
    }
void solve() {
    vi preorder={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int idx=-1;
    Node* root=BuildTree(preorder,idx);
    cout<<"Flattening the Binary Tree to a Linked List: ";
    FlattenBT(root);
    Node* temp=root;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
