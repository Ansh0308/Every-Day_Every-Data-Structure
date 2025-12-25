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
    Node* random;
    Node(int val){
        data = val;
        next = nullptr;
        random = nullptr;
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
    void printListWithRandom(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node: " << temp->data << " | Random: ";
        if (temp->random)
            cout << temp->random->data;
        else
            cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
    cout << "------------------" << endl;
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
    bool isCyclic(){//O(n)
        if(head==nullptr)return false;
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }

    Node* StartNodeCycle(){//O(n)
        if(head==nullptr)return nullptr;
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }
        if(!isCycle)return nullptr;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    void RemoveCycle(){//O(n)
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        
        Node* slow=head;
        Node* fast=head;
        bool isCycle=false;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCycle=true;
                break;
            }
        }
        if(!isCycle){
            cout<<"No cycle detected"<<endl;
            return;
        }
        slow=head;
        Node* prev=nullptr;
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=nullptr;
        cout<<"Cycle removed"<<endl;
    }
    Node* MergeSortedLists(Node* h1,Node* h2){//O(n+m)
        if(h1==nullptr)return h2;
        if(h2==nullptr)return h1;
        if(h1->data<h2->data){
            h1->next=MergeSortedLists(h1->next,h2);
            return h1;
        }else{
            h2->next=MergeSortedLists(h1,h2->next);
            return h2;
        }
    }
    Node* CopyListWithRandomPointer(Node* head) {
        if(!head) return nullptr;

        // Step 1: Create new nodes and insert them next to original nodes
        Node* newhead=new Node(head->data);
        Node* newtp=newhead;
        Node* oldtp=head->next;
        while(oldtp){
            Node* temp=new Node(oldtp->data);
            newtp->next=temp;
            newtp=newtp->next;
            oldtp=oldtp->next;
        }
        newtp=newhead;
        oldtp=head;
        unordered_map<Node*,Node*> mp;
        while(oldtp){
            mp[oldtp]=newtp;
            oldtp=oldtp->next;
            newtp=newtp->next;
    }
    oldtp=head;
    newtp=newhead;
    while(oldtp){
        if(oldtp->random!=nullptr){
            newtp->random=mp[oldtp->random];
        }
        else{
            newtp->random=nullptr;
        }
        oldtp=oldtp->next;
        newtp=newtp->next;
    }
    return newhead;
}

    
};

void solve() {
    LinkedList ll;

    // Create list: 1 -> 2 -> 3 -> 4 -> NULL
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);

    // Assign random pointers manually
    Node* n1 = ll.head;
    Node* n2 = n1->next;
    Node* n3 = n2->next;
    Node* n4 = n3->next;

    n1->random = n3;   // 1 -> 3
    n2->random = n1;   // 2 -> 1
    n3->random = n4;   // 3 -> 4
    n4->random = n2;   // 4 -> 2

    cout << "Original List (data | random):" << endl;
    ll.printListWithRandom(ll.head);

    // Copy list
    Node* copiedHead = ll.CopyListWithRandomPointer(ll.head);

    cout << "Copied List (data | random):" << endl;
    ll.printListWithRandom(copiedHead);
}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
