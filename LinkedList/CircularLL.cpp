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
class CircularLinkedList{
    Node* head;
    Node* tail;
    public:
    CircularLinkedList(){
        head=tail = nullptr;
    }
    void push_front(int val){
        Node* newNode=new Node(val);
        if(!head){
            head=tail=newNode;
            tail->next=head;
            return;
        }
        newNode->next=head;
        head=newNode;
        tail->next=head;
    }
    void printList(){
        if(!head)return;
        Node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<"(head)"<<endl;
        return;
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==nullptr){
            head=tail=newNode;
            tail->next=head;
            return;
        }
        tail->next=newNode;
        newNode->next=head;
        tail=newNode;
    }
    void pop_front(){
        if(head==nullptr)return;
        if(head==tail){
            delete head;
            head=tail=nullptr;
            return;}
            Node* temp=head;
            head=head->next;
            tail->next=head;
            delete temp;
        
    }
    void pop_back(){
        if(head==nullptr)return;
        if(head==tail){
            delete head;
            head=tail=nullptr;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=head;
        delete tail;
        tail=temp; 
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

    
};

void solve() {
    CircularLinkedList cll;
    cll.push_front(10);
    cll.push_front(20);
    cll.push_front(30);
    cll.printList();
    cll.push_back(5);
    cll.printList();
    cll.pop_front();
    cll.printList();

    
    

}

// -------------------------------
// 🔹 Entry Point
// -------------------------------
int main() {
    solve();
    return 0;
}
