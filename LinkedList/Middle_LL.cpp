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
        next = nullptr;
    }
};
class LinkedList{
    public:
    Node* head;
    Node* tail;
    LinkedList(){
        tail=head = nullptr;
    }
    void push_front(int val){//O(1)
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }
    void printList(){//O(n)
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"Null"<<endl;
        return;
    }
    void push_back(int val){//O(1)
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
    }
    void pop_front(){//O(1)
        if(head==nullptr)return;
        Node* temp=head;
        head=head->next;
        delete temp;

    }
    void pop_back(){//O(n)
        if(head==nullptr)return;
        if(head->next==nullptr){
            delete head;
            head=tail=nullptr;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=nullptr;
        delete tail;
        tail=temp;
    }
    int size(){//O(n)
        int count=0;
        Node* temp=head;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    void insert_at(int pos,int val){//O(n)
        int n=size();
        if(pos<0 || pos>n){
            cout<<"Position out of bounds"<<endl;
            return;
        }
        if(pos==0){
            push_front(val);
            return;
        }
        
        if(pos==n){
            push_back(val);
            return;
        }
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
    int search(int val){//O(n)
        if(head==nullptr)return -1;
        Node* temp=head;
        int pos=0;
        while(temp){
            if(temp->data==val)return pos;
            pos++;
            temp=temp->next;
        }
        return -1;
    }
    void Middle(){//O(n)
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"Middle element is: "<<slow->data<<endl;
    }

    
};

void solve() {
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.printList(); // Output: 30 20 10
    ll.push_back(40);
    ll.push_back(50);
    ll.printList(); // Output: 30 20 10 40 50
    ll.pop_front();
    ll.printList(); // Output: 20 10 40 50
    ll.pop_back();
    ll.printList(); // Output: 20 10 40
    ll.insert_at(1, 25);
    ll.printList(); // Output: 20 25 10 40
    cout << "Size of LinkedList: " << ll.size() << endl; // Output: Size of LinkedList: 4
    int pos = ll.search(10);
    if (pos != -1)
        cout << "Element 10 found at position: " << pos << endl; // Output: Element 10 found at position: 2
    else
        cout << "Element 10 not found in the list." << endl;   
    ll.Middle(); // Output: Middle element is: 25 
    

}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
